#include <iostream>

using namespace std;

int n, cnt;
int dp[1001];

int f(int i)
{
    if (i <= 0)
        return 0;
    return dp[i] ? dp[i] : (dp[i] = (f(i - 1) + f(i - 2)) % 10007);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    cout << f(n) << "\n";
}