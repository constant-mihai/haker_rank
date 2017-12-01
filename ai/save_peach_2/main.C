/***************************************** 

* File Name : main.C

* Creation Date : 31-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>

using namespace std;

typedef struct {
    unsigned int r;
    unsigned int c;
} Coordinates;

typedef vector<string>::const_iterator Vector_it;

Coordinates findPrincess(int n, vector<string> grid) {
    Coordinates          xy  = {0,0};
    unsigned int         i   = 0;
    size_t               pos = string::npos;

    for (i=0; i<grid.size() && pos == string::npos; i++) {
        pos = grid[i].find("p");
    }

    xy.r = i-1;
    xy.c = (int)pos;

    return xy; 
}

void nextMove(int n, int r, int c, vector <string> grid) {
    Coordinates xy = findPrincess(n, grid);
    int iToGo = xy.r - r;   // Rows 
                            // Negative: she's above, positive she's below;
    int jToGo = xy.c - c;   // Princess' position relative to her rescuer
                            // Negative means she's left of him. Positive is right.

    if (jToGo > 0) cout << "RIGHT\n";
    else           cout << "LEFT\n";

}

void displayPathToPrincess(int n, int r, int c, vector<string> grid) {
    Coordinates xy = findPrincess(n, grid);
    int iToGo = xy.r - r;   // Rows 
                            // Negative: she's above, positive she's below;
    int jToGo = xy.c - c;   // Princess' position relative to her rescuer
                            // Negative means she's left of him. Positive is right.

    /* Get Mario to the right column */
    for (unsigned char j = abs(jToGo); j>0; j--) {
        if (jToGo > 0) cout << "RIGHT\n";
        else           cout << "LEFT\n";
    }
    
    /* Get Mario to the right row */
    for (unsigned char i = abs(iToGo); i>0; i--) {
        if (iToGo > 0) cout << "DOWN\n";
        else           cout << "UP\n";
    }

}

int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathToPrincess(n, r, c, grid);

    return 0;
}
