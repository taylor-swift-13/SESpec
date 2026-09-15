int oddDays(int n);

/*@ 
  requires 0 <= n <= 1717986917;
  assigns \nothing;
  ensures 0 <= \result <= 6;
  ensures \result == (n + n/4 - n/100 + n/400) % 7;
*/
int oddDays(int n) {

        int hund1 = n / 100;
        int hund4 = n / 400;
        int leap = n / 4;
        int ordd = n - leap ;
        if (hund1 != 0) {
            ordd += hund1 ;
            leap -= hund1 ;
        }
        if (hund4 != 0) {
            ordd -= hund4 ;
            leap += hund4 ;
        }
        //@ assert leap == n/4 - n/100 + n/400;
        //@ assert ordd == n - n/4 + n/100 - n/400;
        int days = ordd + leap * 2;
        //@ assert days == n + n/4 - n/100 + n/400;
        //@ assert 0 <= days;
        return days % 7;
}
