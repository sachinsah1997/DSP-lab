#include<stdio.h>

int getMax (int arr[], int n){

  int mx = arr[0];
  int i;

  for (i = 1; i < n; i++)
    if (arr[i] > mx)
      mx = arr[i];
  return mx;

}

void countSort (int arr[], int n, int exp){

  int output[n];    // output array
  int i, count[10] = { 0 };

  // Store count of occurrences in count[]

  for (i = 0; i < n; i++)
    count[(arr[i] / exp) % 10]++;

  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (i = n - 1; i >= 0; i--)
    {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }

  for (i = 0; i < n; i++)
    arr[i] = output[i];
}

void radixsort (int arr[], int n){

  int m = getMax (arr, n);
  int exp;

  for (exp = 1; m / exp > 0; exp *= 10)
    countSort (arr, n, exp);
}

void print (int arr[], int n){

  int i;
  for (i = 0; i < n; i++)
    printf ("%d ", arr[i]);
    
    printf("\n");
}

int main (){

  int n;
  scanf ("%d", &n);
  
  if(n<=0){
      printf("INVALID INPUT");
      return 0;
  }

  int arr[n];

  for (int i = 0; i < n; i++)
    {
      int temp;
      scanf ("%d", &temp);
      if(temp<0){
          printf("INVALID INPUT");
          return 0;
      }
      arr[i] = temp;
    }

  printf ("before sorting :"); print (arr, n);

  radixsort (arr, n);

  printf ("After sorting :"); print (arr, n);

  return 0;
}