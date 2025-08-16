#include "bits/stdc++.h"
using namespace std;
int N, M, C;
vector<int> t;

int check(int k)
{

    int bus = 0;
    int cow = 0;
    int lcow = 0;

    while (cow < N)
    {
        if (lcow == cow)
            bus++;

        if (t[cow] - t[lcow] > k)
        {
            lcow = cow;
        }
        else if (cow - lcow + 1 == C)
        {
            cow++;
            lcow = cow;
        }
        else
        {
            cow++;
        }
    }
    return bus <= M;
}
int main()
{

    // freopen("convention.in","r",stdin);
    // freopen("convention.out","w",stdout);

    cin >> N >> M >> C;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        t.push_back(x);
    }

    sort(t.begin(), t.begin());

    int l = 0, r = t.back() - t[0];
    
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l;
    return 0;
}
