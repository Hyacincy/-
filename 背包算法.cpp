#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,j,b,k,y;
	int v[100],w[100];
	int f[100][100]={0},i[100][100]={0}; 
	
	cout<<"请输入共有多少种物品：";
	cin>>n;
	cout<<"请依次输入物品的单个价值："<<endl; 
	for(j=1;j<=n;j++){
		cin>>v[j];
	}
	cout<<"请依次输入物品的单个重量："<<endl;
	for(j=1;j<=n;j++){
		cin>>w[j];
	}
	cout<<"请输入背包限重：";
	cin>>b; 
	
	for(k=1;k<=n;k++){
		for(y=1;y<=b;y++){
			if(f[k-1][y]>f[k][y-w[k]]+v[k] || y<w[k]){
				f[k][y]=f[k-1][y];
				i[k][y]=i[k-1][y];
			}
			else if(f[k-1][y]<=f[k][y-w[k]]+v[k]){
				f[k][y]=f[k][y-w[k]]+v[k];
				i[k][y]=k;
			}
		}
	}
	cout<<"背包在限重下所能携带的物品的最大价值为："<<f[n][b]<<endl; 
}
