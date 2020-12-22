#include <stdio.h>
   
    void main(){

        int i, j, a;
        //given array
        int number[] = {25,10,6,30,5,10,95,48,10,13};
        //no. of element in the array
        int n=10;

        // bubble sort used for sorting
        for (i = 0; i < n; ++i){
            for (j = i + 1; j < n; ++j){

                if (number[i] > number[j]){
                    a =  number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }

        printf("Sorted Array : ");
        for (i = 0; i < n; ++i){
            printf("%d ", number[i]);
        }
        printf("\n");

        //element whose position to found
        int find_element = 10;
        int count = 0;
        int first,last;

        //traverse each element to match the required element.
        for (int i = 0; i < n; ++i){
            //if element matches then increment count so that we can get first position.
            if(number[i] == find_element){
                if(count == 0){
                    printf("Starting index : %d\n", i+1);
                    count++;
                }else{
                    //we will keep on incrementing till last
                    last = i+1;  
                }
            }
        }
        printf("last index : %d\n", last);
    }