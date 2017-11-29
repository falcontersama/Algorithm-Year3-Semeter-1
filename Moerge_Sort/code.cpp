#include<stdio.h>
using namespace std;

int nub;
int ar[10000];


void merge(int left, int mid, int right){
    int dummy[10000];
    int index=0;
    int i=left;
    int j=mid+1;
    for(int k=left; k<=right; k++){
        if(i>mid){
            dummy[index]=ar[j++];
            index++;
            continue;
        }
        if(j>right){
            dummy[index]=ar[i++];
            index++;
            continue;
        }
        dummy[index] = ar[i] < ar[j] ? ar[i++] : ar[j++];
        index++;
    }
    index=0;
    for(int k=left; k<=right;k++,index++){
        ar[k]=dummy[index];
    }
}

void mergeSort(int left,int right){
    if(left>= right) return;
    int mid = (left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,mid,right);
}


int main(){
    scanf("%d",&nub);
    for(int i=0;i<nub;i++){
        scanf("%d",&ar[i]);
    }
    mergeSort(0,nub-1);
    for(int i=0;i<nub;i++){
        printf("%d ",ar[i]);
    }
}