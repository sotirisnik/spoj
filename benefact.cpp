#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

#define MAXN 50010
#define edge pair<int,int>

using namespace std;

int t , n , from , to , cost;
vector < list < edge > > adj(MAXN);
bool visited[MAXN];
int D[MAXN];

int BFS ( int start ) {

    for ( int i = 0; i < MAXN; ++i )
        visited[i] = false , D[i] = -1;

    D[start] = 0;

    queue < int > q;

    q.push ( start );

    while ( q.empty() == false ) {

        int top = q.front();
        q.pop();

        if ( visited[top] ) continue;

        visited[top] = true;

        for ( list<edge>::iterator pos = adj[top].begin(); pos != adj[top].end(); ++pos ) {
            int to = pos->second;
            int cost = pos->first;
            if ( D[to] < 0 ) {
                D[to] = D[top] + cost;
                q.push ( to );
            }
        }

    }

    int maxim = 1;
    
    for ( int i = 2; i <= n; ++i )
        if ( D[i] > D[maxim] )
            maxim = i;

    return ( maxim );

}

int main ( ) {

    //freopen("in.txt","r",stdin);

    scanf ( "%d" , &t );

    while ( t-- ) {

        scanf ( "%d" , &n );

        for ( int i = 1; i <= n; ++i )
            adj[i].clear();

        for ( int i = 1; i <= n-1; ++i ) {
            scanf ( "%d %d %d", &from, &to, &cost );
            adj[from].push_back ( make_pair ( cost, to ) );
            adj[to].push_back ( make_pair ( cost, from ) );
        }

        int start = BFS ( 1 );
        int sol = BFS ( start );

        printf ( "%d\n" , D[sol] );

    }

    return 0;

}