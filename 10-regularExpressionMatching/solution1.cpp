#include <iostream>
using namespace std;

//HARD
class Solution {
public:
    bool isMatch(const char* s, const char* p) {
        if(*p == '\0') return *s == '\0';

        if(*(p+1) != '*') {
            if(*p == *s || (*p == '.' && *s != '\0')){
                return isMatch(s+1, p+1) ;
            }
            else
                return false;
        }
        else {
            while(*p == *s || (*p == '.' && *s != '\0')) {
                if(this->isMatch(s, p+2))
                    return true;
                s++;
            }
            return this->isMatch(s, p+2);
        }
    }

    bool isMatch(string s, string p) {
        return this->isMatch(s.c_str(), p.c_str());
    }
};

int main(int argc, char* argv[]) {
    //string s = "aab";
    //string p = "c*a*b";
    string s = "aaa";
    string p = "a.a";
    cout<<Solution().isMatch(s, p);
}
