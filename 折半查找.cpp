#include<stdio.h>

int main(){
	int T[100],n,i,k,flag=0,left,right,mid;
	printf("请输入数组共有几个数："); 
	scanf("%d",&n);
	printf("请输入已排好序的数组：\n");
	for(i=0;i<n;i++){
		scanf("%d",&T[i]);
	}
	printf("请输入你想要查找的数据K：");
	scanf("%d",&k);
	left=0;
	right=n-1;
	mid=(left+right)/2;
	while(left<=right){
		if(T[mid]==k){
			printf("%d在该数组中，%d的下标j=%d\n",k,k,mid+1);
			flag=1;
			break;
		}
		else if(T[mid]<k){
			left=mid+1;
			mid=(left+right)/2;
		}
		else{
			right=mid-1;
			mid=(left+right)/2;
		}
	}
	if(flag==0){
		printf("%d不在该数组中，j=0\n",k);
	}
	return 0;
} 
