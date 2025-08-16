#include"bits/stdc++.h"
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;
    ll lo=1,hi=(ll)n*n;

    while(lo<hi)
    {
        ll mid=(lo+hi)/2;
        ll than=0;
        for(int i=1;i<=n;i++)
        {
            than+=min((ll)n,mid/(ll)i);
        }
        if(than>=(n*n+1)/2)
        {

            hi=mid;
        }        
        else{
            lo=mid+1;
        }
    }
    cout<<hi;
    return 0;
}
