#include <iostream>

using namespace std;

void heapify(int *a, int i, int N) {

  int left =  2*i;
  int right = 2*i + 1;
  int largest = i;
  if(left <= N && a[left] > a[largest]) largest = left;
  if(right <= N && a[right] > a[largest]) largest = right;
  if(largest != i) {
    int temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
    heapify(a, largest, N);
  }
}
void buildHeap(int *a, int N) {
  for(int i = N/2; i > 0; i--) {
    heapify(a, i, N);
  }
}
/**************************************************************************/
void sort(int *a, int N) {
  buildHeap(a, N);
  for(int i = N; i > 0; i--) {
    int temp = a[1];
    a[1] = a[i];
    a[i] = temp;
    heapify(a, 1, i-1);
  }
}

/******************************* PRIORITY QUEUE ***************************/
int getMax(int *a) {
  return a[1];
}

int extractMax(int *a, int &N) {
  // exception if N == 0
  int max = a[1];
  a[1] = a[N];
  a[N] = max;
  heapify(a, 1, --N);
  return max;
}


void increaseVal(int *a, int i, int val, int N) {

}
//revise 
void insert() {

}



/**************************************************************************/
int main() {
  int N;
  cin>>N;
  int *a = new int[N+1];
  for(int i = 0; i < N; i++) cin>>a[i+1];
  buildHeap(a, N);
  cout<<extractMax(a, N)<<" "<<extractMax(a, N);
  //for(int i = 0; i < N; i++) cout<<a[i+1]<<" ";
  return 0;
}