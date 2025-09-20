#include <iostream>
using namespace std;

int main()
{
	int matrix[3][3]= {{20,0,0},
		{0,30,0},
		{0,0,40}
	};
	int size=sizeof(matrix[0])/sizeof(matrix[0][0]);

	int diag[size];

	for(int i=0; i<3; i++) {
		diag[i]=matrix[i][i];
	}

	return 0;
}
//Q5(b)
//
//
#include <iostream>
using namespace std;

void Display(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main()
{
    int matrix[4][4]={{10,2,0,0},{100,20,4,0},{0,200,30,6},{0,0,300,40}};
    int size=sizeof(matrix[0])/sizeof(matrix[0][0]);
    
    int maindiag[size];
    int subdiag[size-1];
    int supdiag[size-1];
    
    for(int i=0; i<size; i++){
        maindiag[i]=matrix[i][i];
        
        if(i<size-1){
            supdiag[i]=matrix[i][i+1];
        }
        
        if(i>0){
            subdiag[i-1]=matrix[i][i-1];
        }
    }
    Display(maindiag,size);
    Display(supdiag,size-1);
    Display(subdiag,size-1);
    return 0;
}
//Q5(c)
//
//
//
#include <iostream>
using namespace std;

void Display(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
}

int main()
{
    int mat[4][4]={{1,0,0,0},{2,3,0,0},{4,5,6,0},{7,8,9,10}};
    int n=sizeof(mat[0])/sizeof(mat[0][0]);
    
    int totele= (n*(n+1))/2;
    
    int ltm[totele];
    int k=0;
    
    for(int i=0; i<n; i++){
        for(int j=0;j<=i;j++){
            ltm[k]=mat[i][j];
            k++;
        }
    }
    Display(ltm,totele);

    return 0;
}
//Q5(d)
//
//
//
#include <iostream>
using namespace std;

void Display(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
}

int main()
{
    int mat[4][4]={{1,2,3,4},{0,5,6,7},{0,0,8,9},{0,0,0,10}};
    int n=sizeof(mat[0])/sizeof(mat[0][0]);
    
    int totele= (n*(n+1))/2;
    
    int utm[totele];
    int k=0;
    
    for(int i=0; i<n; i++){
        for(int j=i;j<n;j++){
            utm[k]=mat[i][j];
            k++;
        }
    }
    Display(utm,totele);

    return 0;
}
//Q5(e)
//
//
//
#include <iostream>
using namespace std;

void Display(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
}

int main()
{
    int mat[4][4]={{1,2,3,4},{2,5,6,7},{3,6,8,9},{4,7,9,10}};
    int n=sizeof(mat[0])/sizeof(mat[0][0]);
    
    int totele= (n*(n+1))/2;
    
    int sm[totele];
    int k=0;
    
    for(int i=0; i<n; i++){
        for(int j=i;j<n;j++){
            sm[k]=mat[i][j];
            k++;
        }
    }
    Display(sm,totele);

    return 0;
}