#include <iostream>

using namespace std;

int arr[15][15];

int f(int k, int n)
{
  if (k == 0)
    return n;
  if (!arr[k][n])
    for (int i = 1; i <= n; i++)
      arr[k][n] += f(k-1, i);
  return arr[k][n];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int k, n;
    cin >> k >> n;
    cout << f(k, n) << "\n";
  }
}