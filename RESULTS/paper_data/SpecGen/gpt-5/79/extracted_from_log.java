class SVCOMP_linear_0290__75 {
/*@ ensures \result == 0; @*/
static int unknown() {
return 0;
}

/*@ ensures y == \old(y) && x1 == \old(x1) && x2 == \old(x2) && x3 == \old(x3); @*/
static void foo75(int y,int x1,int x2,int x3) {
int c = 0;
int z = 36 * y;

/*@ maintaining 0 <= c && c <= 36 && z == 36 * y + c; @*/
while (unknown() != 0) {

if ( c < 36 )
{
z  = z + 1;
c  = c + 1;
}
}

}
}