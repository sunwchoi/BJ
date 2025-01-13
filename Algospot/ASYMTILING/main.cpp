#include <iostream>

#define mod 1000000007
using namespace std;

size_t dp[101];
size_t asymDp[101];
int C, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 101; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		asymDp[i] = ((dp[i - 1] + dp[i - 2]) + mod - dp[i / 2]) % mod;
		if (i % 2 == 0)
			asymDp[i] = (asymDp[i] + mod - dp[i / 2 - 1]) % mod;
	}
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> n;
		cout << asymDp[n] << "\n";
	}
}
