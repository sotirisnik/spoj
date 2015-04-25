#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct point {
    double x, y;
};

struct circle {
    double x, y, radius;
};

int t;
point player, goalup, goaldown;
circle goalkeeper;

double square( double x ) {

    return ( (double)x*x );

}

bool solve( point p1, point p2, circle c1 ) {

    double c = (double)( p2.y - p1.y ) / (double)( p2.x - p1.x );
    
    double lamda = ( p1.y - c*p1.x - c1.y );
    
    double Delta = square( -2.0*c1.x + 2.0*c*lamda ) - 4.0 * ( 1.0 + square(c) ) * ( square(c1.x) + square(lamda) - square(c1.radius) );
    
    if ( Delta < 0 || Delta < 1e-9 ) {
        return ( false );
    }
    
    return ( true );
    
}

int main( ) {

    scanf( "%d", &t );
    
    goalup.x = goaldown.x = 52.0;
    goalup.y = 3.66;
    goaldown.y = -3.66;
    
    while ( t-- ) {
    
        scanf( "%lf %lf %lf %lf %lf", &player.x, &player.y, &goalkeeper.x, &goalkeeper.y, &goalkeeper.radius );
    
        if ( solve(player,goalup,goalkeeper) && solve(player,goaldown,goalkeeper) ) {
            printf( "No goal...\n" );
        }else {
            printf( "Goal!\n" );
        }
    
    }
    
    return 0;

}