#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        if (!candidates.size())
            return result;
            
        vector<int> record;
        vector<int> candidatesCopy = candidates;
        sort(candidatesCopy.begin(), candidatesCopy.end(), less<int>());
        _combinationSum(0, candidatesCopy, target, record, result);
        return result;
    }

private:
    void _combinationSum(
        int index,
        vector<int>& candidates,
        int target,
        vector<int>& record,
        vector<vector<int> >& result
    ) {
        if (sum(record) == target) {
            result.push_back(record);
            return;
        }

        if (sum(record) > target)
            return;

        for (int i = index; i < (int)candidates.size(); i++) {
            record.push_back(candidates[i]);
            _combinationSum(i, candidates, target, record, result);
            record.pop_back();
        }
    }

    int sum(vector<int> v) {
        int _sum = 0;
        for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
            _sum += *i;
        return _sum;
    }
}
