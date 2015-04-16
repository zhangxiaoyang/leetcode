#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        string romans[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        for(int i = 0; i < 13; ) {
            if(num >= values[i]) {
                result += romans[i];
                num -= values[i];
                continue;
            }

            i++;
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    cout<<Solution().intToRoman(8);
}
