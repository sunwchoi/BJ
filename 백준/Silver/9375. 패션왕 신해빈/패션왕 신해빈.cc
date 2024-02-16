#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, n;

int f(int idx, int pre, vector<pair<string, string> >& arr, vector<int>& dp)
{
    if (pre != -1 && arr[idx].first == arr[pre].first)
        return 0;
    if (dp[idx])
        return dp[idx];
    for (int i = idx + 1; i < n; i++)
        dp[idx] += f(i, idx, arr, dp);
    return ++dp[idx];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        vector<pair<string, string> >    arr(n);
        vector<int> dp(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i].second >> arr[i].first;
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += f(i, -1, arr, dp);
        cout << cnt << "\n";
    }
}