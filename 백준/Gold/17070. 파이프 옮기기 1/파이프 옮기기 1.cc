#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int N;
map<vector<int>, int> dp;

bool isValid(int tX, int tY, int hX, int hY, vector<vector<int>>& mp) {
    if (mp[hY][hX])
        return false;
    if ((hY != tY && hX != tX) && (mp[hY - 1][hX] || mp[hY][hX - 1]))
        return false;
    return true;
}

void bt(int tX, int tY, int hX, int hY, vector<vector<int>>& mp) {
    if (!isValid(tX, tY, hX, hY, mp))
        return ;
    if (dp.find({tX, tY, hX, hY}) != dp.end() || hX == N && hY == N) {
        dp[{tX, tY, hX, hY}]++;
        return;
    }

    bt(hX, hY, hX + 1, hY + 1, mp);
    if (hY != tY)
        bt(hX, hY, hX, hY + 1, mp);
    if (hX != tX)
        bt(hX, hY, hX + 1, hY, mp);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<int>> mp(N + 2, vector<int>(N + 2, 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> mp[i][j];
        }
    }
    bt(1, 1, 2, 1, mp);

    int sum = 0;
    for (auto it = dp.begin(); it != dp.end(); it++) {
        sum += it->second;
    }
    cout << sum << "\n";
    return 0;
}