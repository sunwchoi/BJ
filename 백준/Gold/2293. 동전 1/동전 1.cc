#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> dp;
vector<int> money;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    money = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> money[i];

    dp = vector<int>(k + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= money[i])
                dp[j] += dp[j - money[i]];
        }
    }

    cout << dp[k] << "\n";
}