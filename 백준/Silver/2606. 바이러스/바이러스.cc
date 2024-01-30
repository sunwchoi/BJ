#include <iostream>
#include <vector>

using namespace std;

int N, M, u, v;
vector<int> com[101];
bool  visited[101];
int cnt = -1;

void  dfs(int n)
{
  cnt++;
  visited[n] = true;
  int size = com[n].size();
  for (int i = 0; i < size; i++)
    if (!visited[com[n][i]])
      dfs(com[n][i]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> u >> v;
    com[u].push_back(v);
    com[v].push_back(u);
  }
  dfs(1);
  cout << cnt << "\n";
}