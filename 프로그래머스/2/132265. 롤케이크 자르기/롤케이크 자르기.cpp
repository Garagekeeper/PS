#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<int,int> Amap;
unordered_map<int,int> Bmap;

int solution(vector<int> topping) {
    int answer = 0;
    for (auto& e : topping)
    {
        Bmap[e]++;
        //Bmap.erase(e);
    }

    for (int i=1; i<=topping.size() - 1; i++)
    {
        
        int currentNum = topping[i-1]; 
        if (Bmap[currentNum] == 1) Bmap.erase(currentNum);
        else Bmap[currentNum]--;
        Amap[currentNum];
        if (Amap.size() == Bmap.size()) answer++;
        //cout << Bmap.size() << ", " << Amap.size() << endl;
        
    }
    return answer;
}