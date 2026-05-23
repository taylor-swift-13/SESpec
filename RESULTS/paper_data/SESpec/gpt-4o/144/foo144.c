int foo144(int n, int time);


/*@
ensures (\old(time) % (n - 1) * 2 >= n) ==> (\result == n * 2 - \old(time) % (n - 1) * 2 - 1);
ensures (\old(time) % (n - 1) * 2 < n) ==> (\result == \old(time) % (n - 1) * 2 + 1);

assigns \nothing;
*/

int foo144(int n, int time) 
{

        time = time % (n - 1) * 2;
        if (time < n) {
            return time + 1;
        }
        return n * 2 - time - 1;
}