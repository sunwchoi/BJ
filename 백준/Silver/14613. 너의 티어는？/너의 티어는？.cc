#include <iostream>

using namespace std;

double w, d, l;
unsigned long long fac[21];
double ranks[5];

double sq(double base, int exponent)
{
    double answer = 1;
    for (int i = 0; i < exponent; i++)
        answer *= base;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 20; i++)
        fac[i] = fac[i - 1] * i;

    cin >> w >> l >> d;
    
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 20 - i; j++)
        {
            int k = 20 - i - j;
            double rate = sq(w, i) * sq(l, j) * sq(d, k);
            rate *= (fac[20] / (fac[i] * fac[j] * fac[k]));
            int score = 2000 + 50 * i - 50 * j;
            ranks[score / 500 - 2] += rate;
        }
    }

    cout << fixed;
    cout.precision(8);
    for (int i = 0; i < 5; i++)
        cout << ranks[i] << "\n";

}