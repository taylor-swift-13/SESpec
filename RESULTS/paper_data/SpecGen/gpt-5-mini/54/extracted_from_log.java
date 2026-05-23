class SVCOMP_linear_0144__228 {
static void foo228() {
    //@ ensures true;

int x;
int y;

x = 0;
y = 0;
/*@
  @ maintaining 0 <= x && x <= 101;
  @ decreases 99 - x;
  @*/
while (x < 99) {
if(y % 2 == 0){
x = x + 2;
}
else{
x = x + 1;
}
}

}
}