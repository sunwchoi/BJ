#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
vector<vector<vector<bool>>> vi;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    int N = board.size();
    
    vi = vector<vector<vector<bool>>>(N, vector<vector<bool>>(N, vector<bool>(4)));
        
    pq.push({0, 0, 0, -1});
    while (!pq.empty())
    {
        int d = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        int dir = pq.top()[3];
        
        pq.pop();
        if (x == N - 1 && y == N - 1)
            answer = min(answer, d);
        if (dir < 0)
        {
            for (int i = 0; i < 4; i++)
                vi[y][x][i] = true;
        }
        else
            vi[y][x][dir] = true;
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            int next_d = (dir < 0 || dir == i) ? 100 : 600;
            
            
            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N 
                && !vi[next_y][next_x][i] && !board[next_y][next_x])
            {
                pq.push({d + next_d, next_x, next_y, i});
            }
        }
    }
    return answer;
}