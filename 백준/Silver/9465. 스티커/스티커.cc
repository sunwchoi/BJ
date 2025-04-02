#include <iostream>
#include <vector>

using namespace std;

int T, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        
        vector<vector<int>> sticker(n, vector<int>(2));
        for (int j = 0; j < n; j++)
            cin >> sticker[j][0];
        for (int j = 0; j < n; j++)
            cin >> sticker[j][1];

        vector<vector<int>> dp(n, vector<int>(3));

        dp[0][0] = sticker[0][0];
        dp[0][1] = sticker[0][1];

        for (int j = 1; j < n; j++)
        {
            dp[j][0] = sticker[j][0] + max(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = sticker[j][1] + max(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = max(dp[j - 1][0], max(dp[j - 1][1], dp[j - 1][2]));
        }
        cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << "\n";
    }
}