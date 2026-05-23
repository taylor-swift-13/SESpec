/*@
    requires \valid(array+(0..array_length-1));
    ensures \result == -1 ==> \forall integer i; 0 <= i < array_length ==> array[i] != search;
    ensures \result >= 0 ==> 0 <= \result < array_length && array[\result] == search;
    assigns \nothing;
*/
int linearSearch(int search, int array[], int array_length) {

    int location = -1;
    int c;

    /*@
        loop invariant 0 <= c <= array_length;
        loop invariant location == -1 ==> \forall integer i; 0 <= i < c ==> array[i] != search;
        loop invariant location >= 0 ==> 0 <= location < c && array[location] == search;
        loop assigns c, location;
        loop variant array_length - c;
    */
    for (c = 0; c < array_length; c++) {
        if (array[c] == search) {
            location = c;
            break;
        }
    }
    return location;
}
