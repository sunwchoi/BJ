#include <iostream>
#include <queue>

using namespace std;

int M,N;
int box[1000][1000];
queue<pair<pair<int, int>, int> >   qu;

void    visit(int x, int y, int d)
{
    if (!(0 <= x && x < M  && 0 <= y && y < N) || box[y][x])
        return ;
    box[y][x] = 1;
    qu.push(make_pair(make_pair(x,y), d));
}

int f()
{
    int cnt = 0;
    while (qu.size())
    {
        int x = qu.front().first.first;
        int y = qu.front().first.second;
        cnt = qu.front().second;
        qu.pop();
        visit(x - 1, y, cnt + 1);
        visit(x + 1, y, cnt + 1);
        visit(x, y - 1, cnt + 1);
        visit(x, y + 1, cnt + 1);
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!box[i][j])
                return -1;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
                qu.push(make_pair(make_pair(j, i), 0));
        }
    cout << f() << "\n";
}