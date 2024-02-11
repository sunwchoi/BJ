#include <iostream>

using namespace std;

int T, N, cnt;

void    f(int n)
{
    if (n <= 0)
    {
        if (n == 0)
            cnt++;
        return ;
    }
    for (int i = 1; i <= 3; i++)
        f(n - i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cnt = 0;
        for (int j = 1; j <= 3; j++)
            f(N - j);
        cout << cnt << "\n";
    }
}