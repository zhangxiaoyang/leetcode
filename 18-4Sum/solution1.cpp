#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    void print(vector<int> v) {
        for(vector<int>::iterator i = v.begin(); i != v.end(); i++) {
            cout<<*i<<'\t';
        }
        cout<<endl;
    }
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        int length = nums.size();
        if(length >= 4) {
            sort(nums.begin(), nums.end(), less<int>());
            for(int i = 0; i < length; i++) {
                if(i > 0 && nums[i] == nums[i-1])
                    continue;

                for(int j = i+1; j < length; j++) {
                    if(j > i+1 && nums[j] == nums[j-1])
                        continue;

                    int m = j+1;
                    int n = length-1;
                    while(m < n) {
                        if(m > j+1 && n < length-1 && nums[m] == nums[m-1] && nums[n] == nums[n+1]) {
                            m++;
                            n--;
                            continue;
                        }

                        int sum = nums[i] + nums[j] + nums[m] + nums[n];
                        if(sum < target) {
                            m++;
                        }
                        else if(sum > target) {
                            n--;
                        }
                        else {
                            vector<int> tmp;
                            tmp.push_back(nums[i]);
                            tmp.push_back(nums[j]);
                            tmp.push_back(nums[m]);
                            tmp.push_back(nums[n]);
                            sort(tmp.begin(), tmp.end(), less<int>());
                            print(tmp);
                            result.push_back(tmp);

                            m++;
                            n--;
                        }
                    }
                }
            }
        }
        return result;
    }

};

int main(int argc, char* argv[]) {
    //int array[] = {1, 0, -1, 0, -2, 2}; int target = 0;
    //int array[] = {-1, -1, -1, 1, 1, 1}; int target = 0;
    int array[] = {-1,0,-5,-2,-2,-4,0,1,-2}; int target = -9;
    vector<int> nums(array, array + sizeof(array)/sizeof(int));

    Solution().fourSum(nums, target);
}
