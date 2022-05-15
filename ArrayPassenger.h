/*
 * ArrayPassengers.h
 *
 *  Created on: 14 may. 2022
 *      Author: USURIO
 */

#ifndef ARRAYPASSENGERS_H_
#define ARRAYPASSENGERS_H_

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int statusFlight;
int isEmpty;
}typedef Passenger;

int initPassengers(Passenger passengerList[],int len);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);
int findEmptyPosition(Passenger* pPassenger, int len);
int modifyPassenger(Passenger* pPassenger);
int printPassenger(Passenger* pPassenger);
int findPassengerById(Passenger* pPassenger, int len, int idBuscado);
int removePassenger(Passenger passengerList[], int len, int idBuscado);
int sortPassengerPorApellidoYTipo(Passenger* passengersList, int limit);
int average(Passenger *passengerlist, int len);
int sortPassengerPorCodigoYStatus(Passenger* passengersList, int limit);

#endif /* ARRAYPASSENGERS_H_ */
