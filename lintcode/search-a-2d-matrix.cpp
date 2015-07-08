#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    int searchRow(vector<vector<int> > &matrix, int target) {
        int rowCount = (int)matrix.size();
        if (rowCount == 0 || matrix[0].size() == 0)
            return -1;


        int left = 0;
        int right = rowCount - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == matrix[mid][0])
                return -2;
            else if (target < matrix[mid][0])
                right = mid - 1; 
            else
                left = mid + 1;
        }

        return left - 1;
    }

    bool searchCell(vector<int> &row, int target) {
        int cellCount = (int)row.size();
        int left = 0;
        int right = cellCount - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == row[mid])
                return true;
            else if (target < row[mid])
                right = mid - 1; 
            else
                left = mid + 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rowIndex = searchRow(matrix, target);
        if (rowIndex == -1)
            return false;
        if (rowIndex == -2)
            return true;

        return searchCell(matrix[rowIndex], target);
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int> > matrix;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(5);
    tmp.push_back(7);
    matrix.push_back(tmp);

    tmp.clear();
    tmp.push_back(10);
    tmp.push_back(11);
    tmp.push_back(16);
    tmp.push_back(20);
    matrix.push_back(tmp);

    tmp.clear();
    tmp.push_back(23);
    tmp.push_back(30);
    tmp.push_back(34);
    tmp.push_back(50);
    matrix.push_back(tmp);

    int target = 300;
    cout<<Solution().searchMatrix(matrix, target);
}
