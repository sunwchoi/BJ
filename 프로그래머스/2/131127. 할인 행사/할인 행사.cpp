#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int cnt = 0;
    int answer = 0;
    unordered_map<string, int> mp;
    
    for (int i = 0; i < want.size(); i++)
    {
        mp[want[i]] = number[i];
    }
    
    for (int i = 0; i < discount.size(); i++)
    {
        if (mp.find(discount[i]) != mp.end())
        {
            if (--mp[discount[i]] == 0)
                cnt++;   
        }
        if (i >= 10)
        {
            if (mp.find(discount[i - 10]) != mp.end())
            {
                if (mp[discount[i - 10]]++ == 0)
                    cnt--;
            }
        }
        if (cnt == want.size())
            answer++;
    }
    
    return answer;
}