#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;

        while (n != 1) {
            if (n % 2 == 0)
                n /= 2;
            else
                return false;
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    for (int i = -100; i < 100; i++)
        cout<<i<<' '<<Solution().checkPowerOf2(i)<<endl;
}
