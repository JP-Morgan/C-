#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <Windows.h>
//主要代码在Linux上
//int main()
//{
//	printf("hello");
//	Sleep(10);
//	exit(EXIT_SUCCESS);
//	//return 0;
//}
int Fun()
{
    printf("fun test\n");
    return 1;
}
int main()
{
    printf("ennenen");
    _exit(12);
    //return 0;
}