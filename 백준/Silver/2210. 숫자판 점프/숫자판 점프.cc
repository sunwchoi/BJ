#include <iostream>
#include <set>

using namespace std;

set<int> numberSet;
int digitTable[5][5];
int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

bool isValid(int n)
{
    return 0 <= n && n < 5;
}

bool isValid(int x, int y)
{
    return isValid(x) && isValid(y);
}

void f(int x, int y, int remain, int number)
{
    number = 10 * number + digitTable[x][y];
    remain--;

    if (remain == 0)
    {
        numberSet.insert(number);
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        int nX = x + dir[i][0];
        int nY = y + dir[i][1];

        if (isValid(nX, nY))
            f(nX, nY, remain, number);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> digitTable[i][j];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            f(i, j, 6, 0);
        }
    }

    cout << numberSet.size() << "\n";
}