#include <iostream>

#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    void swap(vector<int> &num, int i, int j) {
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
    bool cmp(int n1, int n2, char type) {
        char s1[255];
        char s2[255];
        sprintf(s1, "%d", n1);
        sprintf(s2, "%d", n2);
        int i = 0;
        while (i < strlen(s1) && i < strlen(s2)) {
            if (s1[i] != s2[i]) {
                if (type == 'L') {
                    return s1[i] >= s2[i];
                }
                else if (type == 'G') {
                    return s1[i] <= s2[i];
                }
            }
            i++;
        }

        cout<<'a'<<endl;
        if (strlen(s1) <= strlen(s2)) {
            if (type == 'L') {
                cout<<s1<<' '<<s2<<' '<<type<<(s2[strlen(s1)] >= s2[0] || strlen(s1) <= strlen(s2))<<endl;
                return s2[strlen(s1)] >= s2[0] || strlen(s1) <= strlen(s2);
            }
            if (type == 'G') {
                cout<<s1<<' '<<s2<<' '<<(type<<s2[strlen(s1)] <= s2[0] || strlen(s1) >= strlen(s2))<<endl;
                return s2[strlen(s1)] <= s2[0] || strlen(s1) >= strlen(s2);
            }
        }
        if (strlen(s1) >= strlen(s2)) {
            if (type == 'L') {
                cout<<s1<<' '<<s2<<' '<<(type<<s1[strlen(s2)] >= s1[0] || strlen(s1) <= strlen(s2))<<endl;
                return s1[strlen(s2)] >= s1[0] || strlen(s1) <= strlen(s2);
            }
            if (type == 'G') {
                cout<<s1<<' '<<s2<<' '<<(type<<s1[strlen(s2)] <= s1[0] || strlen(s1) >= strlen(s2))<<endl;
                return s1[strlen(s2)] <= s1[0] || strlen(s1) >= strlen(s2);
            }
        }
    }
    int partition(vector<int> &num, int i, int j) {
        int pivot = num[i];
        
        while (i < j) {
            while (i < j && cmp(num[j], pivot, 'G')) j--;
            num[i] = num[j];
            while (i < j && cmp(num[i], pivot, 'L')) i++;
            num[j] = num[i];
        }
        num[i] = pivot;
        return i;
    }
    void quicksort(vector<int> &num, int left, int right) {
        if (left < right) {
            int pivot = partition(num, left, right);
            quicksort(num, left, pivot - 1);
            quicksort(num, pivot + 1, right);
        }
    }
    string largestNumber(vector<int> &num) {
        quicksort(num, 0, num.size() - 1);

        string result = "";
        for (int i = 0; i < (int)num.size(); i++) {
            char tmp[255];
            sprintf(tmp, "%d", num[i]);
            if (result.size() == 0 && tmp[0] == '0')
                continue;
            result += tmp;
        }
        return result.size() ? result : "0";
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {1,20,23,4,8};
    //int array[] = {0,0};
    //int array[] = {2147483647,2147483647,2147483646,9,1,8};
    int array[] = {9,97,99,96,95,98,94,96,92,97,9,91,90,90,92};
    //int array[] = {87,81,80,80,89,81,8,85,80,85,87,80,88,85,85,84,89};
    vector<int> num(array, array+sizeof(array)/sizeof(int));
    cout<<Solution().largestNumber(num);
}
