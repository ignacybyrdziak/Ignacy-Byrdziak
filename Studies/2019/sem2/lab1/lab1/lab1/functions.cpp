#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Check_PESEL(char PESEL[]){										//checking if PESEL is valid (validation)		
	char tempPESEL[12];
	for (int i = 0; i < 11; i++)
		tempPESEL[i] = PESEL[i] - 48;

	int summ = 0;													//checking
	for (int i = 0; i < 10; i++){
		if (i % 4 == 1){
			tempPESEL[i] = tempPESEL[i] * 3;
			while (tempPESEL[i] > 10)
				tempPESEL[i] = tempPESEL[i] % 10;
		}
		if (i % 4 == 2){
			tempPESEL[i] = tempPESEL[i] * 7;
			while (tempPESEL[i] > 10)
				tempPESEL[i] = tempPESEL[i] % 10;
		}
		if (i % 4 == 3){
			tempPESEL[i] = tempPESEL[i] * 9;
			while (tempPESEL[i] > 10)
				tempPESEL[i] = tempPESEL[i] % 10;
		}
		summ = summ + tempPESEL[i];
	}

	while (summ > 10)
		summ = summ % 10;

	int real_summ = 10;
	real_summ = real_summ - summ;

	int control_number = tempPESEL[10] - 48;						//checking control number
	if (control_number == real_summ)
		return true;
	else
		return false;
}

void Check_Sex(char PESEL[]){										//checking sex of a person
	if (PESEL[9] % 2 == 0)
		printf("Woman\n");
	else
		printf("Man\n");
}

void Check_Date(char PESEL[]){										//checking birth date of a person
	int year = PESEL[2] - 48;
	int month = 0;
	if (year == 8 || year == 9) {	//19th century{
		month = year - 8;
		year = 18;
	}
	if (year == 0 || year == 1){	//20th century
		month = year;
		year = 19;
	}
	if (year == 3 || year == 2){	//21st century 
		month = year - 2;
		year = 20;
	}
	if (year == 5 || year == 4){	//22nd century
		month = year - 4;
		year = 21;
	}
	if (year == 6 || year == 7){	//23rd century
		month = year - 6;
		year = 22;
	}
	printf("Data to %c%c.%d%c.%d%c%cr.\n", PESEL[4], PESEL[5], month, PESEL[3], year, PESEL[0], PESEL[1]);
}