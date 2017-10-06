#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

void minHeapify(ll * heap, int index, int size){
    int minIndex = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < size && heap[index] > heap[left]) minIndex = left;
    if(right < size && heap[index] > heap[left]) minIndex = right;
    if(minIndex != index){
        swap(heap[index], heap[minIndex]);
        minHeapify(heap, minIndex, size);
    }
}


void shiftUp(ll * heap, int index){
    if(index == 0) return;
    int parentIndex = (index - 1) / 2;
    if(heap[index] < heap[parentIndex]){
        swap(heap[index], heap[parentIndex]);
        shiftUp(heap, parentIndex);
    }
}

void insertValue(ll * heap, ll v, int size){
    if(size == 0){
        heap[0] = v;
    }
    else{
        heap[size] = v;
        shiftUp(heap, size);
    }
}

void deleteValue(ll * heap, ll v, int size){
    
    swap(*find(heap, heap + size, v), heap[size - 1]);
    --size;
    for(int i = size/2 - 1; i >= 0; --i){
        minHeapify(heap, i, size);
    }
}

int main() {
    int Q, choice, size = 0;
    ll v;
    cin>>Q;
    ll heap[Q];
    while(Q--){
        cin>>choice;
        switch(choice){
            case 1:
                cin>>v;
                insertValue(heap, v, size++);
                break;
            case 2:
                cin>>v;
                deleteValue(heap, v, size--);
                break;
            case 3:
                cout<<heap[0]<<endl;
                break;
        }
    }
    return 0;
}
