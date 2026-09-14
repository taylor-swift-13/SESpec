                                                                            
extern int unknown_int(void);
/*@
  requires x < 0;
*/
void loopy_417(int x, int y) {
  
  
  
  while (1) {
    if (x>=0) {
      break;
    } else {
      x=x+y; y++;
    }
  }
  {;

}

  return;
}