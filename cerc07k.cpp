#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <algorithm>

#define MAXN 110

using namespace std;

int visited[MAXN][MAXN][16];

struct state {
    int x, y, keys;
};

state start, top, tmp, goal;

int R , C;
char a[MAXN][MAXN];
int D[MAXN][MAXN][16];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool valid ( int x , int y ) {
     if ( x < 1 || y < 1 ) return ( false );
     if ( x > R || y > C ) return ( false );
     return ( true );
}

int main ( ) {

    //freopen( "in.txt" , "r" , stdin );

    while ( true ) {

        scanf ( "%d %d" , &R , &C );

        if ( R == 0 && C == 0 ) break;

        for ( int i = 1; i <= R; ++i )
            for ( int j = 1; j <= C; ++j ) {
                scanf ( " %c" , &a[i][j] );
                if ( a[i][j] == '*' ) {
                    start.x = i;
                    start.y = j;
                    start.keys = 0;
                    a[i][j] = '.';
               }
            }

        for ( int k = 0; k <= 16; ++k )
            for ( int i = 1; i <= R; ++i )
                for ( int j = 1; j <= C; ++j )
                    D[i][j][k] = -1;
     

        bool fl = false;

        D[start.x][start.y][start.keys] = 0;

        queue < state > q;

        q.push ( start );

        while ( q.empty() == false ) {
            top = q.front();
            q.pop();

            if ( a[top.x][top.y] == 'X' ) {
                fl = true;
                goal = top;
                break;
            }

            for ( int i = 0; i < 4; ++i ) {
            
                if ( valid ( top.x+dx[i] , top.y+dy[i] ) && D[top.x+dx[i]][top.y+dy[i]][top.keys] < 0 ) {
                
                    if ( a[top.x+dx[i]][top.y+dy[i]] == '.' || a[top.x+dx[i]][top.y+dy[i]] == 'X' ) {
                        tmp = top;               
                        tmp.x = top.x+dx[i];
                        tmp.y = top.y+dy[i];
                        D[tmp.x][tmp.y][tmp.keys] = D[top.x][top.y][top.keys] + 1;
                        q.push ( tmp );
                    }

                    //'B','Y','R','G'
               
                    if ( a[top.x+dx[i]][top.y+dy[i]] == 'b' ) {
                        tmp = top;
                        tmp.x = top.x+dx[i];
                        tmp.y = top.y+dy[i];
                        tmp.keys = tmp.keys | (int)pow( 2 , 0 );
                        D[tmp.x][tmp.y][tmp.keys] = D[top.x][top.y][top.keys] + 1;
                        q.push ( tmp );
                    }

                    if ( a[top.x+dx[i]][top.y+dy[i]] == 'y' ) {
                        tmp = top;
                        tmp.x = top.x+dx[i];
                        tmp.y = top.y+dy[i];
                        tmp.keys = tmp.keys | (int)pow( 2 , 1 );
                        D[tmp.x][tmp.y][tmp.keys] = D[top.x][top.y][top.keys] + 1;
                        q.push ( tmp );
                    }

                    if ( a[top.x+dx[i]][top.y+dy[i]] == 'r' ) {
                        tmp = top;
                        tmp.x = top.x+dx[i];
                        tmp.y = top.y+dy[i];
                        tmp.keys = tmp.keys | (int)pow( 2 , 2 );
                        D[tmp.x][tmp.y][tmp.keys] = D[top.x][top.y][top.keys] + 1;
                        q.push ( tmp );
                    }

                    if ( a[top.x+dx[i]][top.y+dy[i]] == 'g' ) {
                        tmp = top;
                        tmp.x = top.x+dx[i];
                        tmp.y = top.y+dy[i];
                        tmp.keys = tmp.keys | (int)pow( 2 , 3 );
                        D[tmp.x][tmp.y][tmp.keys] = D[top.x][top.y][top.keys] + 1;
                        q.push ( tmp );
                    }
                    
                    if ( a[top.x+dx[i]][top.y+dy[i]] == 'R' && top.keys & (int)pow(2,2) ) {
                        tmp = top;
                        tmp.x = top.x+dx[i];
                        tmp.y = top.y+dy[i];
                        D[tmp.x][tmp.y][tmp.keys] = D[top.x][top.y][top.keys] + 1;
                        q.push ( tmp );
                    }

                    if ( a[top.x+dx[i]][top.y+dy[i]] == 'G' && top.keys & (int)pow(2,3) ) {
                        tmp = top;
                        tmp.x = top.x+dx[i];
                        tmp.y = top.y+dy[i];
                        D[tmp.x][tmp.y][tmp.keys] = D[top.x][top.y][top.keys] + 1;
                        q.push ( tmp );
                    }

                }

            }

        }

        if ( fl ) {
            printf ( "Escape possible in %d steps.\n" , D[goal.x][goal.y][goal.keys] );
        }else {
            printf ( "The poor student is trapped!\n" );
        }
        
    }

    return 0;

}