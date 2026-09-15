class SVCOMP_linear_0239__313 {
    /*@ public ghost int j_g;
      @ public ghost int i_g;
      @ public ghost int k_g;
      @ public ghost int v4_g;
      @ public ghost int v3_g;
      @ public ghost int v2_g;
      @ public ghost int v1_g;
      @ public ghost int v5_g;
      @ public ghost int v6_g;
      @ public ghost int l_g;
      @*/

    /*@ requires n >= 0;
      @ ensures l_g == n;
      @ ensures j_g >= 0 && i_g >= 0 && k_g >= 0 && v6_g >= 0 && v5_g >= 0 && v1_g >= 0 && v2_g >= 0 && v3_g >= 0 && v4_g >= 0;
      @ ensures j_g <= n && i_g <= n && k_g <= n && v6_g <= n && v5_g <= n && v1_g <= n && v2_g <= n && v3_g <= n && v4_g <= n;
      @ ensures j_g + i_g + k_g + v6_g + v5_g + v1_g + v2_g + v3_g + v4_g == n;
      @*/
static void foo313(unsigned int n) {

unsigned
unsigned int j;
unsigned int i;
unsigned int k;
unsigned int v4;
unsigned int v3;
unsigned int v2;
unsigned int v1;
unsigned int v5;
unsigned int v6;
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
v6 = 0;

/*@
    maintaining 0 <= l && l <= n;
    maintaining j >= 0 && i >= 0 && k >= 0 && v6 >= 0 && v5 >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0;
    maintaining j <= l && i <= l && k <= l && v6 <= l && v5 <= l && v1 <= l && v2 <= l && v3 <= l && v4 <= l;
    maintaining j + i + k + v6 + v5 + v1 + v2 + v3 + v4 == l;
    decreases n - l;
@*/
while (l < n) {
if((l % 9) == 0){
v6 = v6 + 1;
}
else if((l % 8) == 0){
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

/*@
    set j_g = j;
    set i_g = i;
    set k_g = k;
    set v4_g = v4;
    set v3_g = v3;
    set v2_g = v2;
    set v1_g = v1;
    set v5_g = v5;
    set v6_g = v6;
    set l_g = l;
@*/

}
}