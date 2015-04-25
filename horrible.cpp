#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAXN 100001

int t, n, c, what, from, to, v;

struct state {
    long long numleaves, sum, add;

    void split( state &l, state &r ) {
        l.add += add;
        l.sum += add * l.numleaves;
        r.add += add;
        r.sum += add * r.numleaves;
        add = 0;
    }
    
    void merge( state &l, state &r ) {
        numleaves = l.numleaves + r.numleaves;
        add = 0;
        sum = l.sum + r.sum;
    }

};

state node[4*MAXN];
state identity;

void update ( int v, int x, int y, int qx, int qy, long long val ) {

    if ( qx == x && qy == y ) {
        node[v].add += val;
        node[v].sum += (long long)val * node[v].numleaves;
        return;
    }

    int mid = ( x + y ) / 2;

    node[v].split( node[2*v], node[2*v+1] );
    
    if ( qy <= mid ) {
        update ( 2*v, x, mid, qx, qy, val );     
    }else if ( qx > mid ) {
        update ( 2*v+1, mid+1, y, qx, qy, val );
    }else {
        update ( 2*v, x, mid, qx, mid, val );
        update ( 2*v+1, mid+1, y, mid+1, qy, val );
    }
    
    node[v].merge( node[2*v], node[2*v+1] );
    
}

state query ( int v, int x, int y, int qx, int qy ) {

    if ( qx == x && qy == y ) {
        return ( node[v] );
    }

    int mid = ( x + y ) / 2;

    node[v].split( node[2*v], node[2*v+1] );
    
    state q1 = identity, q2 = identity;

    if ( qy <= mid ) {
        q1 = query ( 2*v, x, mid, qx, qy );
    }else if ( qx > mid ) {
        q2 = query ( 2*v+1, mid+1, y, qx, qy );
    }else {
        q1 = query ( 2*v, x, mid, qx, mid );
        q2 = query ( 2*v+1, mid+1, y, mid+1, qy );
    }

    node[v].merge( node[2*v], node[2*v+1] );
    
    state ret;
    ret.merge( q1, q2 );
    return ( ret );

}

void build ( int v, int begin, int end ) {

    if ( begin == end ) {
        node[v].sum = node[v].add = 0;
        node[v].numleaves = 1;
        return;
    }

    int mid = ( begin + end ) / 2;

    build ( 2*v, begin, mid );
    build ( 2*v+1, mid+1, end );

    node[v].merge( node[2*v], node[2*v+1] );

}

inline void readi(int &v){
    char c;
    while( (c=getchar())<'0' || c > '9' );
    v = c-'0';
    while( (c=getchar())>='0' && c <= '9' ) v = v*10 + c-'0';
}

int main ( ) {

    //freopen("in.txt","r",stdin);

    identity.add = identity.sum = identity.numleaves = 0;
    
    readi ( t );//scanf ( "%d", &t );

    while ( t-- ) {

        readi ( n );
        readi ( c );//scanf ( "%d %d", &n, &c );

        build ( 1, 1, n );

        while ( c-- ) {
           
            readi ( what );//scanf ( "%d", &what );
            if ( what == 0 ) {
               readi ( from );
               readi ( to );
               readi ( v );//scanf ( "%d %d %d", &from, &to, &v );
               update ( 1, 1, n, from, to, v );    
            }else {
                readi ( from );
                readi ( to );//scanf ( "%d %d", &from, &to );
                printf ( "%lld\n",  query ( 1, 1, n, from, to ).sum );      
            }
      
        }
     
    }

    return 0;
   
}
