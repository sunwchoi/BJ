#include <iostream>
#include <vector>

using namespace std;

int N, M;
int table[8][8];
vector<pair<int,int>> virus;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int area;
int answer;

void simul(int idx, int jdx)
{
	for (int i = 0; i < 4; i++)
	{
        int nextIdx = idx + dir[i][0];
        int nextJdx = jdx + dir[i][1];

        if ((0 <= nextIdx && nextIdx < N && 0 <= nextJdx && nextJdx < M) == false)
            continue;
            
		if (table[nextIdx][nextJdx] == 0)
		{
            table[nextIdx][nextJdx] = -1;
            simul(nextIdx, nextJdx);
		}
	}
}

void calculate()
{
    for (int i = 0; i < virus.size(); i++)
        simul(virus[i].first, virus[i].second);

    int output[8][8];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
                output[i][j] = table[i][j];
        }
    }

    int virusArea = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (table[i][j] == -1)
            {
                table[i][j] = 0;
                virusArea++;
            }
        }
    }

    answer = max(answer, area - virusArea);
}

void build(int Idx, int Jdx, int n)
{
    if (table[Idx][Jdx])
        return;

    table[Idx][Jdx] = 1;
    n++;
    if (n == 3)
    {
        calculate();
        table[Idx][Jdx] = 0;
        n--;
        return;
    }

    for (int i = Idx; i < N; i++)
    {
        for (int j = (i != Idx ? 0 : Jdx + 1); j < M; j++)
        	build(i, j, n);
    }

    table[Idx][Jdx] = 0;
    n--;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> table[i][j];
            if (table[i][j] == 0)
                area++;
            else if (table[i][j] == 2)
                virus.emplace_back(i, j);
        }
    }

    area -= 3;

    for (int i = 0; i < N; i++)
    {
        
        for (int j = 0; j < M; j++)
        {
        	build(i, j, 0);
        }
    }

    cout << answer << "\n";
}
