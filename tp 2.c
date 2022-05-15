/*
 ============================================================================
 Name        : tp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Menu.h"
#include "utn_biblioteca.h"

#define PASSENGER_LEN 1000

int main(void) {

	setbuf(stdout,NULL);

	Passenger passengerList[PASSENGER_LEN];

	//llamo a la funcion de inicializar
	initPassengers(passengerList,PASSENGER_LEN);

	//llamo a la funcion menu
	menuPassenger(passengerList, PASSENGER_LEN);

	return EXIT_SUCCESS;
}
