int isLeapYear(int year);

/*@ 
  requires \true;
  assigns \nothing;
  ensures 0 <= \result <= 1;
  ensures (\result != 0) <==> ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
  behavior leap:
    assumes (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    ensures \result == 1;
  behavior not_leap:
    assumes !((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
    ensures \result == 0;
  complete behaviors;
  disjoint behaviors;
*/
int isLeapYear(int year) {

        int leap = 0;

        if (year % 4 == 0)
        {
            if ( year % 100 == 0)
            {
                if ( year % 400 == 0)
                    leap = 1;
                else
                    leap = 0;
            }
            else
                leap = 1;
        }
        else
            leap = 0;

	return leap;
}
