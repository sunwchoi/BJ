#include <iostream>

using namespace std;

int N, K;

int plusBit(int n)
{
    int ret = 1;
    for (; ret != (ret & n); ret = ret << 1)
        ;

    return ret;
}

int countBit(int n)
{    
    int ret = 0;
    for ( ; n; n = n >> 1)
    {
        if (1 == (1 & n))
            ret++;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    
    int answer = 0;
    while (countBit(N + answer) > K)
        answer += plusBit(N + answer);

    cout << answer << "\n";
}