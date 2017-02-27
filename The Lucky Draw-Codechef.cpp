#include<bits/stdc++.h>
using namespace std;
 
int func(int t[],int l,int r,int kk) {
    int m;
    while(r-l>1) {
        m=l+(r-l)/2;
        (t[m]>=kk?r:l)=m;
    }
    return r;
}
int lis(int arr[],int n) {
    int temp[n];
    int max_len=1;
    for(int j=0;j<n;j++) {
        for(int i=0;i<n;i++) {
            temp[i]=0;
        }
        temp[0]=arr[j];
        int len=1;
        for(int i=(j+1);i<(j+n);i++) {
            if(arr[i]<temp[0]) {
                temp[0]=arr[i];
            }
            else if(arr[i]>temp[len-1]) {
                temp[len++]=arr[i];
            }
            else {
                temp[func(temp,-1,len-1,arr[i])]=arr[i];
            }
        }
        if(len>max_len) {
            max_len=len;
        }
    }
    return max_len;
}
 
int main() {
    int n,t;
    cin>>t;
    while(t--) {
            cin>>n;
            int arr[2*n];
            for(int i=0;i<n;i++) {
                cin>>arr[i];
                arr[i+n]=arr[i];
            }
            cout<<"\n"<<lis(arr,n);
    }
    return 0;
}
