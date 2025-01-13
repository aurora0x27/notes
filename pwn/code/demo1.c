#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char sh[] = "/usr/bin/sh";

int init()
{
    setvbuf(stdin , 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    return 0;
}

int func(char* cmd)
{
    system(cmd);
    return 0;
}

int main()
{
    init();
    char a[8] = { 0 };
    char b[8] = { 0 };
    puts("input: ");
    gets(a);
    if (b[0] == 'a') {
        func(sh);
    }
    return 0;
}
