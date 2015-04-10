#include <iostream>
#include <string>
#include <map>
#include <memory.h>
#define N 1000
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        bool table[N][N];
        memset(table, 0, sizeof(table));

        string substring = "";
        for(unsigned int i = 0; i < s.size(); i++) {
            table[i][i] = true;
            substring = s.substr(i, 1);
        }
        for(unsigned int i = 0; i < s.size()-1; i++) {
            if(s[i] == s[i+1]) {
                table[i][i+1] = true;
                substring = s.substr(i, 2);
            }
            else {
                table[i][i+1] = false;
            }
        }

        for(unsigned int skip = 2; skip < s.size(); skip++) {
            for(unsigned int i = 0; i+skip < s.size(); i++) {
                if(s[i] == s[i+skip] && table[i+1][i+skip-1]) {
                    table[i][i+skip] = true;
                    if(substring.size() < skip+1) {
                        substring = s.substr(i, skip+1);
                    }
                }
                else {
                    table[i][i+skip] = false;
                }
            }
        }
        return substring;
    }
};
int main(int argc, char* argv[]) {
    //string s = "adaiziguizhongrenergnohziugiziadb";
    string s = "abb";
    cout<<Solution().longestPalindrome(s);
}
