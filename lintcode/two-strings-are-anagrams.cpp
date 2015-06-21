#include <string>
#include <limits.h>
#include <assert.h>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unsigned char statistic[UCHAR_MAX+1] = {0};
        string::iterator i = s.begin();
        string::iterator j = t.begin();
        for (; i != s.end(); i++, j++) {
            statistic[(int)*i]++;
            statistic[(int)*j]--;
        }

        for (int i = 0; i < UCHAR_MAX+1; i++) {
            if (statistic[i] != 0)
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    assert(Solution().anagram("ab", "ab") == 1);
    assert(Solution().anagram("abc", "cba") == 1);
    assert(Solution().anagram("", "") == 1);
    assert(Solution().anagram("abcd", "cba") == 0);
    assert(Solution().anagram("abcd", "dcbb") == 0);
}

