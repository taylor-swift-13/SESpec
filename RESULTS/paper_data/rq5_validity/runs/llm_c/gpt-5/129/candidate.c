/*@ 
  assigns \nothing;
  ensures 0 <= \result <= 1;
  behavior leap:
    assumes year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    ensures \result == 1;
  behavior nonleap:
    assumes !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    ensures \result == 0;
  ensures (\result == 1) <==> (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
  complete behaviors leap, nonleap;
  disjoint behaviors leap, nonleap;
*/
int isLeapYear(int year);

int isLeapYear(int year) {

        return ((year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? 1 : 0) : 1) : 0);
}
