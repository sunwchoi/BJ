#include <string>
#include <unordered_map>
#include <iostream>


using namespace std;


void preprocess(string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] += 'A' - 'a';
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, pair<int, int>> mp;

    preprocess(str1);
    preprocess(str2);
    
    for (int i = 1; i < str1.length(); i++)
    {
        if ('A' <= str1[i] && str1[i] <= 'Z' &&
            'A' <= str1[i - 1] && str1[i - 1] <= 'Z')
        {
            string tmp = str1.substr(i - 1, 2);
            mp[tmp].first++;        
        }   
    }
    
    for (int i = 1; i < str2.length(); i++)
    {
        if ('A' <= str2[i] && str2[i] <= 'Z' &&
            'A' <= str2[i - 1] && str2[i - 1] <= 'Z')
        {
            string tmp = str2.substr(i - 1, 2);
            mp[tmp].second++;        
        }
    }
    
    int num = 0;
    int denum = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
        auto nde = it->second;
        
        num += min(nde.first, nde.second);
        denum += max(nde.first, nde.second);
    }
    
    cout << num << "\n";
    cout << denum << "\n";
    return denum ? num * 65536 / denum : 65536;
}