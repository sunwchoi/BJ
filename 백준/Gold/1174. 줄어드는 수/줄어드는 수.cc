#include <iostream>

using namespace std;

int N;

void f(long long cur, int pre, int d)
{
    if (d == 0)
    {
        if (--N == 0)
        {
            cout << cur << "\n";
            exit(0);
        }
    }

    for (int i = 0; i < pre; i++)
        f(cur * 10 + i, i, d - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < 10; i++)
        f(0, 10, i + 1);
    cout << -1 << "\n";
}
