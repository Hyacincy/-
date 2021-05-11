#include <iostream>
#include <string>
using namespace std;

int main() {
	int C[100][100]={0},B[100][100]={0};//B的值：1->删除y,2->删除x,3->删除两个
	string x,y,z;
	int i,j,m,n,a,b;
	
	cout<<"请输入序列X：";
	cin>>x;
	m=x.length();
	a=m;
	x='0'+x;
	cout<<"请输入序列Y：";
	cin>>y;
	n=y.length();
	b=n;
	y='1'+y;
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i]==y[j]){
				C[i][j]=C[i-1][j-1]+1;
				B[i][j]=3;
			}
			else{
				if(C[i][j-1]>=C[i-1][j]){
					C[i][j]=C[i][j-1];
					B[i][j]=1;
				}
				else{
					C[i][j]=C[i-1][j];
					B[i][j]=2;
				}
			}
		}
	}
	while(a>=1 && b>=1){
		if(B[a][b]==1){
			b-=1;		
		}	
		else if(B[a][b]==2){
			a-=1;
		}
		else if(B[a][b]==3){
			cout<<x[a];
			z=x[a]+z;
			a-=1;
			b-=1;
		}
	}

	cout<<"最长公共子序列长度为："<<C[m][n]<<endl;
	cout<<"最长公共子序列为："<<z<<endl; 
}
