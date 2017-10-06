*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
int CompareLists(Node headA, Node headB) {
    // This is a "method-only" submission. 
    // You only need to complete this method
    if(headA == null && headB == null) return 1;
    if(headA == null || headB == null) return 0;
    Node A = headA;
    Node B = headB;
    while(A != null && B != null){
        if( A.data != B.data) return 0;
        A = A.next;
        B = B.next;
    }
    if(A == null && B == null) return 1; 
    if(A == null || B == null) return 0;
    return 0;
}
