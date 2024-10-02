#include <iostream>
#include <vector>

using namespace std;

vector<int> tr;
int N, A, B;
int ans;

int sq(int num)
{
    if (num == 0)
        return 0;
    return 1 + sq(num / 2);    
}

bool f(int idx)
{
    if (tr.size() <= idx)
        return false;
    if (tr[idx] == A || tr[idx] == B)
        return true;

    bool l = f(idx * 2), r = f(idx * 2 + 1);
    if (l && r)
    {
        ans = sq(N) - sq(idx);
        return false;
    }
    else if (l || r)
        return true;
    return false;
}

int solution(int n, int a, int b)
{
    N = n, A = a, B = b;
    tr = vector<int>(n * 2);
    
    for (int i = 0; i < n; i++)
        tr[n * 2 - i - 1] = n - i;
    f(1);
    
    return ans;
}