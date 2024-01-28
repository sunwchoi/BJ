#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int M, N;
  cin >> M >> N;
  vector<bool> num(N+1, true);
  num[1] = false;

  for (int i = 2; i <= N; i++)
  {
    if (!num[i])
      continue;
    for(int j = 2; j * i <= N; j++)
      num[j * i] = false;
  }
  for (int i = M; i <= N; i++)
    if (num[i]) cout << i << "\n";
}