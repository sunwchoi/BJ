#include <iostream>

using namespace std;

int N, K, cnt;
int m[10];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = N - 1; i >= 0; i--)
    cin >> m[i];
  for (int i = 0; i < N; i++)
  {
    int tmp = 0;
    while(m[i] * (tmp + 1) <= K)
      tmp++;
    K -= tmp * m[i];
    cnt += tmp;
    if (K == 0)
      break;
  }
  cout << cnt << "\n";
}