#include <iostream>
#include <climits>

using namespace std;

int N, M, B;
int arr[500][500];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> B;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> arr[i][j];

  int min = INT_MAX;
  int hgt = 0;
  for (int i = 0; i <= 256; i++)
  {
    int time = 0;
    long stg = B;
    for (int j = 0; j < N; j++)
      for (int k = 0; k < M; k++)
      {
        if (arr[j][k] > i)
        {
          time += 2*(arr[j][k] - i);
          stg += arr[j][k] - i;
        }
        else if (arr[j][k] < i)
        {
          time += i - arr[j][k];
          stg -= i - arr[j][k];
        }
      }
    if (stg >= 0 && time <= min)
    {
      min = time;
      hgt = i;
    }
  }
  cout << min << " " << hgt << "\n";
}