int isLeapYear(int year);

/*@
    assigns \nothing;
    ensures (\result == 1) <==> ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
    ensures (\result == 0) <==> !((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
*/
int isLeapYear(int year) {

        return ((year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? 1 : 0) : 1) : 0);
}
