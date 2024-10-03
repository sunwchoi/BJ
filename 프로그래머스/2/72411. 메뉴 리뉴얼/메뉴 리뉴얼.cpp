#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>

using namespace std;

unordered_map<string, int> mp;

void f(const string& src, string str, int idx)
{
    mp[str += src[idx]]++;
    
    for (int i = idx + 1; i < src.length(); i++)
        f(src, str, i);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<int, deque<string>> course_map;
    
    for (int i = 0; i < course.size(); i++)
        course_map[course[i]];
    
    for (int i = 0; i < orders.size(); i++)
        for (int j = 0; j < orders[i].size(); j++)
        {
            sort(orders[i].begin(), orders[i].end());
            f(orders[i], "", j);
        }
    
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        string menu = it->first;
        int appear = it->second;
        if (appear >= 2
            && course_map.find(menu.length()) != course_map.end())
        {
            if (!course_map[menu.length()].empty() && mp[course_map[menu.length()][0]] < appear)
                course_map[menu.length()] = deque<string>();
            if (course_map[menu.length()].empty() ||
                !course_map[menu.length()].empty() && mp[course_map[menu.length()][0]] <= appear)
                course_map[menu.length()].push_back(menu);
        }
            
    }
    
    for (auto it = course_map.begin(); it != course_map.end(); it++)
    {
        for (int j = 0; j < (it->second).size(); j++)
        {
            answer.push_back((it->second)[j]);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}