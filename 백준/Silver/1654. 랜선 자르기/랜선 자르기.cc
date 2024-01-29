#include <iostream>

using namespace std;

int K, N;
int len[10000];
int mx = 0;

int b_search(long left, long right)
{
  int cnt = 0;
  if (right - left <= 1)
  {
    for (int i = 0; i < K; i++)
      cnt += len[i] / right;
    return cnt >= N ? right : left;
  }
  long mid = (left + right) / 2;
  for (int i = 0; i < K; i++)
    cnt += len[i] / mid;
  if (cnt >= N)
    return b_search(mid, right);
  else
    return b_search(left, mid);
}

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> K >> N;
  for (int i = 0; i < K; i++)
  {
    cin >> len[i];
    mx = mx > len[i] ? mx : len[i];
  }
  cout << b_search(1, mx) << "\n";
}