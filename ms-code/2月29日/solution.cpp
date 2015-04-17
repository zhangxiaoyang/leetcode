#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#define UINT unsigned int
using namespace std;

bool isLeapYear(UINT year) {
    if(year % 4 == 0 && year % 100 != 0) return true;
    if(year % 400 == 0) return true;
    return false;
}

UINT monthToNum(char* month) {
    string str_month(month);
    map<string, UINT> table;
    table.insert(pair<string, UINT>("January", 1));
    table.insert(pair<string, UINT>("February", 2));
    table.insert(pair<string, UINT>("March", 3));
    table.insert(pair<string, UINT>("April", 4));
    table.insert(pair<string, UINT>("May", 5));
    table.insert(pair<string, UINT>("June", 6));
    table.insert(pair<string, UINT>("July", 7));
    table.insert(pair<string, UINT>("August", 8));
    table.insert(pair<string, UINT>("September", 9));
    table.insert(pair<string, UINT>("October", 10));
    table.insert(pair<string, UINT>("November", 11));
    table.insert(pair<string, UINT>("December", 12));
    return table[str_month];
}

bool largeThanThisDay(UINT month, UINT day) {
    if(month == 2 && day >= 29) return true;
    if(month > 2) return true;
    return false;
}

bool lessThanThisDay(UINT month, UINT day) {
    if(month == 2 && day <= 29) return true;
    if(month < 2) return true;
    return false;
}

int main(int argc, char* argv[]) {
    UINT months[2];
    UINT days[2];
    UINT years[2];

    UINT count = 0;

    if(!(cin >> count)) {
        return 1;
    }

    for(UINT i = 0; i < count*2; i++) {
        UINT index = i % 2;
        char tmp[50] = {0};
        scanf("%s %d, %d", tmp, &days[index], &years[index]);
        months[index] = monthToNum(tmp);

        if(index == 1) {
            UINT result = 0;
            if(years[0] == years[1]) {
                if(isLeapYear(years[0]) && lessThanThisDay(months[0], days[0]) && largeThanThisDay(months[1], days[1]))
                    result++;
            }
            else {
                for(UINT j = years[0] + 1; j < years[1]; j++) {
                    if(isLeapYear(j)) result++;
                }
                if(isLeapYear(years[0]) && lessThanThisDay(months[0], days[0])) result++;
                if(isLeapYear(years[1]) && largeThanThisDay(months[1], days[1])) result++;
            }
            cout<<"Case #"<<(i+1)/2<<": "<<result<<endl;
        }
    }

    return 0;
}
