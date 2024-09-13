#include <deque>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M, start, goal, ans;
vector<deque<pair<int, int>>> gp(1001);
vector<long long> d(1001, LLONG_MAX);
vector<bool> vi(1001);

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        gp[x -  1].push_back(make_pair(y - 1, d));
    }
    cin >> start >> goal;

    d[start - 1] = 0;
    for (int i = 0; i < N; i++) {
        int nde = -1;
        for (int j = 0; j < N; j++) {
            if (vi[j] || d[j] == LLONG_MAX)
                continue;
            if (nde == -1)
                nde = j;
            else if (d[j] < d[nde])
                nde = j;
        }
        if (nde == -1)
            break;
        vi[nde] = true;
        for (int j = 0; j < gp[nde].size(); j++) {
            int next_nde = gp[nde][j].first;
            long long next_d = gp[nde][j].second;

            d[next_nde] = min(d[next_nde], d[nde] + next_d);
        }
    }

    cout << d[goal - 1] << "\n";
    return 0;
}