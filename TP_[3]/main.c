#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"
#define ARCHIVOSINCARGAR "No se ha cargado ningun dato en el sistema.\n"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{	setbuf(stdout, NULL);

    int option;
    int opcionSalida;
    int banderaPrimeraCarga;
    int banderaSistemaVacio;
    int banderaNoGuardo;
    int maxId;
    int banderaCambio;
    int banderaCreoEmpleadoSinCargar;
    int opcionGuardar;
    int retorno;
    int retornoScanf;
    int primerMaxId;
    FILE* pFile;
    FILE* pf;
    banderaPrimeraCarga=0;
    banderaSistemaVacio=0;
    banderaNoGuardo=-1;
    opcionSalida=0;
    banderaCambio=0;


    LinkedList* listaEmpleados = ll_newLinkedList();

    pFile= fopen("maxId.txt", "r");
    if(parser_maxIdFromText(pFile, &primerMaxId)!=1){
    	primerMaxId=1000;
    }

    fclose(pFile);


    do{
    	Menu();
    	LoadIntRange("\nIngrese una opcion:", &option, 10);
        switch(option)
        {
        	case 1:

        		if(banderaPrimeraCarga==0)
        		{
        		int retornoScanf;
                controller_loadFromText("data.csv",listaEmpleados);
        		pFile= fopen("maxId.txt", "r");
        		retornoScanf= parser_maxIdFromText(pFile, &maxId);
        		fclose(pFile);
        		if(retornoScanf==1)
        		{
        			pf= fopen("maxId.txt", "w");
        			//BuscarMayorId(listaEmpleados, &maxId);
        			fprintf(pf, "%d", maxId);
        			fclose(pf);

        		}
                banderaPrimeraCarga=1;
                banderaSistemaVacio=1;

                }
                else{

                	printf("El archivo ya se encuentra cargado en el sistema.\n");
                }

                break;
            case 2:
            	if(controller_loadFromBinary("data.bin", listaEmpleados)==-1)
            	{
            		printf("\nError. El archivo no puede ser creado sin antes guardarse en formato binario");
            	}
            	else
            	{
            		banderaPrimeraCarga=1;
            		banderaSistemaVacio=1;
            	}
            	break;

            case 3:

            	if(banderaPrimeraCarga==0){

            		pFile= fopen("maxId.txt", "r");
            		        		retornoScanf= parser_maxIdFromText(pFile, &maxId);
            		        		fclose(pFile);
            		        		if(retornoScanf==1)
            		        		{
            		        			pf= fopen("maxId.txt", "w");

            		        			fprintf(pf, "%d", maxId);
            		        			fclose(pf);

            		        		}
            		banderaCreoEmpleadoSinCargar=1;
            		banderaSistemaVacio=1;
            	}
            	VerificarTresRetornos(controller_addEmployee(listaEmpleados), "El empleado se ha creado correctamente", "\nIntente nuevamente", "Error. Intente nuevamente");
            	banderaCambio=1;




            	break;
            case 4:
            	if(banderaPrimeraCarga==1 || banderaCreoEmpleadoSinCargar==1)
            	{
            		retorno= controller_editEmployee(listaEmpleados);
            		VerificarTresRetornos(retorno, "Empleado modificado correctamente\n", "El empleado con el id ingresado no existe. Verifique los datos.\n", "Error, vuelva a intentar");
            		if(retorno==0){
            			banderaCambio=1;
            		}
            	}
            	else
				{
					printf("%s", ARCHIVOSINCARGAR);
				}
            	break;
            case 5:
            	if(banderaPrimeraCarga==1 || banderaCreoEmpleadoSinCargar==1)
				{
            		retorno= controller_removeEmployee(listaEmpleados);
            		VerificarTresRetornos(retorno, "empleado eliminado correctamente.\n", "El empleado con el id ingresado no existe, Verifique los datos.\n", "Error, vuelva a intentarlo");
            		if(retorno==0){
            			banderaCambio=1;
            		}
				}
				else
				{
					printf("%s", ARCHIVOSINCARGAR);
				}
            	break;
            case 6:

        		if(banderaCreoEmpleadoSinCargar==1 && banderaPrimeraCarga==1){
        		ll_sort(listaEmpleados, employee_compareById, 1);
        		controller_ListEmployee(listaEmpleados);
        		}else{





        		if(banderaSistemaVacio==1){
        			controller_ListEmployee(listaEmpleados);
        		}


				else
				{
					if(banderaSistemaVacio==0)
					{
					printf("%s", ARCHIVOSINCARGAR);
					}
				}
        		}
            	break;
            case 7:
            	if(banderaPrimeraCarga==1 || banderaCreoEmpleadoSinCargar==1)
				{
            		banderaCreoEmpleadoSinCargar=0;
            		controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("%s", ARCHIVOSINCARGAR);
				}
            	break;
            case 8:
            	if(banderaPrimeraCarga==1 || banderaCreoEmpleadoSinCargar==1)
				{
            		controller_saveAsText("data.csv", listaEmpleados);
					controller_saveAsBinary("data.bin", listaEmpleados);
					banderaNoGuardo=0;
				}
				else
				{
					printf("%s", ARCHIVOSINCARGAR);
				}

            	break;
            case 9:
            	if(banderaPrimeraCarga==1 || banderaCreoEmpleadoSinCargar==1)
				{
            		controller_saveAsText("data.csv", listaEmpleados);
					controller_saveAsBinary("data.bin", listaEmpleados);
					banderaNoGuardo=0;
				}
				else
				{
					printf("%s", ARCHIVOSINCARGAR);
				}

            	break;
            case 10:

            	if(banderaNoGuardo==-1 && banderaCambio==1)
            	{
            		printf("No ha guardado los cambios. Desea hacerlo?\n 1.SI\n2.NO ");
            		scanf("%d", &opcionGuardar);
            		banderaNoGuardo=0;
            		if(opcionGuardar==2)
            		{
            			opcionSalida= SalirDelPrograma();
            			if(opcionSalida==1){
            				pFile= fopen("maxId.txt", "w");
            				fprintf(pFile, "%d", primerMaxId);
            				fclose(pFile);
            			}
            		}
            		else{
            			printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)");
            			scanf("%d", &option);
            			if(option==1){
            				controller_saveAsText("data.csv", listaEmpleados);
            				controller_saveAsBinary("data.bin", listaEmpleados);
            			}
            			else{
            				controller_saveAsBinary("data.bin", listaEmpleados);
            				controller_saveAsText("data.csv", listaEmpleados);
            			}
            		}
            	}
            	else{
            	opcionSalida= SalirDelPrograma();
            	}
            	break;



        }
    }while(opcionSalida != 1);

    printf("El programa ha sido cerrado");
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}






