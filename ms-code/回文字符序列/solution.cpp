#include <iostream>
#include <stdio.h>
#include <string.h>
#define UINT unsigned int
#define MAX_LEN 1001
using namespace std;

UINT solve(char* s, int length) {
    UINT table[MAX_LEN][MAX_LEN];
    for(int i = length-1; i >= 0; i--) {
        table[i][i] = 1;
        if(i + 1 < length) {
            if(s[i] == s[i+1])
                table[i][i+1] = 3;
            else
                table[i][i+1] = 2;
        }

        for(int j = i + 2; j < length; j++) {
            if(s[i] == s[j])
                table[i][j] = table[i+1][j] + table[i][j-1] + 1;
            else {
                table[i][j] = table[i+1][j] + table[i][j-1];
                if(i+1 != j) table[i][j] -= table[i+1][j-1];
            }
        }
    }

    return table[0][length-1];
}

int main(int argc, char* argv[]) {
    UINT count = 0;

    if(!(cin >> count)) {
        return 1;
    }

    for(UINT i = 0; i < count; i++) {
        char tmp[MAX_LEN] = {0};
        scanf("%s", tmp);

        cout<<"Case #"<<i+1<<": "<<solve(tmp, (int)strlen(tmp))<<endl;
    }

    return 0;
}
