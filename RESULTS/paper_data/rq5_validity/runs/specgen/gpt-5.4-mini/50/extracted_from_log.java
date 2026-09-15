class SVCOMP_linear_0092__181 {
    /*@ requires true;
      @ ensures true;
      @*/
static void foo181(int i, int j, int k) {

int n;
int b;

n = 0;
b = 0;

/*@ maintaining 0 <= n;
 
  @ maintaining (b == 0 || b == 1);
  @ decreases (2 * k) - n;
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