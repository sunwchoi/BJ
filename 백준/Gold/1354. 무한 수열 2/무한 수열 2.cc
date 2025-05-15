#include <iostream>
#include <unordered_map>

using namespace std;

long long N, P, Q, X, Y;
unordered_map<long long, long long> dp;

long long f(long long idx)
{
	if (idx <= 0)
		return 1;
	if (dp.find(idx) != dp.end())
		return dp[idx];

	return dp[idx] = f(idx / P - X) + f(idx / Q - Y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> P >> Q >> X >> Y;

	cout << f(N) << "\n";
}