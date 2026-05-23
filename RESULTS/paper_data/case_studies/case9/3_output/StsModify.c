/*@
ensures (-c > -a) && (-b <= -a) && (c < 0) && (b < 0) && (a < 0) ==> (\result == -c);
ensures (-c > a) && (-b <= a) && (c < 0) && (b < 0) && (a >= 0) ==> (\result == -c);
ensures (-c > a) && (b <= a) && (c < 0) && (b >= 0) && (a >= 0) ==> (\result == -c);
ensures (-c > -a) && (b <= -a) && (c < 0) && (b >= 0) && (a < 0) ==> (\result == -c);
ensures (c > -a) && (b <= -a) && (c >= 0) && (b >= 0) && (a < 0) ==> (\result == c);
ensures (c > a) && (b <= a) && (c >= 0) && (b >= 0) && (a >= 0) ==> (\result == c);
ensures (c > a) && (-b <= a) && (c >= 0) && (b < 0) && (a >= 0) ==> (\result == c);
ensures (c > -a) && (-b <= -a) && (c >= 0) && (b < 0) && (a < 0) ==> (\result == c);
ensures (c > -b) && (-b > -a) && (c >= 0) && (b < 0) && (a < 0) ==> (\result == c);
ensures (c > -b) && (-b > a) && (c >= 0) && (b < 0) && (a >= 0) ==> (\result == c);
ensures (c > b) && (b > a) && (c >= 0) && (b >= 0) && (a >= 0) ==> (\result == c);
ensures (c > b) && (b > -a) && (c >= 0) && (b >= 0) && (a < 0) ==> (\result == c);
ensures (-c > b) && (b > -a) && (c < 0) && (b >= 0) && (a < 0) ==> (\result == -c);
ensures (-c > b) && (b > a) && (c < 0) && (b >= 0) && (a >= 0) ==> (\result == -c);
ensures (-c > -b) && (-b > a) && (c < 0) && (b < 0) && (a >= 0) ==> (\result == -c);
ensures (-c > -b) && (-b > -a) && (c < 0) && (b < 0) && (a < 0) ==> (\result == -c);
ensures (-c <= -b) && (-b > -a) && (c < 0) && (b < 0) && (a < 0) ==> (\result == -b);
ensures (-c <= -b) && (-b > a) && (c < 0) && (b < 0) && (a >= 0) ==> (\result == -b);
ensures (-c <= b) && (b > a) && (c < 0) && (b >= 0) && (a >= 0) ==> (\result == b);
ensures (-c <= b) && (b > -a) && (c < 0) && (b >= 0) && (a < 0) ==> (\result == b);
ensures (c <= b) && (b > -a) && (c >= 0) && (b >= 0) && (a < 0) ==> (\result == b);
ensures (c <= b) && (b > a) && (c >= 0) && (b >= 0) && (a >= 0) ==> (\result == b);
ensures (c <= -b) && (-b > a) && (c >= 0) && (b < 0) && (a >= 0) ==> (\result == -b);
ensures (c <= -b) && (-b > -a) && (c >= 0) && (b < 0) && (a < 0) ==> (\result == -b);
ensures (c <= -a) && (-b <= -a) && (c >= 0) && (b < 0) && (a < 0) ==> (\result == -a);
ensures (c <= a) && (-b <= a) && (c >= 0) && (b < 0) && (a >= 0) ==> (\result == a);
ensures (c <= a) && (b <= a) && (c >= 0) && (b >= 0) && (a >= 0) ==> (\result == a);
ensures (c <= -a) && (b <= -a) && (c >= 0) && (b >= 0) && (a < 0) ==> (\result == -a);
ensures (-c <= -a) && (b <= -a) && (c < 0) && (b >= 0) && (a < 0) ==> (\result == -a);
ensures (-c <= a) && (b <= a) && (c < 0) && (b >= 0) && (a >= 0) ==> (\result == a);
ensures (-c <= a) && (-b <= a) && (c < 0) && (b < 0) && (a >= 0) ==> (\result == a);
ensures (-c <= -a) && (-b <= -a) && (c < 0) && (b < 0) && (a < 0) ==> (\result == -a);

assigns \nothing;
*/

int triple_fabs_max(int a, int b, int c)

{
    int fa = a; if (fa < 0) fa = -fa;
    int fb = b; if (fb < 0) fb = -fb;
    int fc = c; if (fc < 0) fc = -fc;
    int m = fa;
    if (fb > m) m = fb;
    if (fc > m) m = fc;
    return m;
}


/*@
  requires \valid(out + (0..2));
  requires \valid_read(a + (0..2));
  requires \valid_read(b + (0..2));
  requires \separated(out + (0..2), a + (0..2));
  requires \separated(out + (0..2), b + (0..2));
  assigns out[0..2];
  ensures out[0] == a[1] * b[2] - a[2] * b[1];
  ensures out[1] == a[2] * b[0] - a[0] * b[2];
  ensures out[2] == a[0] * b[1] - a[1] * b[0];
*/
void vec_cross3(int *out, int *a, int *b)
{
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
    return;
}

/*@
  requires \valid(&out[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= out[i] <= 100;
  requires n > 0;
  requires n < 100;
  requires \valid(&A[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= A[i] <= 100;
  requires \valid(&B[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= B[i] <= 100;
  requires \separated(out + (0..n-1), A + (0..n-1));
  requires \separated(out + (0..n-1), B + (0..n-1));
  assigns out[0..n-1], A[0..n-1], B[0..n-1];
*/
void vec_add(int *out, int *A, int *B, int n)
{
    /*@
      loop invariant 0 <= i <= n;
      loop invariant n == \at(n, Pre);
    */
    for (int i = 0; i < n; i++) {
        out[i] = A[i] + B[i];
    }
    return;
}


/*@
  requires \valid(out + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= out[i] <= 100;
  requires n > 0;
  requires n < 100;
  requires \valid(A + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= A[i] <= 100;
  requires -100 <= k <= 100;
  requires \separated(out + (0..n-1), A + (0..n-1));
  assigns out[0..n-1];
  ensures \forall integer i; 0 <= i < n ==> out[i] == \at(A[i], Pre) * k;
*/
void vec_scale(int *out, int *A, int k, int n)
{
    /*@
      loop invariant 0 <= i <= n;
      loop invariant n == \at(n, Pre);
      loop invariant k == \at(k, Pre);
      loop invariant \valid(out + (0..n-1));
      loop invariant \valid(A + (0..n-1));
      loop invariant \forall integer j; i <= j < n ==> out[j] == \at(out[j], Pre);
      loop assigns out[0..n-1];
    */
    for (int i = 0; i < n; i++) {
        out[i] = A[i] * k;
    }
    return;
}


/*@
  requires \valid(&out[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= out[i] <= 100;
  requires n > 0;
  requires n < 100;
  requires n == 1;
  requires \valid(&A[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= A[i] <= 100;
  requires \valid(&B[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= B[i] <= 100;
  requires \separated(&out[0] + (0..n-1), &A[0] + (0..n-1));
  requires \separated(&out[0] + (0..n-1), &B[0] + (0..n-1));
  assigns out[0..n-1];
  ensures \true;
*/
void vec_sub(int *out, int *A, int *B, int n)
{
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer k; i <= k < n ==> out[k] == \at(out[k], Pre);
      loop assigns i, out[0..n-1];
    */
    for (int i = 0; i < n; i++) {
        out[i] = A[i] - B[i];
    }
    return;
}


/*@
  logic integer mat_sum(int *A, int *B, integer ca_rb, integer cb,
                        integer i, integer j, integer k) =
    k <= 0 ? 0 :
    mat_sum(A, B, ca_rb, cb, i, j, k - 1) +
    A[i * ca_rb + (k - 1)] * B[(k - 1) * cb + j];
*/
        
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
      loop invariant B == \at(B,Pre);
      loop invariant A == \at(A,Pre);
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



/*@
  requires \valid(C);
  requires \valid(q);
           assigns C[0..8]; 
  ensures C[0] == 1 - 2 * (\at(q[1],Pre) * \at(q[1],Pre) + \at(q[2],Pre) * \at(q[2],Pre));
  ensures C[1] == 2 * (\at(q[0],Pre) * \at(q[1],Pre) - \at(q[2],Pre) * \at(q[3],Pre));
  ensures C[2] == 2 * (\at(q[0],Pre) * \at(q[2],Pre) + \at(q[1],Pre) * \at(q[3],Pre));
  ensures C[3] == 2 * (\at(q[0],Pre) * \at(q[1],Pre) + \at(q[2],Pre) * \at(q[3],Pre));
  ensures C[4] == 1 - 2 * (\at(q[0],Pre) * \at(q[0],Pre) + \at(q[2],Pre) * \at(q[2],Pre));
  ensures C[5] == 2 * (\at(q[1],Pre) * \at(q[2],Pre) - \at(q[0],Pre) * \at(q[3],Pre));
  ensures C[6] == 2 * (\at(q[0],Pre) * \at(q[2],Pre) - \at(q[1],Pre) * \at(q[3],Pre));
  ensures C[7] == 2 * (\at(q[1],Pre) * \at(q[2],Pre) + \at(q[0],Pre) * \at(q[3],Pre));
  ensures C[8] == 1 - 2 * (\at(q[0],Pre) * \at(q[0],Pre) + \at(q[1],Pre) * \at(q[1],Pre));
*/
void q_to_C(int *C, int *q)
{
    int x = q[0];
    int y = q[1];
    int z = q[2];
    int w = q[3];

    C[0] = 1 - 2 * (y * y + z * z);
    C[1] = 2 * (x * y - z * w);
    C[2] = 2 * (x * z + y * w);

    C[3] = 2 * (x * y + z * w);
    C[4] = 1 - 2 * (x * x + z * z);
    C[5] = 2 * (y * z - x * w);

    C[6] = 2 * (x * z - y * w);
    C[7] = 2 * (y * z + x * w);
    C[8] = 1 - 2 * (x * x + y * y);
    return;
}


void StsModify(int *pdeltaZ, int *q,
               int *installVector1,
               int *Imeasure,
               int *Imeasure_delta,
               int *gamma, int mdzmax)
{
    int Cq[9];
    int tmpZiGamma[3];
    int tmpV3a[3];
    int tmpV3b[3];
    int tmpV3c[3];
    int tmpZX[9];
    int deltaX1[3];
    int deltaY1[3];
    int deltaZ1[3];

    q_to_C(Cq, q);

    mat_mul(tmpV3a, Cq, &Imeasure[0 * 3], 3, 3, 1);
    mat_mul(tmpZX,  &installVector1[2 * 3], &installVector1[0 * 3], 3, 1, 3);
    mat_mul(tmpV3b, Cq, gamma, 3, 3, 1);
    mat_mul(tmpV3c, tmpZX, tmpV3b, 3, 3, 1);
    vec_sub(tmpV3a, tmpV3a, tmpV3c, 3);
    vec_add(tmpV3a, tmpV3a, &Imeasure_delta[0 * 3], 3);
    vec_cross3(deltaX1, &installVector1[0 * 3], tmpV3a);

    mat_mul(tmpV3a, Cq, &Imeasure[1 * 3], 3, 3, 1);
    mat_mul(tmpZX,  &installVector1[2 * 3], &installVector1[1 * 3], 3, 1, 3);
    mat_mul(tmpV3c, tmpZX, tmpV3b, 3, 3, 1);
    vec_sub(tmpV3a, tmpV3a, tmpV3c, 3);
    vec_add(tmpV3a, tmpV3a, &Imeasure_delta[1 * 3], 3);
    vec_cross3(deltaY1, &installVector1[1 * 3], tmpV3a);

    vec_add(tmpZiGamma, &Imeasure[2 * 3], gamma, 3);
    mat_mul(tmpV3a, Cq, tmpZiGamma, 3, 3, 1);
    vec_add(tmpV3a, tmpV3a, &Imeasure_delta[2 * 3], 3);
    vec_cross3(deltaZ1, &installVector1[2 * 3], tmpV3a);

    vec_add(pdeltaZ, deltaX1, deltaY1, 3);
    vec_add(pdeltaZ, pdeltaZ, deltaZ1, 3);
    vec_scale(pdeltaZ, pdeltaZ, 1, 3);  

    int tmpdZ = triple_fabs_max(pdeltaZ[0], pdeltaZ[1], pdeltaZ[2]);
    if (tmpdZ > mdzmax) {
        int tmpf = mdzmax / tmpdZ;
        pdeltaZ[0] = tmpf * pdeltaZ[0];
        pdeltaZ[1] = tmpf * pdeltaZ[1];
        pdeltaZ[2] = tmpf * pdeltaZ[2];
    }
    return;
}