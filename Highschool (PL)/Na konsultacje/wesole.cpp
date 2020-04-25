#include <iostream>
using namespace std;
int w(int x){
    int sum=0;
    while(x>0){
        sum+=(x%10)*(x%10);
        x/=10;
    }
    return sum;
}
int main(){
    for(int n=10;n<100;n++){
        int pom=n;
        while(true){
            if(pom==4)
                break;
            if(pom==1){
                cout<<n<<"\n";
                break;
            }
            pom=w(pom);
        }
    }
}
