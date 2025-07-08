#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const int& a ,const int& b)
{
    string sa = to_string(a);
    string sb = to_string(b);

    return sa + sb > sb + sa;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    
    for (auto& e : numbers)
    {
        if (answer == "0" && e == 0) answer = "0";
        else
            answer += to_string(e);
    }
    return answer;
}