#include <assert.h>

#include <string.h>

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (!source || !target)
            return -1;

        int sourceLength = strlen(source);
        int targetLength = strlen(target);
        if (sourceLength < targetLength)
            return -1;
        if (!targetLength)
            return 0;

        for (int i = 0; i < sourceLength; i++) {
            int j = 0;
            for (; j < targetLength; j++) {
                if (source[i + j] != target[j])
                    break;
            }

            if (j == targetLength)
                return i;
        }

        return -1;
    }
};

int main(int argc, char* argv[]) {
    assert(Solution().strStr("source", "target") == -1);
    assert(Solution().strStr("abcdabcdefg", "bcd") == 1);
    assert(Solution().strStr("abcdabcdefg", "abcd") == 0);
    assert(Solution().strStr("abcdabcdefg", "abcde") == 4);
    assert(Solution().strStr("", "") == 0);
    assert(Solution().strStr(NULL, "abc") == -1);
    assert(Solution().strStr("abc", NULL) == -1);
    assert(Solution().strStr("abcd", "") == 0);
    assert(Solution().strStr("", "abcd") == -1);
}
