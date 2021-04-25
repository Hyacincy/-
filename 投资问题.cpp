#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	int i,j,k,x,xk,max_value;
	int in[4][6]={0},f[4][6]={0};
	
	cout<<"假设你共有5万元，现在有四个项目可以投资。"<<endl; 
	cout<<"请输入投资第一个项目0-5万元的收益分别是："<<endl;
	for(i=0;i<6;i++){
		cin>>in[0][i];
		f[0][i]=in[0][i];
	} 
	cout<<"请输入投资第二个项目0-5万元的收益分别是："<<endl;
	for(i=0;i<6;i++){
		cin>>in[1][i];
	} 
	cout<<"请输入投资第三个项目0-5万元的收益分别是："<<endl;
	for(i=0;i<6;i++){
		cin>>in[2][i];
	} 
	cout<<"请输入投资第四个项目0-5万元的收益分别是："<<endl;
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
	cout<<"投资的最大收益为："<<max_value<<"万元。"<<endl; 
	return 0;
}

