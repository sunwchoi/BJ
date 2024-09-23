#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
vector<unordered_map<int, int>> tr;
int ans;

int traversal(int nde) {
    deque<int> d;

    for (auto it = tr[nde].begin(); it != tr[nde].end(); it++) {
        d.push_back(traversal(it->first) + it->second);
    }
    if (d.size() == 0) {
        return 0;
    }
    sort(d.begin(), d.end(), std::greater<int>());
    if (d.size() == 1)
        ans = max(ans, d[0]);
    else
        ans = max(ans, d[0] + d[1]);
    return d[0];
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    tr.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;

        cin >> u >> v >> w;
        tr[u][v] = w;
    }

    traversal(1);
    cout << ans << "\n";
    return 0;
}