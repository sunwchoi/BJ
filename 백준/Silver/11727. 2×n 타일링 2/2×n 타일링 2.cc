#include <iostream>

using namespace std;

int n;
int dp[1001];

int f(int len)
{
    if (dp[len])
        return dp[len];
    if (len >= 2)
        dp[len] += f(len - 2) * 2;
    if (len >= 1)
        dp[len] += f(len - 1);
    return dp[len] %= 10007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    dp[0] = 1;
    cout << (n == 0 ? 0 : f(n)) << "\n";
}