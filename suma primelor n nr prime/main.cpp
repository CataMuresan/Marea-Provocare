#include <iostream>

using namespace std;

bool ePrim(int n){
    for(int d = 2; d<=n/2; d++){
        if(n%d == 0){
            return false;
        }
    }
    return true;
}

int suma(int n){
    int s = 0, nr = 0, i = 2;
    while(nr < n){
        if(ePrim(i)){
            nr++;
            s += i;
        }
        i++;
    }
    return s;

}

int main(){

    int n;
    cin>>n;
    cout<<suma(n);

    return 0;
}
