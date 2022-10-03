//October 2nd, 2022 12:11 PM 

#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;


void merge(int A[], int const p, int const q, int const r)
{

    int n1 = q - p + 1;
    int n2 = r - q;
    // int* L = (int*) malloc(sizeof(int) * (n1)); // data block allocated on heap 
	// int* R = (int*) malloc(sizeof(int) * (n2)); // data block is outside of scope of merge()
	// L and R will be deleted on exit from merge(); data blocks will persist
	int *L = new int[n1];
	int *R = new int[n2];
	//int L[n1];
    //int R[n2];
	// L is a pointer to an array of ints 
	// L[i] says "go to the address L and multiply i * size of int (array object)"
    for (int i = 0; i < n1; i++){
		cout << "In merge array char is " << A[p + i] << endl;
        L[i]= A[p + i];
		cout << "In left array char is " << L[i] << " at index " << i << endl;
    }
    for(int j = 0; j < n2; j++){
		cout << "In merge array char is " <<  A[q + 1 + j] << " at index " << q + 1 + j << endl;
        R[j] = A[q + 1 + j];
		cout << "In right array char is " << R[j] << " at index " << j << endl;
    }

	int i = 0; // i is in the index of the left array
	int j = 0; // j is in the index of the right array 
	int k = p; // k is index of the merged array 
    // int* endofL = L + n1;
	// int* endofR = R + n2;
	// int* z = L;
	// int* w = R;

	// Case 1: while the left subarray overlaps with the right subarray,
	// merge the two subarrays into array[p..r]
	while (i < n1 && j < n2){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++; // equivalent  to i = i + 1
		}
		else{
			A[k] = R[j];
			j++; // equivalent  to j = j + 1
		}
		k++;
	}

	// Case 2: the right subarray is shorter than the left subarray, so if the right is empty,
	// copy the remaining elements in the left subarray into array 
	while (i < n1){
		A[k] = L[i];
		i++; // equivalent  to i = i + 1
		k++;
	}

	// Case 3: the left subarray is shorter than the right subarray, so if the left is empty,
	// copy the remaining elements in the right subarray into array 
	while (j < n2){
		A[k] = R[j];
		j++; // equivalent  to j = j + 1
		k++;
	}


	// for(int k = p; k < r; ++k){
	// 	cout << "indexOfMergedArray " << k << " < " << "sentinel " << r << endl;
	// 	if (&L[i] == endofL && &R[j] == endofR){
	// 	cout << "Address of L: "<< &L[i] << " != " << endofL << endl;
	// 	cout << "Address of R: "<< &R[j] << " != " << endofR << endl;
	// 		return; 
	// 	}else{
	// 		if (L[i] <= R[j] || &R[j] == endofR ){
	// 			cout << L[i] << " <= " << R[j] << endl;
	// 			A[k] = L[i];
	// 			cout << "In merged array char is " << A[k] << " at index " << k << endl;
	// 			i++;
	// 		} else{
	// 			cout << L[i] << " > " << R[j] << endl;
	// 			A[k] = R[j];
	// 			cout << "In merged array char is " << A[k] << " at index " << k << endl;
	// 			j++; 
	// 		}
	// 	}
	delete[] L;
	delete[] R;

	//}
}
    
// This merge sort function uses an array
void mergesort(int A[], int const p , int const r)
{
	cout << "Starting merge sort with " <<r<< " items\n";
    if (p < r){
		int q = floor((p + r) /2);
		cout << "r : " << r << endl;
		cout << "p : " << p << endl;
		cout << "q : " << q << endl;
		for (int i = p; i <= q; i++){
			cout << "Contents of left: ";
			cout << i << " : " << A[i]<<endl;
		}
		for (int i = q+1; i <= r; i++){
			cout << "Contents of right: ";
			cout << i << " : " << A[i]<<endl;
		}
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);

    }


	cout << "Ending merge sort\n";}




int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Please include input filename and output filename in param list.\n";
		cout << "Example:\n";
		cout << "     % mySortA numbers.txt mySorted.txt\n";
		exit(EXIT_SUCCESS);
	}


	const int MAX = 1000000;
  	ofstream fout;
	ifstream fin;
	int n;
	
	int v[MAX];
	int count = 0;
	
	fin.open(argv[1]);
	while (fin >> n )
	{
		v[count++] = n;	// insert a number into the arary and increase the index
	}


	mergesort(v,0, count-1);	// call the mergesort function

        fout.open(argv[2], ios::out | ios::trunc);
        for (int i = 0; i < count; i++)
		fout << i << " : " << v[i]<<endl;


        fout.close();
	fin.close();
        return 0;
}	
