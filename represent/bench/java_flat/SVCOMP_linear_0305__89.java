class SVCOMP_linear_0305__89 {
static int unknown() {
return 0;
}

static int foo89(int y,int v1,int v2,int v3) {

int lock = 1;
int x = y;

while (x != y) {
if (unknown()) {

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
