class SVCOMP_linear_0238__312 {
/*@ 
  @ requires n >= 0;
  @ ensures n == \old(n);
  @*/
static void foo312(unsigned int n) {

unsigned
unsigned int j;
unsigned int i;
unsigned int k;
unsigned int v4;
unsigned int v3;
unsigned int v2;
unsigned int v1;
unsigned int v5;
unsigned int l;

i = 0;
k = 0;
j = 0;
l = 0;
v4 = 0;
v3 = 0;
v2 = 0;
v1 = 0;
v5 = 0;

/*@ 
  @ loop_invariant 0 <= l && l <= n;
  @ loop_invariant v5 + v1 + v2 + v3 + v4 + i + j + k == l;
  @ loop_invariant v5 >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0;
  @ loop_invariant v5 == (\num_of int m; 0 <= m && m < l; (m % 8) == 0);
  @ loop_invariant v1 == (\num_of int m; 0 <= m && m < l; (m % 8) != 0 && (m % 7) == 0);
  @ loop_invariant v2 == (\num_of int m; 0 <= m && m < l; (m % 8) != 0 && (m % 7) != 0 && (m % 6) == 0);
  @ loop_invariant v3 == (\num_of int m; 0 <= m && m < l; (m % 8) != 0 && (m % 7) != 0 && (m % 6) != 0 && (m % 5) == 0);
  @ loop_invariant v4 == (\num_of int m; 0 <= m && m < l; (m % 8) != 0 && (m % 7) != 0 && (m % 6) != 0 && (m % 5) != 0 && (m % 4) == 0);
  @ loop_invariant i  == (\num_of int m; 0 <= m && m < l; (m % 8) != 0 && (m % 7) != 0 && (m % 6) != 0 && (m % 5) != 0 && (m % 4) != 0 && (m % 3) == 0);
  @ loop_invariant j  == (\num_of int m; 0 <= m && m < l; (m % 8) != 0 && (m % 7) != 0 && (m % 6) != 0 && (m % 5) != 0 && (m % 4) != 0 && (m % 3) != 0 && (m % 2) == 0);
  @ loop_invariant k  == (\num_of int m; 0 <= m && m < l; (m % 8) != 0 && (m % 7) != 0 && (m % 6) != 0 && (m % 5) != 0 && (m % 4) != 0 && (m % 3) != 0 && (m % 2) != 0);
  @ decreases n - l;
  @*/
while (l < n) {
if((l % 8) == 0){
v5 = v5 + 1;
}
else if((l % 7) == 0){
v1 = v1 + 1;
}
else if((l % 6) == 0){
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