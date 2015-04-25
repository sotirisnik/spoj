#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int t, A, B, C;
//Ax + B*sin(x) = C
       
double f( double x ) {

    return ( (double)A*(double)x + (double)B*(double)sin(x) );
       
}

int main( ) {
    
    //freopen("in.txt","r",stdin);

    scanf ( "%d", &t );

    while ( t-- ) {

        scanf ( "%d %d %d", &A, &B, &C );

        double lo = 0.0f;
        double hi = 300000.0f;

        while ( hi-lo > 1e-7 ) {

            double mid = ( lo + hi ) / 2.;

            if ( f(mid) > C )
                hi = mid;
            else
                lo = mid;

        }

        printf ( "%.6lf\n", (lo+hi)/2. );

    }

    return 0;
    
}
