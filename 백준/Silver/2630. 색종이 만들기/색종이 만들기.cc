#include <iostream>

using namespace std;

int N, b_cnt, w_cnt;
bool    p[128][128];

void    f(int x, int y, int n)
{
    bool    color = p[y][x];

    for (int i = y; i < y + n; i++)
        for (int j = x; j < x + n; j++)
            if (p[i][j] != color)
            {
                n /= 2;
                f(x, y, n);
                f(x + n, y, n);
                f(x, y + n, n);
                f(x + n, y + n, n);
                return ;
            }
    color == 1 ? b_cnt++ : w_cnt++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> p[i][j];
    f(0, 0, N);
    cout << w_cnt << "\n";
    cout << b_cnt << "\n";
}