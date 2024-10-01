#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int T, N, K, X, Y, W;
vector<int> D;
vector<int> dp;
vector<bool> vi;
unordered_map<int, unordered_map<int, bool>> graph;

int f(int nde) {
    if (dp[nde] != -1)
        return dp[nde];
    int ans = 0;

    for (auto it = graph[nde].begin(); it != graph[nde].end(); it++) {
        if (!vi[it->first]) {
            vi[it->first] = true;
            ans = max(ans, f(it->first));
            vi[it->first] = false;
        }
    }
    return dp[nde] = ans + D[nde];
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        D = vector<int>(N + 1);
        dp = vector<int>(N + 1, -1);
        vi = vector<bool>(N + 1);
        graph = unordered_map<int, unordered_map<int, bool>>();
        for (int i = 1; i <= N; i++)
            cin >> D[i];
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            graph[Y][X] = true;
        }

        cin >> W;
        cout << f(W) << "\n";
    }

    return 0;
}