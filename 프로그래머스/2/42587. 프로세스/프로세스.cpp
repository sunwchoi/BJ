#include <string>
#include <vector>
#include <queue>

using namespace std;

int p[10];

bool exc(int idx, vector<int>& priorities)
{
    for (int i = 9; i > priorities[idx]; i--)
    {
        if (p[i])
            return false;
    }
    return true;
}

int solution(vector<int> priorities, int location) {
    queue<int> q;
    int answer = 0;

    for (int i = 0; i < priorities.size(); i++)
    {
        p[priorities[i]]++;
        q.push(i);
    }

    while (q.size())
    {
        int idx = q.front();
        q.pop();
        if (!exc(idx, priorities))
            q.push(idx);
        else if (idx == location)
            return answer + 1;
        else
        {
            p[priorities[idx]]--;
            answer++;
        }
    }
    
    return answer;
}