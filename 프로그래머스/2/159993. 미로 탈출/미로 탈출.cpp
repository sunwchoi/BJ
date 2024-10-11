#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void push(int x, int y, int d, queue<vector<int>>& que, vector<vector<bool>>& vi)
{
    que.push(vector<int>(3));
    que.back()[0] = x;
    que.back()[1] = y;
    que.back()[2] = d;
    vi[y][x] = true;
}
bool isValid(int x, int y, vector<string>& maps, vector<vector<bool>>& vi)
{
    if (0 <= x && x < maps[0].size() && 0 <= y && y < maps.size() 
        && maps[y][x] != 'X' && vi[y][x] == false)
        return true;
    return false;
}

int bfs(char start, char goal, vector<string>& maps)
{
    int start_x, start_y;
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == start)
            {
                start_y = i;
                start_x = j;
            }
        }
    }
    
    queue<vector<int>> que;
    vector<vector<bool>> vi(maps.size(), vector<bool>(maps[0].size()));
    push(start_x, start_y, 0, que, vi);
    while (!que.empty())
    {
        int x = que.front()[0];
        int y = que.front()[1];
        int d = que.front()[2];
        
        que.pop();
        if (maps[y][x] == goal)
            return d;
        
        if (isValid(x + 1, y, maps, vi))
            push(x + 1, y, d + 1, que, vi);
        if (isValid(x - 1, y, maps, vi))
            push(x - 1, y, d + 1, que, vi);
        if (isValid(x, y + 1, maps, vi))
            push(x, y + 1, d + 1, que, vi);
        if (isValid(x, y - 1, maps, vi))
            push(x, y - 1, d + 1, que, vi);
    }
    return -1;
}

int solution(vector<string> maps) {
    int SL, LE;
    
    if ((SL = bfs('S', 'L', maps)) == -1 || (LE = bfs('L', 'E', maps)) == -1)
        return -1;
    return SL + LE;
}