#include <iostream>
#include <string.h>

using namespace std;

/*
Pentru numerele de 2 cifre se repeta ultima cifra din 4 in 4, pentru numerele de 3 cifre se repeta
ultimele 2 cifre din 20 in 20, pentru numerele de 4 cifre se repeta din 100 in 100, astfel observam
ca pentru a afla ultimele n cifre acestea se vor repeta din 4*5^(n-1).

In cazul acesta, nu mergem pana la puterea 7830457 deoarece ultimele 10 se vor repeta din 4*5^(7-1),
astfel nu se va ridica la puterea 7830457 ci la puterea 17957. (4*5^6 = 62500, 7830457%62500 = 17957)
*/

int RidicareLaPutere(int a, int b){ /// a^b
    int k = a;
    for(int i = 1; i<b; i++){
        a *= k;
    }
    return a;
}

int main(){
    int nrDeInmultit = 28433;
    int putereaLuiDoi = 7830457;
    int nr, rest;

    char s[11] = "0000000001";

    putereaLuiDoi = putereaLuiDoi%(4*RidicareLaPutere(5, 6));

    for(int i = 1; i<=putereaLuiDoi; i++){
        rest = 0;
        for(int j = strlen(s)-1; j>=0; j--){
            nr = s[j] - '0';
            nr = nr*2 + rest;
            rest = nr/10;
            nr %= 10;
            s[j] = nr + '0';
        }
    }


    rest = 0;

    long long int nou = 0;

    for(int j = 0; j<strlen(s); j++){ ///Transformare din sir in long long int
        nr = s[j] - '0';
        nou = nou * 10 + nr;
    }

    nou =nou *nrDeInmultit + 1;

    cout<<"Ultimele 10 cifre ale numarului prim non-Mersenne sunt: "<<nou % 10000000000<<endl;


    return 0;
}
