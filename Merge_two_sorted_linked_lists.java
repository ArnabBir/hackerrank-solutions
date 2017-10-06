/*
  Merge two linked lists 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/

Node MergeLists(Node headA, Node headB) {
     // This is a "method-only" submission. 
     // You only need to complete this method 
    if(headA == null) return headB;
    if(headB == null) return headA;
    Node A = headA;
    Node B = headB;
    Node merged = new Node();
    Node merged_head = merged;
    while(A != null && B != null){
        if(A.data >= B.data){
            merged.data = B.data;
            B = B.next;
        }
        else{
            merged.data = A.data;
            A = A.next;
        }
        merged.next = new Node();
        merged = merged.next;
    }
    while(A != null){
        merged.data = A.data;
        if(A.next == null) break;
        merged.next = new Node();
        merged = merged.next;
        A = A.next;
    }
    while(B != null){
        merged.data = B.data;        
        if(B.next == null) break;
        merged.next = new Node();
        merged = merged.next;
        B = B.next;
    }
    //merged.next = null;
    //merged = merged.next;
    return merged_head;
}
