    #include"bits/stdc++.h"
    using namespace std;

    int main(){
        // freopen("bcount.in","r",stdin);
        // freopen("bcount.out","w",stdout);

        int N,Q;
        cin>>N>>Q;
        int list_cow[N];
        pair<int,int> queries[Q];

        
        for(int i=0;i<N;i++)
        {
            cin>>list_cow[i];
        }
        for(int i=0;i<Q;i++)
        {
            int a,b;
            cin>>a>>b;
            queries[i]={a,b};
        }
        
        int pf1[N+1],pf2[N+1],pf3[N+1];
        pf1[0] = pf2[0] = pf3[0] = 0;
        for(int i=1;i<=N;i++)
        {
           pf1[i]=pf1[i-1]+(list_cow[i-1]==1);
           pf2[i]=pf2[i-1]+(list_cow[i-1]==2);
           pf3[i]=pf3[i-1]+(list_cow[i-1]==3);
        }
        int k=0;
        while(k<=Q-1)
        {
                cout<<pf1[queries[k].second]-pf1[queries[k].first-1]
                <<" "<<pf2[queries[k].second]-pf2[queries[k].first-1]
                <<" "<<pf3[queries[k].second]-pf3[queries[k].first-1]<<"\n";
                k++;
        }
        return 0;
    }