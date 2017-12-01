/***************************************** 

* File Name : main.C

* Creation Date : 20-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


int main (int argc, char** argv) {

    int a[10];
    int n = 0;
    long long int sum = 0;

    cin >> n;

    if (n < 1 || n>10) {
        printf("N should be between 1 and 10\n");
        return -1;
    }

    for (int i = 0; i<n; i++) {
        cin >> a[i];
        if (a[i]<0 || a[i]> pow(10,10)) {
            printf("Vector elements should be between 0 and 10^10\n");
            return -1;
        }

        sum+= a[i];
    }

    cout << sum;

    return 0;
}
