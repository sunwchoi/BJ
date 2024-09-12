#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        cin >> arr[i][0];
        for (int j = 1; j < N; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++) {
        int ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        for (int j = x1; j <= x2; j++) {
            ans += arr[j][y2];
            if (y1 != 0)
                ans -= arr[j][y1 - 1];
        }
        cout << ans << "\n";
    }
    return 0;
}
