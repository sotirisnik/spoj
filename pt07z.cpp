#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <memory.h>
#include <algorithm>

#define INFINITY 9999999
#define MAXN 10000

using namespace std;

vector <int> V[MAXN];
int i, j, n, from, to, cost;

bool visit[MAXN];
int D[MAXN];

void dfs( int v, int n ) {

    visit[v] = 1;
    D[v] = n;

    for ( int u = 0; u < V[v].size(); ++u )
        if ( visit[ V[v][u] ] == false )
            dfs ( V[v][u], n + 1 );

}

int main( ) {

    scanf ( "%d", &n );
    
    for ( int i = 0 ; i < n-1; ++i ) {
        scanf ( "%d %d", &from, &to );
        V[from-1].push_back ( to - 1 );
        V[to-1].push_back ( from - 1 ); 
    }

    D[0] = 0;
    dfs ( 0, 0 );

    int node = 0;
    
    for ( int i = 0 ; i < n; ++i )
        if ( D[i] > D[node] )
            node = i;

    memset ( visit, 0, sizeof(visit) );

    dfs ( node, 0 );

    sort ( D, D+n );

    printf ( "%d\n", D[n-1] );

    return 0;

}