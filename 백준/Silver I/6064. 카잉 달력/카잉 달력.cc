#include <iostream>

using namespace std;

int T, M, N, x, y;

int f(int m, int n)
{
    if (m + x == n + y)
        return m + x;
    if (m != 0 && n != 0 && m == n)
        return -1;
    return (m + x < n + y) ? f(m + M, n) : f(m, n + N);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> x >> y;
        cout << f(0, 0) << "\n";
    }
}