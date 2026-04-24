class SVCOMP_unlinear_0044__21 {
static int hoo21(int X,int Y) {

int v, x, y;

v = 2 * Y - X;
y = 0;
x = 0;

while (x <= X) {
if (v < 0) {
v = v + 2 * Y;
} else {
v = v + 2 * (Y - X);
y++;
}
x++;

}

return 0;
}
}
