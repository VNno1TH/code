#include"bits/stdc++.h"
using namespace std;

template<typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;
    int A[N];
    
    for(int i=1;i<=N;i++) cin>>A[i];

    int down_pf[N],up_pf[N+2];
    down_pf[0]=0,up_pf[N+1]=0;

    for(int i=1;i<N;i++)
    {
        down_pf[i]=gcd(down_pf[i-1],A[i]);
    }
    for(int i=N;i>=2;i--)
    {
        up_pf[i]=gcd(up_pf[i+1],A[i]);
    }

    int result=0;
    for(int i=1;i<=N;i++)
    {
        result=max(result,gcd(down_pf[i-1],up_pf[i+1]));
    }
    cout<<result;
    return 0;
}
