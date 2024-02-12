#include <iostream>
#include <queue>

using namespace std;

int N, M;
int mp[1000][1000];
int dis[1000][1000];
queue<pair<pair<int, int>, int> > qu;

void    visit(int x, int y, int d)
{
    if (!(mp[y][x] == 1))
        return ;
    if (dis[y][x])
        return ;
    qu.push(make_pair(make_pair(x, y), dis[y][x] = d));
}

void    bfs(int x, int y)
{
    qu.push(make_pair(make_pair(x, y), 0));
    while (qu.size())
    {
        x = qu.front().first.first;
        y = qu.front().first.second;
        int d = qu.front().second;
        qu.pop();
        visit(x + 1, y, d + 1);
        visit(x - 1, y, d + 1);
        visit(x, y + 1, d + 1);
        visit(x, y - 1, d + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int x;
    int y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 2)
            {
                x = j;
                y = i;
            }
        }
    bfs(x, y);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << (!dis[i][j] && mp[i][j] == 1 ? -1 : dis[i][j])  << " ";
        }
        cout << "\n";
    } 
}