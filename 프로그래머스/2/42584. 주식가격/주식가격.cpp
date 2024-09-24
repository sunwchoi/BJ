#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    size_t len = prices.size();
    vector<int> answer(len);
    stack<pair<int, int>> stk;
    
    for (int i = 0; i < len; i++)
    {
        while (!stk.empty() && stk.top().second > prices[i])
        {
            int idx = stk.top().first;
            answer[idx] = i - idx;
            stk.pop();
        }
        stk.emplace(i, prices[i]);
    }
    
    while (!stk.empty())
    {
        int idx = stk.top().first;
        
        answer[idx] = len - 1 - idx;
        stk.pop();
    }
    
    return answer;
}