#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_set<string> uset;
    
    for (int i = 0; i < phone_book.size(); i++)
    {
        uset.insert(phone_book[i]);
    }
    
    for (int i=0; i < phone_book.size(); i++)
    {
        string temp;
        for (int j =0; j < phone_book[i].size(); j++)
        {   
            temp += phone_book[i][j];
            if ((uset.find(temp) != uset.end()) && (temp != phone_book[i]))
                return false;
        }
    }
    
    return answer;
}