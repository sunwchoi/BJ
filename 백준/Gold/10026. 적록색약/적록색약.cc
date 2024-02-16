#include <iostream>

using namespace std;

int N;
string  mp[100];
bool    vi1[100][100];
bool    vi2[100][100];

bool    isValid(int x, int y, int a, int b, bool vi[100][100])
{
    if (!(0 <= a && a < N) || !(0 <= b && b < N)
        || vi[b][a] || mp[b][a] != mp[y][x])
        return false;
    return true;
}

void    dfs(int x, int y, bool vi[100][100])
{
    vi[y][x] = true;
    if (isValid(x, y, x + 1, y, vi))
        dfs(x + 1, y, vi);
    if (isValid(x, y, x - 1, y, vi))
        dfs(x - 1, y, vi);
    if (isValid(x, y, x, y + 1, vi))
        dfs(x, y + 1, vi);
    if (isValid(x, y, x, y - 1, vi))
        dfs(x, y - 1, vi);
    if (mp[y][x] == 'R')
        mp[y][x] = 'G';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> mp[i];
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!vi1[i][j] && ++cnt)
                dfs(j, i, vi1);
    cout << cnt << "\n";
    cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!vi2[i][j] && ++cnt)
                dfs(j, i, vi2);
    cout << cnt << "\n";
}