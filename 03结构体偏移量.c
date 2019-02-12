//
// Created by phoenix on 2/7/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct A
{
    char a1;
    int a2;
};

void test31()
{
    struct A a={'b',10};
    printf("a2:%d\n",*(int *)((char*)&a+offsetof(struct A,a2)));
    printf("a2:%d\n",*((int*)&a +1));
}

struct B
{
    int a;
    double b;
};

struct C
{
    char a;
    int b;
    struct B bb;
};

int main3()
{
    test31();
    printf("03\n");
    return 0;
}


