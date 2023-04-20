/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
Quick sort and swap functions from 'The practice of programming',  
main function adapted from C++ How to program

*******************************************************************************/
#define SIZE 10
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

//Quick sort: sort array[0]..array[n-1] into increasing order

//function prototypes
void quickSort(int array[], int n);
void swap(int array[], int i, int j);

int main()
{
    int array[SIZE]; //declare array of ints to be sorted
    
    srand(time(NULL));//seed the rand function
    
    for(size_t i = 0; i < SIZE; i++) {
        array[i] = rand() % 90 + 10;//give each element a value
    }
    
    puts("Unsorted array:");
    
    for(size_t i = 0; i < SIZE; i++) {//print the array
        printf("%d  ", array[i]);
    }
    
    puts("\n");
    
    quickSort(array, SIZE);
    puts("Sorted array:");
    for(size_t i; i < SIZE; i++) {//print the array
        printf("%d  ", array[i]);
    }

    return 0;
}

void quickSort(int array[], int n) {
    
    int i;
    int last;
    
    if(n <= 1) {//nothing to do
        return;
    }
    
    swap(array, 0, rand() % n); //move pivot element to array[0]
    last = 0;
    
    for(i = 1; i < n; i++) {//partition
        if(array[i] < array[0]) {
            swap(array, ++last, i);
        }
    }
    swap(array, 0, last);//restore pivot
    quickSort(array, last); //recursively sort
    quickSort(array + last + 1, n - last - 1); //each part
}

//swap: interchange array[i] and array[j]
void swap(int array[], int i, int j) {
    
    int temp;
    
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}










