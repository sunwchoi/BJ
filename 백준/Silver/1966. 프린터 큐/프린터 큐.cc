#include <iostream>
#include <queue>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    int N, M;
    cin >> N >> M;
    queue<pair<int, bool> > que;
    for (int j = 0; j < N; j++)
    {
      int tmp;
      cin >> tmp;
      que.push(make_pair(tmp, j == M ? true : false));
    }
    int ret = 1;
    for (int j = 0; j < N; j++)
    {
      int max = 0;
      for (int k = 0; k < que.size(); k++)
      {
        max = (que.front().first > max ? que.front().first : max);
        que.push(que.front());
        que.pop();
      }
      for (int k = 0; k < que.size(); k++)
      {
        if (que.front().first == max)
          break; 
        que.push(que.front());
        que.pop();
      }
      if (que.front().second) break;
      ret++;
      que.pop();
    }
    cout << ret << "\n";
  }
}