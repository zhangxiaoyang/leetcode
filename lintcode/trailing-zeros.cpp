#include <iostream>
using namespace std;

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long m = n;
        long long i = 0;
        long long j = 0;
        
        while (n != 0 && m != 0) {
            if (m % 2 >= 0)
                i += m / 2;
            if (n % 5 >= 0)
                j += n / 5;
            m /= 2;
            n /= 5;
        }

        return i < j ? i : j;
    }
};

long long main(long long argc, char* argv[]) {
    long long n = 105;
    cout<<Solution().trailingZeros(n);
}
