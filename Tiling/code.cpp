#include<stdio.h>

using namespace std;
int L,X,Y;

void tilling(int x, int y,int targetx,int targety,int sizex,int minx, int miny, int maxx, int maxy){
    if(sizex <= 1){
        return;
        
    }
    if((targetx <= x)&&(targety<=y)){
        printf("0 %d %d\n", x,y);
        tilling((x+minx)/2,(y+miny)/2,targetx,targety,sizex/4, minx, miny,x,y);
        tilling((x+maxx)/2,(y+miny)/2,x+1,y,sizex/4,x+1,miny,maxx,y);
        tilling((x+minx)/2,(y+maxy)/2,x,y+1,sizex/4,minx,y+1,x,maxy);
        tilling((x+maxx)/2,(y+maxy)/2,x+1,y+1,sizex/4,x+1,y+1,maxx,maxy);
    }
    else if((targetx > x)&&(targety<=y)){
        printf("1 %d %d\n", x,y);
        tilling((x+minx)/2,(y+miny)/2,x,y,sizex/4,minx, miny,x,y);
        tilling((x+maxx)/2,(y+miny)/2,targetx,targety,sizex/4,x+1,miny,maxx,y);
        tilling((x+minx)/2,(y+maxy)/2,x,y+1,sizex/4,minx,y+1,x,maxy);
        tilling((x+maxx)/2,(y+maxy)/2,x+1,y+1,sizex/4,x+1,y+1,maxx,maxy);
    }
    else if((targetx <= x)&&(targety>y)){
        //printf("check\n");
        printf("2 %d %d\n", x,y);
        tilling((x+minx)/2,(y+miny)/2,x,y,sizex/4,minx, miny,x,y);
        tilling((x+maxx)/2,(y+miny)/2,x+1,y,sizex/4,x+1,miny,maxx,y);
        tilling((x+minx)/2,(y+maxy)/2,targetx,targety,sizex/4,minx,y+1,x,maxy);
        tilling((x+maxx)/2,(y+maxy)/2,x+1,y+1,sizex/4,x+1,y+1,maxx,maxy);
    }
    else if((targetx > x)&&(targety > y)){
        printf("3 %d %d\n", x,y);
        tilling((x+minx)/2,(y+miny)/2,x,y,sizex/4,minx, miny,x,y);
        tilling((x+maxx)/2,(y+miny)/2,x+1,y,sizex/4,x+1,miny,maxx,y);
        tilling((x+minx)/2,(y+maxy)/2,x,y+1,sizex/4,minx,y+1,x,maxy);
        tilling((x+maxx)/2,(y+maxy)/2,targetx,targety,sizex/4,x+1,y+1,maxx,maxy);
    }
}

int main(){
    
    
    scanf("%d%d%d",&L,&X,&Y);
    printf("%d\n",(L*L-1)/3);
    tilling((L-1)/2, (L-1)/2, X, Y, (L*L), 0, 0, L-1, L-1);
    return 0;
}