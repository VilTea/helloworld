#include "mysort.h"
#include <iostream>
#include <vector>

using namespace std;

Sort::Sort() {}

Sort::~Sort() {}

void Sort::insertionSort (int *target,int size)
{
    int key;
    int j = 0;
    for(int i = 1; i < size; i++)
    {
        key = target[i];
        j = i - 1;
        while(j >= 0 && target[j] > key)
        {
            target[j + 1] = target[j];
            j = j - 1;
        }
        target[j + 1] = key;    
    }
}

void Sort::megraSort (int *target,int front, int last)
{
    if(front < last)
    {
        int mid = (front + last) / 2;
        megraSort(target, front, mid);
        megraSort(target, mid + 1, last);
        Megra(target, front, mid, last);
    }
}

void Sort::Megra(int *target, int front, int mid, int last)
{
    int m = mid - front + 1;
    int n = last - mid;
    int *Left = (int *)calloc(m + 1, sizeof(int));
    int *Right = (int *)calloc(n + 1, sizeof(int));
    int i, j;
    for(i = 0; i < m; i++)
        Left[i] = target[front + i];
    for(j = 0; j < n; j++)
        Right[j] = target[mid + j + 1];
    Left[m] = 2147483647;
    Right[n] = 2147483647;
    i = 0; j = 0;
    for(int k = front; k <= last; k++)
    {
        if(Left[i] <= Right[j])
        {
            target[k] = Left[i];
            i++;
        }
        else
        {
            target[k] = Right[j];
            j++;
        }
    }
}

void Sort::bubbleSort(int *target, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(target[j] > target[j + 1])
            {
                int temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }
}

void Sort::selectionSort(int *target, int size)
{
    int minIndex, temp;
    for(int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < size - 1;)
        {
            if(target[j] < target [minIndex])
                minIndex = j;
        }
        temp = target[i];
        target[i] = target[minIndex];
        target[minIndex] = temp;
    }
}

void Sort::shellSort(int *target, int size)
{
    int temp, gap = 1;
    while(gap < size / 3)
        gap = gap * 3 + 1;
    for(gap; gap > 0; gap = gap / 3)
    {
        for(int i = gap; i < size; i++)
        {
            temp = target[i];
            for(int j = i - gap; j > 0 && target[j] > temp; j -= gap)
                target[j + gap] = target [j]
            target[j + gap] = temp;
        }
    }

}

void Sort::quickSort(int *target, int front, int last)
{
    
}
