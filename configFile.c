//
// Created by phoenix on 2/12/2019.
//

#include "configFile.h"

//获得文件行数
int getLines(FILE *file)
{
    char buffer[1024];
    int lines=0;
    while(fgets(buffer,1024,file)!=NULL)
    {
        if(!isValid(buffer))
        {
            continue;
        }
        memset(buffer,0,1024);
        ++lines;
    }
    fseek(file,0,SEEK_SET);
    return lines;
}

//加载文件
void loadFile(const char*filePath,char***fileData,int *myLines)
{
    FILE *file=fopen(filePath,"r");
    if(file==NULL)
    {
        printf("file is null");
        return;
    }
    int lines=getLines(file);

    //给每行数据分配内存
    char **temp=malloc(sizeof(char*)*lines);
    char buffer[1024]={0};
    int index=0;
    while(fgets(buffer,1024,file)!=NULL)
    {
        //如果返回false，代表当前行无效，则continue
        //不是key：value的行即为无效行
        if(!isValid(buffer))
        {
            continue;
        }
        temp[index]=malloc(strlen(buffer)+1);
        memset(temp[index],0,sizeof(strlen(buffer)+1));
        char *s=strcpy(temp[index],buffer);
        ++index;
        //清空buffer
        memset(buffer,0,1024);
    }
    *fileData=temp;
    *myLines=lines;
    //关闭文件;
    fclose(file);
}
//解析文件
void parseFile(char**fileData,int lines,struct configInfo**info)
{
    struct configInfo *tempInfo=malloc(sizeof(struct configInfo)*lines);
    memset(tempInfo,0,sizeof(struct configInfo)*lines);
    for(int i=0;i<lines;++i)
    {
        int flag=0;
        if (fileData[i][strlen(fileData[i]) - 1] == '\n')
        {
            //printf("最后一个是换行!\n");
            flag = 1;
        }
        char *pos=strchr(fileData[i],':');
        strncpy(tempInfo[i].key,fileData[i],pos-fileData[i]);
        strncpy(tempInfo[i].value,pos+1,strlen(pos+1)-flag);
    }
    //释放文件信息
    for(int i=0;i<lines;++i)
    {
        if(fileData[i]!=NULL)
        {
            free(fileData[i]);
            fileData[i]=NULL;
        }
    }
    free(fileData);
    *info=tempInfo;
}
//根据key获得value
char*getInfo(const char*key,struct configInfo*info,int lines)
{
    for(int i=0;i<lines;++i)
    {
        if(strcmp(key,info[i].key))
        {
            return info[i].value;
        }
    }
    return NULL;
}
//释放配置文件信息
void destroyInfo(struct configInfo*info)
{
    if(NULL!=info)
    {
        free(info);
    }

}
//判断当前行是否有效
int isValid(const char*buf)
{
    if(NULL==buf|| buf[0]=='#' || buf[0]=='\n' || strchr(buf,':')==NULL)
    {
        return 0;
    }
    return 1;
}

