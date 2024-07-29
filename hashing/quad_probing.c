#include<stdio.h>
#include<stdlib.h>
#define tsize 10

void init(int*table)
{
    for(int i =0;i<tsize;i++)
    {
        table[i] = -1;
    }
}

void insert(int*table,int value)
{
    int index = value%tsize;
    int i = 1;
    while(table[index]!=-1)
    {
        index = (index+(i*i))%tsize;
        i++;
    }
    table[value] = value;
}

void display(int*table)
{
    for(int i=0;i<tsize;i++)
    {
        if(table[i]!=-1)
        {
            printf("%d",table[i]);
        }
    }
}