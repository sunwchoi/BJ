#include <iostream>

using namespace std;

unsigned long long   A, B, C;

unsigned long long  f(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return A % C;
    unsigned long long tmp = f(n/2);
    return n % 2 ? ((tmp * tmp)%C * (A%C)) % C : (tmp * tmp) % C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    cout << f(B) << "\n";
}