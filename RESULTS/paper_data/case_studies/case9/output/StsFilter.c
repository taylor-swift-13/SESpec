
/*@
  logic integer mat_sum(int *A, int *B, integer ca_rb, integer cb,
                        integer i, integer j, integer k) =
    k <= 0 ? 0 :
    mat_sum(A, B, ca_rb, cb, i, j, k - 1) +
    A[i * ca_rb + (k - 1)] * B[(k - 1) * cb + j];
*/

        
        


/*@
ensures (x >= -lim) && (x <= lim) ==> (\result == x);
ensures (x < -lim) && (x <= lim) ==> (\result == -lim);
ensures (x > lim) ==> (\result == lim);

assigns \nothing;
*/

int limit_abs(int x, int lim)

{
    if (x >  lim) return  lim;
    if (x < -lim) return -lim;
    return x;
}


/*@
  requires \valid(Ksi);
  requires \valid(q);
  assigns Ksi[0..11];
  ensures Ksi[0] == \old(q[3]);
  ensures Ksi[1] == -\old(q[2]);
  ensures Ksi[2] == \old(q[1]);
  ensures Ksi[3] == \old(q[2]);
  ensures Ksi[4] == \old(q[3]);
  ensures Ksi[5] == -\old(q[0]);
  ensures Ksi[6] == -\old(q[1]);
  ensures Ksi[7] == \old(q[0]);
  ensures Ksi[8] == \old(q[3]);
  ensures Ksi[9] == -\old(q[0]);
  ensures Ksi[10] == -\old(q[1]);
  ensures Ksi[11] == -\old(q[2]);
*/
void q_to_Ksi(int *Ksi, int *q)
{
    int x = q[0];
    int y = q[1];
    int z = q[2];
    int w = q[3];

    Ksi[0] =  w;  Ksi[1]  = -z;  Ksi[2]  =  y;
    Ksi[3] =  z;  Ksi[4]  =  w;  Ksi[5]  = -x;
    Ksi[6] = -y;  Ksi[7]  =  x;  Ksi[8]  =  w;
    Ksi[9] = -x;  Ksi[10] = -y;  Ksi[11] = -z;
    return;
}

void q_normalize(int *q)

{
    (void)q;
    return;
}

        
/*@
  requires \valid(&out[0] + (0..ra * cb-1));
  requires \forall integer i; 0 <= i < ra * cb ==> 0 <= out[i] <= 100;
  requires ra * cb > 0;
  requires ra * cb < 100;
  requires \valid(&A[0] + (0..ra * ca_rb-1));
  requires \forall integer i; 0 <= i < ra * ca_rb ==> 0 <= A[i] <= 100;
  requires ra * ca_rb > 0;
  requires ra * ca_rb < 100;
  requires \valid(&B[0] + (0..ca_rb * cb-1));
  requires \forall integer i; 0 <= i < ca_rb * cb ==> 0 <= B[i] <= 100;
  requires ca_rb * cb > 0;
  requires ca_rb * cb < 100;
  requires \separated(out + (0..ra * cb - 1), A + (0..ra * ca_rb - 1));
  requires \separated(out + (0..ra * cb - 1), B + (0..ca_rb * cb - 1));
  assigns out[0..ra * cb - 1]; 
  ensures \true;
*/
void mat_mul(int *out, int *A, int *B,
             int ra, int ca_rb, int cb)
{
    /*@
      loop invariant i == 0 || (0 <= i <= ra);
      loop invariant \true;
      loop invariant cb == \at(cb,Pre);
      loop invariant ca_rb == \at(ca_rb,Pre);
      loop invariant ra == \at(ra,Pre);
      loop invariant B == \at(B,Pre)  ;
      loop invariant A == \at(A,Pre)  ;
      loop invariant out == \at(out,Pre);
      loop assigns i, out[0..ra * cb - 1];
    */
    for (int i = 0; i < ra; i++) {
        
        /*@
          loop invariant 0 <= j <= cb;
          loop invariant \true;
          loop assigns j, out[i * cb .. i * cb + cb - 1];
        */
        for (int j = 0; j < cb; j++) {
            int s = 0;
            
            /*@
              loop invariant 0 <= k <= ca_rb;
              loop invariant s == mat_sum(A, B, ca_rb, cb, i, j, k);
              loop invariant \true;
              loop assigns k, s;
            */
            for (int k = 0; k < ca_rb; k++) {
                s = s + A[i * ca_rb + k] * B[k * cb + j];
            }
            
            out[i * cb + j] = s;
        }
    }
            
    return;
}
/*@ logic integer ksi_elem(int *q, integer idx) =
      idx == 0 ? q[3] :
      idx == 1 ? -q[2] :
      idx == 2 ? q[1] :
      idx == 3 ? q[2] :
      idx == 4 ? q[3] :
      idx == 5 ? -q[0] :
      idx == 6 ? -q[1] :
      idx == 7 ? q[0] :
      idx == 8 ? q[3] :
      idx == 9 ? -q[0] :
      idx == 10 ? -q[1] :
      -q[2];
*/
/*@ logic integer qb6_elem(int *KS, int *pdeltaZ, integer row) =
      mat_sum(KS, pdeltaZ, 3, 1, row, 0, 3);
*/
/*@ logic integer dq_elem(int *q, int *KS, int *pdeltaZ, integer row) =
      ksi_elem(q, row * 3) * qb6_elem(KS, pdeltaZ, 0) +
      ksi_elem(q, row * 3 + 1) * qb6_elem(KS, pdeltaZ, 1) +
      ksi_elem(q, row * 3 + 2) * qb6_elem(KS, pdeltaZ, 2);
*/
/*@
  requires \valid(bi);
  requires \valid(q);
  requires \valid(pdeltaZ);
  requires \valid(KS);
  assigns q[0..3], bi[0..2]; 
*/
void StsFilter(int *bi, int *q, int *pdeltaZ,
               int *KS, int mblimit)
{
    int qb6[6];
    int Eq[12];
    int dq[4];

    mat_mul(qb6, KS, pdeltaZ, 6, 3, 1);
    q_to_Ksi(Eq, q);
    mat_mul(dq, Eq, qb6, 4, 3, 1);

    /*@
      loop invariant 0 <= i <= 4;
      loop invariant (!(i < 4)) ==> \true;
      loop invariant \true;
      loop assigns i, q[0..3];
    */
    for (unsigned int i = 0; i < 4; i++) {
        q[i] = q[i] + dq[i];
    }
            

    q_normalize(q);

    /*@
      loop invariant 0 <= i <= 3;
      loop invariant \true;
      loop assigns i, bi[0..2];
    */
    for (unsigned int i = 0; i < 3; i++) {
        bi[i] = bi[i] + qb6[i + 3];
        bi[i] = limit_abs(bi[i], mblimit);
    }
            
    return;
}
