#include <iostream>
using namespace std;
int main()
{int i=0,x,y,xh,yh;
int szachy[8][8];
for(y=0;y<=7;y++)
	{for(x=0;x<=7;x++)
		szachy[x][y]=0;
	}
cout<<"---------------------------------------"<<endl;
for(y=0;y<8;y++)
	{for(x=0;x<8;x++)
		{cout<<" "<<szachy[x][y]<<" | ";}
	cout<<endl;
	cout<<"---------------------------------------"<<endl;
	}
cout<<" Podaj pozycje Hetmana "<<endl;
cin>>xh>>yh;
if(xh>=0 && xh<=7 && yh>=0 && yh<=7)
	szachy [xh][yh]=2;
else
	cout<<" Bledna wartosc ";
for(x=xh,y=0;y<=7;y++)
	szachy[x][y]=1;
for(x=0,y=yh;x<=7;x++)
	szachy[x][y]=1;
for(x=xh,y=yh; x>=0 && y>=0;x--,y--)
	szachy[x][y]=1;	
for(x=xh,y=yh; x<=7 && y<=7;x++,y++)
	szachy[x][y]=1;	
for(x=xh,y=yh; x<=7 && y>=0;x++,y--)
	szachy[x][y]=1;
for(x=xh,y=yh; x>=0 && y<=7;x--,y++)
	szachy[x][y]=1;
szachy[xh][yh]=2;
cout<<"---------------------------------------"<<endl;
for(y=0;y<8;y++)
	{for(x=0;x<8;x++)
		{cout<<" "<<szachy[x][y]<<" | ";}
	cout<<endl;
	cout<<"---------------------------------------"<<endl;
	}
for(y=0;y<=7;y++)
	{for(x=0;x<8;x++)
		{if(szachy[x][y]==1)
			i++;
		}
	}
cout<<" Hetman atakuje "<<i<<" pol ";
return 0;
}
