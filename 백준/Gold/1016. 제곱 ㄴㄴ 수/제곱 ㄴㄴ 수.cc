#include <iostream>
#include <cassert>

using namespace std;

long long mn, mx;
bool ans[10000000];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> mn >> mx;

    for (long long i = 2; i * i <= mx; i++)
    {
        long long ii = i * i;
        for (long long j = mn / ii + (mn % ii != 0); j <= mx / ii; j++)
            ans[j * ii - mn] = true;            
    }

    int cnt = mx - mn + 1;
    for (int i = 0; i < mx - mn + 1; i++)
    {
        if (ans[i] == true)
            cnt--;
    }

    cout << cnt << "\n";
}
