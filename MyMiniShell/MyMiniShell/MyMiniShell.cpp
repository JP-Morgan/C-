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
        //1.��ӡ��ʾ����
        command[0] = 0;//���ַ�ʽ����������O(1)��ʱ�临�Ӷȣ�����ַ���
        printf("[Myy@Morgan myshell]-");
        //2.��ȡ�����ַ���
        fgets(command, NUM, stdin);
        command[strlen(command) - 1] = '\0';//cat\n\0��\n��Ϊ\0�ͺ���
        //3.���������ַ��� char *argv[]

       //printf("echo:%s\n",command);
       //fflush(stdout);//��׼���ˢ�£�
       //trtok();
        const char* sep = " ";
        argv[0] = strtok(command, sep);
        int i = 1;
        while (argv[i] = strtok(NULL, sep))
        {
            i++;
        }
        //4.��������Ƿ���Ҫshell����ִ�У��ڽ�����
        if (strcmp(argv[0], "cd") == 0)
        {
            if (argv[1] != NULL) chdir(argv[1]);
            continue;
        }

        //5.ִ�е���������
        if (fork() == 0)
        {
            execvp(argv[0], argv);
            exit(1);
        }
        waitpid(-1, NULL, 0);
    }
    return 0;
}
