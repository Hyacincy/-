#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n,sum,i,j,middle,answer,Ta,Tb;
	int a[100],f[100][100];
	
	cout<<"�����빲�м����ӹ���������0��������";
	cin>>n;
    while(n){
    	sum=0;
    	answer=100000000;
    	
    	cout<<"������ÿ������ļӹ�ʱ�䣺"<<endl;
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
     
		cout<<endl<<"���ŷ������ӹ�ʱ�����Ϊ��"<<answer<<endl;
		cout<<"�÷����»���A�ļӹ�ʱ��Ϊ��"<<Ta<<",����B�ļӹ�ʱ��Ϊ��"<<Tb<<endl;
        cout<<endl<<"�����빲�м����ӹ���������0��������";
        cin>>n;
    }
    return 0;
}

