#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
 
//12x20
using namespace std;
void wypisz(string tab[14][22]){
    for(int i=1;i<13;i++){
        for(int j=1;j<21;j++){
            cout<<tab[i][j];
        }
        cout<<"\n";
    }
}
int main(){
    char zycie_p[14][22],zycie_np[14][22];
    ifstream dane("gra.txt");
    //char pom=(char)getc(dane);
    string tab_p[12];
    for(int i=0;i<12;i++){
        string pom;
        dane>>pom;
        tab_p[i]=pom;
    }
    //for(int i=0;i<12;i++){
      //  cout<<tab_p[i]<<endl;
    //}
    //wypisz(zycie_p);
    for(int i=0;i<12;i++){
        for(int j=0;j<20;j++){
            zycie_p[i+1][j+1]=tab_p[i][j];
        }
    }
    //przepisywanie poziomow
    for(int j=0;j<20;j++){
        zycie_p[0][j+1]=tab_p[11][j];
        zycie_p[13][j+1]=tab_p[0][j];
    }
    //przpisywanie pionow
    for(int i=0;i<12;i++){
        zycie_p[i+1][0]=tab_p[i][19];
        zycie_p[i+1][21]=tab_p[i][0];
    }
    //przepisuywanie rogow
    zycie_p[0][0]=tab_p[11][19];
    zycie_p[0][21]=tab_p[11][0];
    zycie_p[13][0]=tab_p[0][19];
    zycie_p[13][21]=tab_p[0][0];

    int il_pokolen=5;
    for(int g=1;g<=il_pokolen;g++){
            //pokolenia nieparzyste sa liczone z parzystego
        if(g%2==1){
            for(int i=1;i<13;i++){
                for(int j=1;j<21;j++){
                    //szukamy sasiadow zaczynajac od gornego
                    if(zycie_p[i][j]=='.'){
                        int c=0;
                        if(zycie_p[i-1][j]=='X')
                            c++;
                        if(zycie_p[i-1][j+1]=='X')
                            c++;
                        if(zycie_p[i][j+1]=='X')
                            c++;
                        if(zycie_p[i+1][j+1]=='X')
                            c++;
                        if(zycie_p[i+1][j]=='X')
                            c++;
                        if(zycie_p[i+1][j-1]=='X')
                            c++;
                        if(zycie_p[i][j-1]=='X')
                            c++;
                        if(zycie_p[i-1][j-1]=='X')
                            c++;
                        if(c==3){
                            zycie_np[i][j]='X';
                        }
                        else{
                            zycie_np[i][j]='.';
                        }
                    }
                    if(zycie_p[i][j]=='X'){
                        int c=0;
                        if(zycie_p[i-1][j]=='X')
                            c++;
                        if(zycie_p[i-1][j+1]=='X')
                            c++;
                        if(zycie_p[i][j+1]=='X')
                            c++;
                        if(zycie_p[i+1][j+1]=='X')
                            c++;
                        if(zycie_p[i+1][j]=='X')
                            c++;
                        if(zycie_p[i+1][j-1]=='X')
                            c++;
                        if(zycie_p[i][j-1]=='X')
                            c++;
                        if(zycie_p[i-1][j-1]=='X')
                            c++;
                        if(c==3 || c==2){
                            zycie_np[i][j]='X';
                        }
                        else{
                            zycie_np[i][j]='.';
                        }
                    }
                }
            }
            //przepisanie obwodki ponowne
                //przepisywanie poziomow
            for(int j=0;j<20;j++){
                zycie_p[0][j+1]=zycie_p[12][j+1];
                zycie_p[13][j+1]=zycie_p[1][j+1];
            }
            //przpisywanie pionow
            for(int i=0;i<12;i++){
                zycie_p[i+1][0]=zycie_p[i+1][20];
                zycie_p[i+1][21]=zycie_p[i+1][1];
            }
            //przepisuywanie rogow
            zycie_p[0][0]=zycie_p[12][20];
            zycie_p[0][21]=zycie_p[12][0];
            zycie_p[13][0]=zycie_p[0][20];
            zycie_p[13][21]=zycie_p[0][0];

        }
            //pokolenia parzyste sa liczone z nieparzystego
        else{
            for(int i=1;i<13;i++){
                for(int j=1;j<21;j++){
                    //szukamy sasiadow zaczynajac od gornego
                    if(zycie_np[i][j]=='.'){
                        int c=0;
                        if(zycie_np[i-1][j]=='X')
                            c++;
                        if(zycie_np[i-1][j+1]=='X')
                            c++;
                        if(zycie_np[i][j+1]=='X')
                            c++;
                        if(zycie_np[i+1][j+1]=='X')
                            c++;
                        if(zycie_np[i+1][j]=='X')
                            c++;
                        if(zycie_np[i+1][j-1]=='X')
                            c++;
                        if(zycie_np[i][j-1]=='X')
                            c++;
                        if(zycie_np[i-1][j-1]=='X')
                            c++;
                        if(c==3){
                            zycie_p[i][j]='X';
                        }
                        else{
                            zycie_p[i][j]='.';
                        }
                    }
                    if(zycie_np[i][j]=='X'){
                        int c=0;
                        if(zycie_np[i-1][j]=='X')
                            c++;
                        if(zycie_np[i-1][j+1]=='X')
                            c++;
                        if(zycie_np[i][j+1]=='X')
                            c++;
                        if(zycie_np[i+1][j+1]=='X')
                            c++;
                        if(zycie_np[i+1][j]=='X')
                            c++;
                        if(zycie_np[i+1][j-1]=='X')
                            c++;
                        if(zycie_np[i][j-1]=='X')
                            c++;
                        if(zycie_np[i-1][j-1]=='X')
                            c++;
                        if(c==3 || c==2){
                            zycie_p[i][j]='X';
                        }
                        else{
                            zycie_p[i][j]='.';
                        }
                    }
                }
            }
            //przepisywanie obwodki
            for(int j=0;j<20;j++){
                zycie_np[0][j+1]=zycie_np[12][j+1];
                zycie_np[13][j+1]=zycie_np[0][j+1];
            }
            //przpisywanie pionow
            for(int i=0;i<12;i++){
                zycie_np[i+1][0]=zycie_np[i+1][20];
                zycie_np[i+1][21]=zycie_np[i+1][0];
            }
            //przepisuywanie rogow
            zycie_np[0][0]=zycie_np[12][20];
            zycie_np[0][21]=zycie_np[12][0];
            zycie_np[13][0]=zycie_np[0][20];
            zycie_np[13][21]=zycie_np[0][0];

        }

    }
    //wypisywanie
    if(il_pokolen%2==0){
        for(int i=0;i<13;i++){
            for(int j=0;j<22;j++){
                cout<<zycie_p[i][j];
            }
            cout<<"\n";
        }
    }
    else{
        for(int i=0;i<13;i++){
            for(int j=0;j<22;j++){
                cout<<zycie_np[i][j];
            }
            cout<<"\n";
        }
    }
}
