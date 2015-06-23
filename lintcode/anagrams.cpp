#include <assert.h>
#include <iostream>

#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, int> cache;
        for (vector<string>::iterator i = strs.begin(); i != strs.end(); i++) {
            string s = *i;
            sort(s.begin(), s.end());
            if (cache.find(s) == cache.end()) {
                cache.insert(pair<string, int>(s, i - strs.begin()));
            } else {
                if (cache[s] >= 0) {
                    result.push_back(strs[cache[s]]);
                    cache[s] = -1;
                }
                result.push_back(*i);
            }
        }

        return result;
    }
};

void test1() {
    vector<string> strs;
    strs.push_back("lint");
    strs.push_back("intl");
    strs.push_back("inlt");
    strs.push_back("code");
    
    vector<string> result = Solution().anagrams(strs);
    for(vector<string>::iterator i = result.begin(); i != result.end(); i++)
        cout<<*i<<' ';
    cout<<endl;
}

void test2() {
    vector<string> strs;
    strs.push_back("");
    strs.push_back("");
    strs.push_back("code");
    
    vector<string> result = Solution().anagrams(strs);
    for(vector<string>::iterator i = result.begin(); i != result.end(); i++)
        cout<<'['<<*i<<']'<<' ';
    cout<<endl;
}

int main(int argc, char* argv[]) {
    test1();
    test2();
}
