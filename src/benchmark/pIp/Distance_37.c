 typedef struct Point {
    int x;
    int y;
} Point;

typedef struct _Point_Pair{
    Point p1;
    Point p2;
} Points;


/*@
requires \valid(pIp);
*/
int distance(Points* pIp) {
    int dx = pIp->p2.x - pIp->p1.x;
    int dy = pIp->p2.y - pIp->p1.y;
    return dx * dx + dy * dy;
}

/*@
requires \valid(pIp);
*/
void main37(Points* pIp) {
    pIp->p1.x = 1;
    pIp->p1.y = 2;
    pIp->p2.x = 3;
    pIp->p2.y = 4;
    int result = distance(pIp);
    /*@ assert result == 8; */
}

