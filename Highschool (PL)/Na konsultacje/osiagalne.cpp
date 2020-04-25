#include <iostream>
using namespace std;
int s(int k){
    int ret=0;
    while(k>0){
        ret+=k%10;
        k/=10;
    }
    //cout<<ret<<endl;
    return ret;
}
int main(){
    for(int n=100;n<1000;n++){
        for(int i=n-27;i<n;i++){
            if(s(i)+i==n){
                cout<<n<<":  "<<i<<" "<<s(i)<<"\n";
                break;
            }
        }
    }
}
