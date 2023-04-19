/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

unsigned int SIZE = 10;

// function prototypes
void selectionSort(int array[], size_t length);
void swap(int array[], size_t first, size_t second);
void printPass(int array[], size_t length, unsigned int pass, size_t index);

int main()
{
    
    int array[SIZE]; //Declare the array of integer numbers to be sorted
    srand(time(NULL)); // seed the rand function
    
    for (size_t i = 0; i < SIZE; i++) {
        array[i] = rand() % 90 + 10; // give each array element a value
    }
    
    puts("Unsorted array:");
    
    for(size_t i; i < SIZE; i++) {//print the unsorted array
        printf("%d ", array[i]);
        
    }
    
    puts("\n");
    
    selectionSort(array, SIZE);
    puts("\nSorted array:");
    
    for(size_t i = 0; i < SIZE; i++) {// print the sorted array
        printf("%d ", array[i]);
        
    }

    return 0;
}
//function that performs selection sort on the array
void selectionSort(int array[], size_t length) {
    //loop over length elements
    for(size_t i = 0; i < length; i++) {
        size_t smallest = i; //first index of remaining array
        
        //loop to find the index of smallest element
        for(size_t j = i + 1; j < length; j++) {
            if(array[j] < array[smallest]) {
                smallest = j;
            }
        }
        
        swap(array, i, smallest);//swap the smallest value
        printPass(array, length, i + 1, smallest);// output pass

    }
}
//function that swaps two elements in the array
void swap(int array[], size_t first, size_t second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}
//function that prints a pass of the algorithm
void printPass(int array[], size_t length, unsigned int pass, size_t index){
    
    printf("\nAfter pass %2d: \n", pass);
    //output elements till the selected item
    for(size_t i = 0; i < index; i++) {
        printf("%d  ", array[i]);
        
    }
    
    printf("%d* ", array[index]);//indicate swap
    //complete outputting the array
    for(size_t i = index + 1; i < length; i++) {
        printf("%d  ", array[i]);
        
    }
    
    printf("%s", "\n");//for some kind of alignment
    //indicate amount of array that is sorted
    for(unsigned int i = 0; i < pass; i++) {
        printf("%s", "--  ");
        
    }
}





