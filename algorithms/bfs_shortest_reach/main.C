/***************************************** 

* File Name : main.C

* Creation Date : 29-07-2015

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

******************************************/

#include <iostream>
#include <stdio.h>
#include <queue>
#include <strings.h>
#include <map>

using namespace std;

typedef enum {
    undiscovered,
    discovered,
    visited,
}Status;

typedef struct Node {
    int          x;
    int          y;
    int          hasEdge; 
    struct Node* parent;
} Node;

typedef map<int, Node>        AdjListMap;

typedef struct AdjList {
    AdjListMap  map;
    Status      status;
    int         distance;

    Node& operator[](int i) {return this->map[i];};
} AdjList;

typedef map<int, AdjList>     AdjLists;

typedef AdjListMap::iterator     AdjList_it;
typedef AdjLists::iterator       AdjLists_it;

void assign_undirected(AdjLists& m, int x, int y) {
    m[x][y].x = x;
    m[x][y].y = y;
    m[x][y].hasEdge = 1;
    m[x].status = undiscovered;

    m[y][x].x = y;
    m[y][x].y = x;
    m[y][x].hasEdge = 1;
    m[y].status = undiscovered;
}

void bfs() {
    int         m = 0, n = 0;
    int         x = 0, y = 0;
    int         s = 0;
    AdjLists    adjLists; 

    cin >> n;
    cin >> m;

    /* Init the hash */
    for (int i=1; i<=n; i++) {
        adjLists[i].status = undiscovered;
    }

    /* Create all the edges */
    for (int i=0; i<m; i++) {
        /* Get the input */
        cin >> x;
        cin >> y;
        /* Build the matrix */

        assign_undirected(adjLists, x, y);
    }

    cin >> s;
    
    queue<Node> vQueue;

    Node first_node = { 0, s, undiscovered, 0};
    vQueue.push(first_node);

    while(!vQueue.empty()) {
        Node cur_node = vQueue.front();
        vQueue.pop();

        /* For adjacency list for the current node*/
        AdjLists_it adl_it    = adjLists.find(cur_node.y);
        AdjList     &list     = adl_it->second;

        if ( adl_it != adjLists.end() ) {
            /* Go through adjecency list and add up the distances */
            AdjList_it  ad_it    = list.map.begin();

            for ( ; ad_it != list.map.end(); ad_it++) {
                Node&  adj_node = ad_it->second;
                if (adjLists[ad_it->first].status == undiscovered) {

                    adjLists[ad_it->first].status      = discovered;
                    adjLists[ad_it->first].distance    = list.distance+6;
                    adj_node.parent     = &cur_node;
                    
                    vQueue.push(adj_node);
                }

                list.status= visited;
            }
        }
    }

    AdjLists_it adl_it = adjLists.begin();
    AdjList_it  ad_it;

    for( adl_it = adjLists.begin() ; adl_it != adjLists.end(); adl_it++ ) {
        if ( adl_it->first != s) {
            if ( adl_it->second.distance == 0 ) cout << "-1 ";
            else cout << adl_it->second.distance << " ";
        }
    }


    cout << endl;
}

int main(int argc, char** argv) {
    int         t = 0; 

    cin >> t;
    for (int i=0; i<t; i++)
        bfs();

    return 0;
}
