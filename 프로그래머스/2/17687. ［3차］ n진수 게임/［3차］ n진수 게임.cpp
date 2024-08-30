#include <string>
#include <vector>

using namespace std;

string answer = "";
string D = "0123456789ABCDEF";
int cnt = 0;
int N, M, T, P;

void f(int num)
{
    if (num == 0)
        return ;
    
    f(num / N);
    if (answer.size() >= T)
        return ;
    cnt++;
    if (cnt % M + 1 == P)    
        answer += D[num % N];
}

string solution(int n, int t, int m, int p) {

    N = n;
    M = m;
    T = t;
    P = p;
    
    if (p == 1)
        answer += "0";
    for (int i = 1; answer.size() < t; i++)
        f(i);
    return answer;
}