#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    size_t len = s.length();
    unordered_map<char, char> pr;
    
    pr[']'] = '[';
    pr['}'] = '{';
    pr[')'] = '(';
    
    for (int i = 0; i < len; i++)
    {
        stack<char> stk;
        for (int j = i; j < i + len; j++)
        {
            char c = s[j % len];
            if (!stk.empty() && pr[c] == stk.top())
                stk.pop();
            else
                stk.push(c);
        }
        if (stk.empty())
            answer++;
    }
    return answer;
}