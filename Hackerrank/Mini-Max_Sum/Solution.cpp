#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.
void miniMaxSum() {
    int a[5];
    long long sum=0;
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    for(int i=0;i<5;i++){
        sum+=a[i];
    }
     int temp=0;
for(int i=0;i<4;i++){
    for(int j=i+1;j<5;j++){
        if(a[i]>a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}
 int first=a[0],last=a[4];
 cout << sum -last << " " << sum -first << endl;
}

int main()
{
    miniMaxSum();
  return 0;
}