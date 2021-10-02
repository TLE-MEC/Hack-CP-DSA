#include <iostream>
using namespace std;

int main()
{
 int n, k, x; //setting variables
 
 cin >> n;
 
 for(int i = 0; i < n; ++i)
 {
  cin >> k; //K lines with and integer representing the category of each of the feedbacks
  
  for(int j = 0; j < k; ++j)
  {
   cin >> x;
   
   //printing values as per the assignment
   
   if(x == 1){
    cout << "Rolien" << endl;
   }else if(x == 2){
    cout << "Naej" << endl;
   }else if(x == 3){
    cout << "Elehcim" << endl;
   }else{
    cout << "Odranoel" << endl;
   }
  }
 }
   
 return 0;
}
