#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001];
vector<int> adjacent[100001];
int order[100001];
int N, M ,R;
int cnt;

void  dfs(int n)
{
  order[n] = ++cnt;
  visited[n] = true;
  int size = adjacent[n].size();
  for (int i = size - 1; i >= 0; i--)
  {
    if (!visited[adjacent[n][i]])
      dfs(adjacent[n][i]);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> R;
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    adjacent[u].push_back(v);
    adjacent[v].push_back(u);
  }
  for (int i = 1; i <= N; i++)
    sort(adjacent[i].begin(), adjacent[i].end());
  dfs(R);
  for (int i = 1; i <= N; i++)
    cout << order[i] << "\n";
}