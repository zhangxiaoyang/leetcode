#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        long i = 0;
        long j = x;
        while (i <= j) {
            long mid = i + (j - i) / 2;
            if (x < mid*mid)
                j = mid - 1;
            else
                i = mid + 1;
        }

        return (int)j;
    }
};

int main(int argc, char* argv[]) {
    cout<<Solution().sqrt(128);
}
