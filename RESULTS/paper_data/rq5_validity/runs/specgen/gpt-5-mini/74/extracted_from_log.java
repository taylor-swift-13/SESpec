class SVCOMP_linear_0238__312 {
    //@ requires n >= 0;
    //@ ensures (\sum int x; 0 <= x && x < n && x % 8 == 0; 1) == v5;
    //@ ensures (\sum int x; 0 <= x && x < n && x % 8 != 0 && x % 7 == 0; 1) == v1;
    //@ ensures (\sum int x; 0 <= x && x < n && x % 8 != 0 && x % 7 != 0 && x % 6 == 0; 1) == v2;
    //@ ensures (\sum int x; 0 <= x && x < n && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 == 0; 1) == v3;
    //@ ensures (\sum int x; 0 <= x && x < n && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 != 0 && x % 4 == 0; 1) == v4;
    //@ ensures (\sum int x; 0 <= x && x < n && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 != 0 && x % 4 != 0 && x % 3 == 0; 1) == i;
    //@ ensures (\sum int x; 0 <= x && x < n && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 != 0 && x % 4 != 0 && x % 3 != 0 && x % 2 == 0; 1) == j;
    //@ ensures (\sum int x; 0 <= x && x < n && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 != 0 && x % 4 != 0 && x % 3 != 0 && x % 2 != 0; 1) == k;
    //@ ensures (\sum int x; 0 <= x && x < n; 1) == (v5 + v1 + v2 + v3 + v4 + i + j + k);
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

    //@ maintaining 0 <= l && l <= n;
    //@ maintaining v5 == (\sum int x; 0 <= x && x < l && x % 8 == 0; 1);
    //@ maintaining v1 == (\sum int x; 0 <= x && x < l && x % 8 != 0 && x % 7 == 0; 1);
    //@ maintaining v2 == (\sum int x; 0 <= x && x < l && x % 8 != 0 && x % 7 != 0 && x % 6 == 0; 1);
    //@ maintaining v3 == (\sum int x; 0 <= x && x < l && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 == 0; 1);
    //@ maintaining v4 == (\sum int x; 0 <= x && x < l && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 != 0 && x % 4 == 0; 1);
    //@ maintaining i  == (\sum int x; 0 <= x && x < l && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 != 0 && x % 4 != 0 && x % 3 == 0; 1);
    //@ maintaining j  == (\sum int x; 0 <= x && x < l && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 != 0 && x % 4 != 0 && x % 3 != 0 && x % 2 == 0; 1);
    //@ maintaining k  == (\sum int x; 0 <= x && x < l && x % 8 != 0 && x % 7 != 0 && x % 6 != 0 && x % 5 != 0 && x % 4 != 0 && x % 3 != 0 && x % 2 != 0; 1);
    //@ maintaining (\sum int x; 0 <= x && x < l; 1) == (v5 + v1 + v2 + v3 + v4 + i + j + k);
    //@ decreases n - l;
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