#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int V, E, K;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    vector<unordered_map<int, int>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;

        cin >> u >> v >> w;
        if (graph[u][v] == 0 || graph[u][v] > w)
        graph[u][v] = w;
    }
    vector<int> vi(V + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
    pq.emplace(0, K);

    while (!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;

        pq.pop();
        if (vi[v] != INT_MAX) {
            continue ;
        }
        vi[v] = d;
        for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
            int next_v = it->first;
            int next_d = it->second;

            if (vi[next_v] == INT_MAX) {
                pq.emplace(d + next_d, next_v);
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (vi[i] != INT_MAX) {
            cout << vi[i] << "\n";
        }
        else
            cout << "INF\n";
    }


    return 0;
}