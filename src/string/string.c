// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i;
	for (i = 0; source[i]; i++)
		destination[i] = source[i];
	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i = 0;
	for (; i < len; i++)
		destination[i] = source[i];

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int len = 0;
	for (; destination[len]; len++) {}

	for (int i = 0; source[i]; i++)
		destination[len++] = source[i];

	destination[len] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int len_d = 0;
	for (; destination[len_d]; len_d++) {}

	size_t i = 0;
	for (; i < len; i++)
		destination[len_d++] = source[i];

	destination[len_d] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	for (int i = 0; ; i++) {
		if (str1[i] != str2[i]) {
			if (str1[i] < str2[i] )
				return -1;
			else
				return 1;
		}
		if (str1[i] == '\0' && str2[i] == '\0' )
			return 0;
	}
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t i = 0;
	for (; i < len; i++) {
		if (str1[i] != str2[i]) {
			if (str1[i] < str2[i] )
				return -1;
			else
				return 1;
		}
		if (str1[i] == '\0' && str2[i] == '\0' )
			return 0;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++) {}

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (str[0] != '\0') {
		if (c == str[0]) {
			char *cop = (char *)str;
			return cop;
		}
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int len = 0;
	for (; str[len]; len++) {}

	for (int i = len - 1; i >= 0; i--)
		if (c == str[i]) {
			char *cop = (char *)(str + i);
			return cop;
		}

	return NULL;
}

int cmp(const char *haystack, const char *needle)
{
	while (haystack[0] != '\0' && needle[0] != '\0') {
		if (haystack[0] != needle[0])
			return 0;
		haystack++;
		needle++;
	}

	if (needle[0] == '\0')
		return 1;
	return 0;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	while (haystack[0] != '\0') {
		if (haystack[0] == needle[0] && cmp(haystack, needle) == 1)
			return (char *)haystack;
		haystack++;
	}

	return NULL;
}
// https://www.techiedelight.com/implement-strstr-function-c-iterative-recursive/

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *res = NULL;

	while (strstr(haystack, needle)) {
		res = strstr(haystack, needle);
		haystack++;
	}

	return res;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	size_t i = 0;
	for (; i < num; i++)
		*(char *)(destination + i) = *(char *)(source + i);

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char p[100000];
	size_t i = 0;
	for (; i < num; i++)
		p[i] = *(char *)(source + i);

	size_t j = 0;
	for (; j < num; j++)
		*(char *)(destination + j) = p[j];

	return destination;
}
// https://www.geeksforgeeks.org/write-memcpy/

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const char *p1 = (const char *)ptr1;
	const char *p2 = (const char *)ptr2;

	size_t i = 0;
	for (; i < num; i++)
		if (p1[i] != p2[i])
			return (int)(p1[i] - p2[i]);

	return 0;
}
// https://aticleworld.com/memcmp-in-c/

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *p = source;
	size_t i = 0;
	for (; i < num; i++)
		*p++ = (unsigned char) value;

	return source;
}
// https://aticleworld.com/memset-in-c/
