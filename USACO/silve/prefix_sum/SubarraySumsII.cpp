// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")
#include"bits/stdc++.h"
using namespace std;
#define ll long long

int main(){
    int n,x;
    cin>>n>>x;
    int Arrays[n];
    for(int i=0;i<n;i++)
    {
        cin>>Arrays[i];
    }
    ll prefix_sum[n+1];
    prefix_sum[0] = 0;
    for(int i=1;i<=n;i++)
    {
        prefix_sum[i]=prefix_sum[i-1]+Arrays[i-1];
    }

    map<ll,ll> _map;
    _map[0]=1;
    ll count =0;
    for(int i=1;i<=n;i++)
    {
        _map[prefix_sum[i]]+=1;
    }
    for(int i=1;i<=n;i++)
    {
        _map[prefix_sum[i-1]]--;
        count+=_map[x+prefix_sum[i-1]];
    }
    cout<<count;
    return 0;

}