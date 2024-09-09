#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<vector<int>, int> mp;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    if (a[1] > b[1])
        return true;
    if (b[1] > a[1])
        return false;
    if (a[0] < b[0])
        return true;
    return false;
}

int GetLeftChild(int idx, int mn, int x, int y, vector<vector<int>>& tr)
{
    while (idx < tr.size())
    {
        if (tr[idx][1] < y)
        {
            if (mn < tr[idx][0] && tr[idx][0] < x)
                return idx;          
        }
        ++idx;
    }
    return -1;
}

int GetRightChild(int idx, int mx, int x, int y, vector<vector<int>>& tr)
{
    while (idx < tr.size())
    {
        if (tr[idx][1] < y)
        {
            if (x < tr[idx][0] && tr[idx][0] < mx)
                return idx;
        }
        ++idx;
    }
    return -1;
}


void iter(int idx, int mx, int mn, vector<vector<int>>& tr, vector<vector<int>>& answer)
{
    answer[0].push_back(mp[tr[idx]]);
    int x = tr[idx][0];
    int y = tr[idx][1];
    int child = GetLeftChild(idx + 1, mn, x, y, tr);
    if (child >= 0)
        iter(child, x, mn, tr, answer);
    child = GetRightChild(idx + 1, mx, x, y, tr);
    if (child >= 0)
        iter(child, mx, x, tr, answer);
    answer[1].push_back(mp[tr[idx]]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);

    for (int i = 0; i < nodeinfo.size(); i++)
        mp[nodeinfo[i]] = i + 1;
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);

    iter(0, 100001, -1, nodeinfo, answer);
    return answer ;
}