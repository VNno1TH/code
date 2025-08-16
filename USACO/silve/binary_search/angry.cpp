#include "bits/stdc++.h"
using namespace std;
int N, K;
vector<int> position;

bool check(int mid)
{
	int be_fire = 0;
	int fire = 0;
	int start = 0;
	while (fire < K and be_fire < N)
	{
		int long_fire = position[start] + 2 * mid;
		for (int i = start; i < N; i++)
		{
			if (position[i] <= long_fire)
			{
				be_fire++;
			}
			else
			{
				start = i;

				break;
			}
		}
		fire++;
	}
	return be_fire == N;
}
int main()
{
	//	 freopen("angry.in","r",stdin);
	//	 freopen("angry.out","w",stdout);
	cin >> N >> K;
	for (int i = 0; i < N; Zi++)
	{
		int x;
		cin >> x;
		position.push_back(x);
	}

	sort(position.begin(), position.end());
	
	int l = 1, r = position.back() - position[0];

	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (check(mid) == true)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	};
    
	cout << l;
	return 0;
}
