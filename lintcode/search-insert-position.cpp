#include <iostream>

#include <vector>
using namespace std;

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int ALen = (int)A.size();

        int left = 0;
        int right = ALen - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (A[mid] == target)
                return mid;
            else if (A[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right + 1;
    }
};

void test1() {
    int array[] = {1,3,5,6};
    vector<int> A(array, array+sizeof(array)/sizeof(int));
    int target = 5;
    cout<<Solution().searchInsert(A, target)<<endl;
}

void test2() {
    int array[] = {1,3,5,6};
    vector<int> A(array, array+sizeof(array)/sizeof(int));
    int target = 2;
    cout<<Solution().searchInsert(A, target)<<endl;
}

int main(int argc, char* argv[]) {
    test1();
    test2();
}
