#include"bits/stdc++.h"
using namespace std;
#define ll long long

int main(){
    int n;cin>>n;

    int arrays[n];
    for(int i=0;i<n;i++) cin>>arrays[i];

    ll pf[n+1];
    for(int i=1;i<=n;i++) pf[i]=pf[i-1]+arrays[i-1];

    map<int,ll> mod;

    mod[(pf[0]%n+n)%n]=1;

    for(int i=1;i<=n;i++)
    {
        mod[(pf[i]%n+n)%n]++;
    }

    ll count=0;

    for (pair<int,ll> p:mod)
    {
        count+=(p.second-1)*p.second/2;
    }
    cout<<count;
}