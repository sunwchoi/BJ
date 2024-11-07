#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer = {0, 0};
    unordered_map<string, vector<int>> mp;
    
    mp["up"] = {0, 1};
    mp["down"] = {0, -1};
    mp["left"] = {-1, 0};
    mp["right"] = {1, 0};
    
    for (int i = 0; i < keyinput.size(); i++)
    {
        int dx = mp[keyinput[i]][0];
        int dy = mp[keyinput[i]][1];
        if (board[0] / 2 * -1<= answer[0] + dx && answer[0] + dx <= board[0] / 2)
            answer[0] += dx;
        if (board[1] / 2 * -1 <= answer[1] + dy && answer[1] + dy <= board[1] / 2)
            answer[1] += dy;
    }
    
    return answer;
}