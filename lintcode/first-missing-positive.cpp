#include <iostream>
#include <assert.h>

#include <vector>
using namespace std;

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    void swap(vector<int> &A, int i , int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

    int firstMissingPositive(vector<int> A) {
        int lenA = (int)A.size();
        if (lenA == 0)
            return 0;

        for (int i = 0; i < lenA; i++) {
            while (A[i] <= lenA && A[i] > 0 && A[i] != A[A[i]-1])
                swap(A, i, A[i]-1);
        }


        for (int i = 0; i < lenA; i++) {
            if (A[i] != i + 1)
                return i + 1;
        }
        return lenA + 1;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {2,4,5};
    vector<int> A(array, array + sizeof(array)/sizeof(int));
    cout<<Solution().firstMissingPositive(A);
}
