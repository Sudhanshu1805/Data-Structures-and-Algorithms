// #include<stdio.h>

// void heapify(int arr[],int i)
// {
//     int parent = (i-1)/2;
//     while(i>0 && arr[i]>arr[parent])
//     {
//         int temp = arr[i];
//         arr[i] = arr[parent];
//         arr[parent] = temp;
//         i = parent;
//         parent = (i-1)/2;
//     }
// }

// void insert(int arr[],int*n,int key)
// {
//     if(*n>100)
//     {
//         prinf("The heap is already full");
//         return;
//     }
//     arr[*n] = key;
//     (*n)++;
//     heapify(arr,*n-1);
// }


#include<Stdio.h>

void heapify(int arr[],int i)
{
    int parent = (i-1)/2;
    while(i>0 && arr[i]>arr[parent])
    {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        i = parent;
        parent = (i-1)/2;
    }
}

void insert(int arr[], int*n,int key)
{
    if(*n>100)
    {
        printf("The heap is already full");
        return;
    }
    arr[*n]= key;
    (*n)++;
    heapify(arr,*n-1);

}