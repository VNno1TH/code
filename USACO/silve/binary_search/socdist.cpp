#include <bits/stdc++.h>
#include <cstdio>
#include <locale>
#include <utility>
#include <vector>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

int N, M;
vector<pair<ll, ll>> grass;

bool check(ll para) {
  int i = 0, count = 0;
  int l = grass.front().first, r = grass.back().second;

  while (l <= r and (count < N and i < M)) {
    if (l <= grass[i].second and l >= grass[i].first) {
      count++;
      l += para;
    } else {
      i += 1;
      l = (grass[i].first > l) ? grass[i].first : l;
    }
  }
  return count == N;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("socdist.in", "r", stdin);
  freopen("socdist.out", "w", stdout);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    if (p.first > p.second)
      swap(p.first, p.second);
    grass.pb(p);
  }
  sort(all(grass));

  int l = 1, r = grass.back().second - grass.front().first;

  while (l < r) {
    ll mid = l + (r - l + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }

  cout << r;
  return 0;
}
