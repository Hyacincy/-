#include <stdio.h>

int main(){
	//ֻ����4 ��4��������·�� 
	int D[4][4];
	int i,j,a,b,c;
	printf("������Ȩ�ؾ���inf���������10000���棺\n");
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d",&D[i][j]);//Ϊ��ʼ�������ֵ 
		}
	}
	
	for(a=0;a<4;a++){ //Floyd�㷨�����·�� 
		for(b=0;b<4;b++){
			if(D[a][b]>0 && D[a][b]<10000){
				for(c=0;c<4;c++){
					if(D[c][a]>0 && D[c][a]<10000){
						D[c][b]=D[c][b]<(D[c][a]+D[a][b])?D[c][b]:(D[c][a]+D[a][b]);
					}
				}
			}
		}
	}
	
	for(i=0;i<4;i++){//���������� 
		for(j=0;j<4;j++){
			if(D[i][j]==10000){
				printf("inf");
			}
			else{
				printf("%-6d",D[i][j]);	
			}
		}
		printf("\n");
	}
	
	return 0; 
}
