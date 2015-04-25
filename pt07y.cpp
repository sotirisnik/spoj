#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>

#define MAXN 10010

using namespace std;

vector < list < int > > adj(MAXN);

bool visited[MAXN];
int n, m, from, to, tot;;
int maxu = 0;

void dfs( int u ) {

    visited[u] = true;
    maxu += 1;

    for ( list<int>::iterator pos = adj[u].begin(); pos != adj[u].end(); ++pos ) {
        if ( !visited[ *pos ] )
            dfs ( *pos );
    }

}

int main( ) {
    
    //freopen("in.txt","r",stdin);

    scanf ( "%d %d", &n, &m );

    for ( int i = 0; i < m; ++i ) {
        scanf ( "%d %d", &from, &to );
        adj[from].push_back ( to );
        adj[to].push_back ( from );
    }

    dfs ( 1 );

    if ( m == 0 ) {
        printf ( "NO\n" );
    }else if ( maxu == n && m == n-1 ) {
        printf ( "YES\n" );
    }else {
        printf ( "NO\n" );
    }

    return 0;

}
