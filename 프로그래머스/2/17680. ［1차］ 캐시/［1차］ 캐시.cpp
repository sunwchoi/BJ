#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void toLow(string& s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] += 'a' - 'A';
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    deque<string>::iterator it;
    
    for (int i = 0; i < cities.size(); i++)
    {
        toLow(cities[i]);
        if ((it = find(cache.begin(), cache.end(), cities[i])) == cache.end())
            answer += 5;
        else
        {
            answer++;
            cache.erase(it);            
        }
        cache.push_back(cities[i]);
        if (cache.size() > cacheSize)
            cache.pop_front();
    }
    
    return answer;
}