#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    
    sort(num.begin(), num.end(), std::greater());
    
    for (int i = 0; i < num.size(); i++)
    {
        answer = answer * 10 + num[i];    
    }
    
    return answer;
}