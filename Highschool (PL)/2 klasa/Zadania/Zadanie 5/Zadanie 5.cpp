#include <iostream>
using namespace std;
int main()
{int n,l,k;
cout<<" Podaj n ";
cin>>n;
	for(l=1;l<=n;l++)
		{if(l%2!=0)
			{for(k=1;k<=n;k++)
				{if(k%2!=0)
					cout<<" * ";
				else
					cout<<" ? ";
				}
				cout<<endl;
			}
		else
			{for(k=1;k<=n;k++)
					{if(k%2!=0)
						cout<<" ? ";
					else
						cout<<" * ";
					}
				cout<<endl;

			}
		}
return 0;}
