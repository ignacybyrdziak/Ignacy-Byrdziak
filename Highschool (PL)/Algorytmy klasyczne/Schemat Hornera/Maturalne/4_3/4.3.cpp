#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
	{ifstream odczyt ("liczby.txt");
	 ofstream zapis ("wynik.txt");
	 string w,wmax="",wmin="";
	 int pozmax,pozmin,nr=1,i;
	 while(!odczyt.eof())
	 	{odczyt>>w;
	 	if(w.size()>wmax.size())
	 		{pozmax=nr;
	 		 wmax=w;
	 		}
	 	if(w.size()<wmin.size())
	 		{pozmin=nr;
	 		 wmin=w;
			}
		if(w.size()==wmax.size())
			{for(i=1;i<w.size();i++)
				{if(w[i]>wmax[i])
					{wmax=w;
					pozmax=nr;
					}
				 else
				 	{if(w[i]<wmax[i])
				 		break;
				 	}
				}
			}
			if(w.size()==wmin.size())
			{for(i=1;i<w.size();i++)
				{if(w[i]>wmax[i])
					{wmin=w;
					pozmin=nr;
					}
				 else
				 	{if(w[i]>wmin[i])
				 		break;
				 	}
				}
			}

		}
	}
	
