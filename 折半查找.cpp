#include<stdio.h>

int main(){
	int T[100],n,i,k,flag=0,left,right,mid;
	printf("���������鹲�м�������"); 
	scanf("%d",&n);
	printf("���������ź�������飺\n");
	for(i=0;i<n;i++){
		scanf("%d",&T[i]);
	}
	printf("����������Ҫ���ҵ�����K��");
	scanf("%d",&k);
	left=0;
	right=n-1;
	mid=(left+right)/2;
	while(left<=right){
		if(T[mid]==k){
			printf("%d�ڸ������У�%d���±�j=%d\n",k,k,mid+1);
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
		printf("%d���ڸ������У�j=0\n",k);
	}
	return 0;
} 
