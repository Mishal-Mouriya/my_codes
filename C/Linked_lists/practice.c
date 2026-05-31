/*Delete Every Second Node Until One Node Remains

You are given a doubly circular linked list with $n$ nodes.

Starting from the head:
Delete every second node
Continue circularly
Stop when only one node remains
Finally, print the value of the remaining node.

Sample Input:510 20 30 40 50
Sample Output:Remaining node: 30
*/



//pseudo code
p=head;
while(p->prev!=p->next)
{
     p=p->next->next;

    if(p==head)
    {
        //deletiion at the head
        tmp=p;
        head=p->next;
        p->prev->next=p->next;
        p->next->prev=p->prev; 
         p=p->next->next;
        continue;    
        free(tmp);

    }
    else
    {
        //deletion at the end
        tmp=p;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        p=p->next->next;
        continue;   
        free(tmp);

    }
}
/*MISTAKES IN THE CODE 
Key Issues in Your Code

The "Dead Code" Problem: Inside both your if and else blocks,
 you have continue; placed before free(tmp);. In C, continue immediately 
 jumps to the next iteration of the loop, meaning your free(tmp) will never 
 execute. This leads to memory leaks.

Skipping Nodes Incorrectly: The problem asks to delete every second node.
If you are at Node 1, you should skip to Node 2 and delete Node 2.
In your code: p = p->next->next; moves the pointer two steps before you even 
start the deletion logic. This makes it very hard to track which node is 
actually being removed.

The Stopping Condition: while(p->prev != p->next) only works reliably if you 
have exactly 2 nodes left (where prev and next point to the same node).
For a robust "one node remains" check, use while(p->next != p).

Redundant Logic: In a circular list, "deletion at the head" and 
"deletion at the end" (or middle) use the exact same pointer manipulation. 
You only need to update the head pointer if the node you are currently 
deleting happens to be the head.
*/