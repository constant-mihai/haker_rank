/***************************************** 

* File Name : main.C

* Creation Date : 20-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <stdio.h>

using namespace std;


int main (int argc, char** argv) {

    int m[1000][2];
    int noL = 0;

    cin >> noL;
    for (int i = 0; i<noL; i++) {
        cin >> m[i][0] >> m[i][1];
    }

    for (int i = 0; i<noL; i++) {
        cout << m[i][0] + m[i][1];
        cout << endl;
    }

}
