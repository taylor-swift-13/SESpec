

void mat_mul(int *out, int *A, int *B,
             int ra, int ca_rb, int cb)
{
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            int s = 0;
            for (int k = 0; k < ca_rb; k++) {
                s = s + A[i * ca_rb + k] * B[k * cb + j];
            }
            out[i * cb + j] = s;
        }
    }
    return;
}

void vec_add(int *out, int *A, int *B, int n)
{
    for (int i = 0; i < n; i++) {
        out[i] = A[i] + B[i];
    }
    return;
}

void vec_sub(int *out, int *A, int *B, int n)
{
    for (int i = 0; i < n; i++) {
        out[i] = A[i] - B[i];
    }
    return;
}

void vec_scale(int *out, int *A, int k, int n)
{
    for (int i = 0; i < n; i++) {
        out[i] = A[i] * k;
    }
    return;
}

void vec_cross3(int *out, int *a, int *b)
{
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
    return;
}

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

int limit_abs(int x, int lim)
{
    if (x >  lim) return  lim;
    if (x < -lim) return -lim;
    return x;
}

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

void StsCompensate(int *pSTSdeltaZ, int *wGyro,
                   int *pSTSIV, int dtime)
{
    int W[9];

    W[0] = 0;        W[1] = -wGyro[2]; W[2] =  wGyro[1];
    W[3] = wGyro[2];   W[4] =  0;       W[5] = -wGyro[0];
    W[6] = -wGyro[1];  W[7] =  wGyro[0];  W[8] =  0;

    mat_mul(pSTSdeltaZ, W, pSTSIV, 3, 3, 1);

    pSTSdeltaZ[0] = pSTSdeltaZ[0] * dtime;
    pSTSdeltaZ[1] = pSTSdeltaZ[1] * dtime;
    pSTSdeltaZ[2] = pSTSdeltaZ[2] * dtime;
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

void StsFilter(int *bi, int *q, int *pdeltaZ,
               int *KS, int mblimit)
{
    int qb6[6];
    int Eq[12];
    int dq[4];

    mat_mul(qb6, KS, pdeltaZ, 6, 3, 1);
    q_to_Ksi(Eq, q);
    mat_mul(dq, Eq, qb6, 4, 3, 1);

    for (unsigned int i = 0; i < 4; i++) {
        q[i] = q[i] + dq[i];
    }

    q_normalize(q);

    for (unsigned int i = 0; i < 3; i++) {
        bi[i] = bi[i] + qb6[i + 3];
        bi[i] = limit_abs(bi[i], mblimit);
    }
    return;
}

void CS_Sts_Gyro_Modify_Single_pipeline(
    int *installVector1,
    int *Imeasure,
    int *KS,
    int *wGyro,
    int *gamma,
    int dtime,
    int mdzmax,
    int mblimit,
    int *q,
    int *bi,
    int *dInno)
{
    int Imeasure_delta[9];

    StsCompensate(&Imeasure_delta[0 * 3], wGyro, &installVector1[0 * 3], dtime);
    StsCompensate(&Imeasure_delta[1 * 3], wGyro, &installVector1[1 * 3], dtime);
    StsCompensate(&Imeasure_delta[2 * 3], wGyro, &installVector1[2 * 3], dtime);

    StsModify(dInno, q, installVector1, Imeasure, Imeasure_delta, gamma, mdzmax);

    StsFilter(bi, q, dInno, KS, mblimit);
    return;
}
