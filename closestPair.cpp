#include <ctime>
#include <cmath>
#include <iostream>  
#include <algorithm>
using namespace std;

#define INFINITE_DISTANCE 65535
#define COORDINATE_RANGE 100.0

typedef struct Point{
    double x;
    double y;
}Point;

double Distance(Point a, Point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool compareD1(Point a, Point b){
    return a.x < b.x;
}

bool compareD2(Point a, Point b){
    return a.y < b.y;
}

double ClosestPair(Point points[], int length, Point &a, Point &b){
    double min;
    double d1,d2;
    int i=0,j=0,k=0,x=0;
    Point a1,b1,a2,b2;

    if(length<2)
        return INFINITE_DISTANCE;
    else if(length==2){
        a=points[0];
        b=points[1];
        min = Distance(points[0], points[1]);
    }
    else{
        Point *p1=new Point[length];
        Point *p2=new Point[length];

        sort(points,points+length,compareD1);
        double mid=points[(length-1)/2].x;

        for(i=0;i<length/2;i++){
        	p1[i]=points[i];
		}
        for(int l=0,m=length/2;m<length;m++){
        	 p2[l++]=points[m];
		}
        d1=ClosestPair(p1,length/2,a1,b1);
        d2=ClosestPair(p2,length-length/2,a2,b2);

        if(d1<d2){ 
			min = d1;
			a=a1;
			b=b1;
		}
        else{
			min=d2;
			a=a2;
			b=b2;
		}
        Point *p3=new Point[length];

        for(i=0,k=0;i<length;i++){   
            if(abs(points[i].x-mid)<=min){
            	p3[k++]=points[i];
			}
		}
        sort(p3,p3+k,compareD2);
        for (i=0;i<k;i++){
            if(p3[j].x-mid>=0){
            	continue;
			}
            x=0;
            for(j=i+1;j<=i+6+x && j<k;j++){
                if(p3[j].x-mid<0){
                    x++;
                    continue;
                }
                if(Distance(p3[i],p3[j])<min){
                    min=Distance(p3[i],p3[j]);
                    a=p3[i];
                    b=p3[j];
                }
            }
        }
    }
    return min;
}

int main(){
	int n;
	double min;
    Point p[10];
    Point a,b;
    
    cout<<"请输入点的个数：";
    cin>>n;
    cout<<"输入点集:（x,y）\n";
    for(int i=0;i<n;i++){
    	cin>>p[i].x>>p[i].y;
	}
    min=ClosestPair(p,n,a,b);
    cout<<"最小距离点对为：("<<a.x<<","<<a.y<<"),("<<b.x<<","<<b.y<<")\n";
    cout<<"最小距离为："<<min;
    return 0;
}
