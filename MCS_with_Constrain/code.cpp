#include <iostream>
#include <vector>

using namespace std;

int mcsw(const vector<int> &a,int l,int r,int w){
    if(l==r) return a[l];

    int mid = (l+r)/2;
    int maxl = mcsw(a,l,mid,w);
    int maxr = mcsw(a,mid+1,r,w);

    int sumr=0,msr=-999999;
    vector<int> dpr(r-mid+1);
    for(int i=mid+1;i<=r;i++){
        sumr = sumr+a[i];
        msr = max(msr,sumr);
        dpr[i-mid] = msr;
    }
    int suml = 0,msl=-999999;
    for(int i=mid;i>=l;i--){
        suml = suml+a[i];
        int li = mid-i+1;
        int ri = w-li;
        if(ri > r-mid){
            ri = r-mid;
        }
        if(ri>0) msl = max(msl,suml+dpr[ri]);
    }
    return max(max(maxl,maxr),msl);
}

main(){
    int n,w;
    cin >> n >> w;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << mcsw(a,0,n-1,w);
}