#include <iostream>
using namespace std;

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int count = 0;

        for (int c = a ^ b; c != 0; c &= c - 1)
            count++;
        return count;
    }
};

int main(int argc, char* argv[]) {
    int a = 31;
    int b = 14;
    cout<<Solution().bitSwapRequired(a, b);
}
