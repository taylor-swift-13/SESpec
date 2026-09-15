class SVCOMP_linear_0232__307 {
    //@ requires n >= 0;
    //@ ensures n >= 0;
static void foo307(int n) {

int j;
int i;
int k;
int l;

i = 0;
k = 0;
j = 0;
l = 0;

/*@ maintaining 0 <= l && l <= n;
  @ maintaining i >= 0 && j >= 0 && k >= 0;
  @ maintaining i + j + k == l;
  @ decreases n - l;
  @*/
while (l < n) {
if ((l % 3) == 0) {
i = i + 1;
}
else if((l % 2) == 0){
j = j + 1;
}
else{
k = k + 1;
}
l = l + 1;
}

}
}