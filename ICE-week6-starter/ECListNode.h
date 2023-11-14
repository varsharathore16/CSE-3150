#ifndef _EC_LIST_NODE_H
#define _EC_LIST_NODE_H

#include <iostream>

// Class for linked list node
class ECListNode
{
public:
  ECListNode() : pNext(NULL), v(-1)  {}
  ECListNode *GetNext() const { return pNext; }
  void SetNext(ECListNode *pn) { pNext = pn;  }
  int GetValue() const { return v; }
  void SetValue(int v1) { v = v1; }

private:
  ECListNode *pNext;
  int v;
};

#endif
