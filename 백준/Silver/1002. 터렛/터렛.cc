#include <iostream>
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            cout << "-1\n";
            continue;
        }

        int dx = x2 - x1;
        int dy = y2 - y1;
        long long d = dx * dx + dy * dy;
        long long r = (r1 + r2) * (r1 + r2);

        if (d > r)
            cout << "0\n";
        else if (d == r)
            cout << "1\n";
        else if (d < r)
        {
            long long R = (r1 - r2) * (r1 - r2);
            if (d > R)
                cout << "2\n";
            else if (d == R)
                cout << "1\n";
            else if (d < R)
                cout << "0\n";
        }
    }

}