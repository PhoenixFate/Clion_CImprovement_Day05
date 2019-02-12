//
// Created by phoenix on 2/9/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test41()
{
    FILE *f=fopen("../test.txt", "r");
    if (f == NULL)
    {
        printf("打开文件失败");
        return;
    }
    char ch;
    while (!feof(f))
    {
        ch = (char)fgetc(f);
        printf("%c", ch);
    }
}

void test42()
{
    FILE *file=fopen("../test.txt","r");
    if(file==NULL)
    {
        printf("打开文件失败");
        return ;
    }
    char buffer[1024];
    while(1)
    {
        char *temp=fgets(buffer,1024,file);
        if(temp==NULL){
            break;
        }
        printf("len:%d",strlen(buffer));
        printf("%s",buffer);
    }
}

int main4()
{
    //test41();
    test42();
    system("pause");
    return 0;
}

