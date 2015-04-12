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

            while(i == 0 && step*j < s.size()) {
                result += s[step*j];
                j++;
            }
            
            step = 2*(nRows-i-1) + i+1;
            j = 0;
            unsigned int index = i + step*j;
            while(i > 0 && i < nRows-1 && index < s.size()) {
                index = j % 2 == 0 ? i+step*(j/2) : i+step*((j+1)/2)-(i+1);
                if(index < s.size()) result += s[index];
                j++;
            }

            step = 2*(nRows-1);
            index = nRows-1;
            j = 0;
            while(i == nRows-1 && index < s.size()) {
                index = nRows-1 + step*j;
                if(index < s.size()) result += s[index];
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
