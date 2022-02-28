#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;
// Declaraciones adelantadas de las funciones
int analiza_menu_1();
int analiza_2_opciones();
int analiza_4_opciones();
void menu_ver_resultados();
void mostrar_funcion_exp(float z_0, int opcion_m_3);
void mostrar_funcion_trigo(float z_0, int opcion_m_3, float opcion_m_4);
void mostrar_funcion_ln(float z_0, int opcion_m_3);
void mostrar_funcion_geo(float z_0, int opcion_m_3);
void mostrar_funcion_binominal(float z_0, float grado, int opcion_m_3);
float funcion_sumatoria_exp(float n_terminos, float x);
float funcion_sumatoria_seno(float x, float n_terminos);
float funcion_sumatoria_coseno(float x, float n_terminos);
float funcion_sumatoria_ln(float n_terminos, float x);
float funcion_sumatoria_geometrica(float n_terminos, float x);
float funcion_sumatoria_binominal(float x, float grado, int n_terminos);
float funcion_criterio_error(float termino_0, float termino_1);
float funcion_factorial(float n);
float funcion_productorio(float n, float grado);
bool funcion_analisis_dominio(float dom, int op_m_1);

int main() {
	int opcion_m_1,opcion_m_2,opcion_m_3,opcion_m_4,n;// opciones menus, opcion_m_4 entre seno y coseno
	float z_0,error,dominio,grados,potencia,pi;
	bool dom_logico;
// Presentando el menu de inicio, repetira hasta que se digite el valor de 6.
	do {
		cout << "\n   * Series de Taylor y Maclaurin *" << endl;
		cout << "            Menu" << endl;
		cout << "   1. Funcion exponencial." << endl;
		cout << "   2. Funciones trigonometricas." << endl;
		cout << "   3. Funcione logaritmica." << endl;
		cout << "   4. Funcione geometrica." << endl;
		cout << "   5. Funcione binomica." << endl;
		cout << "   6. Salir." << endl;
		cout << "\n   Digite su opcion. -> ";
	// Funcion Anliza_menu_1 evitara que se digiten letras o valores no aceptados
		opcion_m_1 = analiza_menu_1();	// valores devueltos  1,2,3,4,5,6,0
	// Si se ditigan los valores de la condicion se evitara este menu
		if (opcion_m_1!=6 && opcion_m_1!=0) {
			cout << "\n Presione cualquier tecla para continuar." << endl;
			getch();
			system("cls");
		// diferente de 3 debido a que la serie Ln no puede tener valores z_0=0
			if (opcion_m_1!=3) {
				do {
					// Sub menu
					cout << "\n          * Menu *" << endl;
					cout << "   1. Series de Taylor." << endl;
					cout << "   2. Series de Maclaurin." << endl;
					cout << "\n   Digite su opcion. -> ";
					// Funcion Anliza_2_opciones evitara que se digiten letras o valores no aceptados
					// valores devueltos  1 , 2 , 0 
					opcion_m_2 = analiza_2_opciones();
				} while ((opcion_m_2!=1 && opcion_m_2!=2));
			}
		}
// Fin de la presentacion del menu principal y sub menu
	// Inicia la muestra de los resultados
		// NOTAS:   
		// 1. Funciones de tipo menu y analizadores de las opciones del menu.
			// * Funcion -> Menu_ver_resultados : 
			// Despliega 4 opciones para la presentacion final :
			// 1ra opcion, mostrara el valor final de la dumatoria
			// 2da opcion, mostrara los n terminos ;n es entregado por el criterio para finalizar una tarea repetitiva do{}while()
			// 3ra opcion, mostrara dicho criterio que sera aclarado en la nota (3-iii).
			// 4ta opcion, sale del menu mostrar reslutados y retorna al menu principal de selecion de series
			// * Funcion -> Anliza_(n)_opciones : 
			// Evitara que se digiten letras o valores no aceptados, ademas que retorna un valor
			// nomerico que sera de gran utilidad en los pasos siguientes del algoritmo.
		// 2. Funciones de tipo matematicas.
			// * Funcion -> Mostrar_Funcion_(...) :
			// i. Presentara la serie que el usuario eligio previamente.
			// ii. Dentro de (...) se varia el nombre final, dependiendo que serie se desea realizar.
			// ej:     Mostrar_Funcion_exp() sirve para realizar la serie exponencial
			// iii. Esta funcion depende de otras a las que llamaremos Funciones primordiales
			// ej:     Mostrar_Funcion_exp() depende de la funcion primordial -> Funcion_sumatoria_exp().
		// 3. Funciones primordiales.
			// * Funcion_sumatoria_(...):
			// i. Dentro de (...) sa cambiara, dependiendo que serie se desea realizar.
			// ej:     Funcion_sumatoria_exp() sirve para realizar la serie exponencial
			// ii. Estas funciones dependeran de 2 muy importantes.
			// a) Funcion_factorial(n) -> Esta funcion realiza la tarea matematica de un factorial tipo n! (utilizada en la mayoria de series).
			// b) Funcion_productorio(n,grado) -> Esta funcion realiza la tarea matematica de un productorio (solo se usara para la serie binominal).
			// iii. Funcion_criterio_error -> Funcion que evalua si el ciclo [ do{ }while( ) para realizar la serie ] deba continuar o no.
			// Es utilizada en todas las series lo que hace dependera de la serie seleccionada.
			// a) Restara el valor de la sumatoria S_n con S_(n-1) y si el valor resulta 0 el ciclo termina.
			// b) Para el termino n-simo si este resulta 0 el ciclo acaba.
		// 4. Funcion_analisis_dominio.
			// Hay series que convergran para todos los valores reales de x, sin embargo para las que no se aplicara dicha funcion 
			// que retorna un valor logico verdadero o falso para el momento de ingrasar el punto de convergencia, sera verdadero 
			// si el z_0  se encuentra en el dominio de la serie y si no retorna el valor logico de falso.
		switch (opcion_m_1) {
		case 0:
			break;
		case 1:
			// EXPONENCIAL***
			cout << endl;
			if (opcion_m_2==1) {
				cout << "   Ingrese el valor del punto de convergencia -> ";
				cin >> z_0;
			} else {
				cout << "   Punto de convergencia : " << endl;
				cout << "                           z_0 = 0" << endl;
				z_0 = 0;
			}
			do {
				menu_ver_resultados();
				// * Si el valor retornado de Anliza_4_opciones es 4 , el programa rergesa al menu principal
				opcion_m_3 = analiza_4_opciones();
				cout << "\n Presione cualquier tecla para continuar." << endl;
				getch();
				system("cls");
				if (opcion_m_3!=4) {
					cout << "\n   * FUNCION EXPONENCIAL *" << endl;
					if (opcion_m_2==1) {
						cout << "    Series de Taylor :" << endl;
					} else {
						cout << "    Series de Maclaurin :" << endl;
					}
					cout << "\n             S = x^n/(n!)" << endl;
					cout << "\n             z_0 = " << z_0 << endl;
					cout << endl;
					mostrar_funcion_exp(z_0,opcion_m_3);
				}
			} while ((opcion_m_3!=4));
			break;
		case 2:
			// TRIGONOMETRICA***
			do {
				cout << "\n          * Menu *" << endl;
				cout << "   1. Serie del Seno." << endl;
				cout << "   2. Serie del Coseno." << endl;
				cout << "\n   Digite su opcion. -> ";
				opcion_m_4 = analiza_2_opciones();
			} while (opcion_m_4!=1 && opcion_m_4!=2);
			cout << endl;
			if (opcion_m_2==1) {
				cout << "   Ingrese el valor del punto de convergencia ( en grados ) -> ";
				cin >> grados;
			} else {
				cout << "   Punto de convergencia : " << endl;
				cout << "                           z_0 = 0" << endl;
				grados = 0;
			}
			z_0 = grados*(M_PI/180);
			do {
				menu_ver_resultados();
				opcion_m_3 = analiza_4_opciones();
				cout << "\n Presione cualquier tecla para continuar." << endl;
				getch();
				system("cls");
				if (opcion_m_3!=4) {
					cout << "\n   * FUNCIONES TRIGONOMETRICAS *" << endl;
					if (opcion_m_2==1) {
						cout << "    Series de Taylor :" << endl;
					} else {
						cout << "    Series de Maclaurin :" << endl;
					}
					if (opcion_m_4==1) {
						cout << "    *   Sen (X) = S_1 ." << endl;
						cout << "\n             S_1 = [ (-1)^n / (2*n+1)! ] * x^(2*n+1)" << endl;
					} else {
						cout << "\n    *   Cos (X) = S_2 ." << endl;						
						cout << "             S_2 = [ (-1)^n / (2*n)! ] * x^(2*n)" << endl;
					}					
					cout << "\n             z_0 = " << grados << " º , z_0 = " << z_0 << " [rad]" << endl;
					cout << endl;
					mostrar_funcion_trigo(z_0,opcion_m_3,opcion_m_4);
				}
			} while (opcion_m_3!=4);
			break;
		case 3:
			// LOGARITMO NATURAL***
			cout << endl;
			dom_logico = false;
			do {
				cout << "   Ingrese el valor del punto de convergencia -> ";
				cin >> dominio;
				dom_logico = funcion_analisis_dominio(dominio,opcion_m_1);
			} while (dom_logico==false);
			z_0 = dominio;
			do {
				menu_ver_resultados();
				opcion_m_3 = analiza_4_opciones();
				cout << "\n Presione cualquier tecla para continuar." << endl;
				getch();
				system("cls");
				if (opcion_m_3!=4) {
					cout << "\n   * FUNCION LOGARITMICA *" << endl;
					cout << "    Series de Taylor :" << endl;
					cout << "\n            S = [ 1/(2*n+1) ]*[ (x-1)/(x+1) ]^(2*n+1)" << endl;					
					cout << "\n             z_0 = " << z_0 << endl;
					cout << endl;
					mostrar_funcion_ln(z_0,opcion_m_3);
				}
			} while ((opcion_m_3!=4));
			break;
		case 4:
			// GEOMETRICA *********************************************
			cout << endl;
			if (opcion_m_2==1) {
				dom_logico = false;
				do {
					cout << "   Ingrese el valor del punto de convergencia -> ";
					cin >> dominio;
					dom_logico = funcion_analisis_dominio(dominio,opcion_m_1);
				} while ((dom_logico==false));
				z_0 = dominio;
			} else {
				cout << "   Punto de convergencia : " << endl;
				cout << "                           z_0 = 0" << endl;
				z_0 = 0;
			}
			do {
				menu_ver_resultados();
				opcion_m_3 = analiza_4_opciones();
				cout << "\n Presione cualquier tecla para continuar." << endl;
				getch();
				system("cls");
				if (opcion_m_3!=4) {
					cout << "   * SERIE GEOMETRICA *" << endl;
					if (opcion_m_2==1) {
						cout << "    Series de Taylor :" << endl;
					} else {
						cout << "    Series de Maclaurin :" << endl;
					}
					cout << "\n             S = 1/(1-x) " << endl;
					cout << "\n             z_0 = " << z_0 << endl;
					cout << endl;
					mostrar_funcion_geo(z_0,opcion_m_3);
				}
			} while (opcion_m_3!=4);
			break;
		case 5:
			// BINOMINAL *********************************************
			cout << endl;
			if (opcion_m_2==1) {
				dom_logico = false;
				do {
					cout << "   Ingrese el valor del punto de convergencia -> ";
					cin >> dominio;
					dom_logico = funcion_analisis_dominio(dominio,opcion_m_1);
				} while (dom_logico==false);
				z_0 = dominio;
			} else {
				cout << "   Punto de convergencia : " << endl;
				cout << "                           z_0 = 0" << endl;
				z_0 = 0;
			}
			cout << "   Ingrese el valor de la potencia -> ";
			cin >> potencia;
			do {
				menu_ver_resultados();
				opcion_m_3 = analiza_4_opciones();
				cout << "\n Presione cualquier tecla para continuar." << endl;
				getch();
				system("cls");
				if (opcion_m_3!=4) {
					cout << "\n  * SERIE BINOMINAL *" << endl;
					if (opcion_m_2==1) {
						cout << "    Series de Taylor :" << endl;
					} else {
						cout << "    Series de Maclaurin :" << endl;
					}
					cout << "\n             S = [ TT (a-k+1)/k ]*[ x^n ] " << endl;
					cout << "\n             a = " << potencia << endl;
					cout << "             z_0 = " << z_0 << endl;
					cout << "\n     Donde TT es el productorio (desde k=1 hasta n_terminos)" << endl;
					mostrar_funcion_binominal(z_0,potencia,opcion_m_3);
				}
			} while (opcion_m_3!=4);
			break;
		}
	} while (opcion_m_1!=6);
	return 0;
}
// ____________________________________________________________________________
// * * * 1. Funciones de tipo menu y analizadores de las opciones del menu. * * *
// ____________________________________________________________________________

int analiza_menu_1() {
	int opcion_1_n = 10;
	char op_1_char[10];
	cin >> op_1_char[0];
	switch (op_1_char[0]) {
	case '1':	opcion_1_n = 1;
		break;
	case '2':	opcion_1_n = 2;
		break;
	case '3':	opcion_1_n = 3;
		break;
	case '4':	opcion_1_n = 4;
		break;
	case '5':	opcion_1_n = 5;
		break;
	case '6':	opcion_1_n = 6;
		cout << "\n   * Saliendo del programa *" << endl;
		break;
	default:	opcion_1_n = 0;
		cout << "   Opcion invalida / Intentelo nuevamente." << endl;
	}
	cout << "\n Presione cualquier tecla para continuar." << endl;
	getch();
	system("cls");
	if (opcion_1_n!=0) {
		cout << endl;
		switch (opcion_1_n) {
		case 1:
			cout << "   * FUNCION EXPONENCIAL *" << endl;
			cout << "   Sea la serie de e^x = S ." << endl;
			cout << "\n             S = x^n/(n!)" << endl;
			cout << "   Donde :" << endl;
			cout << "\n           S es la sumatoria ( Desde 0 hasta n-terminos )" << endl;
			cout << "           x converge para todos los numeros reales" << endl;
			break;
		case 2:
			cout << "   * FUNCIONES TRIGONOMETRICAS *" << endl;
			cout << "   Sean las series de :" << endl;
			cout << "    *   Sen (X) = S_1 ." << endl;
			cout << "\n             S_1 = [ (-1)^n / (2*n+1)! ] * x^(2*n+1)" << endl;
			cout << "\n    *   Cos (X) = S_2 ." << endl;
			cout << "\n             S_2 = [ (-1)^n / (2*n)! ] * x^(2*n)" << endl;
			cout << "   Donde :" << endl;
			cout << "           S es la sumatoria ( Desde 0 hasta n_terminos )" << endl;
			cout << "           x es converge para todos los numeros reales" << endl;
			break;
		case 3:
			cout << "   * FUNCION LOGARITMICA *" << endl;
			cout << "   Sea la serie de Ln (x) = S ." << endl;
			cout << "\n             S = [ 1/(2*n+1) ] * [ (x-1)/(x+1) ]^(2*n+1)" << endl;
			cout << "   Donde :" << endl;
			cout << "           S es la sumatoria ( Desde 0 hasta n-terminos )" << endl;
			cout << "           x converge para valores de  ( -1 < x < 1 )" << endl;
			break;
		case 4:
			cout << "   * SERIE GEOMETRICA *" << endl;
			cout << "   Sea la serie de [ 1/(1-x)^a ] = S ." << endl;
			cout << "\n             S = x^n" << endl;
			cout << "   Donde :" << endl;
			cout << "           S es la sumatoria ( Desde 0 hasta n-terminos )" << endl;
			cout << "           x converge para valores de  ( -1 < x < 1 )" << endl;
			break;
		case 5:
			cout << "   * SERIE BINOMIAL *" << endl;
			cout << "   Sea la serie de ( 1 + x )^a = S ." << endl;
			cout << "\n             S = [ TT ( a-k+1 )/ k ] * [ x^n ]" << endl;
			cout << "   Donde :" << endl;
			cout << "           S es la sumatoria ( Desde 0 hasta n-terminos )" << endl;
			cout << "           TT es la productoria ( Desde k=1 hasta k=n-terminos )" << endl;
			cout << "           x converge para valores de  ( -1 < x < 1 )" << endl;
			cout << "           a converge para todos los numeros reales" << endl;
			break;
		}
	}
	return opcion_1_n;
}

// para menus de 2 opciones
int analiza_2_opciones() {
	int opcion_2_n = 0;
	char op_2_char[10];
	cin >> op_2_char[0];
	switch (op_2_char[0]) {
	case '1':	opcion_2_n = 1;
		break;
	case '2':	opcion_2_n = 2;
		break;
	default:	opcion_2_n = 0;
		cout << "   Opcion invalida / Intentelo nuevamente." << endl;	
	}
	cout << "\n Presione cualquier tecla para continuar." << endl;
	getch();
	system("cls");
	return opcion_2_n;
}
// Analiza entres 4 opciones
int analiza_4_opciones() {
	int opcion_4_n = 0;
	char op_4_char[10];
	cin >> op_4_char[0];
	switch (op_4_char[0]) {
	case '1':	opcion_4_n = 1;
		break;
	case '2':	opcion_4_n = 2;
		break;
	case '3':	opcion_4_n = 3;
		break;
	case '4':	opcion_4_n = 4;
		break;
	default:	opcion_4_n = 0;
		cout << "   Opcion invalida / Intentelo nuevamente." << endl;	
	}
	return opcion_4_n;
}
// menu ver resultados
void menu_ver_resultados() {
	cout << "\n Presione cualquier tecla para continuar." << endl;
	getch();
	system("cls");
	cout << "\n          * Menu *" << endl;
	cout << "   Desea ver :" << endl;
	cout << "   1. El valor de la sumatoria." << endl;
	cout << "   2. Los n-terminos." << endl;
	cout << "   3. Procedimiento." << endl;
	cout << "   4. Salir" << endl;
	cout << "   Digite su opcion. -> ";
}
// _____________________________________________
// * * * 2. Funciones de tipo matematicas * * *
// _____________________________________________
// EXOPNENCIAL
void mostrar_funcion_exp(float z_0, int opcion_m_3) {
	float error = 10,n = 0;// n+1 es la catidad de terminos
	int i;
	// corremos las funciones de sum exp que a su timpo depende de fact
	// y consegimos el valor de n-terminos
	do {
		n = n+1;
		error = funcion_criterio_error(funcion_sumatoria_exp(n-1,z_0),funcion_sumatoria_exp(n,z_0));
	} while (error!=0);
	switch (opcion_m_3) {
	case 1:
		cout << "\n   S = " << funcion_sumatoria_exp(n,z_0) << endl;
		break;
	case 2:
		cout << "   Donde :     t_n es el termino n-esimo" << endl;
		cout << endl;
		for (i=0;i<=n-1;i++) {
			cout << "   t_" << i << " = " << (pow(z_0,i))/funcion_factorial(i) << endl;
		}
		cout << "\n   S = " << funcion_sumatoria_exp(n,z_0) << endl;
		break;
	case 3:
		cout << "   Donde:     S_n es la sumatoria desde 0 hasta n." << endl;
		cout << "              | error | = | S_n - S_(n-1) |" << endl;
		n = 0;
		do {
			cout << "\n    S_" << n << " = " << funcion_sumatoria_exp(n,z_0) << endl;
			n = n+1;
			cout << "     S_" << n << " = " << funcion_sumatoria_exp(n,z_0);
			cout << "     ->     error = ";
			if (n==1) {
				cout << abs(funcion_sumatoria_exp(n-1,z_0)-funcion_sumatoria_exp(n,z_0)) << endl;
			} else {
				cout << error << endl;
			}
			error = funcion_criterio_error(funcion_sumatoria_exp(n-1,z_0),funcion_sumatoria_exp(n,z_0));
		} while (error!=0);
		break;
	}
}

// TRIGONOMETRICA
void mostrar_funcion_trigo(float z_0, int opcion_m_3, float opcion_m_4) {
	float error = 10,n = 0;
	int i;
	if (opcion_m_4==1) {
		// SENO (-1)^n*( (x)^(2*n+1)/Funcion_factorial(2*n+1)
		do {
			n = n+1;
			error = pow((-1),n)*(pow((z_0),(2*n+1))/funcion_factorial(2*n+1));
		} while (error!=0);
		switch (opcion_m_3) {
		case 1:
			cout << "\n     S = " << funcion_sumatoria_seno(z_0,n) << endl;
			break;
		case 2:
			cout << "   Donde :    t_n Termino n-esimo" << endl;
			cout << endl;
			for (i=0 ; i<=n-1 ; i++) {
				cout << "   t_" << i << " = " << pow((-1),i)*(pow((z_0),(2*i+1))/funcion_factorial(2*i+1)) << endl;
			}
			cout << "\n     S = " << funcion_sumatoria_seno(z_0,n) << endl;
			break;
		case 3:
			cout << "   Donde:     t_n es el termino n-esimo." << endl;
			cout << "                     t_n -> 0" << endl;
			n = 0;
			do {
				cout << "\n     t_" << n << " = " << pow((-1),n)*(pow((z_0),(2*n+1))/funcion_factorial(2*n+1)) << endl;
				n = n+1;
			} while ((pow((z_0),(2*n+1))/funcion_factorial(2*n+1)!=0));
			cout << "\n         t_" << n << " = 0" << endl;
			break;
		}
	} else {
		// COSENO   (-1)^n*( (z_0)^(2*n)/Funcion_factorial(2*n) );
		do {
			n = n+1;
			error = pow((-1),n)*(pow((z_0),(2*n))/funcion_factorial(2*n));
		} while (error!=0);
		switch (opcion_m_3) {
		case 1:
			cout << "\n     S = " << funcion_sumatoria_coseno(z_0,n) << endl;
			break;
		case 2:
			cout << "   Donde :    t_n Termino n-esimo" << endl;
			cout << endl;
			for (i=0 ; i<=n-1 ; i++) {
				cout << "   t_" << i << " = " << pow((-1),i)*(pow((z_0),(2*i))/funcion_factorial(2*i)) << endl;
			}
			cout << "\n     S = " << funcion_sumatoria_coseno(z_0,n) << endl;
			break;
		case 3:
			cout << "   Donde:     t_n es el termino n-esimo." << endl;
			cout << "                     t_n -> 0" << endl;
			n = 0;
			do {
				cout << "\n     t_" << n << " = " << pow((-1),n)*(pow((z_0),(2*n))/funcion_factorial(2*n)) << endl;
				n = n+1;
			} while ((pow((-1),n)*(pow((z_0),(2*n))/funcion_factorial(2*n))!=0));
			cout << "\n         t_" << n << " = 0" << endl;
			break;
		}
	}
}

// LOGARITMICA
void mostrar_funcion_ln(float z_0, int opcion_m_3) {
	float error = 10,n = 0;
	int i;
	// n+1 es la catidad de terminos
	do {
		error = (2/(2*n+1))*pow(((z_0-1)/(z_0+1)),(2*n+1));
		n = n+1;
	} while (error!=0);// el ternimo n-simo tiende a cero por valores negativos
	switch (opcion_m_3) {
	case 1:
		cout << "\n   S = " << funcion_sumatoria_ln(n,z_0) << endl;
		break;
	case 2:
		cout << "   Donde :     t_n es el termino n-esimo" << endl;
		cout << endl;
		// revisar a la hora de entrega n-3
		for (i=0 ; i<=n ; i++) {
			if ((2/(2*i+1))*pow(((z_0-1)/(z_0+1)),(2*i+1))!=0) {
				cout << "   t_" << i << " = " << (2/(2*i+1))*pow(((z_0-1)/(z_0+1)),(2*i+1)) << endl;
			}
		}
		cout << "\n   S = " << funcion_sumatoria_ln(n,z_0) << endl;
		break;
	case 3:
		cout << "   Donde:     t_n es el termino n-esimo." << endl;
		cout << "                     t_n -> 0" << endl;
		cout << endl;
		for (i=0 ; i<=n ; i++) {
			if ((2/(2*i+1))*pow(((z_0-1)/(z_0+1)),(2*i+1))!=0) {
				cout << "   t_" << i << " = " << (2/(2*i+1))*pow(((z_0-1)/(z_0+1)),(2*i+1)) << endl;
			}
		}
		break;
	}
}

// GEOMETRICA
void mostrar_funcion_geo(float z_0, int opcion_m_3) {
	float error = 10,n = 0;// n+1 es la catidad de terminos
	int i;
	// corremos las funciones de sum exp que a su timpo depende de fact
	// y consegimos el valor de n-terminos
	do {
		error = (pow(z_0,n));
		n = n+1;
	} while (error!=0);
	switch (opcion_m_3) {
	case 1:
		cout << "\n   S = " << funcion_sumatoria_geometrica(n,z_0) << endl;
		break;
	case 2:
		cout << "   Donde :     t_n es el termino n-esimo" << endl;
		cout << "" << endl;
		for (i=0 ; i<=n-1 ; i++) {
			cout << "   t_" << i << " = " << (pow(z_0,i)) << endl;
		}
		cout << "\n   S = " << funcion_sumatoria_geometrica(n,z_0) << endl;
		break;
	case 3:
		cout << "   Donde:     t_n es el termino n-esimo." << endl;
		cout << "                     t_n -> 0" << endl;
		n = 0;
		do {
			cout << "\n     t_" << n << " = " << (pow(z_0,n)) << endl;
			n = n+1;
		} while (((pow(z_0,n))!=0));
		cout << "\n         t_" << n << " = 0" << endl;
		break;
	}
}

// BINOMINAL
void mostrar_funcion_binominal(float z_0, float grado, int opcion_m_3) {
	float error = 10,n = 0;// n+1 es la catidad de terminos
	int i;
	// corremos las funciones de sum exp que a su timpo depende de fact
	// y consegimos el valor de n-terminos
	do {
		error = (pow(z_0,n));
		n = n+1;
	} while (error!=0);
	switch (opcion_m_3) {
	case 1:
		cout << "\n   S = " << funcion_sumatoria_binominal(z_0,grado,n) << endl;
		break;
	case 2:
		cout << "   Donde :     t_n es el termino n-esimo" << endl;
		cout << endl;
		for (i=0 ; i<=n-1 ; i++) {
			cout << "   t_" << i << " = " << (pow(z_0,i)) << endl;
		}
		cout << "\n   S = " << funcion_sumatoria_binominal(z_0,grado,n) << endl;
		break;
	case 3:
		cout << "   Donde:     t_n es el termino n-esimo." << endl;
		cout << "                     t_n -> 0" << endl;
		n = 0;
		do {
			cout << "     t_" << n << " = " << (pow(z_0,n)) << endl;
			n = n+1;
		} while (((pow(z_0,n))!=0));
		break;
	}
}
// ______________________________________
// * * * 3. FUNCIONES PRIMORDIALES * * *
// ______________________________________

// * FUNCION EXPONENCIAL : e^x ; donde x pretencea los reales
// * sumatoria ( inicio n=0 , hasta n=n_terminos ) = x^n/(n!)
// punto_convergencia
float funcion_sumatoria_exp(float n_terminos, float x) {
	int n;
	float sumatoria = 0;
	for (n=0 ; n<=n_terminos ; n++) {
		sumatoria = sumatoria+(pow(x,n))/funcion_factorial(n);
	}
	return sumatoria;
}

// * FUNCION SENO : sen x ; donde x pretencea los reales
// * sumatoria ( inicio n=0 , hasta n=n_terminos ) = (-1)^n*( (x)^(2*n+1)/(2*n+1)! )
float funcion_sumatoria_seno(float x, float n_terminos) {
	int n;
	float sumatoria = 0;
	for (n=0 ; n<=n_terminos ; n++) {
		sumatoria = sumatoria+pow((-1),n)*(pow((x),(2*n+1))/funcion_factorial(2*n+1));
	}
	return sumatoria;
}

// * FUNCION COSENO : cos x ; donde x pretencea los reales
// * sumatoria ( inicio n=0 , hasta n=n_terminos ) = (-1)^n*( (x)^(2*n)/(2*n)! )
float funcion_sumatoria_coseno(float x, float n_terminos) {
	int n;
	float sumatoria = 0;
	for (n=0 ; n<=n_terminos ; n++) {
		sumatoria = sumatoria+pow((-1),n)*(pow((x),(2*n))/funcion_factorial(2*n));
	}
	return sumatoria;
}

// * * * LAS FUCIONES QUE SIGUEN TIENEN RESTRICCIONES PARA X * * *
// * FUNCION LOGARITMO NATURAL : ln(x)  ; -1<x<1 y x<>0
// * sumatoria ( inicio n=0 , hasta n=n_terminos ) = [ 1/(2*n+1) ]*[ (x-1)/(x+1) ]^(2*n+1)
float funcion_sumatoria_ln(float n_terminos, float x) {
	int n;
	float sumatoria = 0;
	for (n=0 ; n<=n_terminos ; n++) {
		sumatoria = sumatoria+2*((1)/(2*n+1))*pow(((x-1)/(x+1)),(2*n+1));
	}
	return sumatoria;
}

// * FUNCION SERIE GEOMETRICA : (1-x)^-1  ;  -1<x<1
// NOTA X puede ser igual a la unidad
// * sumatoria ( inicio 0 , hasta n=n_terminos )= x^n 
float funcion_sumatoria_geometrica(float n_terminos, float x) {
	int n;
	float sumatoria =0;
	for (n=0 ; n<=n_terminos ; n++) {
		sumatoria = sumatoria+(pow(x,n));
	}
	return sumatoria;
}

// * FUNCION SERIE BINOMIAL : (1-x)^-1  ;  -1<x<1
// NOTA X puede ser igual a la unidad
// * sumatoria ( inicio 0 , hasta n=n_terminos )= x^n 
float funcion_sumatoria_binominal(float x, float grado, int n_terminos) {
	int n;
	float sumatoria =0;
	for (n=0 ; n<=grado+1 ; n++) {
		sumatoria = sumatoria+(pow(x,n))*funcion_productorio(n,grado);
	}
	return sumatoria;
}

float funcion_criterio_error(float termino_0, float termino_1) {
	float error = 10;
	error = abs(termino_0-termino_1);
	return error;
}

// ______________________________________________
// * * * FUNCIONES FACTORIAL Y PRODUCTORIO * * *
// ______________________________________________
float funcion_factorial(float n) {
	float i;
	float valor_factorial =1;
	for (i=1 ; i<=n ; i++) {
		if (n==0) {
			valor_factorial = 1;
		} else {
			valor_factorial = valor_factorial*i;
		}
	}
	return valor_factorial;
}

// * Funcion_productorio (inicia k=1 , hasta n)= TT (grado-k+1) / (k)
float funcion_productorio(float n, float grado) {
	int k = 1;
	float valor_producto =1;
	if (n==0) {
		valor_producto = 1;
	} else {
		for (k=1;k<=n;k++) {
			if (n>=k) {
				valor_producto = valor_producto*((grado-k+1)/(k));
			}
		}
	}
	return valor_producto;
}

// ______________________________________________
// * * * FUNCIONES DOMINIO Y ENPROCESO * * *
// ______________________________________________
bool funcion_analisis_dominio(float dom, int op_m_1) {
	bool retorno_logico = false;
	switch (op_m_1) {
	case 3:
		if (dom>-1 && dom<1 && dom!=0) {
			retorno_logico = true;
		}
		break;
	case 4:
		if (dom>-1 && dom<1) {
			retorno_logico = true;
		}
		break;
	case 5:
		if (dom>-1 && dom<1) {
			retorno_logico = true;
		}
		break;
	}
	if (retorno_logico==false) {
		cout << "\n   Valor invalido / Intentelo nuevamente." << endl;
		cout << "\n Presione cualquier tecla para continuar." << endl;
		getch();
		system("cls");
		cout << "   Ingrese valores dentro del rango de :" << endl;
		if (op_m_1==3) {
			cout << "                     -1 < z_0 < 1  y  z_0 != 0" << endl;
		} else {
			cout << "                     -1 < z_0 < 1 " << endl;
		}
		cout << endl;
	}
	return retorno_logico;
}

