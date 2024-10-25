#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

int toInt(string& s)
{
    int ret = 0;
    for(int i = 0; i < s.length(); i++)
    {
        ret = 10 * ret + s[i] - '0';
    }
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size());
    unordered_map<string, vector<int>> table;
    
    stringstream ss;
    string tmp;
    string key;
    for (int i = 0; i < info.size(); i++)
    {
        ss.str(info[i]);
        ss.clear();
        key.clear();
        while (ss >> tmp)
        {
            if ('0' <= tmp[0] && tmp[0] <= '9')
                table[key].push_back(toInt(tmp));
            else
                key += tmp[0];
        }
    }
    
    for (auto it = table.begin(); it != table.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
    }
    
    
    vector<vector<string>> queryTable = {
        {"c", "j", "p"},
        {"b", "f"},
        {"j", "s"},
        {"c", "p"}
    };
    
    for (int i = 0; i < query.size(); i++)
    {
        stringstream ss(query[i]);
        string tmp;
        vector<string> keys;
        keys.reserve(100);
        int col = 0;    
        
        while (ss >> tmp)
        {
            if ('0' <= tmp[0] && tmp[0] <= '9')
            {
                int limit = toInt(tmp);
                
                for (int j = 0; j < keys.size(); j++)
                {
                    auto it = lower_bound(table[keys[j]].begin(), table[keys[j]].end(), limit);
                    if (it != table[keys[j]].end())
                    {
                        answer[i] += table[keys[j]].size() - std::distance(table[keys[j]].begin(), it);
                    }
                }
            }
            else if (tmp == "-")
            {
                if (keys.empty())
                {
                    keys.push_back("");
                }
                size_t n = keys.size();
                for (int j = 0; j < n; j++)
                {
                    for (int k = 1; k < queryTable[col].size(); k++)
                    {
                        keys.push_back(keys[j]);
                        keys.back() += queryTable[col][k];
                    }
                    keys[j] += queryTable[col][0];
                    
                }
                col++;
            }
            else if (tmp != "and")
            {
                if (keys.empty())
                {
                    keys.push_back("");
                }
                for (int j = 0; j < keys.size(); j++)
                {
                    keys[j] += tmp[0];
                }
                col++;
            }
        }
        
    }
    
    return answer ;
}