#include <string>
#include <vector>

using namespace std;

vector<int> ryan, apitch, answer;
int prevScore;

bool compare()
{
    for (int i = 10; i >= 0; i--)
    {
        if (ryan[i] > answer[i])
            return true;
        else if (ryan[i] < answer[i])
            return false;
    }
    return true;
}

int getScore()
{
    int aScore = 0, rScore = 0;
    
    for (int i = 0; i < 10; i++)
    {
        if (ryan[i] > apitch[i])
            rScore += 10 - i;
        else if (ryan[i] < apitch[i])
            aScore += 10 - i;
        else if (ryan[i] == apitch[i] && ryan[i] != 0)
            aScore += 10 - i;
    }
    
    return rScore - aScore;
}

void f(int n, int idx)
{
    if (n == 0 || idx == 11)
    {
        int res = getScore();
        if (res > 0 && 
                (res > prevScore || 
                 (res == prevScore && compare())))
        {
            prevScore = res;
            answer = ryan;
        }
        return ;
    }
    
    for (int i = 0; i <= n; i++)
    {
        ryan[idx] = i;
        f(n - i, idx + 1);
    }
    ryan[idx] = 0;
}

vector<int> solution(int n, vector<int> info) {
    apitch = info;
    ryan.resize(11);
    answer = {-1};
    
    f(n, 0);
    
    return answer;
}