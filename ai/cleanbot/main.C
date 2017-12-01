/***************************************** 

* File Name : main.C

* Creation Date : 03-09-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

typedef struct {
    int x;
    int y;
} coord;

typedef struct {
    coord xy;
    int   q;        // quadrant
    float dist;     // distance to from location to current bot position.
    bool  cleaned;  // mark as true if cleaned;
} location;

typedef vector<location>::iterator Location_it;

int get_quadrant(int x, int y) {
    if (x < 2 && y < 2) return 1; // (0   , pi/2)     quadrant I
    if (x < 2 && y > 2) return 2; // (pi/2, pi)       quadrant II
    if (x > 2 && y > 2) return 3; // (pi  , 3pi/2)    quadrant III
    if (x > 2 && y < 2) return 4; // (3pi/2, 0)       quadrant IV

    return -1;
}

// He missed a spot
void place_in_queue(int x, int y, vector<location>& spots, int bx, int by) {
    coord diff = {0,0};

    diff.x  = bx - x;
    diff.y  = by - y;

    float       dist      = sqrt((pow(diff.x,2) + pow(diff.y,2)));
    coord       xy        = {x, y};
    // Queue the dirty spots prioritizing by quadrant.
    // It just goes clock-wise.
    // (0,pi/2)(I) -> (pi/2,pi)(II) -> (pi,3pi/2)(III) -> (3pi/2,0)(IV)
    // E.g. (Distance)(Quadrand(Number))
    // 7q1-8q1-9q1 -> 4q2-5q2-7q2 -> 1q3-5q3 -> 2q4;
    // Means if the bot is in quadrand 1 it will clean the dirty spots from distances 7-8-9 first.
    // Then goes around to the other quadrants.
    //
    // On the other hand if it is in quadrant 2 it will clean 4-5-7 from q2 first.
    // Then goes clock wise (q2->q3->q4->q1)and cleans 7-8-9 q1 last.
    int         q           = get_quadrant(x, y);
    location    loc         = {xy, q, dist, false};
    
    // Order the dirty spots first by quadrant, then by distance.
    for (unsigned int i=0; i<spots.size(); i++) {
        if (q <= spots[i].q) {
            // Sort element here.
            if (dist <= spots[i].dist) {
                // insert element here.
                Location_it it  = spots.begin();
                spots.insert(it+i, loc);
            }
        }
    }
}

void go_clean_spot(location &spot, int &bx, int &by) {
    int iToGo = spot.xy.x - bx;   // Rows 
                            // Negative: she's above, positive she's below;
    int jToGo = spot.xy.y - by;   // Princess' position relative to her rescuer
                            // Negative means she's left of him. Positive is right.

    while (jToGo != 0) {
        if (jToGo > 0) { jToGo--; cout << "RIGHT\n";}
        else           { jToGo++; cout << "LEFT\n"; }
    } 
    while (iToGo != 0) {
        if (iToGo > 0) { iToGo--; cout << "DOWN\n";}
        else           { iToGo++; cout << "UP\n";  }
    }

    bx = spot.xy.x;
    by = spot.xy.y;
    spot.cleaned = true;
    cout << "CLEAN\n";
}

// In this case a move means to go all the way to a spot and clean it.
void next_move(int &posr, int &posc, vector <string> board) {
    vector<location> spots;
    // Find all dirty spots relative to the bot.
    for (unsigned int i=0; i<board.size(); i++)
        for(unsigned int j=0; j<board.begin()->size();j++)
        {
            if (board[i][j]=='d') {
                cout << board[i][j];
                place_in_queue(i, j, spots, posr, posc);
            }
            cout << endl;
        }
    // Get bot quadrant.
    // This helps us figure out what quadrant he will clean next.
    int bq = get_quadrant(posr, posc);

    unsigned int pos = 0;
    // Get first elementfrom quadrant bq.
    for (unsigned int i=0; i<=spots.size(); i++) {
        // Go through quadrants
        if (spots[i].q == bq) {
            pos = i;
            break;
        } else continue;
    }

    for (unsigned int i=pos; i<spots.size(); i++) {
        go_clean_spot(spots[i], posr, posc);
    }

    if (spots[0].dist != 0 && spots[0].cleaned == false) {
        // still need to loop through some quadrants.
        for (unsigned int i=0; i<pos; i++) {
            go_clean_spot(spots[i], posr, posc);
        }
    }

}

int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}

