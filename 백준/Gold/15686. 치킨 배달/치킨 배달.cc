#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;

vector<bool> selected(13);
vector<pair<int, int>> house;
vector<pair<int, int>> chiken;
vector<vector<pair<int, int>>> dist;
int ans = INT_MAX;

void getAnswer() {
    int cur_ans = 0;

    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist[i].size(); j++) {
            int d = dist[i][j].first;
            int m = dist[i][j].second;
            if (selected[m]) {
                cur_ans += d;
                break ;
            }
        }
    }

    ans = min(cur_ans, ans);
}

void selectM(int idx, int cnt) {
    if (cnt == M) {
        getAnswer();
        return ;
    }

    for (int i = idx + 1; i < chiken.size(); i++) {
        selected[i] = true;
        selectM(i, cnt + 1);
        selected[i] = false;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int id;
            cin >> id;
            if (id == 1) {
                house.push_back(make_pair(i, j));
            }
            if (id == 2) {
                chiken.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < house.size(); i++) {
        dist.push_back(vector<pair<int, int>>());
        for (int j = 0; j < chiken.size(); j++) {
            int d = abs(house[i].first - chiken[j].first) + abs(house[i].second - chiken[j].second);
            dist[i].push_back(make_pair(d, j));
        }
        sort(dist[i].begin(), dist[i].end());
    }

    selectM(-1, 0);

    cout << ans << "\n";

    return 0;
}