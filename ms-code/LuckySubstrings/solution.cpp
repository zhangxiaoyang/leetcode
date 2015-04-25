#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <math.h>
#define LL long long
using namespace std;

bool isF(LL n) {
    double n1 = sqrt(5*n*n + 4);
    if((LL)n1 == n1) {
        return true;
    }

    double n2 = sqrt(5*n*n - 4);
    if((LL)n2 == n2) {
        return true;
    }

    return false;
}


bool pass(string s) {
    set<char> table;
    for(LL i = 0; i < s.size(); i++) {
        if(!table.count(s[i])) {
            table.insert(s[i]);
        }
    }

    return isF(table.size());
}

void solve(string s) {
    set<string> result;
    for(LL i = 0; i < s.size(); i++) {
        string tmp;
        tmp += s[i];
        result.insert(tmp);
        for(LL j = i+1; j < s.size(); j++) {
            tmp += s[j];
            if(pass(tmp)) {
                result.insert(tmp);
            }
        }
    }

    for(set<string>::iterator i = result.begin(); i != result.end(); i++) {
        cout<<*i<<endl;
    }
}

int main(int argc, char* argv[]) {
    string s;
    cin >> s;
    if(!s.size()) return 0;

    solve(s);
    return 0;
}
