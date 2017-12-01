/***************************************** 

* File Name : main.C

* Creation Date : 20-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, char** argv) {

    int height = 0;
    char c = '#';

    cin >> height;

    if (height<1 || height>100) return -1;

    for (int i=0; i<height; i++) {
        printf("%*c", height-i, c);
        for (int j=0;j<i;j++)
            printf("%c", c);
        printf("\n");
    }
}
