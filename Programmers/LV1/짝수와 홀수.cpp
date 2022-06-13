#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    answer = (num % 2 == 0) ? "Even" : "Odd";
    return answer;
}