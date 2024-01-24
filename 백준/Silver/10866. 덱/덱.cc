#include <iostream>
#include <deque>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  deque<int>  deq;

  int N;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    string cmd;
    int n;

    cin >> cmd;
    if (cmd == "push_back")
    {
      cin >> n;
      deq.push_back(n);
    }
    else if (cmd == "push_front")
    {
      cin >> n;
      deq.push_front(n);
    }
    else if (cmd == "pop_front")
    {
      if (deq.empty())
        cout << -1 << "\n";
      else 
      {
        cout << deq.front() << "\n";
        deq.pop_front();
      }
    }
    else if (cmd == "pop_back")
    {
      if (deq.empty())
        cout << -1 << "\n";
      else 
      {
        cout << deq.back() << "\n";
        deq.pop_back();
      }
    }
    else if (cmd == "size")
      cout << deq.size() << "\n";
    else if (cmd == "empty")
      cout << (deq.empty() ? 1 : 0) << "\n";
    else if (cmd == "front")
      cout << (deq.empty() ? -1 : deq.front()) << "\n";
    else if (cmd == "back")
      cout << (deq.empty() ? -1 : deq.back()) << "\n";
  }
}