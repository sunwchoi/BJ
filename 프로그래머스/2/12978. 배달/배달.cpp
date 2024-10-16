#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

vector<int> vi;
unordered_map<int, unordered_map<int, int>> graph;

void f()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.emplace(0, 1);
    while (!pq.empty())
    {
        int v = pq.top().second;
        int d = pq.top().first;
        
        pq.pop();
        if (vi[v] != INT_MAX)
            continue;
        vi[v] = d;
        for (auto it = graph[v].begin(); it != graph[v].end(); it++)
        {
            int next_v = it->first;
            int next_d = it->second;
            
            if (vi[next_v] == INT_MAX)
                pq.emplace(d + next_d, next_v);
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vi.resize(N + 1, INT_MAX);
    for (int i = 0; i < road.size(); i++)
    {
        if (graph[road[i][0]].find(road[i][1]) == graph[road[i][0]].end() ||
            graph[road[i][0]][road[i][1]] > road[i][2])
        {
            graph[road[i][0]][road[i][1]] = road[i][2];
            graph[road[i][1]][road[i][0]] = road[i][2];    
        }
        
    }
    f();
    for (int i = 1; i <= N; i++)
    {
        cout << vi[i] << "\n";
        if (vi[i] <= K)
            answer++;
    }
    return answer;
}