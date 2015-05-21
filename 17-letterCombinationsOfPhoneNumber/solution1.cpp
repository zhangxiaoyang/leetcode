#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<string>& result, string digits, unsigned int index, string sequence) {
        if(index == digits.size()) {
            result.push_back(sequence);
            return;
        }

        string mapper[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string choices = mapper[digits[index] - '0' - 2];

        for(unsigned int i = 0; i < choices.size(); i++) {
            dfs(result, digits, index+1, sequence + choices[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()) {
            unsigned int index = 0;
            string sequence = "";
            dfs(result, digits, index, sequence);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    string digits = "23";
    vector<string> result = Solution().letterCombinations(digits);
    for(vector<string>::iterator i = result.begin(); i != result.end(); i++) {
        cout<<*i<<"\t";
    }

    return 0;
}
