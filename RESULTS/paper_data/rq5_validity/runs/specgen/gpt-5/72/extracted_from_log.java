class SVCOMP_linear_0236__310 {
//@ requires n >= 0;
//@ assignable \nothing;
//@ ensures true;
static void foo310(unsigned int n) {

unsigned
unsigned int j;
unsigned int i;
unsigned int k;
unsigned int v4;
unsigned int v3;
unsigned int v2;
unsigned int l;

i = 0;
k = 0;
j = 0;
l = 0;
v4 = 0;
v3 = 0;
v2 = 0;

//@ maintaining 0 <= l && l <= n;
//@ maintaining v2 >= 0 && v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0;
//@ maintaining v2 + v3 + v4 + i + j + k == l;
//@ maintaining v2 == (\sum int t; 0 <= t && t < l; ((t % 6) == 0 ? 1 : 0));
//@ maintaining v3 == (\sum int t; 0 <= t && t < l; ((t % 5) == 0 && (t % 6) != 0 ? 1 : 0));
//@ maintaining v4 == (\sum int t; 0 <= t && t < l; ((t % 4) == 0 && (t % 5) != 0 && (t % 6) != 0 ? 1 : 0));
//@ maintaining i  == (\sum int t; 0 <= t && t < l; ((t % 3) == 0 && (t % 4) != 0 && (t % 5) != 0 && (t % 6) != 0 ? 1 : 0));
//@ maintaining j  == (\sum int t; 0 <= t && t < l; ((t % 2) == 0 && (t % 3) != 0 && (t % 4) != 0 && (t % 5) != 0 && (t % 6) != 0 ? 1 : 0));
//@ maintaining k  == (\sum int t; 0 <= t && t < l; ((t % 2) != 0 && (t % 3) != 0 && (t % 5) != 0 ? 1 : 0));
//@ decreases n - l;
while (l < n) {
if((l % 6) == 0){
v2 = v2 + 1;
}
else if ((l % 5) == 0){
v3 = v3 + 1;
}
else if ((l % 4) == 0) {
v4 = v4 + 1;
}
else if((l % 3) == 0){
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