#include <iostream>
#include <string>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        string str2;
        long long number = 0;
        int symbol = 0;
        bool flag = true;

        for(unsigned int i = 0; i < str.size(); i++) {
            if(flag && (str[i] == ' ' || str[i] == '\t')) {
                continue;
            }
            flag = false;

            if(str[i] == '+') {
                if(symbol != 0) {
                    return 0;
                }
                symbol = 1;
                continue;
            }

            if(str[i] == '-') {
                if(symbol != 0) {
                    return 0;
                }
                symbol = 2;
                continue;
            }

            if(str[i] < '0' || str[i] > '9') {
                break;
            }
            str2 += str[i];
        }

        if(str2.size() > 10) {
            return symbol == 2 ? MIN_INT : MAX_INT;
        }

        for(unsigned int i = 0 ; i < str2.size(); i++) {
            number = str2[i] - '0' + number*10;
        }
        
        number = symbol == 2 ? -1*number : number;

        if(int(number) == number) {
            return number;
        }
        return symbol == 2 ? MIN_INT : MAX_INT;
    }
};

int main(int argc, char* argv[]) {
    //string s = '9012111111';
    //string s = " -123";
    //string s = "+-123";
    //string s = "123a3";
    //string s = "   +12 1";
    //string s = "-2147483649";
    //string s = "++ 1";
    //string s = "9223372036854775809";
    string s = "-18446744073709551617";
    cout<<Solution().myAtoi(s);
}
