int fizzBuzz(int n);

/*@
    requires \true;
    assigns \nothing;
    ensures \result == ((n % 3 == 0) ? 3 : 0) + ((n % 5 == 0) ? 5 : 0);
    ensures 0 <= \result <= 8;
    ensures \result == 0 || \result == 3 || \result == 5 || \result == 8;
*/
int fizzBuzz(int n) {

        int res = 0;
        res += ((n % 3 == 0) ? 3 : 0);
        res += ((n % 5 == 0) ? 5 : 0);
        return res;
}
