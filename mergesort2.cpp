// C++ program for Merge Sort
#include <iostream>
#include <cmath>
#include <climits> 
#include <cstdio>
using namespace std;
 
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int A[], int const p, int const q, int const r)
{
    int const n1 = q - p + 1;
    int const n2 = r - q;
 
    // Create temp arrays
    int* L = (int*) malloc(sizeof(int) * (n1+1));
    int* R = (int*) malloc(sizeof(int) * (n2+1));
    int* z = L;
    int* w = R;


    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < n1; i++){
        cout << "Char is " << A[p + i] << endl;
        *(z+i) = A[p + i];
        cout << "In leftarray Char is " << *(z+i) << endl;
    }
    for (auto j = 0; j < n2; j++){
        cout << "Char is " << A[q + 1 + j] << endl;
        *(w+j) = A[q + 1 + j];
        cout << "In rightarray Char is " << *(w+j) << endl;
    }
 
    auto i = 0; // Initial index of first sub-array
    auto j = 0; // Initial index of second sub-array
    int* end = A + r ;
    // k is initial index of merged array
    // Merge the temp arrays back into array[left..right]
    for (int* k = A; k < end; ++k) {
        if (*(L+i) == *end && *(R+j) == *end){
            return;
        }else {
            if (*(L+i) <= *(R+j)) {
                cout << "In leftarr Char is " << *(L+i) << endl;
                cout << "In rightarr Char is " << *(R+j) << endl;
                *k = *(L+i);
                cout << "In merged array Char is " << *k << endl;
                i++;
                ++k;
            }
            else {
                cout << "In leftarry Char is " << *(L+i) << endl;
                cout << "In rightar Char is " << *(R+j) << endl;
                *k = *(R+j);
                cout << "In merged array Char is " << *k << endl;
                j++;
                ++k;
            }
        }

    }
    delete[] L;
    delete[] R;
}
 
// begin is for left index and end is right index of the sub-array of arr to be sorted 
void mergeSort(int A[], int const p, int const r)
{
    if (p < r){
        auto q = floor((p + r) / 2);
        cout << "r is " << r << endl;
        cout << "p is " << p << endl;
        cout << "q is " << q << endl;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }

}
 
// UTILITY FUNCTIONS: Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++){
        cout << *(A+i) << " ";
    }
    cout << "\n";
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
 
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes