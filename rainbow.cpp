#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

#define MAXN 1001
#define INF 999999999

using namespace std;

int p[MAXN],rank[MAXN],num[MAXN],m[MAXN], weight[MAXN];

int set[MAXN], tot;
int memo[MAXN][MAXN];

int n, c, how, x;

int find_set( int x ) {

    if ( x != p[x] )
        p[x] = find_set( p[x] );

    return ( p[x] );

}

void Union( int x, int y ) {

    int px = find_set(x);
    int py = find_set(y);

    if ( rank[px] > rank[py] ) {
        p[py] = px;
    }else {
        p[px] = py;

        if ( rank[px] == rank[py] ) {
            ++rank[py];     
        }

    }
     
}

int best( int i, int how ) {
    
    if ( how < 0 )
        return ( -INF );

    if ( i == tot+1 ) {
        if ( how < 0 )
            return ( -INF );
        return 0;     
    }

    if ( memo[i][how] != -1 )
        return ( memo[i][how] );

    int Best = 0;

    int c1 = num[i] + best( i+1, how-m[i] );
    int c2 = best( i+1, how );

    Best = max( Best, max( c1, c2 ) );

    memo[i][how] = Best;

    return ( memo[i][how] );
        
}

int main( ) {

    //freopen("in.txt","r",stdin);

    while ( true ) {

        scanf ( "%d %d", &n, &c );

        if ( n == 0 && c == 0 )
            break;

        for ( int i = 1; i <= n; ++i )
            scanf ( "%d", &weight[i] );

        for ( int i = 1; i <= n; ++i ) {
            rank[i] = 0;
            num[i] = 0;
            m[i] = 0;
            p[i] = i;
        }

        for ( int i = 1; i <= n; ++i ) {

            scanf ( "%d", &how );

            while ( how-- ) {
                scanf ( "%d", &x );
                Union( i, x );    
            }

        }

        tot = 0;

        for ( int i = 1; i <= n; ++i ) {

            x = find_set( i );
            ++num[x];
            m[ x ] += weight[i];

        }

        for ( int i = 1; i <= n; ++i ) {

            if ( num[i] ) {
            ++tot;
            num[tot] = num[i];
            m[tot] = m[i];
            }

        }

        memset( memo, -1, sizeof(memo) );

        printf ( "%d\n", best( 1, c ) );

    }

    return 0;

}
