#include"bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int beautiful[n];
        for(int i=0;i<n;i++)
        {
            cin>>beautiful[i];
        }
        
        int optimal_left[n-2],optimal_right[n];
        optimal_left[0]=beautiful[0];
        optimal_right[n-1]=beautiful[n-1]-n+1;
        for(int i=1;i<n-2;i++)
        {
            optimal_left[i]=max(beautiful[i]+i,optimal_left[i-1]);
        }
        for(int i=n-2;i>1;i--)
        {
            optimal_right[i]=max(beautiful[i]-i,optimal_right[i+1]);
        }

        int result=0;
        for(int i=1;i<=n-2;i++)
        {
            result=max(result,optimal_left[i-1]+optimal_right[i+1]+beautiful[i]);
        }
        cout<<result<<endl;;
    }
}