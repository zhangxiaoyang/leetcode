#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end(), less<int>());

        for(unsigned int i = 0; i < num.size(); i++) {
            if(i > 0 && num[i] == num[i-1])
                continue;

            for(unsigned int j = i+1; j < num.size(); j++) {
                if(j > i+1 && num[j] == num[j-1])
                    continue;
                int number = 0-num[i]-num[j];

                if(!(find(num.begin()+j+1, num.end(), number) == num.end())) {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(number);
                    sort(tmp.begin(), tmp.end(), less<int>());
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {-1, 0, 1, 2, -1, -4, 1, -1};
    vector<int> num(array, array+8);
    vector<vector<int> > result = Solution().threeSum(num);

    cout<<result.size()<<endl;
    for(unsigned int i = 0; i < result.size(); i++) {
        for(unsigned int j = 0; j < result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
