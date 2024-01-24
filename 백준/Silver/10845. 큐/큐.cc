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
    if (cmd == "push")
    {
      cin >> n;
      deq.push_back(n);
    }
    else if (cmd == "pop")
    {
      cout << (deq.empty() ? -1 : deq.front()) << "\n";
      if (!deq.empty()) deq.pop_front();
    }
    else if (cmd == "size")
      cout << deq.size() << "\n";
    else if (cmd == "empty")
      cout << int(deq.empty()) << "\n";
    else if (cmd == "front")
      cout << (deq.empty() ? -1 : deq.front()) << "\n";
    else if (cmd == "back")
      cout << (deq.empty() ? -1 : deq.back()) << "\n";
  }
}