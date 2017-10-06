/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as  
  class Node {
     int data;
     Node next;
  }
*/
    // This is a "method-only" submission. 
    // You only need to complete this method. 
Node Reverse(Node head) {
    if(head == null || head.next == null){
        return head;
    }
    Node rev = Reverse(head.next);
    head.next.next = head;
    head.next = null;
    return rev;
}
