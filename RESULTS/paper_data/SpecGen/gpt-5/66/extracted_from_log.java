class SVCOMP_linear_0206__284 {
/*@ 
  @ assignable \nothing;
  @ ensures y == (\old(y) <= 0 ? \old(y) : 0);
  @*/
static void foo284(int y) {

int x;

x = 4 * y;

/*@ 
  @ maintaining x == 4 * y && x >= 0;
  @ decreases x / 4;
  @*/
while (x > 0) {
x -= 4;
y--;
}

}
}