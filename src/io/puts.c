#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <internal/syscall.h>

int puts(char* str)
{
    syscall(1, 1, str, strlen(str));
    int ret = syscall(1, 1, "\n", 1);
    return ret;
}
