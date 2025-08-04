#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> beautiful(n);
        for (int i = 0; i < n; i++) {
            cin >> beautiful[i];
        }

        if (n < 3) {
            cout << 0 << endl;
            continue;
        }

        vector<int> optimal_left(n), optimal_right(n);

        // Tính prefix max của beauty[i] + i
        optimal_left[0] = beautiful[0] + 0;
        for (int i = 1; i < n; i++) {
            optimal_left[i] = max(optimal_left[i - 1], beautiful[i] + i);
        }

        // Tính suffix max của beauty[i] - i
        optimal_right[n - 1] = beautiful[n - 1] - (n - 1);
        for (int i = n - 2; i >= 0; i--) {
            optimal_right[i] = max(optimal_right[i + 1], beautiful[i] - i);
        }

        int result = 0;
        for (int i = 1; i <= n - 2; i++) {
            int val = optimal_left[i - 1] + beautiful[i] + optimal_right[i + 1];
            result = max(result, val);
        }

        cout << result << endl;
    }
}
