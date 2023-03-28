// Bubble sort in C++

#include <iostream>
using namespace std;

#include <iostream>
#include <algorithm>
#include <iterator>

#include <chrono>
using namespace std::chrono;

// perform bubble sort
// double mergeSort(int array[], int size) {

//     auto start = high_resolution_clock::now();

 
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);
//     double time = (double)duration.count() / 1000.0;
//     return time;

// }




////////////////////////////////////////////////////////////////////////////////////////////////////
void swapi(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
/* This function is same in both iterative and recursive*/
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
  
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swapi(&arr[i], &arr[j]);
        }
    }
    swapi(&arr[i + 1], &arr[h]);
    return (i + 1);
}
  
/* A[] --> Array to be sorted, 
l --> Starting index, 
h --> Ending index */
void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////

int partitionr(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSortr(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partitionr(arr, start, end);
 
    // Sorting the left part
    quickSortr(arr, start, p - 1);
 
    // Sorting the right part
    quickSortr(arr, p + 1, end);
}
  


// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}




int main() {
  
// making random array 
    const int sz = 74270;
    int randArray[sz],i;
    for(i=0;i<sz;i++)
        randArray[i]=rand(); 

    
    // copying random array

    int data1[sz], data2[sz], data3[sz], data4[sz],data5[sz] ;
    
    std::copy(std::begin(randArray), std::end(randArray), std::begin(data1));
    std::copy(std::begin(randArray), std::end(randArray), std::begin(data2));
    // std::copy(std::begin(randArray), std::end(randArray), std::begin(data3));
    // std::copy(std::begin(randArray), std::end(randArray), std::begin(data4));
    // std::copy(std::begin(randArray), std::end(randArray), std::begin(data5));


    int arr_size = sizeof(randArray) / sizeof(randArray[0]);
    
    



    auto start1 = high_resolution_clock::now();

    quickSortr(data2, 0, arr_size - 1);
 
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    double time1 = (double)duration1.count() / 1000.0;




    auto start2 = high_resolution_clock::now();

    quickSortIterative(data1, 0, arr_size - 1);
 
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    double time2 = (double)duration2.count() / 1000.0;



    cout << "Size :- "<<arr_size<< " | recursive quick :  " << time1  << " | iterative quick : " << time2 << "\n";






}