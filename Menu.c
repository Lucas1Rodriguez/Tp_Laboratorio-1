/*
 * Menu.c
 *
 *  Created on: 14 may. 2022
 *      Author: USURIO
 */

#include "ArrayPassenger.h"
#include "utn_biblioteca.h"

void menuPassenger (Passenger passengerList[], int len)
	{
		int option;
		int lugarLibre;
		int flag;
		do{

			if (utn_getNumeroInt(&option, "\nBienvenido \n1)Altas:\n2)Modificar:\n3)Baja:\n4)Informar:\n5)Salir\n", "\nError opcion Invalida",  1, 5, 5)==0)
				switch (option)
					{
						case 1:
							//Busco lugar libre
							lugarLibre = findEmptyPosition(passengerList, len);
							//Pido y cargo los datos ingresados
							addPassenger(&passengerList[lugarLibre], len, passengerList[lugarLibre].id, passengerList[lugarLibre].name,passengerList[lugarLibre].lastName,passengerList[lugarLibre].price,passengerList[lugarLibre].typePassenger, passengerList[lugarLibre].flycode, passengerList[lugarLibre].statusFlight);
							flag=1;
							break;
						case 2:
							//Verifico que se haya cumplido la opcion 1
							if(flag==1)
							{
								//Recorro el array para imprimir los datos cargados
								for(int i=0;i< len ;i++)
								{
									printPassenger(&passengerList[i]);
								}

								int idIngresado;
								int indexAModif;
								//Pido que ingrese un numero a buscar
								//Verifico que exista
								//Llamo a la funcion modificar e imprimo
								if (utn_getNumeroInt(&idIngresado, "Ingrese ID\n", "Error", 1, 9999, 5)==0)
								{
									indexAModif = findPassengerById(passengerList,len,idIngresado);
									if(indexAModif >=0)
									{
										modifyPassenger(&passengerList[indexAModif]);
										printPassenger(&passengerList[indexAModif]);
										flag=1;
									}
								}
							}
							else{
								printf("Error, no hay pasajeros cargados\n");
							}

							break;
						case 3:
							//Verifico que la opcion 1 se haya ingresado
							if(flag==1)
							{
								//Recorro el array para imprimir los datos cargados
								for(int i=0;i< len ;i++)
								{
									printPassenger(&passengerList[i]);
								}
									int idingresado;
									int idDarBaja;
									//Pido que ingrese un numero a buscar
									//Verifico que exista
									//Llamo a la funcion eliminar e imprimo
									if(utn_getNumeroInt(&idingresado, "\nIngrese ID a eliminar\n", "Error", 1, 9999, 5)==0)
									{
										idDarBaja = findPassengerById(passengerList,len,idingresado);
										if(idDarBaja>=0)
										{
											if(removePassenger(passengerList,len,idingresado)==1)
											{
												printf("Pasajero eliminado\n");
												flag=1;
											}
											else
											{
												printf("No se pudo eliminar al pasajero");
											}
										}
									}
							}
							else
							{
								printf("Error, no hay pasajeros cargados\n");
							}

							break;
						case 4:
							//Verifico que la opcion 1 se haya ingresado
							if(flag==1)
							{
								int Option;
								if (utn_getNumeroInt(&Option, "Elegi una opcion: \n 1) Ordenamiento por apellido y tipo de pasajero \n 2) Promedio de precios y cantidad de pasajeros que lo superan \n 3) Ordenamiento por codigo y estado de vuelo \n", "Error", 1, 3, 5)==0)
								{
									switch(Option)
									{
									case 1:
										//Llamo a la funcion ordenar
										//Verifico que la funcion ordenar devuelva 1
										//Imprimo
										if(sortPassengerPorApellidoYTipo(passengerList, len)==1)
										{
											for(int index=0;index< len ;index++)
											{
												printPassenger(&passengerList[index]);
												flag=1;
											}
										}
										break;
									case 2:
										//Llamo a la funcion promedio
										average(passengerList,len);
										break;
									case 3:
										//Llamo funcion ordenar
										//Verifico que la funcion ordenar devuelva 1
										//Imprimo
										if(sortPassengerPorCodigoYStatus(passengerList, len)==1)
										{
											for(int index=0;index< len ;index++)
											{
												printPassenger(&passengerList[index]);
												flag=1;
											}
										}
										break;
									}
								}
							}
							else
							{
								printf("Error, no hay pasajeros cargados\n");
							}
							break;
						case 5:
							printf("Saliendo...");
							break;
					}
		}while (option <5);
	}

