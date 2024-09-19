#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, E;
int v1, v2;

int dist(int start, int goal, vector<unordered_map<int, int>>& graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> q;

    q.push(make_pair(0, start));
    vector<bool> vi(N);


    while (q.top().second != goal && !q.empty()) {
        int d = q.top().first;
        int v = q.top().second;
        q.pop();
        vi[v] = true;

        for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
            int next_v = it->first;
            int next_d = it->second;

            if (!vi[next_v]) {
                q.push(make_pair(d + next_d, next_v));
            }
        }
    }

    return q.empty() ? 0 : q.top().first;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    vector<unordered_map<int, int>> graph(N + 1);
    for (int i = 0; i < E; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u][v] = d;
        graph[v][u] = d;
    }
    cin >> v1 >> v2;

    int OneV1 = dist(1, v1, graph);
    int OneV2 = dist(1, v2, graph);
    int V1N = dist(v1, N, graph);
    int V2N = dist(v2, N, graph);
    int V1V2 = dist(v1, v2, graph);

    if ((!OneV1 || !V2N) && (!OneV2 || !V1N)) {
        cout << -1 << "\n";
    }
    else
        cout << min(OneV1 + V2N, OneV2 + V1N) + V1V2 << "\n";

    return 0;
}