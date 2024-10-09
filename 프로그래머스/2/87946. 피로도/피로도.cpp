#include <string>
#include <vector>

using namespace std;

vector<bool> vi;
int ans = -1;

void f(int idx, int cnt, int k, vector<vector<int>>& dungeons)
{
    ans = max(cnt, ans);
    vi[idx] = true;
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (dungeons[i][0] <= k && !vi[i])
        {
            f(i, cnt + 1, k - dungeons[i][1], dungeons);
        }
    }
    vi[idx] = false;
}

int solution(int k, vector<vector<int>> dungeons) {
    
    vi = vector<bool>(dungeons.size());
    for (int i = 0; i < dungeons.size(); i++)
        if (dungeons[i][0] <= k)
            f(i, 1, k - dungeons[i][1], dungeons);
        
    return ans;
}