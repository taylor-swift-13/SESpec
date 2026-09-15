
/*@ predicate placeholder_predicate_or_logic_function(int i, int j, int k, int n, int b) =
      (b == 1) && (n == 0) && (k == k) && (j == j) && (i == i);
*/

void foo156(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;

    /*@
      loop invariant (0 < (2 * \at(k,Pre))) ==> (n <= 2 * \at(k,Pre));
      loop invariant (!(0 < (2 * \at(k,Pre)))) ==> ((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns n, b, i, j;
    */
    while(n < (2 * k)){
        n = n + 1;
        if(b == 1){
            b = 0;
            i = i + 1;
        }
        else{
            b = 1;
            j = j + 1;
        }
    }
}
