#include <string.h>

int f(const char *s1, const char *s2);

int f(const char *s1, const char *s2) {
    int i = 0;
    /*@
    loop invariant 0 <= i <= (int)strlen(s1);
    loop invariant count >= -1;
    loop invariant i == ((int)strlen(s1)) - 1 - count;
    loop invariant \forall integer k; 0 <= k < i ==> s1[((int)strlen(s1)) - 1 - k] != s2[k];
    loop invariant \forall integer k; 0 <= k < i ==> s2[k] != s1[((int)strlen(s1)) - 1 - k];
    loop invariant i == (int)strlen(s1) - 1 - count;
    loop invariant i == ((int)strlen(s1)) - 1 - count;
    loop invariant i <= (int)strlen(s1);
    loop invariant i + count == (int)strlen(s1) - 1;
    loop invariant count < (int)strlen(s1);
    loop invariant count + 1 <= (int)strlen(s1);
    loop invariant \forall integer k; 0 <= k <= count ==> s1[k] != s2[i + ((int)strlen(s1) - 1 - count - k)];
    loop invariant \forall integer k; 0 <= k < i ==> s2[k] != s1[(int)strlen(s1) - 1 - k];
    loop invariant \forall integer k; 0 <= k < i ==> s2[k] != s1[((int)strlen(s1)) - 1 - k];
    loop invariant \forall integer k; 0 <= k < i ==> s2[k] != '\0';
    loop invariant \forall integer k; 0 <= k < i ==> s1[(int)strlen(s1) - 1 - k] != s2[k];
    loop invariant \forall integer k; 0 <= k < i ==> s1[((int)strlen(s1)) - 1 - k] != s2[k];
    loop invariant 0 <= i;
    loop invariant 0 <= count;
    loop invariant 0 <= count + 1;
    loop assigns i;
    loop assigns count;
    */
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    return 1;
}
