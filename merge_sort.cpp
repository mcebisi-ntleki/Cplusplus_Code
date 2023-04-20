/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#define SIZE 10
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

//function prototypes
void mergeSort(int array[], size_t length);
void sortSubArray(int array[], size_t low, size_t high);
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right);
void displayElements(int array[], size_t length);
void displaySubArray(int array[], size_t left, size_t right);


int main(void)
{
    int array[SIZE]; //declare the array of ints to be sorted
    
    srand(time(NULL)); // seed the rand function
    
    for(size_t i = 0; i < SIZE; i++) {
        array[i] = rand() % 90 + 10;// give each element a value
    }
    
    puts("Unsorted array:");
    displayElements(array, SIZE); //print the array
    puts("\n");
    mergeSort(array, SIZE); //merge sort the array
    puts("Sorted array");
    
    displayElements(array, SIZE); //print the array

    return 0;
}

//function implements merge sort
void mergeSort(int array[], size_t length) {
    
    sortSubArray(array, 0, length - 1);
    
}

//function sorts a piece of the array
void sortSubArray(int array[], size_t low, size_t high) {
    //test case: size of array is 1
    if((high - low) >= 1) {//is not the base case
        size_t middle1 = (low + high)/2;
        size_t middle2 = middle1 + 1;
        
        //output split step
        printf("%s", "split: ");
        displaySubArray(array, low, high);
        printf("%s", "\n ");
        displaySubArray(array, low, middle1);
        printf("%s", "\n ");
        displaySubArray(array, middle2, high);
        puts("\n");
        
        //split array in half and sort each half recursively
        sortSubArray(array, low, middle1); //first half
        sortSubArray(array, middle2, high); //second half
        
        //merge the sorted arrays
        merge(array, low, middle1, middle2, high);
    }
}

//merge two sorted arrays into one sorted array
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right) {
    size_t leftIndex = left; //index into the left subarray 
    size_t rightIndex = middle2; //index into the right subarray
    size_t combineIndex = left; //index into temporary array
    int tempArray[SIZE]; //temporary array
    
    //output two subarrays before merging
    printf("%s", "merge: ");
    displaySubArray(array, left, middle1);
    printf("%s", "\n ");
    displaySubArray(array, middle2, right);
    puts("");
    
    //nerge tge subarrays until end of one is reached
    while(leftIndex <= middle1 && rightIndex <= right) {
        //place the smaller of the two current elements in 
        //in result and move to the next space in the subarray
        if(array[leftIndex] <= array[rightIndex]) {
            tempArray[combineIndex++] = array[leftIndex++];
        }
        else {
            tempArray[combineIndex++] = array[rightIndex++];
        }
    }
    if(leftIndex == middle2) {//if at end of left subarray
        while(rightIndex <= right) {//copy the right subarray
            tempArray[combineIndex++] = array[rightIndex++];
        }
    }
    //copy values back into original array
    for(size_t i = left; i <= right; i++) {
        array[i] = tempArray[i];
    }
    //output merged subarray
    printf("%s", " ");
    displaySubArray(array, left, right);
    puts("\n");
}

//display elements in array
void displayElements(int array[], size_t length) {
    displaySubArray(array, 0, length - 1);
    
}

//display certain elements in an array
void displaySubArray(int array[], size_t left, size_t right) {
    //output spaces for alignment
    for(size_t i = 0; i < left; i++) {
        printf("%s", " ");
    }
    
    //output elements left in array
    for(size_t i = left; i <= right; i++) {
        printf(" %d", array[i]);
    }
}

















