#include"bits/stdc++.h"
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;        

        int pf[n+1];
        pf[0]=0;

        for(int i=1;i<=n;i++)
        {
            pf[i]=pf[i-1]+(int)(s[i-1]-'0');
        }
        map<int,int> count;
        for(int i=0;i<=n;i++)
        {
            count[pf[i]-i]++;
        }
        ll result=0;

        for(auto [x,y]:count)
        {
            result+=1ll*y*(y-1)/2;
        }
        cout<<result<<endl;
    }
}
