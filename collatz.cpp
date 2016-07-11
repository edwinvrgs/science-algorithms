#include <fstream>
#include <iostream>
using namespace std;

void collatz(long int number)
{
	fstream file;
	
	file.open("data_collatz.log", ios::out);
	
	if(file.fail()) {
		cout << "Ooops pa!";
		return;
	}
	
	file << "Number to analize: " << number << endl << endl;
	file << "Iteration\tPar\t\tImpar" << endl;
	
	for(int i = 0; i < number; i++) {
		
		int n = i;
		
		int contador_par = 0; 
		int contador_impar = 0;
	
		while(n > 1)
		{
			//file << n << endl; //For print all numbers
			
			if ((n%2) == 1) {
				n = 3*n+1;
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
	
	//Data analysis algorithm for the numbers of Collatz
	collatz(1000);
	
	return 0;
}
