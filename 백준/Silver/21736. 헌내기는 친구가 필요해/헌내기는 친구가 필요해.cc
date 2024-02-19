#include <iostream>

using namespace std;

int N, M, rx, ry;
string  mp[600];

int f(int x, int y)
{
    if (!(0 <= x && x < M) || !(0 <= y && y < N) || mp[y][x] == 'X')
        return 0;

    int cnt = mp[y][x] == 'P' ? 1 : 0;

    mp[y][x] = 'X';
    cnt += f(x + 1, y);
    cnt += f(x - 1, y);
    cnt += f(x, y + 1);
    cnt += f(x, y - 1);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> mp[i];
        int pos = mp[i].find('I');
        if (pos != string::npos)
        {
            rx = pos;
            ry = i;
        }
    }
    int tmp = f(rx, ry);
    if (tmp)
        cout << tmp << "\n";
    else
        cout << "TT\n";
}