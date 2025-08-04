#include"bits/stdc++.h"
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    int cnt=0,sum=0;
    for(int l=1,r=1;r<=n;r++)
    {
        sum+=a[r];
        if(sum==x)
        {
            cnt++;
        }
        while(sum>=x)
        {
            sum-=a[l];
            if(sum==x)
                cnt++;
            l++;
        }

    }   
    cout<<cnt;
}