int foo33(int denom);


/*@
ensures (denom != 0) ==> (\result == 1);
ensures (denom == 0) ==> (\result == 0);

assigns \nothing;
*/

int foo33(int denom) 
{
    if (denom == 0) return 0;
    int j = 10 / denom;
    (void)j;
    return 1;
}