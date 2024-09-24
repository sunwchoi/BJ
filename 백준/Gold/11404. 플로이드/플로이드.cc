#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<unordered_map<int, int>> graph;

void f(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> q;
    vector<int> vi(n + 1, INT_MAX);

    q.emplace(0, start);
    while (!q.empty()) {
        int v = q.top().second;
        int d = q.top().first;

        q.pop();
        if (vi[v] != INT_MAX)
            continue;
        vi[v] = d;
        for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
            int next_v = it->first;
            int next_d = it->second;

            if (vi[next_v] == INT_MAX) {
                q.emplace(next_d + d, next_v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ((vi[i] == INT_MAX) ? 0 : vi[i]) << " ";
    cout << "\n";
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        if (graph[a][b] == 0 || graph[a][b] > c)
            graph[a][b] = c;
    }

    for (int i = 1; i <= n; i++) {
        f(i);
    }

    return 0;
}