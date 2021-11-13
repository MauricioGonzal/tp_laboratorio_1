#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"
#define ARCHIVOSINCARGAR "El archivo no esta cargado en el sistema.\n"

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
    int opcionGuardar;
    FILE* pFile;
    FILE* pf;
    banderaPrimeraCarga=0;
    banderaNoGuardo=-1;
    opcionSalida=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

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
        		if(retornoScanf!=0)
        		{
        			pf= fopen("maxId.txt", "w");
        			BuscarMayorId(listaEmpleados, &maxId);
        			fprintf(pf, "%d", maxId);
        			fclose(pf);

        		}
                banderaPrimeraCarga=1;

                }
                else{

                	printf("El archivo ya se encuentra cargado en el sistema.\n");
                }
        		banderaNoGuardo=1;
                break;
            case 2:
            	if(controller_loadFromBinary("data.bin", listaEmpleados)==-1)
            	{
            		printf("\nError. El archivo no puede ser creado sin antes guardarse en formato binario");
            	}
            	else
            	{
            		banderaNoGuardo=1;
            	}
            	break;

            case 3:
            	if(banderaPrimeraCarga==1)
            	{
            	VerificarTresRetornos(controller_addEmployee(listaEmpleados), "El empleado se ha creado correctamente", "Error. Intente nuevamente", "Error. Intente nuevamente");
            	}
            	else
            	{
            		printf("%s", ARCHIVOSINCARGAR);
            	}
            	break;
            case 4:
            	if(banderaPrimeraCarga==1)
            	{
            		VerificarTresRetornos(controller_editEmployee(listaEmpleados), "Empleado modificado correctamente\n", "El empleado con el id ingresado no existe. Verifique los datos.\n", "Error, vuelva a intentar");
            	}
            	else
				{
					printf("%s", ARCHIVOSINCARGAR);
				}
            	break;
            case 5:
            	if(banderaPrimeraCarga==1)
				{

            		VerificarTresRetornos(controller_removeEmployee(listaEmpleados), "empleado eliminado correctamente.\n", "El empleado con el id ingresado no existe, Verifique los datos.\n", "Error, vuelva a intentarlo");

				}
				else
				{
					printf("%s", ARCHIVOSINCARGAR);
				}
            	break;
            case 6:
            	if(banderaPrimeraCarga==1)
				{
            		controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("%s", ARCHIVOSINCARGAR);
				}
            	break;
            case 7:
            	if(banderaPrimeraCarga==1)
				{
            		controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("%s", ARCHIVOSINCARGAR);
				}
            	break;
            case 8:
            	if(banderaPrimeraCarga==1)
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
            	if(banderaPrimeraCarga==1)
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
            	if(banderaNoGuardo==1)
            	{
            		printf("No ha guardado los cambios. Desea hacerlo?\n 1.SI\n2.NO ");
            		scanf("%d", &opcionGuardar);
            		banderaNoGuardo=0;
            		if(opcionGuardar==2)
            		{
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






