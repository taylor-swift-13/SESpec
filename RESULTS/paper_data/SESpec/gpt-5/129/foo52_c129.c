int foo52_c129(int year);


/*@

ensures year % 400 == 0 && year % 100 == 0 && year % 4 == 0 ==> \result == 1;

ensures year % 400 != 0 && year % 100 == 0 && year % 4 == 0 ==> \result == 0;

ensures year % 100 != 0 && year % 4 == 0 ==> \result == 1;

ensures year % 4 != 0 ==> \result == 0;


assigns \nothing;
*/

int foo52_c129(int year) 
{

        return ((year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? 1 : 0) : 1) : 0);
}