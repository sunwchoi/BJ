#include <iostream>
#include <vector>

using namespace std;

int C, n;
vector<vector<int> > tr;
vector<vector<pair<int, int> > > dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> n;
		tr = vector<vector<int> >(n, vector<int>(n));
		dp = vector<vector<pair<int, int> > >(n, vector<pair<int, int> >(n));
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < j + 1; k++)
			{
				cin >> tr[j][k];
			}
		}

		dp[0][0].first = tr[0][0];
		dp[0][0].second = 1;
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < j + 1; k++)
			{
				if (k == 0)
				{
					dp[j][k].first = tr[j][k] + dp[j - 1][k].first;
					dp[j][k].second = dp[j - 1][k].second;
				}
				else if (k == j)
				{
					dp[j][k].first = tr[j][k] + dp[j - 1][k - 1].first;
					dp[j][k].second = dp[j - 1][k - 1].second;
				}
				else if (dp[j - 1][k - 1].first > dp[j - 1][k].first)
				{
					dp[j][k].first = tr[j][k] + dp[j - 1][k - 1].first;
					dp[j][k].second = dp[j - 1][k - 1].second;
				}
				else if (dp[j - 1][k - 1].first < dp[j - 1][k].first)
				{
					dp[j][k].first = tr[j][k] + dp[j - 1][k].first;
					dp[j][k].second = dp[j - 1][k].second;
				}
				else if (dp[j - 1][k - 1].first == dp[j - 1][k].first)
				{
					dp[j][k].first = tr[j][k] + dp[j - 1][k].first;
					dp[j][k].second = dp[j - 1][k - 1].second + dp[j - 1][k].second;
				}
			}

		}
		int sum = 0;
		int mx = 0;
		for (int i = 0; i < n; i++)
		{
			if (dp[n - 1][i].first > mx)
			{
				mx = dp[n - 1][i].first;
				sum = dp[n - 1][i].second;
			}
			else if (dp[n - 1][i].first == mx)
			{
				sum += dp[n - 1][i].second;
			}
		}
		cout << sum << "\n";
	}
}
