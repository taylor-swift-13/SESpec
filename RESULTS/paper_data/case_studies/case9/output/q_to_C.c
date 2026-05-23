

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