#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define NUM 128
#define CMD_NUM 64

int main()
{
    char command[NUM];
    for (; ; )
    {
        char* argv[CMD_NUM] = { NULL };
        //1.打印提示符！
        command[0] = 0;//这种方式，可以做到O(1)的时间复杂度，清空字符串
        printf("[Myy@Morgan myshell]-");
        //2.获取命令字符串
        fgets(command, NUM, stdin);
        command[strlen(command) - 1] = '\0';//cat\n\0把\n改为\0就好了
        //3.解析命令字符串 char *argv[]

       //printf("echo:%s\n",command);
       //fflush(stdout);//标准输出刷新！
       //trtok();
        const char* sep = " ";
        argv[0] = strtok(command, sep);
        int i = 1;
        while (argv[i] = strtok(NULL, sep))
        {
            i++;
        }
        //4.检查命令是否需要shell本身执行，内建命令
        if (strcmp(argv[0], "cd") == 0)
        {
            if (argv[1] != NULL) chdir(argv[1]);
            continue;
        }

        //5.执行第三方命令
        if (fork() == 0)
        {
            execvp(argv[0], argv);
            exit(1);
        }
        waitpid(-1, NULL, 0);
    }
    return 0;
}
