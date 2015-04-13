#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) return s;

        string result = "";
        for(int i = 0; i < nRows; i++) {
            unsigned int step = 2*(nRows-1);
            unsigned int j = 0;
            unsigned base = 0;
            while(i == 0
                && (base + step*j) < s.size()) {
                result += s[base + step*j];
                j++;
            }
            
            j = 0;
            base = i;
            while(i > 0
                && i < nRows-1
                && base < s.size()) {
                result += s[base];
                base += j % 2 == 0 ? 2*(nRows-i-1) : 2*i;
                j++;
            }

            step = 2*(nRows-1);
            base = nRows-1;
            j = 0;
            while(i == nRows-1 
                && (base + step*j) < s.size()) {
                result += s[base + step*j];
                j++;
            }

        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    //string s = "PAYPALISHIRING";
    string s = "PAYPALISHIRING";
    cout<<Solution().convert(s, 4);
    return 0;
}
