int foo68_c143(int n, int time);


/*@

ensures \old(time) % ((n - 1) * 2) < n ==> \result == \old(time) % ((n - 1) * 2) + 1;

ensures \old(time) % ((n - 1) * 2) >= n ==> \result == n * 2 - \old(time) % ((n - 1) * 2) - 1;


assigns \nothing;
*/

int foo68_c143(int n, int time) 
{

        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
}