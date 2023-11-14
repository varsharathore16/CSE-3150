#include "ECLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* get the length of the linked list: how many nodes in the linked list */
/* pHead: head node pointer to the linked list */
/* return the number of nodes of the linked list pointed by pHead */
int ECGetLinkedListLength(struct ECLinkedListNode *pHead )
{
  int res = 0;
  struct ECLinkedListNode *pn = pHead;
  while(pn != NULL)
  {
    ++res;
    pn = pn->pNext;
  }
  return res;
}

/* delete a node from the linked list */
/* pPre: the node prior to the node to delete, pNodeToDel: this is the node to delete */
void ECDeleteNode(struct ECLinkedListNode *pPre, struct ECLinkedListNode *pNodeToDel)
{
  if( pPre != NULL )
  {
    pPre->pNext = pNodeToDel->pNext;
  }
//printf("free node: %ld\n", (long)pNodeToDel);
  if( pNodeToDel != NULL )
  {
    // it seems you have to set pNext to NULL; otherwise on some platform the code craeshes
    // which might be due to pNext is also freed!
    pNodeToDel->pNext = NULL;
  }
  free( pNodeToDel );
}

/* delete all nodes with a specific value from the linked list */
/* input: pHead: head node pointer to the linked list which to be processed */
/* input: val: all nodes with value equal to val should be deleted */
/* output: the pointer to the head ndoe of the linked list after the delete operation */
struct ECLinkedListNode *ECLinkedListDeleteVal(struct ECLinkedListNode *pHead, int val)
{
  /* loop through the nodes to delete it  */
  struct ECLinkedListNode *pPre = NULL;
  struct ECLinkedListNode *pNodeCur = pHead;
  struct ECLinkedListNode *pNext = NULL;
  while( pNodeCur != NULL )
  {
    if( pNodeCur->value == val )
    {
      pNext = pNodeCur->pNext;
      if( pNodeCur == pHead )
      {
        pHead = pNodeCur->pNext;
      }
      ECDeleteNode(pPre, pNodeCur);
      pNodeCur = pNext;
    }
    else
    {
      pPre = pNodeCur;
      pNodeCur = pNodeCur->pNext;
    }
  }
  return pHead;
}
