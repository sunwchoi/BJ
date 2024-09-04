#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int nde, int& cnt, vector<vector<bool>>& graph, vector<bool>& vi)
{
    vi[nde] = true;
    cnt++;
    for (int i = 0; i < graph[nde].size(); i++)
    {
        if (graph[nde][i] && !vi[i])
            dfs(i, cnt, graph, vi);  
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    vector<vector<bool>> graph(n, vector<bool>(n));
    
    for (int i = 0; i < wires.size(); i++)
    {
        graph[wires[i][0] - 1][wires[i][1] - 1] = true;
        graph[wires[i][1] - 1][wires[i][0] - 1] = true;
        
    }

    for (int i = 0; i < wires.size(); i++)
    {
        vector<bool> vi(n);
        int cnt[2] = {0, 0};
        graph[wires[i][0] - 1][wires[i][1] - 1] = false;
        graph[wires[i][1] - 1][wires[i][0] - 1] = false;
        for (int j = 0; j < n; j++)
        {
            if (vi[j])
                continue ;
            if (!cnt[0])
                dfs(j, cnt[0], graph, vi);
            else
                dfs(j, cnt[1], graph, vi);
        }
        cout << cnt[0] << " " << cnt[1] << "\n";
        answer = min(abs(cnt[1] - cnt[0]), answer);
        graph[wires[i][0] - 1][wires[i][1] - 1] = true;
        graph[wires[i][1] - 1][wires[i][0] - 1] = true;
    }                
    return answer;
}