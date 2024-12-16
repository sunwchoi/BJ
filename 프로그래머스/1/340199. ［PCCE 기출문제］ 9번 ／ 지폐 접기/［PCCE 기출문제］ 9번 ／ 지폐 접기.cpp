#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    if (bill[0] > bill[1])
        swap(bill[0], bill[1]);
    if (wallet[0] > wallet[1])
        swap(wallet[0], wallet[1]);
    
    while(wallet[0] < bill[0] || wallet[1] < bill[1])
    {
        bill[1] /= 2;
        answer++;
        if (bill[0] > bill[1])
            swap(bill[0], bill[1]);
    }
    
    return answer;
}