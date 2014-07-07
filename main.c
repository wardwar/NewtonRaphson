#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void coba()
{
	int user_power, i = 0, cnt = 0, flag = 0;
	float coef[10] = { 0 };
	float x1 = 0, x2 = 0, t = 0;
	float fx1 = 0, fdx1 = 0;

	printf("\n\n\t\t\t PROGRAM NEWTON RAPHSON");

	printf("\n\n\n\tMasukkan banyaknya polinom : ");
	scanf_s("%d", &user_power);

	for (i = 0; i <= user_power; i++)
	{
		printf("\n\t x^%d::", i);
		scanf_s("%f", &coef[i]);
	}

	printf("\n");

	printf("\n\t Polinomnya : ");
	for (i = user_power; i >= 0; i--)//printing coeff.
	{
		printf(" %fx^%d", coef[i], i);
	}

	printf("\n\t Masukkan X1---->");
	scanf_s("%f", &x1);

	printf("\n ******************************************************");
	printf("\n Iterasi    X1    FX1    F'X1  ");
	printf("\n **********************************************************");

	do
	{
		cnt++;
		fx1 = fdx1 = 0;
		for (i = user_power; i >= 1; i--)
		{
			fx1 += coef[i] * (pow(x1, i));
		}
		fx1 += coef[0];
		
		for (i = user_power; i >= 0; i--)
		{
			fdx1 += coef[i] * (i*pow(x1, (i - 1)));
		}
		t = x2;
		x2 = (x1 - (fx1 / fdx1));

		x1 = x2;

		printf("\n %d         %f  %f  %f ", cnt, x2, fx1, fdx1);

	} while ((fabs(t - x1)) >= 0.0001);
	printf("\n\t Akarnya %f", x2);
	_getch();
}

int main(int argc, char *argv[]) {

	

	
	coba();
	return 0;
}

