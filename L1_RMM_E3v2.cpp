#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;
// Declaraciones adelantadas de las funciones
float funcion_cambio_variable_m(float a, float b, float c, float d);
float funcion_cambio_variable_n(float a, float b, float c, float d);
float funcion_discriminate(float m, float n);
float funcion_raiz_de_cuadratica_1(float discriminante, float n);
float funcion_raiz_de_cuadratica_2(float discriminante, float n);
void mostrar_resultados(float coeficiente_cubico, float coeficiente_cuadratico, float a, float b, float m, float n, float discriminante);

int main() {
	float a,b,coeficiente_cuadratico,coeficiente_cubico,coeficiente_lineal,discriminante,m,n,termino_independiente;
	char opcion_menu_char[1];
	int opcion_menu_n = 0;
	float var_aux,x_1,x_2,x_3;
	opcion_menu_char[0] = '0';
	
	do{	coeficiente_cuadratico=0;coeficiente_cubico=0;coeficiente_lineal=0;termino_independiente=0;
		discriminante=0;m=0;n=0;
		cout << "         * Calculadora *" << endl;
		cout << "\n   Sea la ecuacion cubica :" << endl;
		cout << "\n            ( a )*x^3 + ( b )*x^2 + (c)*x + (d) = 0." << endl;
		cout << "\n   donde:     a != 0." << endl;
		do {
			cout << "\n   Digite el coeficiente cubico -> ";
			cin >> var_aux;
			if (var_aux==0) {
				cout << "   Valor invalido/Intentelo nuevamente." << endl;
				cout << "   Debe ingresar un valor distinto a 0 " << endl;
			}
		} while (var_aux==0);
		coeficiente_cubico = var_aux;
		cout << "   Digite el coeficiente cuadratico -> ";
		cin >> coeficiente_cuadratico;
		cout << "   Digite el coeficiente lineal -> ";
		cin >> coeficiente_lineal;
		cout << "   Digite el coeficiente independiente -> ";
		cin >> termino_independiente;
		cout << "\n Presione cualquier tecla para continuar." << endl;
		getch();
		system("cls");
		// menu//	
		do {
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
			// out menu
			if (opcion_menu_n==1 || opcion_menu_n==2) {
				m = funcion_cambio_variable_m(coeficiente_cubico,coeficiente_cuadratico,coeficiente_lineal,termino_independiente);
				n = funcion_cambio_variable_n(coeficiente_cubico,coeficiente_cuadratico,coeficiente_lineal,termino_independiente);
				discriminante = funcion_discriminate(m,n);
				a = funcion_raiz_de_cuadratica_1(discriminante,n);
				b = funcion_raiz_de_cuadratica_2(discriminante,n);
				cout << "   Sea la ecuacion de 3er grado :" << endl;
				cout << "\n         ( " << coeficiente_cubico << " )*x^3 + ( " << coeficiente_cuadratico << " )*x^2 + ( " << coeficiente_lineal << " )*x + ( " << termino_independiente << " ) = 0." << endl;
				if (opcion_menu_n==2) {
					cout << "\n   Sea la ecuacion ordenada del modo :" << endl;
					cout << "     [x+" << coeficiente_cuadratico << "/(" << coeficiente_cubico << "*3)]^3 + {[3*(" << coeficiente_cubico << ")*(" << coeficiente_lineal << ") -(" << coeficiente_cuadratico << ")^2] / [3*(" << coeficiente_cubico << ")^2]}*x +..." << endl;
					cout << "                ...+{[27*(" << coeficiente_cubico << ")^2*(" << termino_independiente << ") -" << coeficiente_cuadratico << "^3]/(" << coeficiente_cubico << "*3)^3} = 0 " << endl;
					cout << "\n   Realizando el siguiente cambio de variable :" << endl;
					cout << "     x + " << coeficiente_cuadratico << "/(" << coeficiente_cubico << "*3) = z" << endl;
					cout << "\n   Entonces :" << endl;
					cout << "     x = z - [" << coeficiente_cuadratico << "/(" << coeficiente_cubico << "*3)]" << endl;
					cout << "\n Presione cualquier tecla para continuar." << endl;
					getch();
					system("cls");
					cout << "   Reemplazando y operando saldra :" << endl;
					cout << "     z^3 + {[3*(" << coeficiente_cubico << ")*(" << coeficiente_lineal << ") -(" << coeficiente_cuadratico << ")^2] / [3*(" << coeficiente_cubico << ")^2]}*z + {[ (" << coeficiente_cuadratico << ")^3*3 -9*(" << coeficiente_cubico << ")(" << coeficiente_cuadratico << ")(" << coeficiente_lineal << ") +27*(" << termino_independiente << ")*(" << coeficiente_cubico << ")^2 ]/(" << coeficiente_cubico << "*3)^3} = 0 " << endl;
					cout << "\n   Realizando el 2do cambio de variable :" << endl;
					cout << "     m = [3*(" << coeficiente_cubico << ")*(" << coeficiente_lineal << ") -(" << coeficiente_cuadratico << ")^2] / [3*(" << coeficiente_cubico << ")^2]" << endl;
					cout << "     * m = " << m << endl;
					cout << "" << endl;
					cout << "     n = [ (" << coeficiente_cuadratico << ")^3*3 -9*(" << coeficiente_cubico << ")(" << coeficiente_cuadratico << ")(" << coeficiente_lineal << ") +27*(" << termino_independiente << ")*(" << coeficiente_cubico << ")^2 ]/(" << coeficiente_cubico << "*3)^3" << endl;
					cout << "     * n = " << n << endl;
					cout << "\n   Realizdo la operacion auxiliar:" << endl;
					cout << "      z = r_1 + r_2   // ()^3" << endl;
					cout << "     z^3 = (r_1)^3 +(r_2)^3 +3*[r_1*r_2]*[ r_1+r_2 ]" << endl;
					cout << "     z^3 -[(r_1)^3 +(r_2)^3] -[3*r_1*r_2]*z = 0" << endl;
					cout << "\n Presione cualquier tecla para continuar." << endl;
					getch();
					system("cls");
					cout << "\n     z^3 -[(r_1)^3 +(r_2)^3] -[3*r_1*r_2]*z = 0" << endl;
					cout << "" << endl;
					cout << "   Obteniendo el siguiente sistema de ecuaciones :" << endl;
					cout << "     ( ) ... -(3*r_1*r_2) = m   // ()^3" << endl;
					cout << "     (1) ... (r_1*r_2)^3 = -(m/3)^3" << endl;
					cout << "\n     ( ) ... -(r_1)^3-(r_2)^3 = n" << endl;
					cout << "     (2) ... +(r_1)^3+(r_2)^3 = -n" << endl;
					cout << "\n Presione cualquier tecla para continuar." << endl;
					getch();
					system("cls");
					cout << "   Sea una ecuacion de 2do grado :" << endl;
					cout << "              y^2 +(-1)*(P_1+P_2)*y +P_1*P_2 = 0" << endl;
					cout << "   Cuyas raices cumplen :" << endl;
					cout << "              P_1 +P_2 = -(Q_1/Q_2)     Y     P_1*P_2 = -(Q_0/Q_2) " << endl;
					cout << "\n   La ec. de 2do grado quedaria :" << endl;
					cout << "              y^2 +(Q_1/Q_2)*y +(Q_0/Q_2) = 0" << endl;
					cout << "   Para nuestro caso :" << endl;
					cout << "                   (r_1)^3 = P_1     Y     (r_2)^3 = P_2" << endl;
					cout << "\n   Reemplazando en el sistema de ec. anterior :" << endl;
					cout << "     (1) ... ( Q_0/Q_2 ) = -(m/3)^3" << endl;
					cout << "     (2) ... -( Q_1/Q_2 ) = -n" << endl;
					cout << "   En la ec. de 2do grado :" << endl;
					cout << "              y^2 +y*n -(m/3)^3 = 0" << endl;
					cout << "\n Presione cualquier tecla para continuar." << endl;
					getch();
					system("cls");
					cout << "\n              y^2 +y*n -(m/3)^3 = 0" << endl;
					cout << "\n Hallando su discriminante :" << endl;
					cout << "          discriminante = n^2 -4*(-m/3)^3 " << endl;
					cout << "          discriminante = " << n << "^2 +4*(" << m << "/3)^3 " << endl;
					cout << "         * discriminante = " << discriminante << endl;
					cout << "\n Presione cualquier tecla para continuar." << endl;
					getch();
					system("cls");
					if (discriminante>0) {
						cout << "   * Formula de cardano :" << endl;
						cout << "      {y -[-n +(discriminante)^0.5] / 2} * {y -[-n -(discriminante)^0.5] / 2} = 0" << endl;
						cout << "   Donde :     (r_1)^3 = -n +(discriminante)^0.5" << endl;
						cout << "               (r_2)^3 = -n -(discriminante)^0.5" << endl;
						cout << "  Solucion real :" << endl;
						cout << "     z_1 = r_1 + r_2 " << endl;
						cout << "  Retornando al cambio de variable :" << endl;
						cout << "     x_1 = r_1 +r_2 -(b/3*b)" << endl;
						cout << "     x_1 = (-n+(discriminante)^0.5)^1/3 +(-n-(discriminante)^0.5)^1/3 " << endl;
						cout << "     x_1 = (-" << n << "+(" << discriminante << ")^0.5)^1/3 +(-" << n << "-(" << discriminante << ")^0.5)^1/3 " << endl;
						cout << "\n  y para los terminos imaginarios :" << endl;
						cout << "     z_(2,3) = [ -0.5*( r_1 +r_2 ) ] +(+/-){ (3)^0.5/(2)[ r_1 -r_2 ] }*i" << endl;
						cout << "     z_(2,3) = [ -0.5*( (-" << n << "+(" << discriminante << ")^0.5)^1/3 +(-" << n << "-(" << discriminante << ")^0.5)^1/3 ) ] +..." << endl;
						cout << "              (+/-){(3)^0.5/(2)[ (-" << n << "+(" << discriminante << ")^0.5)^1/3 -(-" << n << "-(" << discriminante << ")^0.5)^1/3]}*i" << endl;
					}
					if (discriminante==0) {
						cout << "   z_1 = 3*[ n/m ]" << endl;
						cout << "   z_1 = 3*[ " << n << "/" << m << " ]" << endl;
						cout << "\n   z_(2,3) = z_1/2" << endl;
					}
					if (discriminante<0) {
						cout << "   * Formula de cardano :" << endl;
						cout << "      {y -[-n +(|discrim|)^0.5] /2} * {y -[-n -(|discrim|)^0.5] /2} = 0" << endl;
						cout << "   Donde :     (r_1)^3 = -n +( |discriminante|^0.5 )*i" << endl;
						cout << "               (r_2)^3 = -n -( |discriminante|^0.5 )*i" << endl;
						cout << "\n   Sea la solucion de la raiz cubica de la unidad :" << endl;
						cout << "      W_0 = 1" << endl;
						cout << "      W_(1,2) = -0.5 +(+/-)[(3^0.5)/2]*i " << endl;
						cout << "\n   En forma trigonometrica la solucion sera :" << endl;
						cout << "    x_1 = 2*[-m/3]^0.5 *cos(phi/3) -[ b/(3*a) ]" << endl;
						cout << "    x_2 = 2*[-m/3]^0.5 *cos(phi+2*pi/3) -[ b/(3*a) ]" << endl;
						cout << "    x_3 = 2*[-m/3]^0.5 *cos(phi+4*pi/3) -[ b/(3*a) ]" << endl;
						cout << "\n   Donde phi = arcos { [3*(n)2*(m)][-3/(m)]^0.5 }" << endl;
					}
					cout << "\n Presione cualquier tecla para continuar." << endl;
					getch();
					system("cls");
					cout << "\n   finalmente :" << endl;
				}
				cout << "\n   Las soluciones seran :" << endl;
				mostrar_resultados(coeficiente_cubico,coeficiente_cuadratico,a,b,m,n,discriminante);
			}
			cout << "\n Presione cualquier tecla para continuar." << endl;
					getch();
					system("cls");
		} while (opcion_menu_n<3);
	}while(opcion_menu_n!=4);
	return 0;
}

float funcion_cambio_variable_m(float a, float b, float c, float d) {
	float m = 0;
	m = (3*a*c-pow(b,2))/(3*pow(a,2));
	return m;
}

float funcion_cambio_variable_n(float a, float b, float c, float d) {
	float n = 0;
	n = (2*(pow(b,3))-9*a*b*c+27*d*(pow(a,2)))/pow((3*a),3);
	return n;
}

float funcion_discriminate(float m, float n) {
	float valor_discriminante = 0;
	valor_discriminante = pow(n,2)+4*pow((m/3),3);
	return valor_discriminante;
}

float funcion_raiz_de_cuadratica_1(float discriminante, float n) {
	float a_raiz = 0;
	float var_aux = 0;
	var_aux = ((-n+pow(discriminante,0.5))/2);
	if (var_aux<0) {
		var_aux = -var_aux;
		a_raiz = -pow(var_aux,(0.33333333));//a_raiz = -pow(var_aux,(1/3));
	} else {
		a_raiz = pow(var_aux,(0.33333333));
	}
	return a_raiz;
}

float funcion_raiz_de_cuadratica_2(float discriminante, float n) {
	float b_raiz = 0;
	float var_aux = 0;
	var_aux = ((-n-pow(discriminante,0.5))/2);
	if (var_aux<0) {
		var_aux = -var_aux;
		b_raiz = -pow(var_aux,(0.33333333));
	} else {
		b_raiz = pow(var_aux,(0.33333333));
	}
	return b_raiz;
}

// Coeficiente_cubico,Coeficiente_cuadratico
void mostrar_resultados(float coeficiente_cubico, float coeficiente_cuadratico, float AX, float BX, float m, float n, float discriminante) {
	int k;
	float op_aux = 0,phi,pi,vector_z[3];
	float x_1 = 0,x_2 = 0,x_compleja[2];
	x_compleja[0] = 0;
	x_compleja[1] = 0;
	if(m==0&&n==0){
		x_1 = -coeficiente_cuadratico/(coeficiente_cubico*3);
		cout << "\n         x_(1,2,3) = " << x_1 << endl;
	}else{	
	if (discriminante>0) {
		x_1 = AX+BX-(coeficiente_cuadratico/(3*coeficiente_cubico));
		x_compleja[0] = -(AX+BX)/2-(coeficiente_cuadratico/(3*coeficiente_cubico));
		x_compleja[1] = ((AX-BX)*(pow(3,0.5)))/2;
		cout << "\n         x_1 = " << x_1 << endl;
		cout << "         x_(2,3) = " << x_compleja[0] << " +/- ( " << x_compleja[1] << " )*i" << endl;
	}
	if (discriminante==0) {
		x_1 = ((3*n)/m)-(coeficiente_cuadratico/(3*coeficiente_cubico));
		x_2 = -x_1/2;
		cout << "         x_1 = " << x_1 << endl;
		cout << "         x_(2,3) = " << x_2 << endl;
	}
	if (discriminante<0) {
		op_aux = (3*n)/(2*m)*pow((-3/m),0.5);
		phi = acos(op_aux);
		discriminante = -discriminante;
		for (k=0;k<=2;k++) {
			vector_z[k] = 2*pow((-m/3),0.5)*cos((phi+2*k*M_PI)/3);
			cout << "         x_" << k+1 << " = " << vector_z[k]-coeficiente_cuadratico/(3*coeficiente_cubico) << endl;
		}
	}	
	}
}

