#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        int left = 1;
        int right = x;
        while (left < right - 1) {
            int mid = left + (right - right) / 2;
            int quo = x / mid;
            
            if (mid == quo) {
                return quo;
            }
            else if (mid > quo) {
                right = mid;
            }
            else {
                left = mid;
            }
        }

        return left;
    }
};

int main(int argc, char* argv[]) {
    Solution().sqrt(x);
}
