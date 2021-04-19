#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int L[1001];

int select(int left,int right,int k){
    if(left>=right)
        return L[left];
    int x=L[left];
    int i=left;
    int j=right+1;
    while(true){
        do{
            i++;
        }while(L[i]<x);
        do{
            j--;
        }while(L[j]>x);
        if(i>=j){
        	break;
		}
        swap(L[i],L[j]);
    }
    if(j-left+1==k){
    	return x;
	}
    L[left]=L[j];
    L[j]=x;
    if(j-left+1<k){
    	return select(j+1,right,k-j+left-1);
	}
    else{
    	return select(left,j-1,k);
	}
}

int main(){
    int n;
    cout<<"���������ݵĸ�����";
    cin>>n;
    while(n){
        int k,i;
        cout<<"��������Ҫ���ҵĵ�kС�����ֵ�k��";
        cin>>k;
        cout<<"������"<<n<<"������:"<<endl;
        for(i=0;i<n;i++){
        	cin>>L[i];
		}
    	cout<<"��kС������Ϊ��";
        cout<<select(0,n-1,k)<<endl<<endl;
        cout<<"���������ݵĸ�����";
    	cin>>n;
    }
    return 0;
}
