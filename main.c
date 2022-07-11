#include <stdio.h>
#include <stdlib.h>

int validar(int ,int );
int noEntrega(int [],int );
void ordenar(float [],int [],int );

int main()
{
    int j,i,mes,dia,productor,maxproductor,x,vdia[31]={0},mindia,minproductor,sinEntregas;
    float totalkilos=0,kilos,vkilos[31]={0},vproductor[25]={0},maxkilos,minkilos,minkilos2,vproductor2[25]={0},vproductor3[25]={0},vkilos2[31]={0};

    printf("Ingrese el mes de entrega: ");
    mes=validar(0,12);
    while(mes!=0)
    {
        printf("Ingrese el numero de productor: ");
        productor=validar(1,25);
        printf("Ingrese el dia de entrega: ");
        dia=validar(1,31);
        printf("Ingrese la cantidad de kilos: ");
        do{
            scanf("%f",&kilos);
        }while(kilos<0);
        printf("\n");

        vproductor[productor-1]+=kilos;

        totalkilos+=kilos;

        vdia[dia-1]=dia;
        vkilos[dia-1]+=kilos;

        vproductor2[productor-1]+=kilos;
        vproductor3[productor-1]+=kilos;

        vkilos2[dia-1]+=kilos;

        printf("Ingrese el mes de entrega: ");
        mes=validar(0,12);
    }
    maxkilos=vproductor[0];
    for(x=0;x<25;x++)
    {
        if(vproductor[x]>maxkilos)
        {
            maxkilos=vproductor[x];
            maxproductor=x+1;
        }
    }
    printf("El numero de productor que mas kilos entrego es: %d\n",maxproductor);//punto 1

    printf("Total de kilos almacenados en este periodo: %.2f\n",totalkilos);//punto 2

    ordenar(vkilos,vdia,31);
    printf("Dia             Cantidad de kilos\n");
    for(x=0;x<31;x++)
    {
        if(vkilos[x]!=0)
        {
            printf("%d              %.2f\n",vdia[x],vkilos[x]);//punto 3
        }
    }

    minkilos=vproductor2[0];
    for(i=0;i<25;i++)
    {
        if(minkilos!=0)
        {
            if(vproductor2[i]<minkilos)
            {
                minkilos=vproductor2[i];
                minproductor=i+1;
            }
            else
                minkilos=vproductor2[i];
        }
    }
    minkilos2=vproductor3[0];
    for(j=0;j<31;j++)
    {
        if(minkilos2!=0)
        {
            if(vproductor3[j]<minkilos2)
            {
                minkilos2=vproductor3[j];
                mindia=j+1;
            }
            else
                minkilos2=vproductor3[j];
        }
    }
    printf("La menor entrega fue de %.2f, para el dia %d, y productor %d\n",minkilos2,mindia,minproductor);//punto 4 sin terminar

    sinEntregas=noEntrega(vkilos2,31);
    printf("La cantidad de dias sin entregas es de: %d\n",sinEntregas);//punto 5

    return 0;
}
int validar(int min,int max)
{
    int dato;

    do{
        scanf("%d",&dato);
    }while(dato<min||dato>max);

    return dato;
}
void ordenar(float v[],int c[],int cant)
{
    int sen=0,x,aux,aux2;

    while(sen==0)
    {
        sen=1;
        for(x=0;x<cant-1;x++)
        {
            if(v[x]<v[x+1])
            {
                aux=v[x];
                v[x]=v[x+1];
                v[x+1]=aux;

                aux2=c[x];
                c[x]=c[x+1];
                c[x+1]=aux2;

                sen=0;
            }
        }
        cant=cant-1;
    }
};
int noEntrega(int v[],int can)
{
    int sinEntregas,x;

    for(x=0;x<can;x++)
    {
        if(v[x]==0)
            sinEntregas++;
    }

    return sinEntregas;
};
