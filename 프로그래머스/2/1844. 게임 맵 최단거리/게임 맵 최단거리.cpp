#include<vector>
#include<queue>

using namespace std;

void push(int x, int y, int d, queue<vector<int>>& que, vector<vector<bool>>& vi)
{
    que.emplace(3);
    que.back()[0] = x;
    que.back()[1] = y;
    que.back()[2] = d;
    vi[y][x] = true;
}

bool isValid(int x, int y, vector<vector<int> >& maps, vector<vector<bool>>& vi)
{
    int rowSize = maps.size();
    int colSize = maps[0].size();
    
    if (0 <= x && x < colSize && 0 <= y && y < rowSize && maps[y][x] == 1 && !vi[y][x])
        return true;
    return false;
}

int bfs(vector<vector<int> >& maps)
{
    int rowSize = maps.size();
    int colSize = maps[0].size();
    
    vector<vector<bool>> vi(rowSize, vector<bool>(colSize));
    queue<vector<int>> que;
    que.emplace(3);
    while (!que.empty())
    {
        int x = que.front()[0];
        int y = que.front()[1];
        int d = que.front()[2];
        
        que.pop();
        if (x == colSize - 1 && y == rowSize - 1)
            return d + 1;
        
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

int solution(vector<vector<int> > maps)
{   
    return bfs(maps);
}