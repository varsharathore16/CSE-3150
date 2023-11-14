#include "ECListNode.h"
#include "ECList.h"

// Linked list 
ECList :: ECList() : pHead(NULL), numNodes(0) 
{
}
  
// insert node with value val after a node
// if node is NULL, insert to the front
void ECList :: Insert(int val, ECListNode *pPre)
{
  ECListNode *pn = new ECListNode;
  pn->SetValue( val );
  ++numNodes;
  if( pPre != NULL )
  {
    ECListNode *pnn = pPre->GetNext();
    pPre->SetNext( pn );
    pn->SetNext( pnn );
  }
  else
  {
    pn->SetNext( pHead );
    pHead = pn;
  }
}

// delete a node
void ECList :: Delete(ECListNode *pNode)
{
  if( pHead == NULL )
  {
    return;
  }

  // find out the priror node to pNode first
  if( pNode == pHead )
  {
    pHead = pHead->GetNext();
    delete pNode;
    --numNodes;
    return;
  }

  ECListNode *pnc = pHead;
  while( pnc != NULL &&  pnc->GetNext() != pNode  )
  {
    pnc = pnc->GetNext();
  }
  if( pnc == NULL )
  {
    return;
  }
  --numNodes;
  pnc->SetNext( pNode->GetNext()  );
  delete pNode;

}

// get a node with value; if multiple nodes with the same value, return the first from head
ECListNode * ECList::GetNode(int val)
{
  ECListNode *pnc = pHead;
  while( pnc != NULL &&  pnc->GetValue() != val  )
  { 
    pnc = pnc->GetNext();
  }
  return pnc;
}

// get the number of nodes in the list
int ECList:: GetSize() const
{
  return numNodes;
}

