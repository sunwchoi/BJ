#include <iostream>
#include <vector>

using namespace std;

int N, x;
vector<pair<int, int>> pipe;
vector<vector<int>> dp;

int f(int idx, int len)
{
	if (len >= x)
		return len == x ? 1 : 0;

	if (idx == N)
		return 0;

	if (dp[idx][len] == -1)
	{
		dp[idx][len] = 0;
		int L = pipe[idx].first;
		int C = pipe[idx].second;
		for (int i = 0; i <= C; i++)
			dp[idx][len] += f(idx + 1, len + L * i);
	}

	return dp[idx][len];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> x;
	dp = vector<vector<int>>(N, vector<int>(x + 1, -1));
	for (int i = 0; i < N; i++)
	{
		int L, C;
		cin >> L >> C;
		pipe.push_back({ L, C });
	}

	cout << f(0, 0);
}