#include <iostream>
#include <deque>

using namespace std;

int N, parent, erase;
deque<int> child[50];

int leaf(int nde)
{
    if (nde == erase)
        return 0;

    int ret = 0;
    for (int i = 0; i < child[nde].size(); i++)
        ret += leaf(child[nde][i]);

    return ret ? ret : 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        if (tmp == -1)
            parent = i;
        else
            child[tmp].push_back(i);
    }
    cin >> erase;

    cout << leaf(parent) << "\n";
}