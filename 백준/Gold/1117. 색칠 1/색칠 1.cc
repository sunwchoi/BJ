#include <iostream>
#include <vector>

using namespace std;

long long W, H, f, c, x1, x2, Y1, y2;
long long mid, last;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> W >> H >> f >> c >> x1 >> Y1 >> x2 >> y2;

    mid = min(f, W - f);
    last = max(f, W - f);

    long long color;
    if (x1 < mid && mid < x2)
        color = ((mid - x1) * 2 + (x2 - mid)) * (c + 1) * (y2 - Y1);
    else
        color = (x2 - x1) * (mid >= x2 ? 2 : 1) * (c + 1) * (y2 - Y1);

    cout << W * H - color << "\n";
}