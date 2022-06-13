#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    // 정수형 범위 초과
    
    while(n != 1)
    {
        n = n % 2 == 0 ? n / 2 : n * 3 + 1;
        answer++;
        
        if (answer == 500)
        {
            answer = -1;
            break;
        }
    }
    
    return answer;
}