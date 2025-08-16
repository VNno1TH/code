#include"bits/stdc++.h"
#define ll long long

using namespace std;
bool check(pair<ll,ll>at_pos,pair<ll,ll>destination,string wind_info,ll mid)
{
    int wind_len=(int)wind_info.length();
    ll wind_x=0,wind_y=0;
    for(int i=0;i<wind_len;i++){
        switch(wind_info[i]){
            case 'U':
                wind_y++;
                break;
            case 'D':
                wind_y--;
                break;
            case 'L':
                wind_x--;
                break;
            case 'R':
                wind_x++;
                break;
        }

    }
    wind_x*=mid/(ll)wind_len;
    wind_y*=mid/(ll)wind_len;

    int mod=mid%(ll)wind_len;
    for(int i=0;i<mod;i++)
    {
         switch(wind_info[i]){
            case 'U':
                wind_y++;
                break;
            case 'D':
                wind_y--;
                break;
            case 'L':
                wind_x--;
                break;
            case 'R':
                wind_x++;
                break;
        }
    }
    at_pos.first+=wind_x;
    at_pos.second+=wind_y;

    return abs(at_pos.first-destination.first)+abs(at_pos.second-destination.second)<=mid;

}
int main(){
    pair<ll,ll> at_pos;
    cin>>at_pos.first>>at_pos.second;
    pair<ll,ll> destination;
    cin>>destination.first>>destination.second;

    int wind_len;cin>>wind_len;
    string wind_info;cin>>wind_info;

    ll lo=1,hi=INT64_MAX/2;
    ll valid=-1;
    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;
        if(check(at_pos,destination,wind_info,mid))
        {
            valid=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<valid<<endl;return 0;

}
