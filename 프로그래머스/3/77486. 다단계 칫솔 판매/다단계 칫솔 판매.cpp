#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>



using namespace std;

unordered_map<string, string> graph;
unordered_map<string, int> result;

void f(const string& name, int money)
{
    if (money >= 10)
        result[name] += money - money / 10;
    else
    {
        result[name] += money;
        return;        
    }
    if (graph[name] != "-")
        f(graph[name], money / 10);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    
    for (int i = 0; i < enroll.size(); i++)
    {
        graph[enroll[i]] = referral[i];
    }
    for (int i = 0; i < seller.size(); i++)
    {
        f(seller[i], amount[i] * 100);
    }
    for (int i = 0; i < enroll.size(); i++)
        answer[i] = result[enroll[i]];
    
    return answer;
}