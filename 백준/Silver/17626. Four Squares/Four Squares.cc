#include <iostream>

using namespace std;

int n;
int dp[50001];

int max_sq(int num)
{
    int sq = 0;
    while ((sq+1)*(sq+1) <= num)
        sq++;
    return sq;
}

int f(int num)
{
    if (num == 0 || dp[num])
        return dp[num];
    int size = max_sq(num);
    int ret = 5;
    for (int i = size; i >= 1; i--)
        ret = min(f(num - i * i), ret);
    return (dp[num] = ret + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    cout << f(n) << "\n";
}