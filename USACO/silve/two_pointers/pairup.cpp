#include"bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);cout.tie(0);
    // freopen("pairup.in","r",stdin);
    // freopen("pairup.out","w",stdout);

    int N;
    cin>>N;

    vector<pair<int,int>> a;

    for(int i=0;i<N;i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end(),[](pair<int,int> x,pair<int,int> y){
        return x.second>y.second;
    });
    int result=0;
    int l=0,r=N-1;

    while(l<=r)
    {
        result=max(result,a[l].second+a[r].second);
        if(a[l].first!=0 )
        {
            a[l].first--;
        }
        else{
            l++;
        }

        if(a[r].first!=0)
        {
            a[r].first--;
        }
        else{
            r--;
        }

    }
    cout<<result;
}