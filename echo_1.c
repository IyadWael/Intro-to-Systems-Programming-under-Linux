# include<stdio.h>
# include<string.h>

void echo(void);

int main()
{
   echo();
  return 0;
}

void echo(void)
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
