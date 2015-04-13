#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int y = 0;
        int x2 = x;
        while(x2/10) {
            y = y*10 + x2%10;
            x2 /= 10;
        }
        y = y*10 + x2;

        return x==y;
    }
};

int main(int argc, char* argv[]) {
    int number = 1312992133;
    cout<<Solution().isPalindrome(number);
}
