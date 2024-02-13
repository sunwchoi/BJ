#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
string  mp[25];
int vi[25][25];
deque<int>  cnt;

bool    isValid(int x, int y)
{
    return (0 <= x && x < N && 0 <= y && y < N && mp[y][x] == '1' && !vi[y][x]);
}
void    dfs(int x, int y)
{
    vi[y][x] = true;
    cnt.back()++;
    if (isValid(x - 1, y))
        dfs(x - 1, y);
    if (isValid(x + 1, y))
        dfs(x + 1, y);
    if (isValid(x, y - 1))
        dfs(x, y - 1);
    if (isValid(x, y + 1))
        dfs(x, y + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> mp[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (mp[i][j] == '1' && !vi[i][j])
            {
                cnt.push_back(0);
                dfs(j, i);
            }
    cout << cnt.size() << "\n";
    sort(cnt.begin(), cnt.end());
    for (int i = 0; i < cnt.size(); i++)
        cout << cnt[i] << "\n";
}