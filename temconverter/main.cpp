// TemConverter.cpp : main project file.
//Student: Praminda Imaduwa-Gamage

#include <iostream>

//using namespace System;
using namespace std;

double getConvert(int c);
int getChoice();
void showDegreesK(double c);
bool validSelection();
double isValidtem(string str);

int main()
{
	int choice;
	bool choiceK;
	double Celsius;
	
	cout << "Welcome to the Temperature Converter !\n";
	
	do{
		choiceK=validSelection();
		choice=getChoice();
		
		if (choice != 0){
			Celsius = getConvert(choice);
			
			if (choiceK){
				showDegreesK(Celsius);
			}
		}
	} while (choice != 0);
	
	cout << "\nThank you for using temperature converter !";
	
	system("pause");
    return 0;
}


double getConvert(int c)

{
	double cdegree, fdegree;
	
	switch (c)
	{
		case 1:
			
			fdegree = isValidtem("Fahrenheit");
			//cout << "Enter your Fahrenheit temperature: ";
			//cin >> fdegree;
			cdegree = (5.0/9.0)*(fdegree - 32.0);
			cout << "A temp of " << fdegree << " Fahrenheit converted to Celsius = "
			<< cdegree << endl;
			break;
			
		case 2:
			cdegree = isValidtem("Celsius");
			//cout << "Enter your Celsius temperature: ";
			//cin >> cdegree;
			cout << "A temp of " << cdegree << " Celsius converted to Fahrenheit = "
			<< (9.0/5.0*cdegree) + 32.0 << endl;
			break;
	}
	return cdegree;
}

void showDegreesK(double c)

{
	double kelvin = c + 273.15;
	
	if (kelvin < 0){
		cout << "Sorry ! this temperature is out of Kelvin range"<<endl;
	}
	else {
		cout << "This is also a temperature of: " << kelvin << endl;
	}
	
}

bool validSelection() {
	
	char choice[2] = { 'Y', 'y' };
	char choiceNeg[2] = { 'N', 'n' };
	bool flag = false;
	bool flagNeg = true;
	char c[10];
	
	do{
		cout << "Would you like see degrees Kelvin (K) in the results? (Y/N):";
		cin >> c;
		
		if (!iscntrl(c[1])){
			cout << "Invalid Entry !\n";
		}
		else {
			
			for (int i = 0; i < sizeof(choice); i = i + 1) {
				if (c[0] == choice[i]) {
					flag = true;
				}
				else if (c[0] == choiceNeg[i]) {
					flagNeg = false;
					flag = true;
				}
			}
			if (!flag) {
				cout << "Make a selection with Y or N" << endl;
			}
		}
		
	} while (!flag);
	
	return flagNeg;
}

int getChoice(){
	
	char choice[3] = { '0', '1', '2' };
	char c[10];
	bool flag = false;
	int flagc;
	
	do {
		//flagc=0;
		cout << "Select conversion type (1=F to C, 2=C to F, 0=end):";
		cin >> c;
		
		for (int i=1; i<sizeof(c);i=i+1){
		
			flagc=isprint(c[i]);
				cout << flagc<<endl;

		}
		
		
		if(flagc){
		
			cout << "Invalid Entry !\n";
			
		} else {
			for (int i = 0; i<3; i = i + 1){
				if (c[0] == choice[i]){
					flag = true;
				}
			}
			
			if (!flag){
				cout << "Invalid Entry !\n";
			}
		}
		
	} while (!flag);
	
	int b = c[0] - 48;
	return b;
}

double isValidtem(string str)
{
	char userTem[10];
	double temp;
	bool flag = false;
	
	do{
		cout << "Enter your " << str << " temperature: ";
		cin >> userTem;
		
		for (int i = 0; i<sizeof(userTem); i = i + 1){
			
			if (isdigit(userTem[i])){
				flag = true;
			}
		}
		
		if (!flag){
			cout << "Temperature should be numeric\n";
			flag = false;
		} else {
			temp = atof(userTem);
			flag = true;
		}
	} while (!flag);
	
	return temp;
}
