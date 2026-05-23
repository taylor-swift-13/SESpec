class SVCOMP_linear_0183__263 {
/*@ 
  @ ensures true;
  @ assignable \nothing;
  @*/
 /*@ spec_public @*/ static void foo263(int k) {

int n;
int i;

n = 0;
i = 0;

//@ maintaining 0 <= i;
//@ maintaining n == (i + 1) / 2;
//@ decreases 2 * k - i;
while (i < 2 * k) {
if(i % 2 == 0){
n = n + 1;
}
i = i + 1;
}

}
}