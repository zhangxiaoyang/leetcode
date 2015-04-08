#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &vNumbers, int target) {
        vector<int> vResults;
        map<int, unsigned int> mTable;

        for(unsigned int i = 0; i < vNumbers.size(); i++) {
            if(!mTable.count(vNumbers[i])) {
                mTable.insert(pair<int, unsigned int>(vNumbers[i], i));
            }
            if(mTable.count(target - vNumbers[i]) && mTable[target - vNumbers[i]] < i) {
                vResults.push_back(mTable[target - vNumbers[i]] + 1);
                vResults.push_back(i + 1);
                cout<<vResults[0]<<","<<vResults[1]<<endl;
                return vResults;
            }
        }
        return vResults;
    }
};

int main(int argc, char* argv[]) {
    //int numbers[] = {7, 2, 11, 15};
    //int target = 9;
    int numbers[] = {3,2,4};
    int target =6;

    vector<int> vNumbers(numbers, numbers + 5);
    Solution().twoSum(vNumbers, target);
    return 0;
}

