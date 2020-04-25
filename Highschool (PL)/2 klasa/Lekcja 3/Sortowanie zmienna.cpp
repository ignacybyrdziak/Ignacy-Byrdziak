#include <iostream>
using namespace std;
int main()
{float a,b,c,pom;
cout<<" Podaj trzy liczby ";
cin>>a>>b>>c;
			if(a>b)
			{pom=a;
			a=b;
			b=pom;}
    if(a>c)
    {pom=a;
    a=c;
    c=pom;}
            if(b>c)
            {pom=b;
            b=c;
            c=pom;}
cout<<a<<","<<b<<","<<c<<endl;
return 0;
}
