#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> T;
vector<int> P;
vector<vector<int>> dp;

int f(int day)
{
    if (day >= N)
        return day == N ? 0 : -1;

    if (dp[day][0] == 0 || dp[day][1] == 0)
    {
        dp[day][0] = f(day + 1);
        dp[day][1] = f(day + T[day]);
        if (dp[day][1] != -1)
            dp[day][1] += P[day];
    }
    
    return max(dp[day][0], dp[day][1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    T = vector<int>(N);
    P = vector<int>(N);
    dp = vector<vector<int>>(N, vector<int>(2));
    for (int i = 0; i < N; i++)
        cin >> T[i] >> P[i];

    cout << f(0) << "\n";
}