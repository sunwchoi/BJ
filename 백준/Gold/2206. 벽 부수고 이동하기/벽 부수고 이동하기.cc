#include <iostream>
#include <queue>

using namespace std;

int N, M;
string input[1000];
bool vi[1000][1000][2];
queue<long long> pq;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

long long encode(long long n, long long y, long long x)
{
    return (n << 20) | (y << 10) | x;
}

void decode(long long k, long long& n, long long& y, long long& x)
{
    long long nBit = 0b0111111111111111111111111111111111111111111100000000000000000000;
    long long yBit = 0b0000000000000000000000000000000000000000000011111111110000000000;
    long long xBit = 0b0000000000000000000000000000000000000000000000000000001111111111;

    n = (k & nBit) >> 20;
    y = (k & yBit) >> 10;
    x = k & xBit;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> input[i];

    long long ans = -1;
    pq.push(encode(0, 0, 0));
    while (pq.empty() == false)
    {
        long long k = pq.front();
        long long sign = k >= 0 ? 1 : -1;
        long long n = 0;
        long long y = 0;
        long long x = 0;

        decode(k * sign, n, y, x);
        pq.pop();

        if (y == N - 1 && x == M - 1)
        {
            if (ans == -1)
                ans = n + 1;
            else
                ans = min(n + 1, ans);
        }

        bool& visit = k >= 0 ? vi[y][x][0] : vi[y][x][1];

        if (visit == true)
            continue;
        visit = true;

        for (int i = 0; i < 4; i++)
        {
            long long nextY = y + dir[i][0];
            long long nextX = x + dir[i][1];

            if ((0 <= nextY && nextY < N && 0 <= nextX && nextX < M) == false)
                continue;

            if (input[nextY][nextX] == '1')
            {
                if (k < 0)
                    continue;
                pq.push(-1 * encode(n + 1, nextY, nextX));

            }
            else
                pq.push(sign * encode(n + 1, nextY, nextX));
        }
    }

    cout << ans << "\n";
}
