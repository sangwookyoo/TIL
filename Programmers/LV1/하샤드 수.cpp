#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int num = x;
    
    while(num)
    {
        sum += num % 10;
        num /= 10;
    }
    
    x % sum == 0 ? answer = true : answer = false;
    
    return answer;
}