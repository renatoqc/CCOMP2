#include <iostream>
using namespace std;

void fibo(int n){
  int n1 = 1;
  int n2 = 1;
  cout << n1 << " "<< n2;
  for(int i = 0;i < n - 2; i++){
    int a = n1 + n2;
    n1 = n2;
    n2 = a;
    cout<<" "<<a;
  }
}

int main() {
  int n;
  cout<<"Ingese numero: ";
  cin>>n;
  fibo(n);
}