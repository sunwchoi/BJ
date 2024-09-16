#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int len = 100001;
vector<bool> vi(len);
priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;



int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    pq.push(make_pair(0, N));
    while(pq.top().second != K) {
        int t = pq.top().first;
        int n = pq.top().second;
        vi[n] = true;
        pq.pop();

        for (int i = n * 2; i < len; i *= 2) {
            if (vi[i])
                break;
            vi[i] = true;
            pq.push(make_pair(t, i));
        }
        if (n > 0 && !vi[n - 1]) {
            pq.push(make_pair(t + 1, n - 1));
        }
        if (n < len - 1 && !vi[n + 1]) {
            pq.push(make_pair(t + 1, n + 1));
        }
    }

    cout << pq.top().first << "\n";
    return 0;
}