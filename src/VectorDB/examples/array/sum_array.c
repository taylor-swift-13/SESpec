
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array,begin, end - 1) + array[end - 1];
*/

/*@ requires \valid(array + (0 .. n-1));
    requires n >= 0;
    ensures \result == sum(array, 0, n);
*/
int array_sum(int* array, int n) {
    int total = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant total == sum(array, 0, i);
        loop assigns total, i;
    */
    while (i < n) {
        total += array[i];
        i++;
    }
    
    return total;
}







