#include <iostream>
#include <unordered_map>

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> dp;

long long f(long long idx)
{
	if (dp.find(idx) != dp.end())
		return dp[idx];

	return dp[idx] = f(idx / P) + f(idx / Q);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> P >> Q;
	
	dp[0] = 1;
	cout << f(N) << "\n";
}