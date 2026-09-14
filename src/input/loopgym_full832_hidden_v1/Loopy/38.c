                                                                                                        
extern int unknown(void);

extern int unknown();

/*@
  requires fbuflen >0;
*/
void loopy_38(int fbuflen)
{
  
  
  int fb;
  
  
  fb = 0;
  while (unknown())
  {
    
    if (unknown())
      break;

    if (unknown())
      break;

    {;

}

    {;

}

    fb++;
    if (fb >= fbuflen-1)
      fb = 0;

    {;

}

    {;

}

    fb++;
    if (fb >= fbuflen-1)
      fb = 0;

    {;

}

    {;

}

    fb++;
    if (fb >= fbuflen-1)
      fb = 0;
  }

  if (fb > 0)
  {
    
    {;

}

    {;

}

  }

 END:  return;
}