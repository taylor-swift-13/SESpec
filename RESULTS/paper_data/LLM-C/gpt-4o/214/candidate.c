#include <stdlib.h>

/*@
    requires num >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int catalanNumber(int num);

/*@
    requires num >= 0;
    ensures \result >= 0;
    ensures \result == \sum(0 <= i < num, \prod(0 <= j < i, catalan[j] * catalan[i - j - 1]));
    assigns \nothing;
*/
int catalanNumber(int num) {

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
int catalan_len = num + 1;
        catalan[0] = 1;
        for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[num];
}
