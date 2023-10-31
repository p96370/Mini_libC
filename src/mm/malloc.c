// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <internal/syscall.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void* malloc(size_t size)
{
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!mem_list_add(ptr, size))
		return ptr;

	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	void *ptr = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!mem_list_add(ptr, size * nmemb))
		return ptr;

	memset(ptr, 0, size * nmemb);

	return NULL;
}

void free(void *ptr)
{
	size_t len = mem_list_find(ptr)->len;
	mem_list_del(ptr);
	munmap(ptr, len);
}

void *realloc(void *ptr, size_t size)
{
	void *new_ptr = mmap(NULL, sizeof(void *), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	struct mem_list *old = mem_list_find(ptr);

	syscall(__NR_mremap, ptr, old->len, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, new_ptr);

	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, size * nmemb);
}
