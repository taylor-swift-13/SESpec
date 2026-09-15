class SVCOMP_linear_0149__232 {
//@ requires y >= 0;
//@ assignable \nothing;
//@ ensures y == \old(y);
static void foo232(/*unsigned*/ int y) {

 /*unsigned*/ int x;
 /*unsigned*/

x = 2;

//@ maintaining x >= 2 && x <= y;
//@ decreases y - x;
while (x < y) {
if (x < y / x) {
x *= x;
}
else {
x++;
}
}

}
}