//
// Created by phoenix on 2/12/2019.
//

#ifndef CLION_CIMPROVEMENT_DAY05_CONFIGFILE_H
#define CLION_CIMPROVEMENT_DAY05_CONFIGFILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct configInfo
{
    char key[64];
    char value[128];
};
//获取文件有效行数
int getLines(FILE *file);
//加载文件
void loadFile(const char*filePath,char***fileData,int *myLines);
//解析文件
void parseFile(char**fileData,int lines,struct configInfo**info);
//根据key获得value
char*getInfo(const char*key,struct configInfo*info,int lines);
//释放配置文件信息
void destroyInfo(struct configInfo*info);
//判断当前行是否有效
int isValid(const char*buf);



#endif //CLION_CIMPROVEMENT_DAY05_CONFIGFILE_H
