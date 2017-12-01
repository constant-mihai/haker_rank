/***************************************** 

* File Name : main.C

* Creation Date : 20-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define CALCTIME (s[i-2]-48)*10 + (s[i-1]-48)

int main(int argc, char**argv) {

    int a[3];
    int add = 0;
    string s;

    cin >> s;

    for (unsigned int i=0, c = 0; i<s.length(); i++) {
        if (s[i] == ':' || (s[i] == 'P' || s[i] == 'A')) a[c++] = CALCTIME;
        if (s[i] == 'P') add = 12; 
    }

    if (add == 0) {
        s.resize(s.size()-2);
        if (s[0] == '1' && s[1] == '2') { s[0] = '0'; s[1] = '0';}
        cout << s;
    } else {
        unsigned int size = sizeof(a)/sizeof(int);
        for (unsigned int i = 0; i<size; i++) {
            if (a[i] < 0) return -1;

            int tmp = a[i]+add;
            if (tmp < 10) 
                cout << "0" << tmp;
            else
               cout << tmp; 

            add = 0;

            if (i==size-1) cout << "\n";
            else cout << ":";
        }
    }
}
