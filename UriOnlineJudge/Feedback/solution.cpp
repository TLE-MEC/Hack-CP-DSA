#include <iostream>
using namespace std;

int main()
{
 int n, k, x;
 
 cin >> n;
 
 for(int i = 0; i < n; ++i)
 {
  cin >> k;
  
  for(int j = 0; j < k; ++j)
  {
   cin >> x;
   
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
