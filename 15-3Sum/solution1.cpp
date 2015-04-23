#include <iostream>
#include <vector>
#include <set>
#define UINT unsigned int
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        set<int> num2;
        for(vector<int>::iterator i = num.begin(); i != num.end(); i++) {
           num2.insert(*i);
        }

        for(set<int>::iterator i = num2.begin(); i != num2.end(); i++) {
            for(set<int>::iterator j = i + 1; j != num2.end(); j++) {
                for(set<int>::iterator k = j + 1; k != num2.end(); k++) {
                    if(*i + *j + *k == 0) {
                        vector<int> v;
                        v.push_back(*i);
                        v.push_back(*j);
                        v.push_back(*k);
                        cout<<*i<<" "<<*j<<" "<<*k<<endl;
                        result.push_back(v);
                    }
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {-1, 0, 1, 2, -1, -4};
    vector<int> num(array, array+6);
    Solution().threeSum(num);
    return 0;
}
