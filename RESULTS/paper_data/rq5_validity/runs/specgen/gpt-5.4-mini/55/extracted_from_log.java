class SVCOMP_linear_0149__232 {
    /*@ requires true;
      @ ensures true;
      @*/
static void foo232(int y) {

int x;

x = 2;

/*@ maintaining x >= 2;
 
  @ decreases y - x;
  @*/
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