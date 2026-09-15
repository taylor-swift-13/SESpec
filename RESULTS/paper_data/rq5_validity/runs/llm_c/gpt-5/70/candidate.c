/*@ 
  logic integer count_v4(integer m) =
    (m <= 0) ? 0 :
    count_v4(m-1) + (((m-1) % 4 == 0) ? 1 : 0);

  logic integer count_i(integer m) =
    (m <= 0) ? 0 :
    count_i(m-1) + ((((m-1) % 4) != 0) && (((m-1) % 3) == 0) ? 1 : 0);

  logic integer count_j(integer m) =
    (m <= 0) ? 0 :
    count_j(m-1) + ((((m-1) % 4) != 0) && (((m-1) % 3) != 0) && (((m-1) % 2) == 0) ? 1 : 0);

  logic integer count_k(integer m) =
    (m <= 0) ? 0 :
    count_k(m-1) + ((((m-1) % 4) != 0) && (((m-1) % 3) != 0) && (((m-1) % 2) != 0) ? 1 : 0);
*/

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
  ensures l == n;
  ensures v4 == count_v4(n);
  ensures i == count_i(n);
  ensures j == count_j(n);
  ensures k == count_k(n);
  ensures v4 + i + j + k == n;
*/
void foo308(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;

    /*@
      loop invariant 0 <= l <= n;
      loop invariant v4 == count_v4(l);
      loop invariant i == count_i(l);
      loop invariant j == count_j(l);
      loop invariant k == count_k(l);
      loop invariant v4 + i + j + k == l;
      loop assigns i, j, k, v4, l;
      loop variant n - l;
    */
    while (l < n) {
       if ((l % 4) == 0) {
       v4 = v4 + 1;
      }
       else if((l % 3) == 0){
       i = i + 1;
      }
       else if((l % 2) == 0){
       j = j + 1;
      }
       else{
       k = k + 1;
      }
       l = l + 1;
      }

  }
