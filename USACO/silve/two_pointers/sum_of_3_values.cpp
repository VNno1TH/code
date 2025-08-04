#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<pair<int, int>> a(n); // pair<value, original_index>
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; // lưu chỉ số gốc (1-based)
    }

    sort(a.begin(), a.end()); // sort theo value

    for (int i = 0; i < n; ++i) {
        int target = x - a[i].first;
        int l = 0, r = n - 1;

        while (l < r) {
            if (l == i) { l++; continue; }
            if (r == i) { r--; continue; }

            int sum = a[l].first + a[r].first;

            if (sum == target) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << endl;
                return 0;
            }
            else if (sum < target) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
