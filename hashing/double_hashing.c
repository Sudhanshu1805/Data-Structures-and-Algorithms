#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void init(int * table)
{
    for(int i=0;i<SIZE;i++)
    {
        table[i] = -1;
    }
}

int hash_function(int value, int i)
{
    int firsthash = value%SIZE;
    int secondhash = value%5;
    return((firsthash + i*secondhash)%SIZE);
}

void insert(int value,int*table)
{
    int index = value%SIZE;
    int i =0;
    while(table[index]!=-1)
    {
        index = hash_function(value,i);
        i++;
    }
    table[index] = value;
}

void display(int *table)
{
    for(int i=0;i<SIZE;i++)
    {
        if(table[i]!=-1)
        {
            printf("Index %d Value = %d",i,table[i]);
        }
    }
}
