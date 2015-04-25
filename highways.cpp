#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

#define MAXN 100010
#define INF 999999999
#define ii pair<int,int>

using namespace std;

vector < list<ii> > adj(MAXN);

struct state {
    int cost, id;
    state ( ) {}
    state ( int cost, int id ) : cost(cost), id(id) {}
};

bool operator < ( const state &a, const state &b ) {
    return ( a.cost > b.cost );
}

int tests, n, m, s, t, from, to, cost;
int D[MAXN];

int main ( ) {

    //freopen("in.txt","r",stdin);

    scanf ( "%d", &tests );

    while ( tests-- ) {

        scanf ( "%d %d %d %d", &n, &m, &s, &t );

        for ( int i = 1; i <= n; ++i )
            adj[i].clear();

        for ( int i = 1; i <= m; ++i ) {
            scanf ( "%d %d %d", &from, &to, &cost );
            adj[from].push_back ( ii(cost,to) );
            adj[to].push_back ( ii(cost,from) );
        }

        for ( int i = 1; i <= n; ++i )
            D[i] = INF;

        D[s] = 0;

        priority_queue < state > q;

        q.push ( state(cost,s) );

        while ( q.empty() == false ) {
        
            state top = q.top();
            q.pop();

            int u = top.id;

            for ( list<ii>::iterator pos = adj[u].begin(); pos != adj[u].end(); ++pos ) {
                if ( D[pos->second] > D[top.id]+pos->first ) {
                    D[pos->second] = D[top.id]+pos->first;
                    q.push ( state(D[top.id]+pos->first,pos->second) );
                }
            }

        }

        if ( D[t] != INF ) {
            printf ( "%d\n", D[t] );
        }else {
            printf ( "NONE\n" );
        }

    }

    return 0;

}