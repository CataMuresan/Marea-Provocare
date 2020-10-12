#include <iostream>

using namespace std;

bool ePrim(int numar){
    for(int d = 2; d<=numar/2; d++){
        if(numar%d == 0){
            return false;
        }
    }
    return true;
}

int sumaPrimelorNCifrePrime(int numar){
    int suma = 0, nrAparitii = 0, i = 2;
    while(nrAparitii < numar){
        if(ePrim(i)){
            nrAparitii++;
            suma += i;
        }
        i++;
    }
    return suma;

}

int main(){

    int numar;
    cin>>numar;
    cout<<sumaPrimelorNCifrePrime(numar);

    return 0;
}
