#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    if (s[0] == '\(')
        stk.push(s[0]);
    else 
        return false;
    
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '\)')
        {
            if (stk.size())
                stk.pop();
            else
                return false;
        }
        else
            stk.push(s[i]);
    }

    
    return stk.size() ? false : true;
}