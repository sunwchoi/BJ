#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
  int n;
  cin >> n;
  vector<int> op(n);

  if (n == 0)
  {
    cout << "0\n";
    return 0;
  }

  for (int i = 0; i < n; i++)
    cin >> op[i];
  sort(op.begin(), op.end());
  int cut = round(double(0.15) * n);
  int sum = 0;
  for (int i = cut; i < n - cut; i++)
    sum += op[i];
  cout << round((double)sum / (n - 2 * cut)) << "\n";
}