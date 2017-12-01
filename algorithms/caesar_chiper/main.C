/***************************************** 

* File Name : main.C

* Creation Date : 21-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <stdio.h>
#include <string>


using namespace std;

bool sanitize(char c) {
    if (c < 33 || (c > 90 && c < 97) || c > 122)
       return false; 
    else return true;
}

char rotate_letters(char c, unsigned int k) {
    
    if (c >= 65 && c <= 90) {
        /* Upper case */
        return (((k%26)+(c-65))%26)+65;
    } else if (c >= 97 && c <= 122) {
        /* Lower case */
        return ((k%26)+(c-97))%26+97;
    }

    return c;
}

int main(int argc, char** argv)
{
    unsigned int n = 0, k = 0;
    string s;

    cin >> n;
    cin >> s;
    cin >> k;

    if (n < 1 || n > 100) return -1;
    if (k < 0 || k > 100) return -1;
    if (s.length() != n)  return -1;

    for (unsigned int i = 0; i < s.length(); i++) {
        if (!sanitize(s[i])) return -1;
        s[i] = rotate_letters(s[i], k); 
    }

    cout << s;
    
    return 0;
}
