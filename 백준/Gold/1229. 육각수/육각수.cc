#include <iostream>
#include <vector>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<int> six;
	int d = 1;
	int dd = 4;

	six.push_back(1);
	while (six.back() < N)
		six.push_back(six.back() + (d += dd));

	vector<int> dp(N + 1, 7);
	dp[0] = 0;

	for (int i = 0; i < six.size(); i++)
	{
		for (int j = six[i]; j <= N; j++)
			dp[j] = min(dp[j], dp[j - six[i]] + 1);
	}

	cout << dp[N] << "\n";
}