#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int length = nums.size();
        if(length < 2)
            return length;

        set<int> s;
        for(int i = 0; i < length; i++) {
            s.insert(nums[i]);
        }

        int ret = 1;
        int count = 1;
        set<int>::iterator i = s.begin();
        i++;
        for(; i != s.end(); i++) {
            set<int>::iterator j = i;
            j--;
            if(*i - *j == 1)
                count++;
            else {
                if(count > ret)
                    ret = count;
                count = 1;
            }
        }
        if(count > ret)
            ret = count;
        return ret;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {100, 4, 200, 1, 3, 2};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    cout<<Solution().longestConsecutive(nums);
}
