#include <stdio.h>

int main() {
    
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d",&temp);
        arr[i] = temp;
    }
   int i, j, position, swap;
   for (i = 0; i < (n - 1); i++) {
      position = i;
      for (j = i + 1; j < n; j++) {
         if (arr[position] > arr[j])
            position = j;
      }
      if (position != i) {
         swap = arr[i];
         arr[i] = arr[position];
         arr[position] = swap;
      }
   }
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
   return 0;
}