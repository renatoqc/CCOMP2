#include <iostream>
using namespace std;

bool primo(int e){
    for(int i = 2; i < e; i++){
        if(e % i == 0){
            return false;
        }
    }
    return true;
}

void primos(int n){
    for(int i = 2; i < n; i++){
        if(primo(i)){
            cout<<i<<" ";
        }
    }
}

int main() {
    int n;
    cin>>n;
    primos(n);
}