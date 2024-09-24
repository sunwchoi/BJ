#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;
    size_t N = board.size();
    size_t M = moves.size();
    
    for (int i = 0; i < M; i++)
    {
        int x = moves[i] - 1;
        int y = 0;
        while (y != N && !board[y][x])
            y++;
        if (y == N)
            continue;
        int tmp = board[y][x];
        board[y][x] = 0;
        if (!stk.empty() && stk.top() == tmp)
        {
            stk.pop();
            answer += 2;            
        }
        else
            stk.push(tmp);
    }

    return answer;
}