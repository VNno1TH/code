#include"bits/stdc++.h"
using namespace std;

int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    // H=0;P=1,S=2

    int N;
    cin>>N;
    int gestures[N];

    for(int i=0;i<N;i++) 
    {
        char ges;cin>>ges;
        if (ges=='H')
            gestures[i]=0;
        else if(ges=='P')
            gestures[i]=1;
        else
            gestures[i]=2;
    }

    int pf0[N+1],pf1[N+1],pf2[N+1];
    pf0[0]=pf2[0]=pf1[0]=0;

    for(int i=1;i<=N;i++)
    {
        pf0[i]=pf0[i-1]+(gestures[i-1]==0);
        pf1[i]=pf1[i-1]+(gestures[i-1]==1);
        pf2[i]=pf2[i-1]+(gestures[i-1]==2);
    }
    int result=0;

    //Th ko thay doi
    for(int i=0;i<3;i++)
    {
        result = max(result, pf1[N]);
        result = max(result, pf2[N]);
        result = max(result, pf0[N]);
    }

    // TH thay doi
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                continue;
            
            for(int k=1;k<=N;k++)
            {
                int temp=0;
                if(i==0)
                    temp+=pf1[k]-pf1[0];
                else if(i==1)
                    temp+=pf2[k]-pf2[0];
                else if(i==2)
                    temp+=pf0[k]-pf0[0];
                
                if(j==0)
                    temp+=pf1[N]-pf1[k-1];
                else if(j==1)
                    temp+=pf2[N]-pf2[k-1];
                else if(j==2)
                    temp+=pf0[N]-pf0[k-1];

                result=max(result,temp);
            }
        }   
    }
    cout<<result;
    return 0;
}
