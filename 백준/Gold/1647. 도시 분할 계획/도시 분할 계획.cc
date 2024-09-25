#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int N, M;

unordered_map<int, unordered_map<int, int>> graph;
vector<int> vi;
int sum, mx;

void f() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> q;

    q.emplace(0, 1);
    while (!q.empty()) {
        int v = q.top().second;
        int d = q.top().first;

        q.pop();
        if (vi[v] != INT_MAX)
            continue;
        vi[v] = d;
        mx = max(mx, d);
        sum += d;
        for (auto it = graph[v].begin(); it != graph[v].end(); ++it) {
            int next_v = it->first;
            int next_d = it->second;

            if (vi[next_v] == INT_MAX) {
                q.emplace(next_d, next_v);
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vi.resize(N + 1, INT_MAX);
    vi[0] = 0;
    for (int i = 0; i < M; i++) {
        int A, B, C;

        cin >> A >> B >> C;
        graph[A][B] = C;
        graph[B][A] = C;
    }
    f();

    cout << sum - mx << "\n";
    return 0;
}