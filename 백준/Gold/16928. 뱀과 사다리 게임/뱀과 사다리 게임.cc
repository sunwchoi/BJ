#include <iostream>
#include <queue>

using namespace std;

int N, M;
int mp[101];
bool    vi[101];
queue<pair<int, int> >  qu;

void    visit(int n, int d)
{
    if (!(0 < n && n <= 100) || vi[n])
        return ;
    vi[n] = true;
    if (!mp[n])
        qu.push(make_pair(n, d));
    else 
        visit(mp[n], d);
}

int f()
{
    qu.push(make_pair(1, 0));
    vi[1] = true;
    while (qu.front().first != 100)
    {
        int n = qu.front().first;
        int d = qu.front().second;
        qu.pop();

        visit(n + 1, d + 1);
        visit(n + 2, d + 1);
        visit(n + 3, d + 1);
        visit(n + 4, d + 1);
        visit(n + 5, d + 1);
        visit(n + 6, d + 1);
    }
    return qu.front().second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N + M; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x] = y;
    }
    cout << f() << "\n";
}