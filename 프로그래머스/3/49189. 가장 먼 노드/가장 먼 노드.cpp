#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

unordered_map<int, deque<int>> mp;
int mx, cnt;

void bfs(vector<bool>& vi)
{
    queue<pair<int, int>> que;
    
    que.push(make_pair(1, 0));
    vi[1] = true;
    while (que.size())
    {
        pair<int, int> nde = que.front();
        int num = nde.first;
        int depth = nde.second;
        cout << num << " " << depth << "\n";
        que.pop();

        if (mx < depth)
        {
            mx = depth;
            cnt = 0;
        }
        cnt++;
        
        for (int i = 0; i < mp[num].size(); i++)
        {
            int next_num = mp[num][i];
            if (!vi[next_num])
            {
                que.push(make_pair(next_num, depth + 1));            
                vi[next_num] = true;                
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<bool> vi(edge.size() + 1);
    
    for (int i = 0; i < edge.size(); i++)
    {
        mp[edge[i][0]].push_back(edge[i][1]);
        mp[edge[i][1]].push_back(edge[i][0]);
    }

    
    bfs(vi);
    
    return cnt;
}