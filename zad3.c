/*
 ============================================================================
 Name        : zad3.c
 Author      : MS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float suma(int a,int b)
	{
	float wynik=a+b;
	return wynik;
	}
float iloraz (int a,int b)
	{
	float x=a; //rzutowanie
	float y=b;
	float wynik=x/y;
	return wynik;
	}

//deklaracja wskażnika na funkcję
float (*funkcja_wsk) (int, int);


//deklaracja 3 funkcji z argumentem w postaci wskaźnika
float funkcja3(float (*wsk_do_funkcji_przekazany) (int, int),int a ,int b)
	{
	//implementacja aby wykonywała odpowiednią funkcję
	float wynik = (*wsk_do_funkcji_przekazany) (a,b);
	return wynik;
	}




int main(void) {
	//wywołanie funkcji3 z adresem funkcji suma jako argument
	funkcja_wsk=&suma;
	printf("wunik sumowania : %f \n",funkcja3(funkcja_wsk,2,3));

	//wywołanie funkcji3 z adresem funkcji iloraz jako argument
	funkcja_wsk=&iloraz;
	printf("wynik ilorazu : %f \n",funkcja3(funkcja_wsk,2,3));

	//eksperymenty
	printf("wynik  : %f \n",funkcja3(suma,2,3));  //sama nazwa funkcji także jest wskaźniekiem na funkcję
	printf("wynik  : %f \n",funkcja3(iloraz,2,3));
	printf("wynik  : %f \n",funkcja3(NULL,2,3));
	return EXIT_SUCCESS;
}

/* nazwa funkcji jest jednocześnie jest jednocześnie wskaźnikiem na funkcję
 * w przypadku podania NULL jako wskaźnika funkcja się nie wykona ale nie wystąpi błąd

 */
