#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <memory.h>
#include <algorithm>

#define INFINITY 9999999
#define MAXN 100100

using namespace std;

vector < int > V[MAXN];
int i, j, n, from, to, cost, t;

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

    scanf ( "%d", &t );

    for ( int k = 1; k <= t; ++k ) {

        scanf ( "%d", &n );
        
        for ( int i = 0 ; i < n; ++i )
            V[i].clear(),visit[i]=0;

        for ( int i = 0 ; i < n-1; ++i ) {
            scanf ( "%d %d", &from, &to );
            V[from].push_back ( to );
            V[to].push_back ( from ); 
        }

        D[0] = 0;
        dfs ( 0, 0 );

        int node = 0;
        
        for ( int i = 0 ; i < n ; ++i )
            if ( D[i] > D[node] )
                node = i;

        memset ( visit, 0, sizeof(visit) );

        dfs ( node, 0 );

        sort ( D, D+n );
        
        int d = D[n-1];
        
        if ( d & 1 ) 
            cout << ( d>>1 ) + 1 << "\n";
        else
            cout << ( d >> 1 ) << "\n";

    }

    return 0;

}