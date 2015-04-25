#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

#define MAXN 1000010

using namespace std;

int f , s , g , u , d;
bool visited[MAXN];
int D[MAXN];
queue <int> q;
int sol;

inline void readi( int &v ) {
    char c;
    while( (c=getchar())<'0' || c > '9' );
    v = c-'0';
    while( (c=getchar())>='0' && c <= '9' ) v = v*10 + c-'0';
}

int main ( ) {

    //freopen( "in.txt","r",stdin);

    //scanf ( "%d %d %d %d %d" , &f , &s , &g , &u ,&d );

    readi ( f ) , readi ( s ) , readi ( g ) , readi ( u ) , readi ( d );

    for ( int i = 0; i < MAXN; i++) 
        D[i] = -1;

    sol = -1;

    q.push ( s );
    D[s] = 0;

    while ( q.empty() == false ) {

        int top = q.front();
        q.pop();

        if ( visited[top] ) continue;

        visited[top] = true;

        if ( top == g ) {
            sol = D[top];
            break;
        }

        if ( (top+u) <= f && D[top+u] < 0 ) {
            q.push ( top+u );
            D[top+u] = D[top] + 1;
        }

        if ( (top-d) >= 1 && D[top-d] < 0 ) {
            q.push ( top-d ); 
            D[top-d] = D[top] + 1;
        }

    }

    if ( sol != -1 ) {
        printf ( "%d\n" , sol );
    }else {
        printf ( "use the stairs\n" );
    }

    return 0;

}
