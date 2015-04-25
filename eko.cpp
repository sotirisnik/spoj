#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 1000001

using namespace std;

int n, m, st, en;
int a[MAXN];

int main( ) {
    
    //freopen("in.txt","r",stdin);

    scanf ( "%d %d", &n, &m );

    for ( int i = 0; i < n; ++i ) {
        scanf ( "%d", &a[i] );
        en = max ( en, a[i] );
    }

    while ( st < en ) {

        int mid = ( st + en + 1 ) / 2;

        long long tmp = 0;
        for ( int i = 0; i < n; ++i )
            tmp += max ( 0, a[i] - mid );

        if ( tmp >= m )
            st = mid;
        else
            en = mid-1;

    }

    printf ( "%d\n", st );

    return 0;
       
}
