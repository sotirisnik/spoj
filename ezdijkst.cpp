#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

#define INF 99999999
#define ii pair<int,int>
#define MAXN 10000

using namespace std;

int i, j, n, V, K, s, t, from, to, cost;

int Dijkstra( ) {

    vector< list<ii> > v(MAXN);
    list<ii>::iterator pos;

    for ( int j = 0; j < K; ++j ) {
        scanf ( "%d %d %d", &from, &to, &cost );
        v[from].push_back ( make_pair ( cost, to ) );
    }

    scanf ( "%d %d", &s, &t );

    vector <int> D(V+1,INF);

    priority_queue < ii > q;

    D[s] = 0;

    q.push ( make_pair ( 0, s ) );

    while ( q.empty() == false ) {
    
        ii top = q.top();
        q.pop();

        if ( top.first <= D[top.second] ) {
            for ( pos = v[top.second].begin(); pos != v[top.second].end(); ++pos ) {
                int v2 = pos->second; int cost = pos->first;
                if ( D[v2] > D[top.second] + cost ) {
                    D[v2] = D[top.second] + cost;
                    q.push ( make_pair ( D[v2], v2 ) );
                } 
            }
        }
        
    }

    return ( D[t] );

}

int main ( ) {

    scanf ( "%d", &n );

    for ( int i = 0; i < n; ++i ) {
    
        scanf ( "%d %d", &V, &K );

        int sol = Dijkstra ( );

        if ( sol != INF )
            printf ( "%d\n", sol );
        else
            printf ( "NO\n" );

    }

    return 0;

}