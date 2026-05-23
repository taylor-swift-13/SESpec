class SVCOMP_linear_0234__309 {
/*@ requires n >= 0;
  @ ensures i >= 0 && j >= 0 && k >= 0 && v3 >= 0 && v4 >= 0;
  @ ensures i + j + k + v3 + v4 == n;
  @ ensures v3 == (\sum int t; 0 <= t && t < n && t % 5 == 0; 1);
  @ ensures v4 == (\sum int t; 0 <= t && t < n && t % 5 != 0 && t % 4 == 0; 1);
  @ ensures i == (\sum int t; 0 <= t && t < n && t % 5 != 0 && t % 4 != 0 && t % 3 == 0; 1);
  @ ensures j == (\sum int t; 0 <= t && t < n && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 == 0; 1);
  @ ensures k == (\sum int t; 0 <= t && t < n && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 != 0; 1);
  @*/
static void foo309(unsigned int n) {

unsigned
/*@ spec_public @*/ unsigned int j;
/*@ spec_public @*/ unsigned int i;
/*@ spec_public @*/ unsigned int k;
/*@ spec_public @*/ unsigned int v4;
/*@ spec_public @*/ unsigned int v3;
/*@ spec_public @*/ unsigned int l;

i = 0;
k = 0;
j = 0;
l = 0;
v4 = 0;
v3 = 0;

/*@ maintaining 0 <= l && l <= n;
  @ maintaining i >= 0 && j >= 0 && k >= 0 && v3 >= 0 && v4 >= 0;
  @ maintaining i + j + k + v3 + v4 == l;
  @ maintaining v3 == (\sum int t; 0 <= t && t < l && t % 5 == 0; 1);
  @ maintaining v4 == (\sum int t; 0 <= t && t < l && t % 5 != 0 && t % 4 == 0; 1);
  @ maintaining i == (\sum int t; 0 <= t && t < l && t % 5 != 0 && t % 4 != 0 && t % 3 == 0; 1);
  @ maintaining j == (\sum int t; 0 <= t && t < l && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 == 0; 1);
  @ maintaining k == (\sum int t; 0 <= t && t < l && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 != 0; 1);
  @ decreases n - l;
  @*/
while (l < n) {
if ((l % 5) == 0){
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