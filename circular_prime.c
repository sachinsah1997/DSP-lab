#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>

    int isPrime(int n){
 
        for (int i = 3; i <= sqrt(n); i += 2){
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
    
   int rotate(int a){

     char name[20];
     int i,j,k,ans;
     int count = 0;
    
     sprintf(name, "%d", a); 
     for(i=0;i<strlen(name);i++){
        char temp[20];
        count = 0;
    for(j=i+1;j<strlen(name);j++){
          temp[count] = name[j];
          count++;
    }
    for(k=0;k<=i;k++){
          temp[count] = name[k];
            count++;
    }  

     int newnumber  = atoi(temp);
     ans = isPrime(newnumber);
     if(ans == 0 ){
         return ans;
     }
     }
        return ans;
    }


int main(){
    
    int n;
    scanf("%d", &n);
    
    if (n <= 0){
     printf("%d",-1);
    }
    else if(n == 1){
        printf("%d",0);
    }
    else if (n == 2 ){
        printf("%d",1);
    }
    else if (n % 2 == 0){
        printf("%d",0);
    }else{
    int ans = rotate(n);
    printf("%d",ans);
    }
    return 0;
}