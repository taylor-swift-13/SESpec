class SVCOMP_linear_0086__176 {
    /*@
      @ ensures (k <= 0 ==> (i == \old(i) && j == \old(j)))
      @      && (k > 0 ==> (i == \old(i) + k && j == \old(j) + k));
      @ assignable \nothing;
      @*/
static void foo176(int i, int j, int k) {

int n;
int b;

n = 0;
b = 1;

/*@ 
  @ maintaining k == \old(k);
  @ maintaining i == \old(i) + (n + 1) / 2;
  @ maintaining j == \old(j) + n / 2;
  @ maintaining b == ((n % 2 == 0) ? 1 : 0);
  @ maintaining (k <= 0 ==> n == 0) && (k > 0 ==> 0 <= n && n <= 2 * k);
  @ decreases (k > 0 ? 2 * k - n : 0);
  @*/
while(n < (2 * k)){
n = n + 1;
if(b == 1){
b = 0;
i = i + 1;
}
else{
b = 1;
j = j + 1;
}
}

}
}