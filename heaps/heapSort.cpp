#include<bits/stdc++.h>

using namespace std;

void max_heapify(int A[], int n, int i)
{
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;

  if(l < n && A[largest] < A[l])
    largest = l;

  if(r < n && A[largest] < A[r])
    largest = r;

  if(largest != i){
    swap(A[i], A[largest]);
    max_heapify(A, n, largest);
  }
}

void buildheap(int A[], int n){
  for (int i = n/2 - 1; i >= 0; i--) {
    max_heapify(A, n, i);
  }
}
void heapsort(int A[], int n){
  buildheap(A, n);
  for (int i = n - 1; i >= 0; i--) {
    swap(A[0], A[i]);
    max_heapify(A, i, 0);
  }
}

int main() {
  int A[7] = {1,35,6,4,3,2,55};
  heapsort(A, 7);
  for (int i = 0; i < 7; i++) {
    std::cout << A[i] << " ";
  }
  std::cout << '\n';
  return 0;
}
