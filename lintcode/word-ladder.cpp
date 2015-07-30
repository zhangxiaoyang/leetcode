#include <string>
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> dict) {
        queue<string> q;
        q.push(start);
        
        map<string, int> cache;
        cache[start] = 1;
        
        dict.erase(start);
        dict.insert(end);
        
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            
            if (str == end)
                return cache[str];

            for (int i = 0; i < (int)str.size(); i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    string nextStr = replace(str, i, ch);
                    if (dict.find(nextStr) != dict.end()) {
                        q.push(nextStr);
                        cache[nextStr] = cache[str] + 1;
                        dict.erase(nextStr);
                    }
                }
            }
        }
        
        return 0;
    }

    string replace(string str, int index, char ch) {
        str[index] = ch;
        return str;
    }
};
