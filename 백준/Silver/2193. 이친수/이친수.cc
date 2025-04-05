#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<unsigned long long>> dp;

unsigned long long f(int n, int pre)
{
    if (dp[n][pre])
        return dp[n][pre];

    if (pre == 0)
        return dp[n][pre] = f(n - 1, 0) + f(n - 1, 1);

    if (pre == 1)
        return dp[n][pre] = f(n - 1, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (N == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    dp = vector<vector<unsigned long long>>(N, vector<unsigned long long>(2));
    dp[1][0] = 2;
    dp[1][1] = 1;

    cout << f(N - 1, 1) << "\n";
}