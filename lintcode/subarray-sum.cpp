#include <iostream>
#include <assert.h>

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> result;

        map<int, int> m;
        m[0] = -1;

        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            
            if (m.count(sum)) {
                result.push_back(m[sum] + 1);
                result.push_back(i);
                return result;
            }
            m.insert(pair<int, int>(sum, i));
        }
        
        return result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    vector<int> result = Solution().subarraySum(nums);
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(2);
    assert(equal(result.begin(), result.end(), answer.begin()));
}
