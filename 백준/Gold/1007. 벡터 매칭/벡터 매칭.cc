#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int T, N;
pair<int, int> point[20];
int s[20];
int e[20];
bool isS[20];
double ans;

void f(int idx, int n)
{
    if (n == N / 2)
    {
        int eIdx = 0;
        for (int i = 0; i < N; i++)
        {
            if (isS[i] == false)
                e[eIdx++] = i;
        }

        
        for (int i = 0; i < N / 2; i++)
        {
            long long dxSum = 0;
            long long dySum = 0;
            for (int j = 0; j < N / 2; j++)
            {
                int dx = point[s[j]].first - point[e[(j + i) % (N / 2)]].first;
                int dy = point[s[j]].second - point[e[(j + i) % (N / 2)]].second;

                dxSum += dx;
                dySum += dy;
            }
            
            ans = min(sqrt(dxSum * dxSum + dySum * dySum), ans);
        }
        return;
    }

    for (int i = idx; i < N; i++)
    {
        s[n] = i;
        isS[i] = true;
        f(i + 1, n + 1);
        isS[i] = false;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        ans = numeric_limits<double>::max();
        for (int j = 0; j < N; j++)
        {
            int x, y;
            cin >> x >> y;
            point[j] = make_pair(x, y);
        }

        f(0, 0);
        cout << fixed;
        cout.precision(7);
        cout << ans << "\n";
    }
}