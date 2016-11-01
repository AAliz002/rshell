#ifndef CMDAND_H
#define CMDAND_H

#include "cmdBase.h"
#include <string.h>

class cmdAnd: public cmdBase
{
  private:
    cmdBase* left;
    cmdBase* right;
  public:
    cmdAnd(cmdBase* l, cmdBase* r): left(l), right(r) {};
    bool execute()
    {
      left->execute();
      right->execute();
      return true;
    }
};

#endif
