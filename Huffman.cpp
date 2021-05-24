#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct{       
    double weight;
    int parent,lchild,rchild;
}HTNode;
typedef HTNode HuffmanTree[100];
 
typedef struct{       
    int id;
    double weight;
}temp;
 
typedef struct{       
    char ch;         
    char bits[101];   
}CodeNode;
typedef CodeNode HuffmanCode[100];

 //��ʼ����������
void InitHuffmanTree(HuffmanTree T,int m){
	int i;
	
    for(i=0;i<m;i++){
        T[i].lchild=-1;
        T[i].rchild=-1;
        T[i].parent=-1;
        T[i].weight=0;
    }
}

//����Ҷ��Ȩֵ
void InputWeight(HuffmanTree T,int n){
	int i;
	double x;
	
    for(i=0;i<n;i++){
        scanf("%lf",&x);
        T[i].weight=x;
    }
}

 //��������ıȽϺ���
bool cmp(temp a,temp b){
    return a.weight<b.weight;
}
 
void SelectMin(HuffmanTree T,int k,int *p1,int *p2,int m){
    temp x[m];              
    int i,j;
    
    for(i=0,j=0;i<=k;i++){  
        if(T[i].parent==-1){
            x[j].id=i;      
            x[j].weight=T[i].weight;
            j++;           
        }
    }
    sort(x,x+j,cmp);       
    *p1=x[0].id;
    *p2=x[1].id;
}
 
void CreateHuffmanTree(HuffmanTree T,int n,int m){
    int i,p1,p2;
    
    InitHuffmanTree(T,m); 
    InputWeight(T,n);        
    for(i=n;i<m;i++){
        SelectMin(T,i-1,&p1,&p2,m);
        T[p1].parent=T[p2].parent=i;
        T[i].lchild=p1;             
        T[i].rchild=p2;            
        T[i].weight=T[p1].weight+T[p2].weight;
    }
}
 
void CharSetHuffmanEncoding(HuffmanTree T,HuffmanCode H,int n){
    int c,p,start,i;
    char cd[n+1];
 
    cd[n]='\0';
    getchar();
    for(i=0;i<n;i++){
        H[i].ch=getchar();
        start=n;
        c=i;
        while((p=T[c].parent)>=0){
            if(T[p].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
            c=p;
        }
        strcpy(H[i].bits,&cd[start]);
    }
}

int main(){
    HuffmanTree T;
    HuffmanCode H;
    int n,m,i;
    double wpl=0.0;
    
    printf("�������������");
    scanf("%d",&n);
    m=2*n-1;
    
    printf("������%d��Ҷ�ӽ���Ȩֵ��\n",n);
    CreateHuffmanTree(T,n,m);
    
    printf("������%d��Ҷ�ӽ����������ַ�(�ַ�֮��û�пո�)��\n",n);
    CharSetHuffmanEncoding(T,H,n);

    printf("\n���������룺\n");
    for(i=0;i<n;i++){
        printf("ch:%c  code:%s\n",H[i].ch,H[i].bits);
        wpl+=strlen(H[i].bits)*T[i].weight;
    }
    
    printf("\n�볤��%.2lf\n",wpl);
    return 0;
}
