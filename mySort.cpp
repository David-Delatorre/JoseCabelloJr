#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;


void merge(int A[], int const p, int const q, int const r)
{

    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++){
        L[i]= A[p + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = A[q + 1 + j];
    }

	int i = 0;
	int j = 0;
    int* endofL = L + n1;
	int* endofR = R + n2;
	int* z = L;
	int* w = R;
	for(int k = p; k < r; k++){
		
		if (L[i] == *endofL && R[j] == *endofR){
			return; 
		}else{
			if (L[i] <= R[j]){
				cout << L[i] << " <= " << R[j] << endl;
				A[k] = L[i];
				i = i + 1;
			} else{
				cout << L[i] << "  > " << R[j] << endl;
				A[k] = R[j];
				j = j + 1; 
			}
		}

	}
}
    
// This merge sort function uses an array
void mergesort(int A[], int const p , int const r)
{
	cout << "Starting merge sort with " <<r<< " items\n";
    if (p < r){
        int q = floor((p+r)/2);
        mergesort(A,p,q);
        mergesort(A,q+1,r);
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

	mergesort(v,0, count);	// call the mergesort function

        fout.open(argv[2], ios::out | ios::trunc);
        for (int i = 0; i < count; i++)
		fout << i << ' : ' << v[i]<<endl;


        fout.close();
	fin.close();
        return 0;
}	
