#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int N, M;
vector<string> table;
unordered_set<long long> st;
long long mx = -1;

bool isValid(int x, int y)
{
    return 0 <= x && x < M && 0 <= y && y < N;
}

void f(int preX, int preY, int curX, int curY, long long n)
{
    st.insert(n);
    mx = max(mx, n);
    
    if (isValid(curX, curY) == false)
        return;

    int dx = curX - preX;
    int dy = curY - preY;

    f(curX, curY, curX + dx, curY + dy, n * 10 + table[curY][curX] - '0');
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    table = vector<string>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> table[i];
        for (int j = 0; j < M; j++)
        {
            long long n = table[i][j] - '0';
            
            mx = max(mx, n);
            st.insert(n);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                for (int l = 0; l < M; l++)
                {
                    if (k == i && l == j)
                        continue;   

                    f(j, i, l, k, table[i][j] - '0');
                }
            }
        }
    }

    long long answer = -1;
    for (int i = 0 ; i * i <= mx; i++)
    {
        auto it = st.find(i * i);
        if (it != st.end())
            answer = i * i;
    }

    cout << answer << "\n";
}