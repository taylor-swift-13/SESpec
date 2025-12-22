

/*@
requires l > 0;
requires n > l;
*/
void foo03(int n, int l) {
  int i,k;

  k = 1;
  for (k=1; k<n; k++){
  	i = l;
    for (; i<n; i++) {
    }
  }
    /*@ assert \forall integer i; (l <= i < n) ==> (1 <= i); */
  

}
