#include"bits/stdc++.h"
using namespace std;
int T_max;

bool check(int k, const vector<int>& d){

    priority_queue<int> pq;
    int N=(int)d.size();
    int time=0;
    for(int i=1;i<=N-1;i++)
    {
        if((int)pq.size()==k)
        {   
            time=0;
            time = -pq.top();
            pq.pop();
        }
        if(time+d[i]>T_max)
            return false;
        else {
            pq.push(-time-d[i]);
        }
    }
    return true;
}
int main(){
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);

    int N;
    cin>>N>>T_max;
    vector<int> d(N+1,0);
    for(int i=1;i<=N;i++)
    {
        cin>>d[i];
    }
    
    int l=1,r=N;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(check(mid,d)==true)
        {
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l;
    return 0;
}
