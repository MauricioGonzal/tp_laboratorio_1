#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"

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
    int banderaNoGuardo;
    int maxId;
    int retornoFread;
    int opcionGuardar;
    banderaNoGuardo=-1;
    FILE* pFile;
    FILE* pf;
    banderaPrimeraCarga=0;
    opcionSalida=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	Menu();
    	LoadIntRange("\nIngrese una opcion:", &option, 10);
        switch(option)
        {

        	case 1:

        		if(banderaPrimeraCarga==0){
        		int retornoScanf;
                	controller_loadFromText("data.csv",listaEmpleados);
        		pFile= fopen("maxId.txt", "r");
        		retornoScanf= parser_maxIdFromText(pFile, &maxId);
        		fclose(pFile);
        		if(retornoScanf!=0){
        			pf= fopen("maxId.txt", "w");
        			BuscarMayorId(listaEmpleados, &maxId);

        		fprintf(pf, "%d", maxId);
        		fclose(pf);

        		}
                banderaPrimeraCarga=1;

                }
                else{
                	printf("el archivo ya se encuentra cargado en el sistema.\n");
                }
        		banderaNoGuardo=1;
                break;
            case 2:

            	retornoFread=controller_loadFromBinary("data.bin", listaEmpleados);
            	printf("%d", retornoFread);
            	if(retornoFread==-1){
            		printf("Aun no hay informacion en este archivo");
            	}
            	banderaNoGuardo=1;
            	break;

            case 3:
            	controller_addEmployee(listaEmpleados);

            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText("data.csv", listaEmpleados);
            	controller_saveAsBinary("data.bin", listaEmpleados);
            	banderaNoGuardo=0;
            	break;
            case 9:
            	controller_saveAsBinary("data.bin", listaEmpleados);
            	controller_saveAsText("data.csv", listaEmpleados);
            	banderaNoGuardo=0;
            	break;
            case 10:
            	if(banderaNoGuardo==1){
            		printf("No ha guardado los cambios. Desea hacerlo?\n 1.SI\n2.NO ");
            		scanf("%d", &opcionGuardar);
            		banderaNoGuardo=0;
            		if(opcionGuardar==2){
            			opcionSalida= SalirDelPrograma();
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






