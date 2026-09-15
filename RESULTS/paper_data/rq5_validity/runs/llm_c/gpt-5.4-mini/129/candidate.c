/*@
    ensures \result == 1 || \result == 0;
    ensures \result == 1 <==> ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
    assigns \nothing;
*/
int isLeapYear(int year);

int isLeapYear(int year) {

        return ((year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? 1 : 0) : 1) : 0);
}
