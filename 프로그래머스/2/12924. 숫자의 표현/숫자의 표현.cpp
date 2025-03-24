#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    deque<int> sum;
    
    for (int i = 1; i <= n; i++)
    {
        for (auto it = sum.begin(); it != sum.end(); )
        {
            *it += i;
            if (*it >= n)
            {
                if (*it == n)
                    answer++;
                it = sum.erase(it);
            }
            else
                it++;
        }
        sum.push_back(i);
    }
    return answer + 1;
}