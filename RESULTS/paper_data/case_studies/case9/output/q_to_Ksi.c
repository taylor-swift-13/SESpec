

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