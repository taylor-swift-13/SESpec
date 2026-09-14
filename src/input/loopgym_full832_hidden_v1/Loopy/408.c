                                                                            
extern int unknown_int(void);
/*@
  requires y>0 || x>0;
*/
void loopy_408(int x, int y) {
  
  
  
  while (1) {
    if (x+y>-2) {
      break;
    }
    if (x>0) {
      x++;
    } else {
      y++;
    }
  }
  {;

}

  return;
}