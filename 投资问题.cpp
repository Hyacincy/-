#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	int i,j,k,x,xk,max_value;
	int in[4][6]={0},f[4][6]={0};
	
	cout<<"�����㹲��5��Ԫ���������ĸ���Ŀ����Ͷ�ʡ�"<<endl; 
	cout<<"������Ͷ�ʵ�һ����Ŀ0-5��Ԫ������ֱ��ǣ�"<<endl;
	for(i=0;i<6;i++){
		cin>>in[0][i];
		f[0][i]=in[0][i];
	} 
	cout<<"������Ͷ�ʵڶ�����Ŀ0-5��Ԫ������ֱ��ǣ�"<<endl;
	for(i=0;i<6;i++){
		cin>>in[1][i];
	} 
	cout<<"������Ͷ�ʵ�������Ŀ0-5��Ԫ������ֱ��ǣ�"<<endl;
	for(i=0;i<6;i++){
		cin>>in[2][i];
	} 
	cout<<"������Ͷ�ʵ��ĸ���Ŀ0-5��Ԫ������ֱ��ǣ�"<<endl;
	for(i=0;i<6;i++){
		cin>>in[3][i];
	} 
	for(k=1;k<4;k++){
		for(x=1;x<=5;x++){
			for(xk=0;xk<=x;xk++){
				f[k][x]=in[k][xk]+f[k-1][x-xk]>f[k][x]?in[k][xk]+f[k-1][x-xk]:f[k][x];
			}
		}
	}
	
	max_value=f[0][0];
	for(i=0;i<4;i++){
		for(j=0;j<6;j++){
			max_value=max_value>f[i][j]?max_value:f[i][j];
		}
	}
	cout<<"Ͷ�ʵ��������Ϊ��"<<max_value<<"��Ԫ��"<<endl; 
	return 0;
}

