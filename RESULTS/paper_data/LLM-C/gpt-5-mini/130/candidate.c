int linearSearch(int search, int array[], int len);

/*@
    requires len >= 0;
    requires \valid_read(array + (0 .. len-1));
    assigns \nothing;
    behavior found:
      assumes \exists integer i; 0 <= i < len && array[i] == search;
      ensures 0 <= \result < len;
      ensures array[\result] == search;
      ensures \forall integer j; 0 <= j < \result ==> array[j] != search;
    behavior not_found:
      assumes \forall integer i; 0 <= i < len ==> array[i] != search;
      ensures \result == -1;
    complete behaviors found, not_found;
    disjoint behaviors found, not_found;
*/
int linearSearch(int search, int array[], int len) {

    int c;
    int location = -1;

    /*@
        loop invariant 0 <= c <= len;
        loop invariant location == -1 || (0 <= location < c && array[location] == search);
        loop assigns c, location;
        loop variant len - c;
    */
    for (c = 0; c < len; c++) {
        if (array[c] == search) {
            location = c;
            break;
        }
    }
    if (c == len) {
        location = -1;
    }
    return location;
}
