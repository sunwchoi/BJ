#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int C, N;
vector<int> money;
vector<int> customer;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C >> N;
    money.resize(N);
    customer.resize(N);

    for (int i = 0; i < N; i++)
        cin >> money[i] >> customer[i];

    dp.resize(C + 101, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < C + 101; j++)
        {
            if (j >= customer[i] && dp[j - customer[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - customer[i]] + money[i]);
        }
    }

    int answer = INT_MAX;
    for (int i = C; i < C + 101; i++)
        answer = min(dp[i], answer);
    
    cout << answer << "\n";
}
