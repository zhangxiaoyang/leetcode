#include <iostream>

#include <limits.h>
#include <math.h>
using namespace std;

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        unsigned int tmp = pow(2, j - i + 1) - 1;
        tmp = tmp << i;
        tmp = ~tmp;
        return (n & tmp) ^ (m << i);
    }
};

int main(int argc, char* argv[]) {
    int n = 0x400;
    int m = 0x15;
    int i = 2;
    int j = 6;
    cout<<hex<<Solution().updateBits(n, m, i, j);
}
