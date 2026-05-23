class SVCOMP_linear_0092__181 {
static void foo181(int i, int j, int k) {
//@ requires k <= 0 || (k > 0 && k <= Integer.MAX_VALUE / 2 && i <= Integer.MAX_VALUE - k && j <= Integer.MAX_VALUE - k);
//@ ensures (k <= 0 ==> (i == \old(i) && j == \old(j))) && (k > 0 ==> (i == \old(i) + k && j == \old(j) + k));
//@ ensures k == \old(k);

int n;
int b;

n = 0;
b = 0;

//@ maintaining k == \old(k);
//@ maintaining n >= 0;
//@ maintaining (k <= 0 ==> n == 0) && (k > 0 ==> n <= 2 * k);
//@ maintaining b == n % 2;
//@ maintaining i + j == \old(i) + \old(j) + n;
//@ decreases (k > 0 ? 2 * k - n : 0);
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