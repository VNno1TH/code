#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        vector<vector<int>> hotel(N, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> hotel[i][j];
            }
        }
    }
}
