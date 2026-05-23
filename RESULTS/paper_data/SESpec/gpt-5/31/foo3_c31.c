int foo3_c31(int i);


/*@

ensures i != 0 ==> \result == 1;

ensures i == 0 ==> \result == 0;


assigns \nothing;
*/

int foo3_c31(int i) 
{
    if (i == 0) return 0;
    int j = 10 / i;
    (void)j;
    return 1;
}