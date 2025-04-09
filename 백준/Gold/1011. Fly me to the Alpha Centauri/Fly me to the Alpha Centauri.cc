#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int T, x, y;
vector<unsigned int> sum;
vector<unsigned int> dis;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sum.resize(2);
    sum[1] = 1;
    for (unsigned int i = 2; ; i++)
    {
        sum.push_back(i + sum[i - 1]);
        if (sum[i - 1] * 2 + i >= INT_MAX)
            break;
    }

    dis.resize(2);
    dis[1] = 1;
    for (unsigned int i = 2; dis[i - 1] <= INT_MAX; i++)
        dis.push_back(sum[i / 2] * 2 + (i % 2 ? i / 2 + 1: 0));

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> x >> y;
        auto it = lower_bound(dis.begin(), dis.end(), y - x);
        cout << it - dis.begin() << "\n";
    }
}