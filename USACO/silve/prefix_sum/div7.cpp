#include"bits/stdc++.h"
using namespace std;
#define ll long long

int main(){
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);

    int N;
    cin>>N;
    int cow_ID[N];
    for(int i=0;i<N;i++) cin>>cow_ID[i];

    ll pf[N+1];
    pf[0]=0*1ll;

    for(int i=1;i<=N;i++) pf[i]=pf[i-1]+(ll)cow_ID[i-1];
    int result=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=N;j>=i;j--)
        {
            ll temp=pf[j]-pf[i-1];
            if(temp%7==0) result=max(result,(j-i+1));
        }
    }
    cout<<result;
    return 0;

}
