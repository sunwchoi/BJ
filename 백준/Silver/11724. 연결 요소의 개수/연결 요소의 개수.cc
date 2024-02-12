#include <iostream>
#include <deque>

using namespace std;

int N, M, u, v;
deque<int>  nde[1001];
bool    vi[1001];

void    dfs(int n)
{
    vi[n] = true;
    int size = nde[n].size();
    for (int i = 0; i < size; i++)
        if (!vi[nde[n][i]])
            dfs(nde[n][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        nde[u].push_back(v);
        nde[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
        if (!vi[i])
        {
            dfs(i);
            cnt++;
        }
    cout << cnt << "\n";
}