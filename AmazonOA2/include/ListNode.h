#ifndef LISTNODE_H
#define LISTNODE_H


#include<stddef.h>


class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x);
    virtual ~ListNode();

protected:
private:
};

#endif // LISTNODE_H
