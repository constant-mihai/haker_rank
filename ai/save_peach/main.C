/***************************************** 

* File Name : main.C

* Creation Date : 31-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <vector>
using namespace std;

typedef enum {
    ERROR,
    TopLeft,
    TopRight,
    BotLeft,
    BotRight,
} Corner;

typedef vector<string>::const_iterator Vector_it;

Corner findPrincess(int n, vector<string> grid) {
    size_t npos = 0;
    if ( (npos = grid[0].find("p")) != string::npos) {
        if (npos == 0) return TopLeft;
        else           return TopRight;
    } else {
        if (npos == 0) return BotLeft;
        else           return BotRight;
    }
    
    return ERROR; 
}

void displayPathtoPrincess(int n, vector <string> grid){
    Corner corner = findPrincess(n, grid);
    int iToGo = n/2;
    int jToGo = n/2;
    
    switch (corner) {
        case TopLeft:
            while (iToGo--) {
                cout << "UP\n";
            }
            while (jToGo--) {
                cout << "LEFT\n";
            }
        break;
        case TopRight:
            while (iToGo--) {
                cout << "UP\n";
            }
            while (jToGo--) {
                cout << "RIGHT\n";
            }
        break;
        case BotLeft:
            while (iToGo--) {
                cout << "DOWN\n";
            }
            while (jToGo--) {
                cout << "LEFT\n";
            }
        break;
        case BotRight:
            while (iToGo--) {
                cout << "DOWN\n";
            }
            while (jToGo--) {
                cout << "RIGHT\n";
            }
        break;
        
        default:
            cout << "\n";
            break;
    }
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
