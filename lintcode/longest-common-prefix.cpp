#include <iostream>
#include <assert.h>

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";

        string prefix = "";
        for (int i = 0; i < (int)strs[0].size(); i++) {
            for (int j = 1; j < (int)strs.size(); j++) {
                if (strs[0][i] != strs[j][i])
                    return prefix;
            }
            prefix += strs[0][i];
        }

        return prefix;
    }
};

int main(int argc, char* argv[]) {
    vector<string> strs;
    strs.push_back("ABCD");
    strs.push_back("ABEF");
    strs.push_back("ACEF");
    assert(Solution().longestCommonPrefix(strs) == "A");
}
