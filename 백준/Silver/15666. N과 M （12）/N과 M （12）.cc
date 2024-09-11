#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<int> cur;
set<vector<int>> ans;

void f(int idx) {
    if (cur.size() == M) {
        ans.insert(cur);
        return ;
    }

    for (int i = idx; i < N; i++) {
        cur.push_back(arr[i]);
        f(i);
        cur.pop_back();
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    f(0);

    for (auto it = ans.begin(); it != ans.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << " ";
        }
        cout << "\n";
    }

    return 0;
}