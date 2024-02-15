#include <iostream>
#include <queue>

using namespace std;

int M, N, H, tomato;
int box[100][100][100];
bool    vi[100][100][100];
queue<pair<pair<pair<int, int>, int>, int> > qu;


void    visit(int x, int y, int z, int d)
{
    if ((!(0 <= x && x < M)) || (!(0 <= y && y < N)) || (!(0 <= z && z < H)) || (box[z][y][x]))
        return ;
    tomato--;
    box[z][y][x] = 1;
    qu.push(make_pair(make_pair(make_pair(x, y), z), d));
}

int bfs()
{
    int d;
    while (qu.size())
    {
        pair<pair<pair<int, int>, int>, int> nde = qu.front();
        qu.pop();
        int x = nde.first.first.first;
        int y = nde.first.first.second;
        int z = nde.first.second;
        d = nde.second;
        visit(x + 1, y, z, d + 1);
        visit(x - 1, y, z, d + 1);
        visit(x, y + 1, z, d + 1);
        visit(x, y - 1, z, d + 1);
        visit(x, y, z + 1, d + 1);
        visit(x, y, z - 1, d + 1);
    }
    return tomato ? -1 : d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                    qu.push(make_pair(make_pair(make_pair(k, j), i), 0));
                else if (box[i][j][k] == 0)
                    tomato++;
            }
    cout << bfs() << "\n";
}