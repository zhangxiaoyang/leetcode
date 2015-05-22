#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void generate(int n, int leftCount, int rightCount, vector<string>& result, string s) {
        if(leftCount == rightCount && leftCount == n) {
            result.push_back(s);
            return;
        }

        if(leftCount < n)
            generate(n, leftCount+1, rightCount, result, s + "(");
        if(leftCount > rightCount)
            generate(n, leftCount, rightCount+1, result, s + ")");

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n > 0)
            generate(n, 0, 0, result, "");
        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<string> result = Solution().generateParenthesis(4);
    for(vector<string>::iterator i = result.begin(); i != result.end(); i++) {
        cout<<*i<<endl;
    }
}
