#include <stdio.h>
 
int main() {
 
 int i = 0, j = 0, n, k, x; //initalizing values
 
 scanf("%d", &n);
 
 for(i = 0; i < n; ++i) 
 {
  scanf("%d", &k); //K lines with and integer representing the category of each of the feedbacks
  
  for(j = 0; j < k; ++j)
  {
   scanf("%d", &x);
   
   //Printing names as per the assignment
   
   if(x == 1){
    printf("Rolien\n"); 
   }else if(x == 2){
       printf("Naej\n");
   }else if(x == 3){
       printf("Elehcim\n");
   }else{
       printf("Odranoel\n");
   }
  }
 }
 
    return 0;
}
