#include<stdio.h>

int main(){
	int T[100],n,i,k,flag=0;
	printf("���������鹲�м�������");
	scanf("%d",&n);
	printf("���������ź�������飺\n");
	for(i=0;i<n;i++){
		scanf("%d",&T[i]);
	}
	printf("����������Ҫ���ҵ�����K��");
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(T[i]==k){
			printf("%d�ڸ������У�%d���±�j=%d\n",k,k,i+1);
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("%d���ڸ������У�j=0\n",k);
	}
	return 0;
} 
