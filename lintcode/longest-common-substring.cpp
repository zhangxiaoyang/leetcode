#include <iostream>
#include <assert.h>

#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int maxLen = 0;
        int ALen = (int)A.size();
        int BLen = (int)B.size();

        for (int i = 0; i < ALen; i++) {
            for (int j = 0; j < BLen; j++) {
                int len = 0;
                while (i+len < ALen && j+len < BLen
                    && A[i+len] == B[j+len]) {
                    len++;
                }

                if (len > maxLen)
                    maxLen = len;
            }
        }

        return maxLen;
    }
};

int main(int argc, char* argv[]) {
    string A, B;
    assert(Solution().longestCommonSubstring(A, B) == 0);

    A = "ABCD";
    B = "CBCE";
    assert(Solution().longestCommonSubstring(A, B) == 2);

    A = "ABCD";
    B = "";
    assert(Solution().longestCommonSubstring(A, B) == 0);
    cout<<"A";
}
