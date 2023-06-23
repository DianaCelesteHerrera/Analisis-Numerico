//Herrera Godina Diana Celeste
#include <stdio.h>
#include <math.h>
#define DIM 20

double x[DIM],y[DIM];

double f (double x){
    return exp (x)/(pow (x,2)-3);
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
}
//primera derivada dos puntos
double primeraDerivadaProgresiva (double x, double h) {
    return (f(x+h) - f (x))/h;
}
double primeraDerivadaCentrada (double x, double h) {
    return (f(x+h) - f (x-h))/(2*h);
}
double primeraDerivadaRegresiva (double x, double h) {
    return (f(x) - f (x-h))/(h);
}

//segunda derivada dos puntos
double segundaDerivadaProgresiva (double x, double h) {
    return (f(x)-2*f(x+h)+f(x+2*h))/(h*h);
}
double segundaDerivadaCentrada (double x, double h) {
    return (f(x-h)-2*f(x)+f(x+h))/(h*h);    //  [1 -2 1]
}
double segundaDerivadaRegresiva (double x, double h) { 
    return (f(x-2*h)-2*f(x-h)+f(x))/(h*h);
}

//Primera derivada 3 puntos
double primeraDerivada3puntos (double x, double h){
	return (-3*f(x)+4*f(x+h)-f(x+2*h))/(2*h);
}
double primeraDerivadaCentradaOrden4 (double x, double h){
	return (f(x-2*h)-8*f(x-h)+8*f(x+h)-f(x+2*h))/(12*h);
}
double primeraDerivadaRegresivaSegundoOrden (double x, double h) {
	return (f(x-2*h)-4*f(x-h)+3*f(x))/(2*h);
}

//Segunda derivada 3 puntos
double segundaDerivadaProgresivaOrden2 (double x, double h) {
	return (2*f(x)-5*f(x+h)+4*f(x+2*h)-f(x+3*h))/(h*h);
}	
double segundaDerivadaCentradaOrden4(double x, double h) {
	return (-f(x-2*h)+16*f(x-h)-30*f(x)+16*f(x+h)-f(x+2*h))/(12*h*h);
}
double segundaDerivadaRegresivaOrden2(double x, double h) {
	return (-f(x-3*h)+4*f(x-2*h)-5*f(x-h)+2*f(x))/(h*h);
}	

int main () {
    int c, op, centrada, regresiva, progresiva;
    double x,xi,xf,deltaX;
    
    do {
    	printf("\n ----{ MENU DERIVADAS }----\n");
    	printf("\n 1. Derivada Centrada");
    	printf("\n 2. Derivada Regresiva");
    	printf("\n 3. Derivada Progresiva");
    	printf("\n 4. Salir ");
    	printf("\n------------------------------");
    	printf("\n\nIgrese la opcion que desee:\t");
    	scanf( "%d", &op );
    	
    	switch ( op )
        {
			case 1:
				printf ("\nValor inicial:");
        		scanf ("%lf", &xi);
        		printf ("\nValor final: ");
        		scanf ("%lf", &xf);
        		printf ("\nValor aproximar X0: ");
        		scanf ("%lf", &x);
        		printf ("\nValor de h: ");
        		scanf ("%lf", &deltaX);
        		printf("\n---{ Tabulando }---\n");
        		tabula(xi,xf,deltaX);
        		
        		printf("\n----{ ORDEN DERIVADAS }----\n");
        		printf( "\n 1. 2 Puntos");
    			printf( "\n 2. 3 Puntos\n");
    			printf("\n------------------------------");
    			printf(" \nIngrese la opcion que desee:\t");
    			scanf( "%d", &centrada );
    			
    			switch ( centrada ) {
    				case 1:
    					printf("\n----{ RESULTADO DERIVADAS }------\n");
    					printf ("\n1a. derivada centrada: %lf\n",primeraDerivadaCentrada(x,deltaX));
    					printf ("\n2a. derivada centrada: %lf\n",segundaDerivadaCentrada(x,deltaX));
    					printf("\n--------------------------------\n");
    					break;
    					
    				case 2:
    					printf("\n----{ RESULTADO DERIVADAS }------\n");
    					printf ("\n1a. derivada centrada orden4: %lf\n",primeraDerivadaCentradaOrden4(x,deltaX));
    					printf ("\n2a. derivada centrada orden4: %lf\n",segundaDerivadaCentradaOrden4(x,deltaX));
    					printf("\n--------------------------------\n");
    					break;
    			}	
			
				break;
			
			case 2:
			    printf ("\nValor inicial:");
        		scanf ("%lf", &xi);
        		printf ("\nValor final: ");
        		scanf ("%lf", &xf);
        		printf ("\nValor aproximar X0: ");
        		scanf ("%lf", &x);
        		printf ("\nValor de h: ");
        		scanf ("%lf", &deltaX);
        		printf("\n---{ Tabulando }---\n");
        		tabula(xi,xf,deltaX);
        		
        		printf("\n----{ ORDEN DE DERIVADA }----\n");
        		printf("\n 1. 2 Puntos");
    			printf("\n 2. 3 Puntos ");
    			printf("\n------------------------------");
    			printf("\nIngrese la opcion que desee:  \t");
    			scanf( "%d", &regresiva );
				
				switch ( regresiva ) {
					
					case 1:
						printf("\n----{ RESULTADO DERIVADAS }------\n");
						printf ("\n1a. derivada regresiva: %lf\n",primeraDerivadaRegresiva(x,deltaX));
						printf ("\n2a. derivada regresiva: %lf\n",segundaDerivadaRegresiva(x,deltaX));
						printf("\n--------------------------------\n");
						break;
					
					case 2:
						printf("\n----{ RESULTADO DERIVADAS }------\n");
						printf ("\n1a. derivada regresiva orden2: %lf\n",primeraDerivadaRegresivaSegundoOrden(x,deltaX));
						printf ("\n2a. derivada regresiva orden2: %lf\n",segundaDerivadaRegresivaOrden2(x,deltaX));
						printf("\n--------------------------------\n");
						
						break;
				}	
				break;
			
			case 3:
				printf ("\nValor inicial: ");
        		scanf ("%lf", &xi);
        		printf ("\nValor final: ");
        		scanf ("%lf", &xf);
        		printf ("\nValor aproximar X0: ");
        		scanf ("%lf", &x);
        		printf ("\nValor de h: ");
        		scanf ("%lf", &deltaX);
        		printf("\n---{ Tabulando }---\n");
        		tabula(xi,xf,deltaX);
        		
				printf("\n----{ ORDEN DERIVADAS }----\n");
        		printf("\n 1. 2 Puntos");
    			printf("\n 2. 3 Puntos");
    			printf("\n------------------------------");
    			printf("\nIngrese la opcion que desee:  \t");
    			scanf("%d", &progresiva);
    				
				switch ( progresiva ) {
					
					case 1:
						printf("\n----{ RESULTADO DERIVADAS }------\n");
						printf ("\n1a. derivada Progresiva 2 puntos: %lf\n",primeraDerivadaProgresiva(x,deltaX));
						printf ("\n2a. derivada Progresiva 2 puntos: %lf\n",segundaDerivadaProgresiva(x,deltaX));
						printf("\n--------------------------------\n");
						break;
					
					case 2:
						printf("\n----{ RESULTADO DERIVADAS }------\n");
						printf ("\n1a. derivada Progresiva 3 Puntos: %lf\n",primeraDerivada3puntos(x,deltaX));
						printf ("\n2a. derivada Progresiva 3 Puntos: %lf\n",segundaDerivadaProgresivaOrden2(x,deltaX));
						printf("\n--------------------------------\n");
						break;
        	    }
        	
				break;
    	}	
    	fflush (stdin);// Limpia el buffer del teclado
    	
    } while (op != 4);
}



