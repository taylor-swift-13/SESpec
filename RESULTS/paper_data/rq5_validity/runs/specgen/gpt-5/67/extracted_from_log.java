class SVCOMP_linear_0225__300 {
static void foo300(int n) {
//@ requires n >= 0;
//@ ensures n == \old(n);
    /*@ spec_public @*/
int i;
int k;
int j;

i = 0;
j = 0;
k = 0;

//@ maintaining 0 <= i && i % 3 == 0 && j % 3 == 0 && k % 3 == 0;
//@ maintaining i == j + k;
//@ maintaining i <= n;
//@ decreases n - i;
while(i < n){
i = i + 3;
if((i % 2) != 0)
j = j + 3;
else
k = k + 3;
}

}
}