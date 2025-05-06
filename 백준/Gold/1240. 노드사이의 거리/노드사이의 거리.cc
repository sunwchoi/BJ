#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int dist[1001][1001];
bool vi[1001];

int dfs(int v, int w)
{
    if (dist[v][w])
        return dist[v][w];

    for (int i = 1; i <= N; i++)
    {
        if (dist[v][i] && vi[i] == false)
        {
            vi[i] = true;
            
            int tmp = dfs(i, w);
            if (tmp)
                return tmp + dist[v][i];

            vi[i] = false;
        }
    }

    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N - 1; i++)
    {
        int v, w, d;
        cin >> v >> w >> d;
        
        dist[v][w] = d;
        dist[w][v] = d;
    }

    for (int i = 0; i < M; i++)
    {
        memset(vi, false, N + 1);
        int v, w;
        cin >> v >> w;

        vi[v] = true;
        cout << dfs(v, w) << "\n";
    }
}