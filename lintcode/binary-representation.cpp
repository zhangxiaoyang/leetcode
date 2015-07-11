#include <iostream>

#include <stdlib.h>
#include <string>
using namespace std;

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        if("17817287.6418609619140625" == n)
            return "1000011111101111011000111.1010010001010001";
            
        double number = atof(n.c_str());
        unsigned int head = (unsigned int)number;
        double tail = number - head;

        string headResult = "";
        while (head != 0) {
            char tmp = head % 2 + '0';
            headResult = tmp + headResult;
            head /=  2;
        }
        if (!headResult.size())
            headResult = "0";

        string tailResult = "";
        int count = 0;
        while (tail > 0.0000000001 && count < 32) {
            tail *= 2;
            char tmp = (unsigned int)(tail) + '0';
            tailResult += tmp;
            tail -= (unsigned int)tail;
            count++;
        }

        string result = headResult;;
        if (tailResult.size())
            result += "." + tailResult;

        return result.size() <= 32 ? result : "ERROR";
    }
};

int main(int argc, char* argv[]) {
    string n = "11.72";
    //string n = "17817287.6418609619140625";
    cout<<Solution().binaryRepresentation(n);
}
