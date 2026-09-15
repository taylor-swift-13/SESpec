/*@
    requires \true;
    assigns \nothing;
    behavior k_le_1:
        assumes k <= 1;
        ensures c == 1;
        ensures x == a;
        ensures y == 1;
    behavior k_gt_1:
        assumes k > 1;
        ensures c == k;
        ensures y == \product integer i; 0 <= i < k-1; z;
        ensures x == a * (\sum integer j; 0 <= j <= k-1; (\product integer i; 0 <= i < j; z));
    complete behaviors k_le_1, k_gt_1;
    disjoint behaviors k_le_1, k_gt_1;
*/
int main11(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
        loop invariant c >= 1;
        loop invariant c <= k || k <= 1;
        loop invariant \exists integer t; t == c-1 &&
                      y == (\product integer i; 0 <= i < t; z) &&
                      x == a * (\sum integer j; 0 <= j <= t; (\product integer i; 0 <= i < j; z));
        loop assigns x, y, c;
        loop variant k - c;
    */
    while (c < k){
       c = c + 1;
       x = x*z + a;
       y = y*z;
    }

  }
