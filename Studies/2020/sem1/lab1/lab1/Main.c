#include <stdio.h>
#include <vector>

void calc2(unsigned int a, unsigned int b)
{
	char operator;
	unsigned int c, d, e, f, g, h, i, j, k, l;

	printf("Podaj dzialanie\n");
	scanf_s(" %c", &operator);
	
	switch (operator)
	{
	case '&':
		c = (a & b);
		printf("%d AND %d wynosi %d\n", a, b, c);
		break;

	case '|':
		d = (a | b);
		printf("%d OR %d wynosi %d\n", a, b, d);
		break;

	case '~':
		e = ~a;
		f = ~b;
		printf("%d NEG wynosi %x, a %d NEG wynosi %x\n", a, e, b, f);
		break;

	case '<':
		g = a << 1;
		h = b << 1;
		printf("%d SHL wynosi %x, a %d SHL wynosi %x\n", a, g, b, h);
		break;

	case '>':
		i = a >> 1;
		j = a >> 1;
		printf("%d SHR wynosi %x, a %d SHR wynosi %x\n", a, i, b, j);
		break;

	case '^':
		k = (a ^ b);
		printf("%d XOR %d wynosi %d\n", a, b, k);
		break;

	case 'x':
		l = ~(a ^ b);
		printf("%d XAND %d wynosi %d\n", a, b, l);
		break;
	}

	return;
}

void hex_to_bin(int a)
{
	vector <int> binary;

	return 0;
}

int main()
{
	unsigned int i, j, k;
	printf("Podaj 2 liczby\n");
	scanf_s("%d%d", &i, &j);

	calc2(i, j);

	printf("Podaj liczbe do zamiany z hex na bin");
	scanf_s("%x", &k);
	hex_to_bin(k);

	//int k=calc(i,j);
	//printf("Suma to %d",k);

	return 0;
}

/*int calc(int a, int b)
{
int c;
c=a+b;
return c;
}*/
