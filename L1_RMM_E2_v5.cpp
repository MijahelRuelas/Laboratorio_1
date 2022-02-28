#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;
// Prototipo de funciones
float funcion_discriminante(float a, float b, float c);
void funcion_tricotomia(float discriminante, float a, float b, float c);

int main() {
	float coef_cuadratico,coef_indep,coef_lineal,var_aux;
	char opcion_menu_char[1] = {'0'};
	int opcion_menu_n = 0;
	do {
		cout << "\n         * Calculadora *" << endl;
		cout << "\n   Sea la ecuacion cuadratica :" << endl;
		cout << "\n            ( a )*x^2 + ( b )*x + (c) = 0." << endl;
		cout << "\n   donde:     a != 0." << endl;
		cout << endl;
		do {
			cout << "   Digite el coeficiente cuadratico     -> ";
			cin >> var_aux;
			if (var_aux==0) {
				cout << "   Valor invalido/Intentelo nuevamente." << endl;
				cout << "   Debe ingresar un valor distinto a 0. " << endl;
				cout << "" << endl;
			}
		} while (var_aux==0);
		coef_cuadratico = var_aux;
		cout << "   Digite el coeficiente lineal         -> ";
		cin >> coef_lineal;
		cout << "   Digite el coeficiente independiente  -> ";
		cin >> coef_indep;
		cout << "\n Presione cualquier tecla para continuar." << endl;
		getch();
		system("cls");
	do{
	
		do {
			cout << "\n           * Menu *" << endl;
			cout << "\n   Desea :" << endl;
			cout << "   1. Ver las raices resultantes." << endl;
			cout << "   2. Ver el procedimiento." << endl;
			cout << "   3. Ingresar nuevos valores" << endl;
			cout << "   4. Salir" << endl;
			cout << "\n   Digite su opcion -> ";
			cin >> opcion_menu_char[0];
			switch (opcion_menu_char[0]) {
			case '1':	opcion_menu_n = 1;
				break;
			case '2':	opcion_menu_n = 2;
				break;
			case '3':	opcion_menu_n = 3;
				break;
			case '4':	opcion_menu_n = 4;
				break;
			default:	opcion_menu_n = 0;
				cout << "  Opcion invalida / Intenteelo nuevamente." << endl;
			}
			cout << "\n Presione cualquier tecla para continuar." << endl;
			getch();
			system("cls");
		} while (opcion_menu_n==0);
		// sale del loop del menu
		if (opcion_menu_n==1 || opcion_menu_n==2) {
			cout << "   Sea la ecuacion de 2do grado :" << endl;
			cout << "\n          ( " << coef_cuadratico << " )*x^2 + ( " << coef_lineal << " )*x + ( " << coef_indep << " ) = 0." << endl;
			// mostrar procedimiento
			var_aux = funcion_discriminante(coef_cuadratico,coef_lineal,coef_indep);
			if (opcion_menu_n==2) {
				cout << "\n     x_(1,2) = (-" << coef_lineal << ") + (+/-)[ (" << coef_lineal << ")^2 - 4*(" << coef_cuadratico << ")*(" << coef_indep << ") ]^(0.5) / (" << coef_cuadratico << "*2)" << endl;
				cout << "\n   Donde :    Discriminante = (" << coef_lineal << ")^2 - 4*(" << coef_cuadratico << ")*(" << coef_indep << ")" << endl;
				cout << "              Discriminante = " << var_aux << endl;
				cout << "   Entonces :" << endl;
				if (var_aux>0) {
					cout << "              x_(1,2) = (-" << coef_lineal << ") + (+/-)[" << var_aux << "]^(0.5) / (" << coef_cuadratico << "*2)" << endl;
				}
				if (var_aux==0) {
					cout << "              x_(1,2) = (-" << coef_lineal << ") / (" << coef_cuadratico << "*2)" << endl;
				}
				if (var_aux<0) {
					cout << "              x_(1,2) = (-" << coef_lineal << ") (+/-) [ (" << -var_aux << ")^0.5 ]*i / (" << coef_cuadratico << "*2)" << endl;
				}
			}
			cout << "" << endl;
			if (var_aux<0) {
				cout << "   Tiene como raices imaginarias :" << endl;
			} else {
				cout << "   Tiene como raices :" << endl;
			}
			cout << endl;
			funcion_tricotomia(var_aux,coef_cuadratico,coef_lineal,coef_indep);
			cout << "\n\n Presione cualquier tecla para continuar." << endl;
			getch();
			system("cls");
		}		
		}while(opcion_menu_n<3);		
	} while (opcion_menu_n!=4);
	return 0;
}

float funcion_discriminante(float a, float b, float c) {
	float discriminante;
	discriminante = 0;
	discriminante = pow(b,2)-4*a*c;
	return discriminante;
}

void funcion_tricotomia(float discriminante, float a, float b, float c) {
	if (funcion_discriminante(a,b,c)>0) {
		cout << "              x_1 = " << (-b+pow(discriminante,0.5))/(2*a) << endl;
		cout << "              x_2 = " << (-b-pow(discriminante,0.5))/(2*a) << endl;
	}
	if (funcion_discriminante(a,b,c)==0) {
		cout << "              x_(1,2) = " << (-b)/(2*a) << endl;
	}
	if (funcion_discriminante(a,b,c)<0) {
		cout << "              x_(1,2) = " << -b/(2*a) << " +/- (" << (pow((-discriminante),0.5))/(2*a) << ")*i" << endl;
	}
}

