#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> viCol;
vector<bool> viRise;
vector<bool> viDown;

int answer;

void nQueen(int x, int y, int n)
{
    if (viCol[x] || viRise[x + y] || viDown[x - y + n - 1])
        return ;
    if (y == n - 1)
    {
        answer++;
        return ;
    }

    viCol[x] = true;
    viRise[x + y] = true;
    viDown[x - y + n - 1] = true;
    for (int i = 0; i < n; i++)
    {
        nQueen(i, y + 1, n);
    }
    viCol[x] = false;
    viRise[x + y] = false;
    viDown[x - y + n - 1] = false;
}

int solution(int n) {

    viCol.resize(n);
    viRise.resize(2 * n - 1);
    viDown.resize(2 * n - 1);
    
    for (int i = 0; i < n; i++)
        nQueen(i, 0, n);
    
    return answer;
}