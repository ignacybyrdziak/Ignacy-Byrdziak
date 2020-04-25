#include <iostream>
using namespace std;
int main(){
    /*int tab[4]={0,1,0,-1};
    long long int R;
    cin>>R;
    int sum=0,pom=R*R;
    for(int i=1;i<=R;i++){
        if(R%i==0){
            sum+=(tab[i%4]*pom)/i;
        }
    }
    cout<<sum*4;*/
    int r;
    cin>>r;
    int sum=0;
    for(int x=1;x<=r;x++){
        for(int y=0;y<=r;y++){
            if(x*x+y*y<=r*r)
                sum++;
        }
    }
    cout<<1+sum*4;
}
