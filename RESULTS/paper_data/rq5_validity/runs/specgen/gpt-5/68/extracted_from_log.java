class SVCOMP_linear_0231__306 {
/*@ spec_public
  @ ensures true;
  @*/
static void foo306(unsigned int n) {

unsigned
unsigned int j;
unsigned int i;
unsigned int l;

i = 0;
j = 0;
l = 0;

//@ maintaining 0 <= l && l <= n;
//@ maintaining i >= 0 && j >= 0;
//@ maintaining i + j == l;
//@ maintaining i == (l + 1) / 2 && j == l / 2;
//@ decreases n - l;
while (l < n) {
if ((l % 2) == 0) {
i = i + 1;
}
else{
j = j + 1;
}
l = l + 1;
}

}
}