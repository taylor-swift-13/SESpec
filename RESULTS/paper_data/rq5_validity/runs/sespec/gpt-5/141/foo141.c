int foo141(int n);


/*@
ensures (n == 1) ==> (\result == 0);
ensures (n % 2 == 0) && (n != 1) ==> (\result == n / 2);
ensures (n % 2 != 0) && (n != 1) ==> (\result == n);

assigns \nothing;
*/

int foo141(int n) 
{

        return ((n == 1) ? 0 : ((n % 2 == 0) ? (n / 2) : n));
}