int foo364(int n);


/*@
  assigns \nothing;
  ensures \result == ((n + n / 4 - (n / 100 != 0 ? n / 100 : 0) + (n / 400 != 0 ? n / 400 : 0)) % 7);
  ensures (n / 100 == 0 && n / 400 == 0) ==> \result == ((n + n / 4) % 7);
  ensures (n / 100 != 0 && n / 400 == 0) ==> \result == ((n + n / 4 - n / 100) % 7);
  ensures (n / 100 == 0 && n / 400 != 0) ==> \result == ((n + n / 4 + n / 400) % 7);
  ensures (n / 100 != 0 && n / 400 != 0) ==> \result == ((n + n / 4 - n / 100 + n / 400) % 7);
*/
int foo364(int n) {

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
        int days = ordd + leap * 2;
        return days % 7;
}