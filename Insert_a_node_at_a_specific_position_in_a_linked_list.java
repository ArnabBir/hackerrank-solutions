/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
    

Node InsertNth(Node head, int data, int position) {
   // This is a "method-only" submission. 
    // You only need to complete this method. 
    if (head == null && position == 0){
        head = new Node();
        head.data = data;
        head.next = null;
        return head;
    }
    else if(position == 0) {
        Node temp = new Node();
        temp.data = data;
        temp.next = head;
        return temp;
    }
    else{
        Node current = head;
        for(int i = 0; i < position - 1; ++i){
            current = current.next;
        }    
        Node temp = new Node();
        temp.data = data;
        temp.next = current.next;
        current.next = temp;
        return head;
    }
}
