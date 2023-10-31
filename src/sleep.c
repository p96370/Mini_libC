// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

// Define the system call number for sleep
#define SYS_SLEEP 100   // Replace with the actual system call number

void sleep(unsigned int seconds)
{
	syscall(SYS_SLEEP, seconds);
}

int main(void)
{
	printf("Sleeping for 5 seconds...\n");
	sleep(5);
	printf("Awake!\n");
	return 0;
}
