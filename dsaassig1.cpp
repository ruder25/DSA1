#include<iostream>
using namespace std;


void Create(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<"Enter The ith element: ";
		cin>>arr[i];
	}

}

void Display(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
}

int Insert(int* arr, int n, int pos, int addele) {
	if(pos > n+1) {
		cout<<"Can't insert element at required position."<<endl;
		return n;
	}
	else {
		int ind=pos-1;
		for(int i=n-1; i>=ind; i--) {
			arr[i+1]=arr[i];
		}
		arr[ind]= addele;
	}
	return n+1;
}

int Delete(int* arr, int n, int pos) {
	int ind=pos-1;
	for(int i=ind; i<n-1; i++) {
		arr[i]=arr[i+1];

	}

	return n-1;
}

int Linear_Search(int* arr, int n, int ele) {
	for(int i=0; i<n; i++) {
		if(arr[i]==ele) {
			return i;
		}
	}
	return -1;
}

int Insert_by_element(int* arr,int n, int ele) {
	for(int i=0; i<n; i++) {
		if(arr[0]>ele) {
			return Insert(arr, n, 1, ele);
		}

		else if(arr[n-1]<ele) {
			return	Insert(arr,n,n+1,ele);
		}

		if(arr[i]<=ele && arr[i+1]>ele) {
			return	Insert(arr,n,i+2,ele);
		}
	}

	return -1;
}

int main() {
	int arr[10];
	int Func;
	int size;
	cout<<"Enter The No. of Elements. ";
	cin>>size;
	Create(arr,size);
	bool isExit=false;
	while(!isExit){
	cout<<"Press 1 to display Array"<<endl;
	cout<<"Press 2 to Insert an element Array"<<endl;
	cout<<"Press 3 to Delete an element Array"<<endl;
	cout<<"Press 4 to Linear Search Array"<<endl;
	cout<<"Press 5 to Insert By element Array"<<endl;
	cout<<"Press 6 to Exit Array"<<endl;
	cin>>Func;

	switch(Func) {

	case 1: {
		Display(arr,size);
		break;
	}

	case 2: {
		int pos;
		int addele;
		cout<<"Enter the position where the element is to be added: ";
		cin>>pos;

		cout<<"Enter the the element to be added: ";
		cin>>addele;
		size=Insert(arr, size, pos, addele);
		Display(arr,size);
		break;
	}

	case 3: {
		int pos;
		cout<<"Enter the Position of element to be deleted: ";
		cin>>pos;
		size=Delete(arr, size, pos);
		Display(arr,size);
		break;
	}

	case 4: {
		int ele;
		cout<<"Enter the element to be searched: ";
		cin>>ele;
		int index=Linear_Search(arr,size,ele);
		cout<<index;
		break;
	}

	case 5: {
		int ele;
		cout<<"Enter the element to be added: ";
		cin>>ele;
		size=Insert_by_element(arr,size,ele);
		Display(arr,size);
		break;
	}

	case 6: {
		isExit=true;
		break;
	}

	default: {
		cout<<"Invalid Arguement";
		break;
	}
	}

	}

	return 0;
}
//Q2//
//
//
//
#include<iostream>
using namespace std;

void Display(int* arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"\t";
	}
}

int Delete(int* arr, int n, int pos){
	int ind=pos-1;
	for(int i=ind; i<n-1; i++){
		arr[i]=arr[i+1];
		
	}
	
	return n-1;
} 


int main(){
    int arr[5]={1,2,1,5,2};
    int size=5;
    
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]==arr[j]){
                size=Delete(arr,size,j+1);
                
            }
        }
    }
    
    
    Display(arr,size);
    return 0;
}
//Q3//
//
//
//
#include <iostream>
using namespace std;

int main()
{
    int i;
    int arr[5]={1};
    for(i=0; i<5; i++){
        cout<<arr[i];
        
    }

    return 0;
}
//Q4//
//
//
//
//
#include <iostream>
using namespace std;

void swapnum(int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
}
void Display(int* arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"\t";
	}
}

int main()
{
  int arr[6]={1,2,3,4,5,6};
   
   int size=6;
   
   for(int i=0; i<size/2; i++){
       swap(arr[i], arr[size-i-1]);
   }
    Display(arr,size);
  return 0;
}
//(b)
#include <iostream>
using namespace std;

void swapnum(int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
}

void Display2D(int (&arr)[][3],int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void Transpose(int (&arr)[][3],int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<3; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}
int main()
{
   int arr1[3][3]={0};
    int arr2[3][3]={
        {1,2,3},{4,5,6},{7,8,1}
    };
   // MatrixMult(arr1,arr2,3);
    Transpose(arr2,3);
    Display2D(arr2,3);
   // Display2D(arr1,3);
    return 0;
}
//Q5//
//
//
//
#include <iostream>
using namespace std;

int SumByRow(int (&arr)[][3], int row, int size){
    int sum=0;
    if (row>2){
        cout<<"Not enough rows"<<endl;
    }
    
    else{
    for(int i =0; i<3; i++){
        sum += arr[row][i];
    }
    }
    return sum;
    
}

int SumByCol(int (&arr)[][3], int col, int size){
    int sum=0;
    if (col>size){
        cout<<"Not enough coloumns"<<endl;
    }
    
    else{
    for(int i =0; i<size; i++){
        sum += arr[i][col];
    }
    }
    return sum;
    
}

int main()
{
    int arr[3][3]={
        {1,2,3}, {4,5,6}, {7,8,9}
    };
    
    char c;
    cout<<"Enter R to get sum of Row"<<endl;
    cout<<"Enter C to get sum of Coloumn"<<endl;
    
    cin>>c;
    
    switch(c){
        case 'R':{
            int no;
            cout<<"Enter the no. of row of whose sum is to be found: ";
            cin>>no;
            int sum=SumByRow(arr,no,3);
            cout<<sum;
            break;
        }
        
        case 'C':{
             int no;
            cout<<"Enter the no. of Coloumn of whose sum is to be found: ";
            cin>>no;
            int sum=SumByCol(arr,no,3);
            cout<<sum;
            break;
        
        }
        
        default:{
            cout<<"Invalid Input";
            break;
        }
    }

    return 0;
}