#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

#define MAXN 110

using namespace std;

char key[] = {'A','L','L','I','Z','Z','W','E','L','L'};
char map[MAXN][MAXN];

int dx[] = {-1,1,0,0,-1,-1,1,1};
int dy[] = {0,0,-1,1,-1,1,-1,1};

int t, R, C;

bool valid( int x, int y ) {
     if ( x < 0 || y < 0 ) return ( false );
     if ( x >= R || y >= C ) return ( false );
     return ( true );     
}

bool visited[MAXN][MAXN];

bool dfs( int i, int j, int cnt ) {

    if ( cnt == 10 )
        return ( true );

    visited[i][j] = true;

    for ( int k = 0; k < 8; ++k )
        if ( valid(i+dx[k],j+dy[k]) )
            if ( visited[i+dx[k]][j+dy[k]] == false && map[i+dx[k]][j+dy[k]] == key[ cnt ] )
                if ( dfs( i+dx[k], j+dy[k], cnt+1 ) )
                    return ( true );
       
    visited[i][j] = false;

    return ( false );
     
}

int main( ) {

    //freopen(in.txt,r,stdin);

    scanf( "%d", &t );

    while ( t-- ) {

        scanf( "%d %d", &R, &C );

        for ( int i = 0; i < R; ++i )
            scanf ( "%s", map[i] );

        bool fl = false;

        memset ( visited, false, sizeof(visited) );

        for ( int i = 0; i < R; ++i )
            for ( int j = 0; j < C; ++j )
                if ( map[i][j] == 'A' && dfs(i,j,1) ) {
                    fl = true;
                    i = R+1;
                    j = C+1;
                    break;   
                }

        if ( fl ) {
            printf ( "YES\n" );
        }else {
            printf ( "NO\n" );     
        }

    }

    return 0;
    
}
