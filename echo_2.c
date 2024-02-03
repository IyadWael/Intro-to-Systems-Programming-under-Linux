#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    /* if(argv[0]!="./echo")
       {
       printf("Not supported command");
       } 
       else
       { */
    int i;
    for (i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    //}

    printf("\n");
    return 0;
}

