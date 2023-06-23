//Herrera Godina Diana Celeste
#include <stdio.h>
#include <math.h>
#define DIM 100
double y[DIM],x[DIM];

double f (double x) {
}

void tabula (double xi,double xf,double deltaX) {
    int i=0;

    while (xi <= xf) {
        x[i] = xi;
        y[i] = f (xi);
        printf ("%.4lf\t%.4lf\n",x[i],y[i]);
        xi += deltaX;
        i++;
    }
	printf ("\n");
}

double Trapecio (double a, double b, int n) {
	int i;
	double h,integral,suma;

	h= (b-a)/n;
	tabula(a,b,h);
	suma = 0;
	for (i = 1; i < n-1; i++)
		suma= suma + f (a+h*i);
	integral = h/2.0 * (f (a) + 2*suma + f (b));
	return integral;
}
double S13 (double a, double b, int n) {
	int i;
	double h,integral,sumaP,sumaI;

	h= (b-a)/n;
	tabula(a,b,h);
	sumaP = 0;
	for (i = 2; i <= n-1; i=i+2)
		sumaP= sumaP + f (a+h*i);
	sumaI = 0;
	for (i = 1; i <= n-1; i=i+2)
		sumaI= sumaI + f (a+h*i);
    printf ("h= %lf, sumaP= %lf, sumaI= %lf\n",h,sumaP,sumaI);
	integral = h/3.0 * (f(a) + 2*sumaP + 4*sumaI+ f(b));
	return integral;
}
double S38 (double a, double b, int n) {
	int i;
	double h,integral,sumaM3,sumaNoM3;

	h= (b-a)/n;
	tabula(a,b,h);
	sumaM3 = 0;
	for (i = 3; i <= n-1; i=i+3)
		sumaM3= sumaM3 + f (a+h*i);
	sumaNoM3 = 0;
	for (i = 1; i <= n-1; i++)
		if (i % 3)
			sumaNoM3= sumaNoM3 + f (a+h*i);
    printf ("h= %lf, sumaM3= %lf, sumaNoM3= %lf\n",h,sumaM3,sumaNoM3);
	integral = 3*h/8.0 * (f(a) + 3*sumaNoM3 + 2*sumaM3+ f(b));
	return integral;
}

main () {
	int d,i,c,n;
	double x,xi,xf,deltaX,a,b;

	do {
		fflush (stdin);
		printf("\n---{ Programa Integracion }----\n");
		printf ("\nLimite inferior: ");
		scanf ("%lf",&a);
		printf ("\nLimite superior: ");
		scanf ("%lf",&b);
		printf ("\nNumero de particiones: ");
		scanf ("%d",&n);
		for(i=0;i<n;i++){
			printf("\n----{ Valores de Y }-----\n");
	    	printf("\nIngrese el valor valor de y:\t");
		    scanf("%d",&y[i]);
		}
		if (n % 3 == 0)			// Multiplo de 3
			printf ("\nLa integral aprox. 3/8= %lf\n", S38 (a,b,n));
		else if (n % 2 == 0)	// Multiplo de 2
			printf ("\nLa integral aprox. 1/3= %lf\n", S13 (a,b,n));
		else
			printf ("\nLa integral aprox. Trapecio= %lf\n", Trapecio (a,b,n));
		printf ("Repetir s/n: ");
		fflush (stdin);// Limpia el buffer del teclado
		c= getchar ();
	} while (c == 's');

}









