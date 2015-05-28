#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(char c) {
        return (c >= '0' && c <= '9')
            || (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            ? true : false;
    }

    char toLower(char c) {
        if(c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        return c;
    }

    bool isPalindrome(string s) {
        int length = s.size();
        if(length < 2) return true;

        char* p = &s[0];
        char* q = &s[length-1];

        while(p < q) {
            if(!isValid(*p)) {
                p++;
                continue;
            }
            if(!isValid(*q)) {
                q--;
                continue;
            }

            if(toLower(*p) == toLower(*q)) {
                p++;
                q--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    string s = "A man, a plan, a canal: Panama";
    cout<<Solution().isPalindrome("abba");
}
