#include <stdlib.h>

/*@
    requires num >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int catalanNumber(int num);

int catalanNumber(int num) {

/*@
    requires num >= 0;
    requires \valid((int *)malloc(sizeof(int) * (num + 1)));
    assigns *((int *)0 .. (int *)0);
    ensures \result >= 0;
*/
        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
int catalan_len = num + 1;
/*@ 
        loop invariant 1 <= i <= num + 1;
        loop assigns i, catalan[1 .. num];
        loop variant num - i + 1;
*/
        catalan[0] = 1;
        for (int i = 1; i <= num; i++) {
/*@
            loop invariant 0 <= j <= i;
            loop assigns j, catalan[i];
            loop variant i - j;
*/
            catalan[i] = 0;
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[num];
}
