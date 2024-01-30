#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, R, u, v, cnt;
int order[100001];
vector<int> adjacent[100001];

void  bfs(int n)
{
  queue<int> que;

  que.push(n);
  order[n] = ++cnt;
  while (!que.empty())
  {
    int nde1 = que.front();
    int size = adjacent[nde1].size();
    que.pop();
    for (int i = 0; i < size; i++) 
    {
      int nde2 = adjacent[nde1][i];
      if (!order[nde2])
      {
        order[nde2] = ++cnt;
        que.push(nde2);
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> R;
  for (int i = 0; i < M; i++)
  {
    cin >> u >> v;
    adjacent[u].push_back(v);
    adjacent[v].push_back(u);
  }
  for (int i = 1; i <= N; i++)
    sort(adjacent[i].begin(), adjacent[i].end());
  bfs(R);
  for (int i = 1; i <= N; i++)
    cout << order[i] << "\n";
}