#include "Input.h"


float IngresarFlotante(char mensaje[])
{
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}
int IngresarEntero(char mensaje[])
{
	int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}

int enteroValidado ( char msj[], char msjError[], int min , int max){

    int valor;
    printf("%s", msj);
    valor=IngresarEntero(" ");
    while(valor < min || valor > max ){
        printf("%s", msjError);
        valor=IngresarEntero("\nIngrese nuevamente: ");
    }
    return valor;
}

float flotanteValidado ( char msj[], char msjError[], float min , float max){

    float valor;
    printf("%s", msj);
    valor=IngresarFlotante(" ");
    while(valor < min || valor > max ){
        printf("%s", msjError);
        valor=IngresarFlotante("\nIngrese nuevamente: ");
    }
    return valor;
}

char IngreseCaracter(char mensaje[])
{
	char caracterIngresado;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &caracterIngresado);

	return caracterIngresado;
}

int getString(char cadena[], char mensaje[], int tam)
{
	char auxiliarString[1000];
	int retorno;
	retorno = -1;
	if (cadena != NULL && mensaje != NULL)
	{
		retorno = 0;
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxiliarString);

		while (strlen(auxiliarString) > tam || isValidName(auxiliarString)!=-1 )
		{
			printf("Reingrese, solo letras: ");
			fflush(stdin);
			scanf("%[^\n]", auxiliarString);
		}
		strcpy(cadena, auxiliarString);
	}
	return retorno;
}

int isValidName(char* stringRecibido)   //si fuera un numero podr�a necesitar parametros para validar max y min
{
    int retorno=-1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'A' && stringRecibido[i]!=' ' ) ||
           (stringRecibido[i]>'Z' && stringRecibido[i]<'a') ||
           stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int esAlfaNumerico(char* stringRecibido)   //si fuera un numero podr�a necesitar parametros para validar max y min
{
    int retorno=-1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
    	if( (stringRecibido[i]<'0' && stringRecibido[i]!=' ')  || (stringRecibido[i]>'9' && stringRecibido[i]<'A' ) || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int getStringAlfaNumerico(char cadena[], char mensaje[], int tam)
{
	char auxiliarString[1000];
	int retorno;
	retorno = -1;
	if (cadena != NULL && mensaje != NULL)
	{
		retorno = 0;
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxiliarString);

		while (strlen(auxiliarString) > tam || esAlfaNumerico(auxiliarString)!=-1 )
		{
			printf("Reingrese, puede letras y/o numeros: ");
			fflush(stdin);
			scanf("%[^\n]", auxiliarString);
		}
		strcpy(cadena, auxiliarString);
	}
	return retorno;
}



