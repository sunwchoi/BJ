#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<pair<int, int>> s;

int getRootNde(int idx) {
    return idx == s[idx].first ? idx : getRootNde(s[idx].first);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    s = vector<pair<int, int>>(n + 1);
    for (int i = 0; i <= n; i++) {
        s[i] = make_pair(i, 0);
    }

    for (int i = 0; i < m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        int aRoot = getRootNde(a);
        int bRoot = getRootNde(b);

        if (cmd == 0 && a != b) {
            if (s[aRoot].second == s[bRoot].second) {
                s[bRoot].first = s[aRoot].first;
                s[aRoot].second++;
            }
            else if (s[aRoot].second > s[bRoot].second) {
                s[bRoot].first = s[aRoot].first;
            }
            else {
                s[aRoot].first = s[bRoot].first;
            }
        }
        else if (cmd == 1) {
            if (s[aRoot].first == s[bRoot].first) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}