#include <iostream>
#include <deque>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  deque<int> cur, seed;
  deque<bool> out;

  for (int i = 1; i <= n; i++)
    seed.push_back(i);

  for (int i = 0; i < n; i++)
  {
    int in;
    cin >> in;
    while (!seed.empty() && seed.front() <= in)
    {
      cur.push_back(seed.front());
      seed.pop_front();
      out.push_back(true);
    }
    if (cur.empty() || cur.back() < in)
    {
      cout << "NO\n";
      exit(0);
    }
    while (!cur.empty() && cur.back() >= in)
    {
      cur.pop_back();
      out.push_back(false);
    }
  }
  for (int i = 0; i < n * 2; i++)
    cout << (out[i] ? "+" : "-")<< "\n";
}