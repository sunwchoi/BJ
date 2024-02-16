#include <iostream>
#include <vector>

using namespace std;

int N;
string  mp[100];
vector<vector<bool> >    vi;

bool    isValid(int x, int y, int a, int b)
{
    if (!(0 <= a && a < N) || !(0 <= b && b < N)
        || vi[b][a] || mp[b][a] != mp[y][x])
        return false;
    return true;
}

void    dfs(int x, int y)
{
    vi[y][x] = true;
    if (isValid(x, y, x + 1, y))
        dfs(x + 1, y);
    if (isValid(x, y, x - 1, y))
        dfs(x - 1, y);
    if (isValid(x, y, x, y + 1))
        dfs(x, y + 1);
    if (isValid(x, y, x, y - 1))
        dfs(x, y - 1);
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
    vi = vector<vector<bool> >(N, vector<bool>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!vi[i][j] && ++cnt)
                dfs(j, i);
    cout << cnt << "\n";
    cnt = 0;
    vi = vector<vector<bool> >(N, vector<bool>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!vi[i][j] && ++cnt)
                dfs(j, i);
    cout << cnt << "\n";
}