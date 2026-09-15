/*@
    requires n >= 0;
    ensures \result == 0 || (\exists integer sum, count; 
        sum == \sum(1, n, (i % 2 == 0 ? i : 0)) &&
        count == \sum(1, n, (i % 2 == 0 ? 1 : 0)) &&
        \result == sum / count);
*/
int averageEven(int n);

int averageEven(int n) {

        int sum = 0;
        int count = 0;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant sum == \sum(1, i - 1, (j % 2 == 0 ? j : 0));
            loop invariant count == \sum(1, i - 1, (j % 2 == 0 ? 1 : 0));
            loop assigns i, sum, count;
            loop variant n - i;
        */
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
}
