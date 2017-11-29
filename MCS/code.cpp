#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
 * 
 */
int main() {
    int num1;
    vector<int> myvec;
    int maxi = INT_MIN;
    int sumi = 0;

    
    cin>>num1;
    for(int i=0; i<num1; i++){
        int tmp;
        cin>>tmp;
        sumi = sumi + tmp;
        if(sumi > maxi){
            maxi = sumi;
        }
        if(sumi < 0 ){
            sumi = 0;
        }
        
    }
    
    cout<<maxi;
    return 0;
    
}