#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int mp[500][500];
bool    vi[500][500];

bool    isValid(int x, int y)
{
    if ((0 <= x && x < M) && (0 <= y && y < N))
        return true ;
    return false ;
}

int f1(int x, int y, int cnt)
{
    if (!isValid(x, y) || vi[y][x] || cnt == 4)
        return 0;
    vi[y][x] = true;
    int ret = mp[y][x] +\
        max(max(f1(x + 1, y, cnt + 1), f1(x - 1, y, cnt + 1)), max(f1(x, y + 1, cnt + 1), f1(x, y - 1, cnt + 1)));
    vi[y][x] = false;
    return ret;
}

int f2(int x, int y)
{
    int ret = mp[y][x];
    int cnt = 0;

    if (isValid(x + 1, y) && ++cnt)
        ret += mp[y][x + 1];
    if (isValid(x - 1, y) && ++cnt)
        ret += mp[y][x - 1];
    if (isValid(x, y + 1) && ++cnt)
        ret += mp[y + 1][x];
    if (isValid(x, y - 1) && ++cnt)
        ret += mp[y - 1][x];
    if (cnt == 4)
        ret -= min(min(mp[y][x+1], mp[y][x-1]), min(mp[y+1][x], mp[y-1][x]));
    return ret;
}

int f()
{
    int ret = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            memset(vi, false, sizeof(vi));
            ret = max(max(f1(j, i, 0), f2(j, i)), ret);
        }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> mp[i][j];
    cout << f() << "\n";
}