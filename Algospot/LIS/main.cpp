#include <iostream>
#include <vector>

using namespace std;

int C, N;
int arr[500];
vector<int> dp;

int getLIS(int idx)
{
	if (dp[idx] > 0)
		return dp[idx];
	
	int maxLen = 0;
	for (int i = idx + 1; i < N; i++)
	{
		if (arr[idx] < arr[i])
			maxLen = max(maxLen, getLIS(i));
	}

	return dp[idx] = 1 + maxLen;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> N;
		dp = vector<int>(N);
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
		}
		int answer = 0;
		for (int j = 0; j < N; j++)
		{
			answer = max(answer, getLIS(j));
		}
		cout << answer << "\n";
	}
}
