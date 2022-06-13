#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if (a > b)
    {
        int num = 0;
        num = b;
        b = a;
        a = num;
    }
    
    for (int i = a; i <= b; i++)
    {
        answer += i;
    }
    
    return answer;
}