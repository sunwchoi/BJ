#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int N, E;

vector<vector<int>> cost;
vector<int> parent;
vector<int> ranks;

int find(int v) {
    if (parent[v] == -1)
        return v;
    return (parent[v] = find(parent[v]));
}

void merge(int u, int v) {
    int parent_u = find(u);
    int parent_v = find(v);

    if (ranks[parent_u] < ranks[parent_v]) {
        parent[parent_u] = parent_v;
    }
    else if (ranks[parent_v] < ranks[parent_u]) {
        parent[parent_v] = parent_u;
    }
    else {
        parent[parent_v] = parent_u;
        ranks[parent_u]++;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;

    cin >> N >> E;

    parent = vector<int>(N + 1, -1);
    ranks = vector<int>(N + 1, 0);
    cost = vector<vector<int>>(E, vector<int>(3));
    for (int i = 0; i < E; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    sort(cost.begin(), cost.end(), [](const vector<int>& a, const vector<int>& b) { return (a[2] < b[2]); });
    for (int i = 0; i < cost.size(); i++) {
        int u = cost[i][0];
        int v = cost[i][1];
        int c = cost[i][2];

        if (find(v) != find(u)) {
            merge(u, v);
            answer += c;
        }
    }
    cout << answer << "\n";


    return 0;
}