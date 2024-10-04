#include <bits/stdc++.h>
#define ll long double
#define DEBUG 1
#define DEBUG_PRINT(msg...) if(DEBUG) printf(msg)

// TODO: GOTTA FIX THIS SHIT

typedef struct Point {
    ll x;
    ll y;
} Point;

int intersects(const Point &p, const std::vector<Point> &verts, int N) {
    int count = 0; // no of intersections
    for (int i=0; i<N; i++) {
        // shift coordinates
        Point A = { verts[i].x - p.x, verts[i].y - p.y };
        Point B = { verts[(i+1)%N].x - p.x, verts[(i+1)%N].y - p.y };
        
        ll K = ( A.x * (B.y - A.y) - A.y * (B.x - A.x) );
        if ( -.00001 < K && K < .00001 && (A.y != B.y)) return -1; // is on the boundary
        if ((A.x == 0 && A.y == 0) || (B.x == 0 && B.y == 0)) return -1; // is a vertex

        // slightly ajust the y value to ensure the ray doesnt hit it exactly
        if (A.y == 0) A.y += .01;
        if (B.y == 0) B.y += .01;
        

        if ( A.y * B.y < 0 && K * (B.y - A.y) > 0) count++;
    }
    return count;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<Point> verts(n);

    for (int i=0; i<n; i++) std::cin >> verts[i].x >> verts[i].y;
    for (int i=0; i<m; i++) {
        ll px, py;
        std::cin >> px >> py;
        int count = intersects({px, py}, verts, n);
        
        if (count == -1) printf("BOUNDARY\n");
        else if (count%2 == 0) printf("OUTSIDE\n");
        else if (count%2 == 1) printf("INSIDE\n");
    }
}