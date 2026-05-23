#include <limits.h>
#include <stdlib.h>


/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@loop assigns j, catalan[i];
              loop variant i - j;*/
int stub_A(int num);

/*@loop invariant j <= i;
            loop invariant i <= num;
            loop invariant i <= num + 1;
            loop invariant i <= catalan_len;
            loop invariant i <= catalan_len - 1;
            loop invariant i < catalan_len;
            loop invariant catalan_len == num + 1;
            loop invariant catalan[i] == 0 || catalan[i] >= 0;
            loop invariant catalan[0] == 1;
            loop invariant \forall integer k; j <= k < i ==> catalan[k] >= 0;
            loop invariant \forall integer k; j <= k < i ==> catalan[k] == catalan[k];
            loop invariant \forall integer k; j <= k < i ==> catalan[k] == 0 || catalan[k] >= 0;
            loop invariant \forall integer k; 1 <= k < i ==> catalan[k] >= 0;
            loop invariant \forall integer k; 0 <= k < j ==> catalan[k] >= 0;
            loop invariant \forall integer k; 0 <= k < j ==> catalan[k] >= 0 && catalan[i-k-1] >= 0;
            loop invariant \forall integer k; 0 <= k < j ==> catalan[k] == catalan[k];
            loop invariant \forall integer k; 0 <= k < i ==> catalan[k] >= 0;
            loop invariant \forall integer k; 0 <= k < i ==> catalan[k] == catalan[k];
            loop invariant 1 <= i;
            loop invariant 0 <= j;
            loop invariant 0 <= i;
            loop invariant 0 <= catalan_len;
            loop invariant 0 <= catalan[i];
            loop invariant 0 < i;
            loop assigns j;
            loop assigns i;
            loop assigns catalan[0..num];
            loop assigns catalan[0..catalan_len-1];*/
int stub_B(int num);

/*@loop invariant j <= i;
            loop invariant i <= num;
            loop invariant i <= num + 1;
            loop invariant i <= catalan_len;
            loop invariant i <= catalan_len - 1;
            loop invariant i < catalan_len;
            loop invariant catalan_len == num + 1;
            loop invariant catalan[i] == 0 || catalan[i] >= 0;
            loop invariant catalan[0] == 1;
            loop invariant \forall integer k; j <= k < i ==> catalan[k] >= 0;
            loop invariant \forall integer k; j <= k < i ==> catalan[k] == catalan[k];
            loop invariant \forall integer k; j <= k < i ==> catalan[k] == 0 || catalan[k] >= 0;
            loop invariant \forall integer k; 1 <= k < i ==> catalan[k] >= 0;
            loop invariant \forall integer k; 0 <= k < j ==> catalan[k] >= 0;
            loop invariant \forall integer k; 0 <= k < j ==> catalan[k] >= 0 && catalan[i-k-1] >= 0;
            loop invariant \forall integer k; 0 <= k < j ==> catalan[k] == catalan[k];
            loop invariant \forall integer k; 0 <= k < i ==> catalan[k] >= 0;
            loop invariant \forall integer k; 0 <= k < i ==> catalan[k] == catalan[k];
            loop invariant 1 <= i;
            loop invariant 0 <= j;
            loop invariant 0 <= i;
            loop invariant 0 <= catalan_len;
            loop invariant 0 <= catalan[i];
            loop invariant 0 < i;
            loop assigns j;
            loop assigns i;
            loop assigns catalan[0..num];
            loop assigns catalan[0..catalan_len-1];*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@loop assigns j, catalan[i];
              loop variant i - j;*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
