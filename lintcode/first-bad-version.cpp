#include <iostream>
using namespace std;

class VersionControl {
    public:
        static bool isBadVersion(int k) {
            if (k == 1) return false;
            if (k == 2) return true;
            if (k == 3) return true;
            return true;
        }

};
/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (VersionControl().isBadVersion(mid + 1))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left + 1;
    }
};

int main(int argc, char* argv[]) {
    int n = 3;
    cout<<Solution().findFirstBadVersion(n);
}
