#include <iostream>
#include <vector>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  std::vector<std::pair<int, int> > body(N);
  std::vector<int> order(N);

  for (int i = 0; i < N; i++)
  {
    cin >> body[i].first >> body[i].second;
    for (int j = 0; j < i; j++)
    {
      if (body[j].first > body[i].first && body[j].second > body[i].second)
        order[i]++;
      else if (body[j].first < body[i].first && body[j].second < body[i].second)
        order[j]++;
    }
  }
  for (int i = 0; i < N; i++)
  cout << order[i] + 1 << "\n";
}