#include <iostream>
#include <vector>

using namespace std;

void swap(int &a , int &b ) {
    int tmp = a;
    a = b;
    b = tmp;
}
void max_heapify(int arr[],int i,int size)//以某个节点为根节点的子树进行调整，调整为大顶堆
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if( l < size && arr[l] > arr[i] )
    {
        largest=l;
    }
    if( r < size && arr[r] > arr[largest] )
    {
        largest=r;
    }
    if( largest!=i )
    {
        swap(arr[largest], arr[i]);
        max_heapify(arr,largest,size);
    }
}

void build_max_heap(int arr[],int size) {
    for(int i=size/2-1; i>=0; i--)
        max_heapify(arr, i, size);
}

void heapSort(int arr[],int size) {
    build_max_heap(arr,size);
    for(int i=size-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr,0,i);
    }
}

void print(int arr[],int size ) {
   for (int i=0; i<size; ++i) {
       cout << arr[i] << " " ;
   }
   cout << endl;
}
int main(void) {
    int arr[] {1,3,7,5,2,6,9,4,8,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    heapSort(arr, size);
    print(arr,size);


}
