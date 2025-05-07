#include <iostream>
using namespace std;

int N;
int ans[1000001];
int cnt[1000001];
int input[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
        cnt[input[i]]++;
    }

    for (int i = 0; i < N; i++)
    {
        if (cnt[input[i]] > 0)
        {
            for (int j = 1; input[i] * j <= 1000000; j++)
                ans[input[i] * j] += cnt[input[i]];
            
            cnt[input[i]] *= -1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[input[i]] - 1 << "\n";
    }
}