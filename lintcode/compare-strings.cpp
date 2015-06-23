#include <iostream>
#include <assert.h>

#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        int alphabet[26] = {0};
        for (string::iterator i = A.begin(); i != A.end(); i++) {
           alphabet[*i - 'A']++;
        }

        for (string::iterator j = B.begin(); j != B.end(); j++) {
            if (alphabet[*j - 'A'] == 0)
                return false;
            else
                alphabet[*j - 'A']--;
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    assert(Solution().compareStrings("ABCD", "ACD") == true);
    assert(Solution().compareStrings("ABCD", "AABC") == false);
    assert(Solution().compareStrings("", "") == true);
    assert(Solution().compareStrings("A", "") == true);
    assert(Solution().compareStrings("", "A") == false);
}
