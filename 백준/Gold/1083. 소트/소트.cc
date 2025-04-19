#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N, S;
int arr[50];
map<int, int, greater<int>> idxMap;

void swp(int& left, int& right)
{
    idxMap[left]++;

    int tmp = left;
    
    left = right;
    right = tmp;
    
    if (--S == 0)
    {
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        exit(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        idxMap.insert({ arr[i], i });
    }
    cin >> S;

    int fix = 0;
    while (idxMap.empty() == false)
    {
        int idx = -1;
        for (auto it = idxMap.begin(); it != idxMap.end(); it++)
        {
            if (it->second - fix <= S)
            {
                idx = it->second;
                idxMap.erase(it->first);
                break;
            }
        }

        for (int i = idx; i > fix; i--)
            swp(arr[i - 1], arr[i]);
        fix++;
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

}
