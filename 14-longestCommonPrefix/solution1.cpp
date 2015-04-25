#include <iostream>
#include <vector>
#include <limits.h>
#define UINT unsigned int
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        if(!strs.size()) return prefix;

        int index = -1;
        UINT size = INT_MAX;

        for(UINT i = 0; i < strs.size(); i++) {
            if(strs[i].size() < size) {
                size = strs[i].size();
                index = i;
            }
        }

        for(UINT i = 0; i < strs[index].size(); i++) {
            for(UINT j = 0; j < strs.size(); j++) {
                if(strs[j][i] != strs[index][i]) {
                    return prefix;
                }
            }
            prefix += strs[index][i];
        }
        
        return prefix;
    }
};

int main(int argc, char* argv[]) {
    vector<string> strs;
    /*
    strs.push_back("abcd");
    strs.push_back("abed");
    strs.push_back("a");
    strs.push_back("abcdefg");
    */

    cout<<Solution().longestCommonPrefix(strs);
    return 0;
}
