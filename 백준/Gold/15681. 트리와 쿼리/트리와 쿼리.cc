#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<deque<int>> tr;
vector<bool> vi;
vector<int> cnt;

int traversal(int nde) {

    cnt[nde] = 1;
    vi[nde] = true;
    for (int i = 0; i < tr[nde].size(); i++) {
        if (!vi[tr[nde][i]]) {
            cnt[nde] += traversal(tr[nde][i]);
        }
    }

    return cnt[nde];
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R >> Q;
    tr.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;

        cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }

    vi.resize(N + 1);
    cnt.resize(N + 1);
    traversal(R);

    for (int i = 0; i < Q; i++) {
        int u;

        cin >> u;
        cout << cnt[u] << "\n";
    }

    return 0;
}