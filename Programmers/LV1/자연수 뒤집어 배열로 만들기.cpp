#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n)
    {
        answer.push_back(n % 10);
        // 맨뒤에 요소 삽입
        n /= 10;
    }
    
    return answer;
}
