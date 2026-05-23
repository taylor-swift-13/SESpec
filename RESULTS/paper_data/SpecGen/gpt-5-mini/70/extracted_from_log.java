class SVCOMP_linear_0233__308 {
static void foo308(/* unsigned */ int n) {

/* unsigned */
 /* unsigned */ int j;
 /* unsigned */ int i;
 /* unsigned */ int k;
 /* unsigned */ int v4;
 /* unsigned */ int l;

/*@
  @ requires n >= 0;
  @ 
  @ // The method classifies each integer x in [0,n) into exactly one of four buckets:
  @ // v4  : x % 4 == 0
  @ // i   : x % 4 != 0 && x % 3 == 0
  @ // j   : x % 4 != 0 && x % 3 != 0 && x % 2 == 0
  @ // k   : x % 4 != 0 && x % 3 != 0 && x % 2 != 0
  @ //
  @ // Final counts add up to n and equal the number of elements satisfying the corresponding predicates.
  @ ensures i + j + k + v4 == n;
  @ ensures v4 == (\num_of int x; 0 <= x && x < n && x % 4 == 0; 1);
  @ ensures i  == (\num_of int x; 0 <= x && x < n && x % 4 != 0 && x % 3 == 0; 1);
  @ ensures j  == (\num_of int x; 0 <= x && x < n && x % 4 != 0 && x % 3 != 0 && x % 2 == 0; 1);
  @ ensures k  == (\num_of int x; 0 <= x && x < n && x % 4 != 0 && x % 3 != 0 && x % 2 != 0; 1);
  @*/
i = 0;
k = 0;
j = 0;
l = 0;
v4 = 0;

/*@
  @ maintaining 0 <= l && l <= n;
  @ maintaining 0 <= i && 0 <= j && 0 <= k && 0 <= v4;
  @ // invariant: the counts reflect classification of [0,l)
  @ maintaining i + j + k + v4 == l;
  @ maintaining v4 == (\num_of int x; 0 <= x && x < l && x % 4 == 0; 1);
  @ maintaining i  == (\num_of int x; 0 <= x && x < l && x % 4 != 0 && x % 3 == 0; 1);
  @ maintaining j  == (\num_of int x; 0 <= x && x < l && x % 4 != 0 && x % 3 != 0 && x % 2 == 0; 1);
  @ maintaining k  == (\num_of int x; 0 <= x && x < l && x % 4 != 0 && x % 3 != 0 && x % 2 != 0; 1);
  @ decreases n - l;
  @*/
while (l < n) {
if ((l % 4) == 0) {
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