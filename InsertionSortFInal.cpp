#include<iostream>
using namespace std;

void Print(int A[], int n) {
   for(int i = 0; i<n; i++)
      cout << A[i] << endl;
}
void InsertionSort(int A[], int n) {
   int tmp, j;
   for(int i = 1; i<n; i++) {
      tmp = A[i];
      j = i;
      while(j > 0 && A[j-1]>tmp) {
         A[j] = A[j-1];
         j--;
      }
      A[j] = tmp;
   }
}

int main() {
   int n;
   cin >> n;
   int A[n];
   for(int i = 0; i<n; i++) {
      cin >> A[i];
   }

   InsertionSort(A, n);
   Print(A, n);
}
