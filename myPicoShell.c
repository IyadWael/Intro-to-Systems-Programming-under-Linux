#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
void cd();
void pwd(void);
void my_exit(void);
void echo(char *token);

extern char **environ;

int main(int argc, char *argv[])
{
    char buff[100];
    char str[20];

    while (1) {
        printf("Readyyy>>>");
        char *cmd = NULL;
        size_t n = 0;
        int size = getline(&cmd, &n, stdin);
        cmd[size - 1] = 0;
// Used strtok function to parse the command to tokens
        char *token = strtok(cmd, " ");
        if (strlen(cmd) == 0)
            continue;
        // Comparing the first token which is the command in order to take the right action(Built-in commands)
        if (strcmp(token, "echo") == 0) {
            echo(token);
        } else if (strncmp(token, "pwd", 3) == 0) {
            pwd();
        } else if (strcmp(token, "cd") == 0) {
            cd();
        } else if (strncmp(token, "exit", 4) == 0) {
            my_exit();
            break;
        }
        // Here using fork and exec functions in order to perform external commands
        else {


            pid_t returned_pid = fork();
            if (returned_pid > 0) {
                int wstatus;
                wait(&wstatus);
            } else if (returned_pid == 0) {

                char *new_program_argv[] = { NULL };

                execvp(cmd, new_program_argv);

                printf("I am not in the mode of execution. Exec failed\n");

                return -1;
            }

            else {
                printf("ERROR: I could not get a child\n");
            }

            free(cmd);
            cmd = NULL;
            n = 0;
        }
    }

    return 0;
}

void my_exit(void)
{
    printf("Good Bye:)\n");
}


void pwd(void)
{
    int MAX_SIZE = 100;
    char buf[MAX_SIZE];
    char *path = getcwd(buf, MAX_SIZE);
    printf("%s\n", path);
}

void cd(char *token)
{
    token = strtok(NULL, " ");
    chdir(token);

}

void echo(char *token)
{

    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL)
            printf("%s ", token);
    }
    if (token != NULL)
        printf("\n");
}

