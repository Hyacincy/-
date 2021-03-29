#include <stdio.h>
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
    int n,A[100],i;
    printf("请输入共有几个数：");
    scanf("%d",&n);
    printf("请输入数据：\n");
    for(i=0;i<n;i++){
	scanf("%d",&A[i]);
    }
    MergeSort(A,0,n-1);
    printf("排列后的数据为：\n");
    for(i=0;i<n;i++){
	printf("%d ",A[i]);
    }
    return 0;
} 
