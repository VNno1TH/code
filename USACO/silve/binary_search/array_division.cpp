#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define endl '\n'
int n,k;
vector<int> t;

bool valid(ll mid){
    int count=1;
    ll sum=0;
    int i=0;
    while (i<n) {
        if(t[i]>mid) return false;
        
        if(sum+t[i]<=mid)
        {
            sum+=t[i];
            i++;
        }
        else{
            count++;
            sum=0;
        }
    }

    return count<=k;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    FOR(i,0,n)
    {
        int te;cin>>te;
        t.pb(te);
    }

    ll sum=0;
    FOR(i,0, n)
    {
        sum+=1ll*t[i];
    }
    
    ll l=1,r=sum;
    while(l<r)
    {
        ll mid=l+(r-l)/2;
        if(valid(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l;return 0;

    
     

    

}


