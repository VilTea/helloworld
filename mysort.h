#ifndef MYSORT_H_
#define MYSORT_H_

class Sort {
private:
    void Megra(int *target, int front, int mid, int last);
public:
    Sort();
    ~Sort();
    void insertionSort(int *target, int size);//Time.O(n^2)(min-O(n)) Room.O(1)
    void megraSort(int *target, int front, int last);//Time.O(nlgn) Room.O(n) 
    void bubbleSort(int *target, int size);//Time.O(n^2)(min-O(n)) Room.O(1)
    void selectionSort(int *target, int size);//Time.O(n^2)(ever) Room.O(1)
    void shellSort(int *target, int size);
    void quickSort(int *target, int front, int last);
};

#endif