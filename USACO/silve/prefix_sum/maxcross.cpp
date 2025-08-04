#include"bits/stdc++.h"
using namespace std;

int main(){
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);

    int N,K,B;
    cin>>N>>K>>B;

    map<int,int> check;
    for(int i=0;i<B;i++)
    {
        int b_s;
        cin>>b_s;
        check[b_s]=1;
    }

    int pf[N+1];
    pf[0]=0;

    for(int i=1;i<=N;i++)
    {
        pf[i]=pf[i-1]+check[i];
    }

    int result=INT_MAX;
    for(int i=K;i<=N;i++)
    {
        result=min(result,pf[i]-pf[i-K]);
    }
    cout<<result;
    return 0;
}