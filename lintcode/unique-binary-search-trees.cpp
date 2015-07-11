#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        if (n <= 1)
            return 1;

        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - j - 1];
        }
        return dp[n];
    }
};

int main(int argc, char* argv[]) {
    for (int i = 0; i < 10; i++)
        cout<<i<<' '<<Solution().numTrees(i)<<endl;
}
