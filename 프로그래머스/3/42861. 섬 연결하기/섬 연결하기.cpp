#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, unordered_map<int, int>> graph;

int prim(int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<bool> vi(n);
    int cnt = 0;
    int ans = 0;
    
    pq.emplace(0, 0);
    while (cnt != n)
    {
        int v = pq.top().second;
        int c = pq.top().first;
        pq.pop();
        
        if (vi[v])
            continue;
        vi[v] = true;
        cnt++;
        ans += c;
        for (auto it = graph[v].begin(); it != graph[v].end(); it++)
        {
            int next_v = it->first;
            int next_c = it->second;
            
            if (!vi[next_v])
                pq.emplace(next_c, next_v);
        }
    }
    return ans;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 0; i < costs.size(); i++)
    {
        int u = costs[i][0];
        int v = costs[i][1];
        int c = costs[i][2];
        
        graph[u][v] = c;
        graph[v][u] = c;
    }
    return prim(n);
}