#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn = 100;
int A[maxn];
int dis[maxn];
int M[maxn][maxn];
int way[maxn];
int n;

void Dijkstra(int s){
    memset(way,-1,sizeof(way));
    memset(dis,0x3f,sizeof(dis));
    memset(A,0,sizeof(A));
    dis[s] = 0;
    while(1){
        int k = 0;
        for(int j = 1; j <= n; j++){
            if(!A[j] && dis[j]<dis[k])
                k=j;
        }
        if(!k){
        	return;
		}
        A[k] = 1;
        for(int j = 1; j <= n; j++){
            if(dis[j]>dis[k]+M[k][j]){
                dis[j]=dis[k]+M[k][j];
                way[j]=k;
            }
        }
    }
}

int main(){
    int m,x,y,z,Point;
    printf("�����빲�м����㣬�����ߣ�"); 
    scanf("%d%d",&n,&m);
    memset(M,0x3f,sizeof(M));
    printf("������ÿ���ߵ�x,y,z,����x��y�ľ���Ϊz�������ֱ�ʾ��ĸ����1��ʼ����\n"); 
    for(int i = 0; i < m; i++){
        scanf("%d%d%d",&x,&y,&z);
        M[x][y] = z;
    }
    
    Dijkstra(1);
    printf("��ʼ��Ϊa����������ֹ�㣨���֣���");
    scanf("%d",&Point);
    printf("a���õ�����·��Ϊ��%d\n",dis[Point]);
    return 0;
}

