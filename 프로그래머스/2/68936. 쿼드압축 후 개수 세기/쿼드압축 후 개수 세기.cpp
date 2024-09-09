#include <string>
#include <vector>

using namespace std;
vector<int> answer(2);

void f(int x, int y, int len, vector<vector<int>>& arr)
{
    bool pass = true;
    
    for (int i = x; i < x + len; i++)
    {
        for (int j = y; j < y + len; j++)
        {
            if (arr[i][j] != arr[x][y])
            {
                pass = false;
                break;
            }
        }
    }
    if (pass)
        answer[arr[x][y]]++;
    else
    {
        len /= 2;
        f(x, y, len, arr);
        f(x + len, y, len, arr);
        f(x, y + len, len, arr);
        f(x + len, y + len, len, arr);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    
    f(0, 0, arr.size(), arr);
    return answer;
}