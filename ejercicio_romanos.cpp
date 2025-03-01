#include <iostream>

int romanToInt(std::string s) {
	if ( (s.length() < 1) && (s.length() > 15)){ // Si la longitud de los caracteres del string está fuera del rango permitido
	    std::cout << "La cantidad de caracteres no es válida. Se espera que esté entre 1 y 15. La función retornará un cero. Reinicia el programa.";
	    return 0;
	}
	int resultado = 0;  // Se inicializa la variable de resultado en 0 para evitar acumular el resultado con algún valor ya asignado.
	for (int i = 0; i < s.length(); i++) {  // Se recorre un for tantas veces como caracteres tenga el string
		switch(s[i]) {  // Se analiza el condenido de la i-ésima posición del string y, según la letra identificada, se suma su valor a la suma acumulada del resultado
		case 'M':
			resultado = resultado + 1000;
			break;
		case 'D':
			resultado = resultado + 500;
			break;
		case 'C':
		    
		    if (s[i+1] == 'D') { // Si la letra de la siguiente posición a 'C' es una 'D', por reglas de números romanos el resultado es 400.
				resultado = resultado + 400;
				i = i+1;    /* Como el resultado del número de esta letra actual está ligado al de la siguiente letra, se incrementa el contador
				            para que en la siguiente iteración no se considere esa letra. */
				break;
			}
			else if (s[i+1] == 'M') {   // Si la letra de la siguiente posición a 'C' es una 'M', por reglas de números romanos el resultado es 900.
				resultado = resultado + 900;
				i = i+1;    /* Como el resultado del número de esta letra actual está ligado al de la siguiente letra, se incrementa el contador
				            para que en la siguiente iteración no se considere esa letra. */
				break;
			}
			else {
				resultado = resultado + 100;  // Si no hay ninguna letra con la que pueda combinarse para formar otro número, se obtiene su resultado por individual
				break;
			}
		case 'L':
			resultado = resultado + 50;
			break;
		case 'X':
			if (s[i+1] == 'L') { // Si la letra de la siguiente posición a 'X' es una 'L', por reglas de números romanos el resultado es 40.
				resultado = resultado + 40;
				i = i+1;    /* Como el resultado del número de esta letra actual está ligado al de la siguiente letra, se incrementa el contador
				            para que en la siguiente iteración no se considere esa letra. */
				break;
			}
			else if (s[i+1] == 'C') {    // Si la letra de la siguiente posición a 'X' es una 'C', por reglas de números romanos el resultado es 90.
				resultado = resultado + 90;
				i = i+1;    /* Como el resultado del número de esta letra actual está ligado al de la siguiente letra, se incrementa el contador
				            para que en la siguiente iteración no se considere esa letra. */
				break;
			}
			else {
				resultado = resultado + 10;   // Si no hay ninguna letra con la que pueda combinarse para formar otro número, se obtiene su resultado por individual
				break;
			}
		case 'V':
			resultado = resultado + 5;
			break;
		case 'I':
			if (s[i+1] == 'V') { // Si la letra de la siguiente posición a 'I' es una 'V', por reglas de números romanos el resultado es 4.
				resultado = resultado + 4;
				i = i+1;    /* Como el resultado del número de esta letra actual está ligado al de la siguiente letra, se incrementa el contador
				            para que en la siguiente iteración no se considere esa letra. */
				break;
			}
			else if (s[i+1] == 'X') {    // Si la letra de la siguiente posición a 'I' es una 'X', por reglas de números romanos el resultado es 90.
				resultado = resultado + 9;
				i = i+1;    /* Como el resultado del número de esta letra actual está ligado al de la siguiente letra, se incrementa el contador
				            para que en la siguiente iteración no se considere esa letra. */
				break;
			}
			else {
				resultado = resultado + 1;  // Si no hay ninguna letra con la que pueda combinarse para formar otro número, se obtiene su resultado por individual
				break;
			}

		}
	}
	return resultado;

}

int main()
{
	std::string cadena = "MCMXCIV";
	std::cout << romanToInt(cadena)<<std::endl;

	return 0;
}