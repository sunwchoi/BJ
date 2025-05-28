#include <iostream>
#include <cmath>

using namespace std;

int X, Y, D, T;

double f(double d, double t, bool firstJump)
{
    if (d > D)
        return f(d - D, t + T, false);
    if (d == D)
        return t + T;
    return min(min(t + d, t + T + D - d), t + (1 + firstJump) * T);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y >> D >> T;
    double d = sqrt(X * X + Y * Y);
    double ans = min(f(d, 0, true), d);
    cout << fixed;
    cout.precision(9);
    cout << ans << "\n";
}