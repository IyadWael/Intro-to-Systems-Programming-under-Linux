#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int MAX_SIZE = 100;
    char buf[MAX_SIZE];
    char *path = getcwd(buf, MAX_SIZE);
    printf("%s\n", path);

    return 0;
}

