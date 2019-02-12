//
// Created by phoenix on 2/12/2019.
//
#include "configFile.h"
void test51()
{
    int lines=0;
    char**fileData;
    loadFile("../config.ini",&fileData,&lines);
    for(int i=0;i<lines;++i)
    {
        printf("%s",fileData[i]);
    }
    printf("\n");
    struct configInfo *info=NULL;
    parseFile(fileData,lines,&info);
    for(int i=0;i<lines;++i)
    {
        printf("key:%s   ",info[i].key);
        printf("value:%s",info[i].value);
        printf("\n");
    }

    printf("-------------------------------------------------------------\n");
    printf("%s\n",getInfo("ip",info,lines));
    destroyInfo(info);
    info=NULL;
}

int main()
{
    test51();
    return 0;
}

