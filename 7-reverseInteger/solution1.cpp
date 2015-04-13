#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long y = 0;

        for(unsigned int i = 0; x/10; i++) {
            y = y*10 + x%10;
            x /= 10;
        }
        y = y*10 + x%10;

        return (int)y == y ? y : 0;
    }
};

int main(int argc, char* argv[]) {
    //int number = 1534236469; 
    int number = 12340;
    cout<<Solution().reverse(number);
}
