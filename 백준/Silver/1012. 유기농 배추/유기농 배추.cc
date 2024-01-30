#include <iostream>
#include <vector>

using namespace std;

int T, M, N, K;

void  dfs(int x, int y, vector<vector<bool> >& po, vector<vector<bool> >& vi)
{
  vi[y][x] = true;
  if (x - 1 >= 0 && po[y][x-1] && !vi[y][x-1])
    dfs(x-1, y, po, vi);
  if (y - 1 >= 0 && po[y-1][x] && !vi[y-1][x])
    dfs(x, y-1, po, vi);
  if (x + 1 < M && po[y][x+1] && !vi[y][x+1])
    dfs(x+1, y, po, vi);
  if (y + 1 < N && po[y+1][x] && !vi[y+1][x])
    dfs(x, y+1, po, vi);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++)
  {
    int cnt = 0;
    cin >> M >> N >> K;
    vector<vector<bool> > po(N, vector<bool>(M));
    vector<vector<bool> > vi(N, vector<bool>(M));
    for (int j = 0; j < K; j++)
    {
      int x, y;
      cin >> x >> y;
      po[y][x] = true;
    }
    for (int j = 0; j < N; j++)
      for (int k = 0; k < M; k++)
        if (!vi[j][k] && po[j][k])
        {
          dfs(k, j, po, vi);
          cnt++;
        }
    cout << cnt << "\n";
  }
}