#include <iostream>

using namespace std;

int T, N;
pair<int, int> dp[41];

pair<int, int> f(int n) {
  if (dp[n].first || dp[n].second)
    return dp[n];
  dp[n] = f(n - 1);
  dp[n].first += dp[n-2].first;
  dp[n].second += dp[n-2].second;
  return dp[n];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;

  dp[0] = make_pair(1, 0);
  dp[1] = make_pair(0, 1);
  for (int i = 0; i < T; i++)
  {
    cin >> N;
    f(N);
    cout << dp[N].first << " " << dp[N].second << "\n";
  }
}