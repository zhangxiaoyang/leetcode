#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int numLen = (int)num.size();
        int left = 0;
        int right = numLen - 1;
        
        if (num[left] < num[right])
            return num[left];
        if (numLen <= 2)
            return num[numLen-1];

        while (left <= right) {
            int mid = (left + right) / 2;
            if (num[mid] < num[mid+1] && num[mid] < num[mid-1])
                return num[mid];
            else if (num[mid] > num[right])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return num[left] < num[right] ? num[left] : num[right];
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {-9,-8,-7,-6,-5,-4,-3,-2,-1,-10};
    int array[] = {10,12,13, 0};
    vector<int> num(array, array+sizeof(array)/sizeof(int));
    cout<<Solution().findMin(num);
}
