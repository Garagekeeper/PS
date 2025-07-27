#include <string>
#include <vector>

using namespace std;
int deci2biCnt = 0;
string Deci2bi(int n)
{
    string binary ="";
    while(n != 0)
    {
        binary += (n % 2) +'0';
        n /= 2;
    }
    
    string res = string(binary.rbegin(), binary.rend());
    deci2biCnt++;
    return res;
}

vector<int> solution(string s) 
{
    vector<int> answer;
    string currStr = s;
    int cnt = 0;
    while(true)
    {
        if (currStr == "1") break;

        string temp = "";  
        for (auto& e : currStr)
        {
            if (e != '0') temp+=e;
            else cnt++;
        }
        currStr = Deci2bi(temp.size());
    }
    return {deci2biCnt, cnt};
}