int lcm(int num1, int num2);

/*@
    requires \true;
    assigns \nothing;
    behavior zero:
        assumes \old(num1) == 0 || \old(num2) == 0;
        ensures \result == -1;
    behavior nonzero:
        assumes \old(num1) != 0 && \old(num2) != 0;
        ensures (\result == -1)
             || (
                   \result >= 0
                && \result <= Integer.MAX_VALUE
                && \result % ( (\old(num1) < 0) ? -\old(num1) : \old(num1) ) == 0
                && \result % ( (\old(num2) < 0) ? -\old(num2) : \old(num2) ) == 0
                && \result >= ( ( (\old(num1) < 0) ? -\old(num1) : \old(num1) ) > ( (\old(num2) < 0) ? -\old(num2) : \old(num2) ) ? ( (\old(num1) < 0) ? -\old(num1) : \old(num1) ) : ( (\old(num2) < 0) ? -\old(num2) : \old(num2) ) )
                && \forall integer t; ( ( ( (\old(num1) < 0) ? -\old(num1) : \old(num1) ) > ( (\old(num2) < 0) ? -\old(num2) : \old(num2) ) ? ( (\old(num1) < 0) ? -\old(num1) : \old(num1) ) : ( (\old(num2) < 0) ? -\old(num2) : \old(num2) ) ) <= t && t < \result ) ==> !( t % ( (\old(num1) < 0) ? -\old(num1) : \old(num1) ) == 0 && t % ( (\old(num2) < 0) ? -\old(num2) : \old(num2) ) == 0 )
               );
    complete behaviors zero, nonzero;
    disjoint behaviors zero, nonzero;
*/
int lcm(int num1, int num2) {

        if (num1 == 0 || num2 == 0) {
            return -1;
        }
        if (num1 < 0)
            num1 = -num1;
        if (num2 < 0)
            num2 = -num2;

            int result = (num1 > num2) ? num1 : num2;

            /*@
                loop invariant num1 > 0 && num2 > 0;
                loop invariant result >= (num1 > num2 ? num1 : num2);
                loop invariant \forall integer t; ( (num1 > num2 ? num1 : num2) <= t && t < result ) ==> !( t % num1 == 0 && t % num2 == 0 );
                loop assigns result;
                loop variant Integer.MAX_VALUE - result;
            */
            while (result < Integer.MAX_VALUE)
            {
                if (result % num1 == 0 && result % num2 == 0)
                {
                    break;
                }
                result++;
            }

        if (result % num1 == 0 && result % num2 == 0) {
            return result;
        }
        return -1;
}
