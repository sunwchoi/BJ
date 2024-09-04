#include <string>
#include <unordered_map>

using namespace std;


void f(string& str, unordered_map<string, pair<int, int>>& mp, bool idx)
{
    for (int i = 0; i < str.length(); i++)
    {
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] += 'A' - 'a';
    }
    
    for (int i = 1; i < str.length(); i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z' &&
            'A' <= str[i - 1] && str[i - 1] <= 'Z')
        {
            string tmp = str.substr(i - 1, 2);
            if (!idx)
                mp[tmp].first++;
            else
                mp[tmp].second++;
        }   
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, pair<int, int>> mp;

    f(str1, mp, false);
    f(str2, mp, true);
    
    int num = 0;
    int denum = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        auto nde = it->second;
        
        num += min(nde.first, nde.second);
        denum += max(nde.first, nde.second);
    }
    
    return denum ? num * 65536 / denum : 65536;
}