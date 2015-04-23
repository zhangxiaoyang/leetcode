#include <iostream>
#include <map>
using namespace std;

class Solution {

public:
    int romanToInt(string s) {
        map<string, int> table;
        table["I"] = 1;
        table["V"] = 5;
        table["X"] = 10;
        table["L"] = 50;
        table["C"] = 100;
        table["D"] = 500;
        table["M"] = 1000;
        table["IV"] = 4;
        table["IX"] = 9;
        table["XL"] = 40;
        table["XC"] = 90;
        table["CD"] = 400;
        table["CM"] = 900;

        int number = 0;

        for(int i = s.size()-1; i >= 0; ) {
            if(i-1 >= 0) {
                string key = s.substr(i-1, 2);
                if(table.count(key)) {
                    number += table[key];
                    i -= 2;
                }
                else {
                    number += table[string(&s[i], 1)];
                    i--;
                }
            }
            else {
                number += table[string(&s[i], 1)];
                i--;
            }
        }

        return number;
    }

};

int main(int argc, char* argv[]) {
    cout<<Solution().romanToInt("XIII");
}
