class SVCOMP_linear_0303__87 {
static int unknown() {
return 0;
}

static int foo87(int y) {

int lock = 1;
int x = y;

while (x != y) {
if ( unknown() ) {

lock  = 1;
x  = y;

} else {

lock  = 0;
x  = y;
y  = y + 1;

}

}

return 0;
}
}
