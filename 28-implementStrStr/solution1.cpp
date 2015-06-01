#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLength = (int)haystack.size();
        int needleLength = (int)needle.size();

        for(int i = 0; i < haystackLength - needleLength + 1; i++) {
            cout<<"!";
            bool flag = true;
            for(int j = 0; j < needleLength; j++) {
                if(haystack[i+j] != needle[j]) {
                    flag = false;
                    break;
                }
            }

            if(flag)
                return i;
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    string haystack = "abb";
    string needle = "abaab";
    //string haystack = "abcdcdefg";
    //string needle = "cde";

    cout<<Solution().strStr(haystack, needle);
}
