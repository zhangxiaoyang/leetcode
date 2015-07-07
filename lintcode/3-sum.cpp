#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        int numsLen = (int)nums.size();
        vector<vector<int> > result;
        sort(nums.begin(), nums.end(), less<int>());

        for (int i = 0; i < numsLen; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int j = i + 1;
            int k = numsLen - 1;
            while (j < k) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    j++;
                    continue;
                }

                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    sort(tmp.begin(), tmp.end(), less<int>());
                    result.push_back(tmp);
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    vector<vector<int> > result = Solution().threeSum(nums);

    for (vector<vector<int> >::iterator i = result.begin(); i != result.end(); i++) {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
            cout<<*j<<' ';
        cout<<endl;
    }
}
