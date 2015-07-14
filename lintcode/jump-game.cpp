#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        if (A.size() <= 1)
            return true;

        int lastStep = 0;
        for (int i = 0; i < (int)A.size() - 1; i++) {
            int step = max(A[i], lastStep);
            if (step > 0)
                lastStep = step - 1;
            else
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {2,3,1,1,4};
    int array[] = {3,2,1,0,4};
    vector<int> A(array, array+sizeof(array)/sizeof(int));
    cout<<Solution().canJump(A);
}
