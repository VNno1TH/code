#include"bits/stdc++.h"
using namespace std;


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> a(n,0),b(m,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int ans=0;
    int tmp=INT_MAX;
    int l=0,r=0;
    while(l<n or r<m)
    {
        if(r==m and l<n)
        {
            ans=max(ans,abs(a[l]-b[m-1]));
            l++;
            continue;   
        }
        if(r<m and l==n)
        {
            int temp=INT_MAX;
            while(r<m)
            {
                temp=min(temp,abs(a[n-1]-b[r]));
                r++;
            }

            ans=max(ans,temp);
            break;
        }
        if(a[l]<=b[r])
        {
            tmp=min(tmp,abs(a[l]-b[r]));
            ans=max(ans,tmp);
            l++;
            if(r>0)
                r--;
            tmp=INT_MAX;
            continue;
        }

        if(a[l]>b[r])
        {
            tmp=min(tmp,abs(a[l]-b[r]));
            r++;
            continue;
        }


    }
    cout<<ans;
}