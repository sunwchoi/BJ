#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<vector<int>> graph;
deque<int> child;
int wolfCnt, sheepCnt, answer;

void f(int nde, vector<int>& info)
{
    if (info[nde])
        wolfCnt++;
    else
        sheepCnt++;
    
    if (sheepCnt == wolfCnt)
    {
        if (info[nde])
            wolfCnt--;
        else
            sheepCnt--;
        return ;
    }
    answer = max(answer, sheepCnt);

    for (int i = 0; i < graph[nde].size(); i++)
        child.push_back(graph[nde][i]);
    
    for (int i = 0; i < child.size(); i++)
    {
        int next_nde = child.front();
        child.pop_front();
        f(next_nde, info);
        child.push_back(next_nde);
    }
    
    for (int i = 0; i < graph[nde].size(); i++)
        child.pop_back();

    if (info[nde])
        wolfCnt--;
    else
        sheepCnt--;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    graph = vector<vector<int>>(info.size());
    
    for (int i = 0; i < edges.size(); i++)
    {
        int p = edges[i][0];
        int c = edges[i][1];
        
        graph[p].push_back(c);
    }
    f(0, info);
    
    return answer;
}