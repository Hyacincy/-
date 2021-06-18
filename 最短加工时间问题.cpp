#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n,sum,i,j,middle,answer,Ta,Tb;
	int a[100],f[100][100];
	
	cout<<"请输入共有几个加工任务（输入0结束）：";
	cin>>n;
   	while(n){
    		sum=0;
    		answer=100000000;
    	
    		cout<<"请输入每个任务的加工时间："<<endl;
    		for(i=1;i<=n;i++){
    			cin>>a[i];
           		sum+=a[i];
        	}
       		middle=sum/2;
        	for(i=1;i<=n;i++){
        		for(j=1;j<=middle;j++){
        			if(j>=a[i]){
        				f[i][j]=f[i-1][j]>f[i-1][j-a[i]]+a[i]?f[i-1][j]:f[i-1][j-a[i]]+a[i];
				}
            			else{
            				f[i][j]=f[i-1][j];
				}
				cout<<f[i][j]<<" "; 
			}
			cout<<endl;
    		}
    		Ta=f[n][middle];
    		Tb=sum-f[n][middle];
    		answer=Ta>Tb?Ta:Tb;
     
		cout<<endl<<"最优方案：加工时间最短为："<<answer<<endl;
		cout<<"该方案下机器A的加工时间为："<<Ta<<",机器B的加工时间为："<<Tb<<endl;
        	cout<<endl<<"请输入共有几个加工任务（输入0结束）：";
        	cin>>n;
    	}
    return 0;
}

