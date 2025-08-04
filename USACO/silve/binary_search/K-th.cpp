#include <bits/stdc++.h>
using namespace std;
int n,t,k;

int query(int r, int k) {
	int res;
	cout << "? " << 1 << " " << r << '\n';
	cin >> res;
	return r - res <= k;
}

int main() {
	
	cin >> n >> t >> k;
	k--;

	int lo = 0;
	int hi = n;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (query(mid, k)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}

	cout << "! " << hi << '\n';
}

