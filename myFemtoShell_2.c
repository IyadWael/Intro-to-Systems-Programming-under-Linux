# include<stdio.h>
# include<string.h>
#include <unistd.h>

void cd (char *path);
void pwd (void);
void my_exit(void);

void echo(void);

int main(int argc,char*argv[])
{
  // echo_exit();
 // while(1)
 // {
   // printf("Readyy> ");
    printf("argv[0]--->%s\n",argv[0]);
    printf("argv[1]--->%s\n",argv[1]);
    printf("argv[2]--->%s\n",argv[2]);
    printf("argv[3]--->%s\n",argv[3]);

   // if(argv[1] == "echo")
   // {
            printf("I have entered echo\n");
            printf("%s",argv[2]);
            printf("\n");
           // echo(argv[2]);
   // }
     if(argv[1]=="exit")
    {
       my_exit();
      // break;
    }
    else if(argv[1]=="pwd")
    {
       pwd();
    }
    else if(argv[1]=="cd")
    {
      cd(argv[2]);
    }
    else
    {
     printf("Error:Enter one of these commands(echo,pwd,cd,exit)\n");
    }
 // }
  return 0;
}

void echo_exit(void)
{
  char * exit ="exit";
  char str[20];
  while(1)
  {
  printf("Readyy> ");
  fgets(str,20,stdin);
  if(strncmp(str,exit,4)==0)
 {
   printf("Good Bye:)\n");
   break;
 }
  else
  {
   printf("You said:%s\n",str);
  }
}
}




/*void echo (void)
{

{
   printf("%s",argv[2]);
}

printf("\n");
}*/

void my_exit(void)
{
 // if(strncmp(str,exit,4)==0)
// {
   printf("Good Bye:)\n");
  // return;
// }

}
void pwd (void)
{
   int MAX_SIZE = 100;
    char buf[MAX_SIZE];
    char *path = getcwd(buf, MAX_SIZE);
    printf("%s\n", path);

}

void cd (char *path)
{
    chdir(path);

}


