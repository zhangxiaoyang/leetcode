#include <iostream>
#include <assert.h>

#include <vector>
using namespace std;

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        if (A.size() == 0)
            return 0;

        int i = 0;
        int j = (int)A.size() - 1;
        while (i <= j) {
            if (A[i] == elem) {
                A[i] = A[j];
                j--;
            }
            else {
                i++;
            }
        }
        return j + 1;
    }
};

void test1() {
    int array[] = {0,4,4,0,0,2,4,4};
    vector<int> A(array, array + sizeof(array)/sizeof(int));
    int elem = 4;
    assert(Solution().removeElement(A, elem) == 4);
}

void test2() {
    int array[] = {1,2,3,4,4,4,4,4};
    vector<int> A(array, array + sizeof(array)/sizeof(int));
    int elem = 4;
    assert(Solution().removeElement(A, elem) == 3);
}

int main(int argc, char* argv[]) {
    test1();
    test2();
}
