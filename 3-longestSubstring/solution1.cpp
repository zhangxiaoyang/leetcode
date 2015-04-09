#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;

        int result = 1;

        vector<int> lengths;
        map<char, int> table;
        lengths.push_back(1);
        table.insert(pair<char, int>(s[0], 0));

        for(unsigned int i = 1; i < s.size(); i++) {
            int tmpLength = 0;
            if(!table.count(s[i])) {
                tmpLength = lengths[lengths.size()-1] + 1;
                lengths.push_back(tmpLength);
                table.insert(pair<char, int>(s[i], i));
            }
            else {
                int tmp = lengths[lengths.size()-1] + 1;
                tmpLength = i - table[s[i]];
                tmpLength = tmpLength > tmp ? tmp : tmpLength;
                lengths.push_back(tmpLength);
                table[s[i]] = i;
            }
            result = tmpLength > result ? tmpLength : result;
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    //string s = "abcabcbb";
    //string s = "dvdf";
    string s = "abba";
    cout<<Solution().lengthOfLongestSubstring(s);
}
