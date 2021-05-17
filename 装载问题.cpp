#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Merge(int A[],int l,int m,int r){
    int x = m-l+1,y=r-m;
    int i,j,k;
    int *B = new int[x];
    int *C = new int[y];
    for(i=0,j=l;i<x;i++,j++){
    	B[i]=A[j];	
    }
    for(i=0,j=m+1;i<y;i++,j++){
    	C[i]=A[j];
    }
    i=0;
	j=0;
	k=l;
    while(i<x&&j<y){
        if(B[i]<=C[j]){
            A[k++]=B[i++];
        }
        else{
            A[k++]=C[j++];
        }
    }
    if(i>=x){
        while(j<y){
            A[k++]=C[j++];
	}
    }
    else{
        while(i<x){
            A[k++]=B[i++];
	}
    }
}

void MergeSort(int A[],int l,int r){
    int m;
    if(l<r){
        m=(l+r)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        Merge(A,l,m,r);
    }
}

int main(){
	int n,C,i,j=0,W[100],t=0;
	cout<<"请输入轮船的最大载重量：";
	cin>>C;
	cout<<"请输入集装箱个数：";
	cin>>n;
	
	cout<<"请依次输入集装箱的重量："<<endl;
	for(i=0;i<n;i++){
	    cin>>W[i];
	}
	
	MergeSort(W,0,n-1);
	while(1){
	    if(t+W[j]>C){
		break;
	    }
	    t+=W[j];
	    j++;
	}
	cout<<endl<<"轮船最多装"<<j<<"个集装箱，重量分别为："<<endl;
	for(i=0;i<j;i++){
	    cout<<W[i]<<" "; 
	}
	cout<<endl;
	return 0;
}

