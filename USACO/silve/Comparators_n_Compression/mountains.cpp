#include"bits/stdc++.h"
using namespace std;

struct Mountain{
    int start;
    int end; 
};

int main(){
    freopen("moutnains.in","r",stdin);
    freopen("mountains.out","w",stdout);

    int n;cin>>n;
    vector<Mountain> mountains;
    for(int i=0;i<n;i++)
    {
        int s,e;cin>>s>>e;
        mountains.push_back({s,e});
    
    } 
    
}

