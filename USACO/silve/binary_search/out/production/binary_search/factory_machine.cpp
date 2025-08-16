#include <bits/stdc++.h>
#include <clocale>
#include <cmath>
#include <sys/types.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define endl '\n'

int n,t;
vector<int> k;

bool check(ll l)
{
    ll sum=0;
    FOR(i, 0, n)
    {
        sum+=l/k[i];
    }
    return sum>=t;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>t;
    FOR(i,0, n)
    {
       int temp;cin>>temp;
       k.pb(temp);
    }
    
    sort(all(k));
    ll l=1,r=1ll*k.front()*t;
    while(l<r)
    {
        ll mid =l+(r-l)/2;
        if(check(mid))
            r=mid;
        else{
            l=mid+1;
        }
    }
    cout<<l;
    return 0;
}


