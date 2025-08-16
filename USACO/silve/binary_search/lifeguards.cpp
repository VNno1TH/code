#include"bits/stdc++.h"
using namespace std;

struct Event{
    int time;
    int cow_id;
    bool is_cow;
};

int main(){
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);

    int N;cin>>N;
    vector<Event> events;
    for(int i=0;i<N;i++)
    {
        int start,end;cin>>start>>end;
        events.push_back({start,i,true});
        events.push_back({end,i,false});
    }
    sort(events.begin(),events.end(),[](const Event &e1,const Event &e2){
            return e1.time<e2.time;
    });
    
    set<int> active;
    int total_time=0;
    int curr_time=0;
    int prev_time=0;
    vector<int> alone_time(N);

    
    for(const auto e: events)
    {
        curr_time=e.time;
        
        if(active.size()>0)
        {
            total_time+=curr_time-prev_time;
        }

        if(active.size()==1){
            alone_time[*active.begin()]=curr_time-prev_time;
        }

        if(e.is_cow)
        {
            active.insert(e.cow_id);
        }       
        else{
            active.erase(e.cow_id);
        }
        prev_time=curr_time;
    }


    cout<<total_time-*min_element(alone_time.begin(),alone_time.end());
}
