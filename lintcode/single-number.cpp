#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        int number = 0;
        for (int i = 0; i < (int)A.size(); i++) {
           number ^= A[i] ;
        }
        return number;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {1,2,2,1,3,4,3};
    vector<int> A(array, array+sizeof(array)/sizeof(int));
    cout<<Solution().singleNumber(A);
}
