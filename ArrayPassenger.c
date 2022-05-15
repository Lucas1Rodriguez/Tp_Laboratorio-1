/*
 * ArrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: USURIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn_biblioteca.h"

#define NAME_AND_LAST_NAME_LEN 51
#define FLY_CODE_LEN 10




static int getId(void);
static int getFieldToModify(int* selectedField);
static int SortPassengers(void);

//Se inicializa la bandera isEmpty
int initPassengers(Passenger passengerList[],int len)
{
	int index;
	int retorno = -1;

	if(passengerList != NULL && len > 0)
	{
		for(index=0; index < len; index++)
		{
			passengerList[index].isEmpty = 1;
		}
		retorno=1;
	}
	return retorno;
}

//Cargo los pasajeros
//Llamo a las funciones pedir entero,texto y float
//Devuelvo el resultado por puntero
//Cambio el valor de la bandera a 0
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno=-1;
	int auxType;
	int auxStatus;
	float auxPrice;
	char auxName[NAME_AND_LAST_NAME_LEN];
	char auxLastName[NAME_AND_LAST_NAME_LEN];
	char auxFlyCode[FLY_CODE_LEN];

	if(list!=NULL)
	{
		if(utn_getText(auxName, NAME_AND_LAST_NAME_LEN , "Ingrese el nombre del pasajero: \n", "Error\n",3)==0)
		{
			if(utn_getText(auxLastName,NAME_AND_LAST_NAME_LEN, "\nIngrese el apellido del pasajero: \n", "Error\n",3)==0)
			{
				if(utn_getNumeroFloat(&auxPrice, "\nIngrese el precio del viaje:  \n", "Error\n",1, 100000, 3)==0)
				{
					if(utn_getNumeroInt(&auxType, "\nIngrese el tipo de pasajero: \n1)Hombre \n2)Mujer \n3)Otro \n", "Error\n",1, 3, 3)==0)
					{
						if(utn_getText(auxFlyCode, FLY_CODE_LEN , "\nIngrese el codigo de vuelo: \n", "Error\n",3)==0)
						{
							if(utn_getNumeroInt(&auxStatus, "\nIngrese el estado del vuelo: \n1)Activo \n2)Inactivo \n", "Error\n",1, 2, 3)==0)
							{
							list->price= auxPrice;
							list->typePassenger= auxType;
							list->id = getId();
							strncpy(list->name,auxName,sizeof(list->name));
							strncpy(list->lastName,auxLastName,sizeof(list->lastName));
							strncpy(list->flycode,auxFlyCode,sizeof(list->flycode));
							list->statusFlight = auxStatus;
							list->isEmpty = 0;
							retorno=1;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

//Funcion privada del archivo
//Genero un id y lo retorno
static int getId(void)
{
	static int contador=0;
	contador++;//Es global : Mantiene su valor
	return contador;
}


//Recorro el array
//Verifico que haya espacio
//Retorno la posicion
int findEmptyPosition(Passenger* pPassenger, int len)
{
	int retorno=-1;
	int i;

	if(pPassenger!=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(pPassenger[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int modifyPassenger(Passenger* pPassenger)
{
	int status=-1;
	int idAModificar;
	Passenger auxPassenger;
	if(pPassenger !=NULL)
	{
		if(getFieldToModify(&idAModificar)==1)
		{
			status=0;
			switch (idAModificar)
			{
			case 1:
				if(utn_getText(auxPassenger.name,NAME_AND_LAST_NAME_LEN , "Ingrese nuevo nombre: \n", "Error\n", 3)==0)
				{
					strncpy(pPassenger->name, auxPassenger.name, NAME_AND_LAST_NAME_LEN);
				}
				break;
			case 2:
				if(utn_getText(auxPassenger.lastName,NAME_AND_LAST_NAME_LEN , "Ingrese nuevo apellido: \n", "Error\n", 3)==0)
				{
					strncpy(pPassenger->lastName, auxPassenger.lastName, NAME_AND_LAST_NAME_LEN);
				}
				break;
			case 3:
				if(utn_getNumeroFloat (&auxPassenger.price, "Ingrese nuevo precio: \n","Error\n",1,100000,3)==0)
				{
					pPassenger->price = auxPassenger.price;
				}
				break;
			case 4:
				if(utn_getNumeroInt(&auxPassenger.typePassenger, "Ingrese nuevo tipo de pasajero: \n1)Hombre \n2)Mujer \n3)Otro \n","Error\n", 1, 3, 3)==0)
				{
					pPassenger->typePassenger = auxPassenger.typePassenger;
				}
				break;
			case 5:
				if(utn_getText(auxPassenger.flycode,FLY_CODE_LEN , "Ingrese nuevo codigo de vuelo: \n", "Error\n", 3)==0)
				{
					strncpy(pPassenger->flycode, auxPassenger.flycode, FLY_CODE_LEN);
				}
				break;
			}
			status = 1;
		}
	}
	return status;
}
//Funcion privada del archivo
//Llamo a la funcion pedir int
//Retorno por puntero el valor ingresado para la funcion modificar
static int getFieldToModify(int* selectedField)
{
	int status=-1;
	int auxSelectItem;

	{
		status =1;
	if(utn_getNumeroInt(&auxSelectItem, "\nElegi la opcion:\n 1-Nombre\n 2-Apellido\n 3-Precio\n 4-Tipo de pasajero\n 5-Codigo de vuelo\n", "Error, elegi un campo valido",1 , 5, 3)==0)
		*selectedField= auxSelectItem;
	}
	return status;
}

//Imprimo las posiciones que tengan la bandera isEmpty iniciada
int printPassenger(Passenger* pPassenger)
{
	if(pPassenger->isEmpty ==0)
	{
		printf("id: %d, %s, %s, %f, %d, %s, %d\n",pPassenger->id, pPassenger->name, pPassenger->lastName, pPassenger->price, pPassenger->typePassenger, pPassenger->flycode, pPassenger->statusFlight);
	}
	return 1;
}

//Recorro el array
//Verifico que exista el id
//Retorno la posicion
int findPassengerById(Passenger* pPassenger, int len, int idBuscado)
{
	int status=-1;
	int i;

	if(pPassenger!=NULL && len>0 && idBuscado>=0)
	{
		for(i=0; i<len ; i++)
		{
			if( pPassenger[i].id==idBuscado && pPassenger[i].isEmpty == 0)
			{
				status = i;
				break;
			}
		}
	}
	return status;
}

//Para eliminar a los pasajeros
//Cambio el isEmpty del id recibido a 1
int removePassenger(Passenger passengerList[], int len, int idBuscado)
{
	int status = -1;
	if(passengerList != NULL)
	{
		for(int i;i<len;i++)
		{
			if(passengerList[i].id == idBuscado)
			{
				status = 1;
				passengerList[i].isEmpty=1;
			}
		}
	}
	return status;
}

//Funcion privada del archivo
//Llamo a la funcion pedir entero
//Retorno el valor ingresado para la funcion ordenamiento
static int SortPassengers(void)
{
	int status;
	int auxOrdenamiento;

	if(utn_getNumeroInt(&auxOrdenamiento, "\n1)Ordenar A-Z:\n2)Ordenar Z-A\n", "Error",1 , 2, 6)==0)
	{
		status = auxOrdenamiento;
	}
	return status;
}
//Funcion ordenamiento
//Llamo a la funcion seleccionar
//Ordeno segun la opcion ingresada
int sortPassengerPorApellidoYTipo(Passenger* passengersList, int limit)
{
	int estado=-1;
	int flagSwap;
	int auxSortApellido;
	Passenger buffer;

		if(passengersList != NULL && limit>=0)
		{
			flagSwap=0;
			if(SortPassengers()==1)
			{
				do{
					flagSwap=0;
					for(int i=0; i<limit-1; i++)
					{
						auxSortApellido = strncmp(passengersList[i].lastName,passengersList[i+1].lastName,NAME_AND_LAST_NAME_LEN);
						if(auxSortApellido > 0 || (auxSortApellido==0 && passengersList[i].typePassenger > passengersList[i+1].typePassenger))
						{
							flagSwap = 1;
							buffer = passengersList[i];
							passengersList[i] = passengersList[i+1];
							passengersList[i+1] = buffer;
							estado=1;
						}
					}
				limit--;
				}while(flagSwap);
			}
			else
			{
				do{
					flagSwap=0;
				for(int i=0; i<limit-1; i++)
				{
					auxSortApellido = strncmp(passengersList[i].lastName,passengersList[i+1].lastName,NAME_AND_LAST_NAME_LEN);
					if(auxSortApellido < 0 || (auxSortApellido==0 && passengersList[i].typePassenger < passengersList[i+1].typePassenger))
					{
						flagSwap = 1;
						buffer = passengersList[i];
						passengersList[i] = passengersList[i+1];
						passengersList[i+1] = buffer;
						estado=1;
				   }
				}
				limit--;
				}while(flagSwap);
			}
		}
		return estado;
	}

//Funcion promedio
//Recorro el array
//Guardo un contador y un acumulador
//Saco el promedio
int average(Passenger *passengerlist, int len)
{
	int status=-1;
	int cont=0;
	float acum=0;
	float average=0;
	int contMasPromedio=0;

	for(int i=0; i <len ;i++)
	{
		if(passengerlist[i].isEmpty==0)
		{
			cont++;
			acum = acum + passengerlist[i].price;
			status=0;
		}
	}
	average= acum/cont;
	for(int indice = 0; indice <len ;indice++)
	{
		if(passengerlist[indice].isEmpty==0 && passengerlist[indice].price > average)
		{
			contMasPromedio++;
		}
	}
	printf("\nEl promedio es: %f\n",average);
	printf("Superan el precio promedio: %d",contMasPromedio);
	return status;
}


//Funcion ordenamiento
//Llamo a la funcion seleccionar
//Ordeno segun la opcion ingresada
int sortPassengerPorCodigoYStatus(Passenger* passengersList, int limit)
{
	int estado=-1;
	int flagSwap;
	int auxSortCodigo;
	Passenger buffer;

		if(passengersList != NULL && limit>=0)
		{
			flagSwap=0;
			if(SortPassengers()==1)
			{
				do{
					flagSwap=0;
					for(int i=0; i<limit-1; i++)
					{
						auxSortCodigo = strncmp(passengersList[i].flycode,passengersList[i+1].flycode,FLY_CODE_LEN);
						if(auxSortCodigo > 0 || (auxSortCodigo==0 && passengersList[i].statusFlight > passengersList[i+1].statusFlight))
						{
							flagSwap = 1;
							buffer = passengersList[i];
							passengersList[i] = passengersList[i+1];
							passengersList[i+1] = buffer;
							estado=1;
						}
					}
				limit--;
				}while(flagSwap);
			}
			else
			{
				do{
					flagSwap=0;
					for(int i=0; i<limit-1; i++)
					{
						auxSortCodigo = strncmp(passengersList[i].flycode,passengersList[i+1].flycode,FLY_CODE_LEN);
						if(auxSortCodigo < 0 || (auxSortCodigo==0 && passengersList[i].statusFlight < passengersList[i+1].statusFlight))
						{
							flagSwap = 1;
							buffer = passengersList[i];
							passengersList[i] = passengersList[i+1];
							passengersList[i+1] = buffer;
							estado=1;
					   }
					}
				limit--;
				}while(flagSwap);
			}
		}
		return estado;
	}

