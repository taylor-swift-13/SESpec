class SVCOMP_linear_0304__88 {
static int unknown() {
return 0;
}

static int foo88(int x) {

int lock = 1;
int y = x + 1;

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
