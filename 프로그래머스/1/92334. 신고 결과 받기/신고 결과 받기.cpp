#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    unordered_map<string, int> id_map;
    unordered_map<string, int> picked;
    
    for (int i = 0; i < answer.size(); i++)
    {
        id_map[id_list[i]] = i; 
    }
    
    sort(report.begin(), report.end());
    auto newEnd = unique(report.begin(), report.end());
    
    
    for (auto it = report.begin(); it != newEnd; it++)
    {
        stringstream s(*it);
        string x, y;
        s >> x >> y;
        picked[y]++;
    }
    
    for (auto it = report.begin(); it != newEnd; it++)
    {
        stringstream s(*it);
        string x, y;
        s >> x >> y;
        
        if (picked[y] >= k)
            answer[id_map[x]]++;
    } 
    return answer;
}