#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator i = height.begin();
        vector<int>::iterator j = height.end() - 1;
        unsigned int maxWater = 0;

        while(i < j) {
            unsigned int water = min(*i, *j) * (j - i);
            if(water > maxWater)
                maxWater = water;

            if(*i < *j) {
                i++;
            }
            else {
                j--;
            }
        }

        return maxWater;
    }
};

int main(int argc, char* argv[]) {
    int h[] = {5, 3, 6, 2, 11};
    vector<int> height(h, h+5);
    cout<<Solution().maxArea(height);
}
