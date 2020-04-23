#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//void calc2(unsigned int a, unsigned int b)
//{
//	char operator;
//	unsigned int c, d, e, f, g, h, i, j, k, l;
//
//	printf("Podaj dzialanie\n");
//	scanf_s(" %c", &operator);
//	
//	switch (operator)
//	{
//	case '&':
//		c = (a & b);
//		printf("%d AND %d wynosi %d\n", a, b, c);
//		break;
//
//	case '|':
//		d = (a | b);
//		printf("%d OR %d wynosi %d\n", a, b, d);
//		break;
//
//	case '~':
//		e = ~a;
//		f = ~b;
//		printf("%d NEG wynosi %x, a %d NEG wynosi %x\n", a, e, b, f);
//		break;
//
//	case '<':
//		g = a << 1;
//		h = b << 1;
//		printf("%d SHL wynosi %x, a %d SHL wynosi %x\n", a, g, b, h);
//		break;
//
//	case '>':
//		i = a >> 1;
//		j = a >> 1;
//		printf("%d SHR wynosi %x, a %d SHR wynosi %x\n", a, i, b, j);
//		break;
//
//	case '^':
//		k = (a ^ b);
//		printf("%d XOR %d wynosi %d\n", a, b, k);
//		break;
//
//	case 'x':
//		l = ~(a ^ b);
//		printf("%d XAND %d wynosi %d\n", a, b, l);
//		break;
//	}
//
//	return;
//}

typedef struct node
{
	int val;
	struct node * next;
} number_node;

void print_list(number_node * head)
{
	number_node * current = head;

	while (current->next != NULL) {
		printf("%d", current->val);
		current = current->next;
	}
}

void push(number_node * head, int val)
{
	number_node * current = head;
	while (current->next != NULL)
		current = current->next;

	//adding a new variable
	current->next = (number_node *)malloc(sizeof(number_node));
	current->val = val;
	current->next->next = NULL;
}

void push_at_first_place(number_node ** head, int val)
{
	number_node * new_node;
	new_node = (number_node *)malloc(sizeof(number_node));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}

//void dec_to_bin(int a)
//{
//	
//	return 0;
//}

int hex_to_dec(char hex[100])
{
	int value, exponent=0, decimal=0;
	char digit;

	for (int i = strlen(hex)-1; i>=0; i--)
	{
		digit = hex[i];
		switch (digit)
		{
		case 'A':
			value = 10;
			break;
		case 'a':
			value = 10;
			break;
		case 'B':
			value = 11;
			break;
		case 'b':
			value = 11;
			break;
		case 'C':
			value = 12;
			break;
		case 'c':
			value = 12;
			break;
		case 'D':
			value = 13;
			break;
		case 'd':
			value = 13;
			break;
		case 'E':
			value = 14;
			break;
		case 'e':
			value = 14;
			break;
		case 'F':
			value = 15;
			break;
		case 'f':
			value = 15;
			break;
		case '0':
			value = 0;
			break;
		case '1':
			value = 1;
			break;
		case '2':
			value = 2;
			break;
		case '3':
			value = 3;
			break;
		case '4':
			value = 4;
			break;
		case '5':
			value = 5;
			break;
		case '6':
			value = 6;
			break;
		case '7':
			value = 7;
			break;
		case '8':
			value = 8;
			break;
		case '9':
			value = 9;
			break;
		default:
			printf("Blad, zostala wpisana zla liczba");
			break;
		}

		decimal += value * pow(16, exponent);
		exponent++;
	}
	return decimal;
}

int main()
{
	char hex[100];
	printf("Enter any hexadecimal number: ");
	gets(hex);

	int val = hex_to_dec(hex), rest;
	printf("%d", val);

	number_node * binary_numer = (number_node *)malloc(sizeof(number_node));
	binary_numer->next = NULL;

	while (val != 0)
	{
		rest = val % 2;
		push_at_first_place(binary_numer, rest);
		val /= 2;
	}

	printf("\n");
	print_list(binary_numer);

	unsigned int i, j, k;
	//printf("Podaj 2 liczby\n");
	//scanf_s("%d%d", &i, &j);

	//calc2(i, j);

	//printf("Podaj liczbe do zamiany z hex na bin\n");
	//scanf_s("%x", &k);
	//dec_to_bin(k);

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
