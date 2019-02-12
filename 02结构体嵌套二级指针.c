#include <stdio.h>
#include <stdlib.h>

struct Teacher2
{
    char*name;
    char**students;
};

int allocateTeachers(struct Teacher2 ***temp,int len)
{
    if(temp==NULL)
    {
        return -1;
    }
    if(len<=0)
    {
        return -2;
    }

    struct Teacher2 ** ts=malloc(sizeof(struct Teacher2*)*len);
    for(int i=0;i<len;++i)
    {
        ts[i]=malloc(sizeof(struct Teacher2));
        ts[i]->name=malloc(sizeof(char)*64);
        sprintf(ts[i]->name,"teacher_%d",i);
        ts[i]->students=malloc(sizeof(char*)*10);
        for(int j=0;j<10;++j)
        {
            ts[i]->students[j]=malloc(sizeof(char)*64);
            sprintf(ts[i]->students[j],"teacher_%d_student_%d",i,j);
        }
    }
    *temp=ts;
    return 0;
}

int printTeachers(struct Teacher2 **teachers,int len)
{
    if(teachers==NULL)
    {
        return -1;
    }

    for(int i=0;i<len;++i)
    {
        printf("teacher's name:%s\n",teachers[i]->name);
        for(int j=0;j<10;++j)
        {
            printf("students' name:%s\n",teachers[i]->students[j]);
        }


    }
    return 0;
}

int freeTeachers(struct Teacher2 **teachers,int len)
{
    if(teachers==NULL)
    {
        return -1;
    }

    for(int i=0;i<len;++i)
    {
        if(teachers[i]->name!=NULL)
        {
            free(teachers[i]->name);
            teachers[i]->name=NULL;
        }
        if(teachers[i]->students!=NULL)
        {
            for(int j=0;j<10;++j)
            {
                free(teachers[i]->students[j]);
            }
            free(teachers[i]->students);
        }


        free(teachers[i]);
    }
    free(teachers);
    return 0;
}



void test21()
{
    struct Teacher2 **teachers=NULL;
    allocateTeachers(&teachers,5);
    printTeachers(teachers,5);
    if(freeTeachers(teachers,5)==0)
    {
        printf("释放成功\n");
    }
}

int main2() {
    test21();
    printf("Hello, World!\n");
    return 0;
}