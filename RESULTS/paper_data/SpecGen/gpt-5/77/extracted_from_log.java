class SVCOMP_linear_0287__72 {
//@ ensures \result == 0;
static int unknown() {
return 0;
}

//@ ensures true;
//@ ensures y == \old(y);
static void foo72(int y) {
int c = 0;
int z = 36 * y;

//@ maintaining 0 <= c && c <= 36;
//@ maintaining z == 36 * y + c;
while (unknown() != 0) {

if ( c < 36 )
{
z  = z + 1;
c  = c + 1;
}
}

}
}