#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define MAXN 1010

using namespace std;

int parent[MAXN];

#define edge pair<int,int>

#define wedge pair<int,edge>

int find_set ( int x , int *parent ) {

    if ( x != parent[x] )
        parent[x] = find_set ( parent[x] , parent );
    return ( parent[x] );    

}

bool comp ( const wedge &a , const wedge &b ) {
    return a.first < b.first;
}

int t, p, n, m, from, to, cost;
long long sol;

vector < pair<int,edge> > G;

int main ( ) {
    
    //freopen ( "in.txt" , "r" , stdin );
    scanf ( "%d" , &t );

    while ( t-- ) {
    
        G.clear();
    
        scanf ( "%d %d %d" , &p , &n , &m );
        
        for ( int i = 0; i < m; ++i ) {
            scanf ( "%d %d %d" , &from , &to , &cost );   
            G.push_back ( make_pair ( cost , edge(from,to) ) );
        }
     
        sol = 0;

        for ( int i = 1; i <= n; ++i )
            parent[i] = i;

        sort ( G.begin() , G.end() , comp );

        for ( int i = 0; i < G.size(); ++i ) {
            int u = find_set ( G[i].second.first , parent );
            int v = find_set ( G[i].second.second , parent );
            if ( u != v ) {
                sol += G[i].first;
                parent[u] = parent[v];     
            }   
        }
     
        printf ( "%ld\n" , sol*p );
     
    }
    
    return 0;
       
}
