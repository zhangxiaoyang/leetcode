#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        string::iterator i = str.begin();
        bool flag = true;
        map<char, char> m;
        m.insert(pair<char, char>(']', '['));
        m.insert(pair<char, char>(')', '('));
        m.insert(pair<char, char>('}', '{'));

        while(i != str.end()) {
            if(*i == '[' || *i == '(' || *i == '{') {
                s.push(*i);
                i++;
                continue;
            }

            if(*i == ']' || *i == ')' || *i == '}') {
                if(!s.size()) {
                    flag = false;
                    break;
                }

                char top = s.top();
                s.pop();
                if(top == m[*i]) {
                    i++;
                    continue;
                }
                else {
                    flag = false;
                    break;
                }
            }
        }

        return s.size() || !flag ? false : true;
    }
};

int main(int argc, char* argv[]) {
    string s = "[{}{]";
    cout<<Solution().isValid(s);
}
