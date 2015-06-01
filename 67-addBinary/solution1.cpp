#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string::iterator i = a.end() - 1;
        string::iterator j = b.end() - 1;
        string s = "";

        bool carry = false;

        while(i >= a.begin() || j >= b.begin()) {
            char num1 = i >= a.begin() ? *i : '0';
            char num2 = j >= b.begin() ? *j : '0';

            if(carry) {
                int tmp = num1 - '0' + num2 - '0' + (int)carry;

                carry = tmp >= 2 ? true : false;
                s += tmp % 2 + '0';
            }
            else {
                if(num1 == '1' && num2 == '1') {
                    carry = true;
                    s += '0';
                }
                else s += num1 + num2 - '0';
            }

            i--;
            j--;
        }

        if(carry) s += '1';
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(int argc, char* argv[]) {
    string a = "11";
    string b = "1";
    cout<<Solution().addBinary(a, b);
}
