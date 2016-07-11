#include <fstream>
#include <iostream>
using namespace std;

bool isprime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    
	for(int i = 3; (i*i) <= number; i += 2){
    	if(number % i == 0 ) 
			return false;
    }
    
    return true;
}



void collatz(long int number)
{
	fstream file;
	
	file.open("data_collatz.log", ios::out);
	
	if(file.fail()) {
		cout << "Ooops pa!";
		return;
	}
	
	file << "Número a analizar: " << number << endl << endl;
	file << "Etiquetas: " << endl;
	file << "Numero primo -" << endl;
	file << endl << endl;
	file << "Iteracion\tPar\t\tImpar" << endl;
	
	for(int i = 0; i < number; i++) {
		
		int n = i;
		
		int contador_par = 0; 
		int contador_impar = 0;
		
		if(isprime(n))
			file << "-";
	
		while(n > 1)
		{
			//file << n << endl; //For print all numbers
			
			if ((n%2) == 1) {
				
				n = 3 * n+1;
				contador_impar++;
			}
			else {
				
				n = n/2;
				contador_par++;
			}
		}
		
		file << i << "\t\t" << contador_par << "\t\t" << contador_impar << endl;
	}

	system("notepad data_collatz.log");
}

int main() {
	
	//Algoritmo para analizar las iteraciones de la conjetura de Collatz
	//Cuenta la cantidad de iteraciones con numeros pares e impares 
	collatz(1000);
	
	return 0;
}
