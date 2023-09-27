#include <iostream>
using namespace std;

bool perfecto(int e){
    int t = 0;
    for(int i = 1; i < e; i++){
        if(e % i == 0){
            t += i;
        }
    }
    return t == e;
}

void perfectos(int n){
    for(int i = 1; i < n; i++){
        if(perfecto(i)){
            cout<<i<<endl;
        }
    }
}

int main() {
    int n;
    cout<<"Ingese numero: ";
    cin>>n;
    perfectos(n);
}