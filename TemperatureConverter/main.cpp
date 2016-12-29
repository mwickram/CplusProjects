
#include <iostream>

using namespace std;

double getConvert(char c);
double isValid(string str);
double getConvert(char c);
int getChoice();
void showDegreesK(double c);
bool validSelection();

	

int main() 

{
	int choice;
	bool choiceK;
	double Celsius;
	
	cout << "Welcome to the Temperature Converter !\n";
	
	choiceK=validSelection();
	choice = getChoice();

	while(choice!=0) {
		
		if(choice!=0){
			
		Celsius = getConvert(choice);
			
		if(choiceK){
		
			showDegreesK(Celsius);
		}
			
		}
		cout<<endl;
		choiceK = validSelection();
		choice = getChoice();

	}
	
	cout << "Thank you for using temperature converter !";
	
	system("pause");
	return 0;
}



bool validSelection() {
	
	char choice[3] = {'Y','y','1'};
	char choiceNeg[3]={'N','n','0'};
	char c;
	bool flag=false;
	bool flagNeg=true;
	
	do{
		
		cout << "Would you like see degrees Kelvin (K) in the results? (Y/N):";
		
		try {
			cin >> c;
			
			for (int i=0; i<sizeof(choice); i=i+1) {
				if (c==choice[i]) {
					
					flag=true;
					
				} else if (c==choiceNeg[i]) {
					
					flagNeg=false;
					flag=true;
				} 
			}
			
			if (!flag) {
				
				cout << "Make a selection with Y(1) or N(0)" << endl;
			}
			
		}catch (string exceptionString) {
			
			cout<<exceptionString<<endl;
			return 0;
		}
		
	}while(!flag);
	
	return flagNeg;
}


double isValid(string str)
{
	char userTem[10]={NULL};
	double temp;
	bool flag=false;
	
	do{
		cout << "Enter your "<< str << " temperature: ";
		
		try {
			cin >> userTem;
			
			for(int i=0;i<sizeof(userTem);i=i+1){
				
				if(isalpha(userTem[i])){
					
					flag=true;
					userTem[i]=NULL;
				}
			}
			
			if(flag){
				
				cout << "Temperature should be numeric\n";
				flag=false;
				
			} else {
				
				temp= atof(userTem);
				flag=true;
			}
			
		}
		catch (string exceptionString) {
			
			cout<<exceptionString<<endl;
			return 0;
		}
	}while(!flag);
	
	return temp;
}


double getConvert(char c)

{
	double cdegree, fdegree;
	
	switch (c)
	
	{
		case 1:
			
			fdegree=isValid("Fahrenheit");
			cdegree = 5*(fdegree - 32)/9;
			cout << "A temp of " << fdegree << " Fahrenheit converted to Celsius = "
			<< cdegree << endl;
			break;
			
		case 2:
			
			cdegree=isValid("Celsius");
			cout << "A temp of " << cdegree << " Celsius converted to Fahrenheit = "
			<< 9*(cdegree + 32)/5 << endl;
			break;
	}
	
	return cdegree;
}



int getChoice(){
	
	char choice[3]={'0', '1', '2'};
	char c[10]={NULL};
	bool flag=false;
	
	do {
		
		cout << "Select conversion type (1=F to C, 2=C to F, 0=end):";
		
		try {
			
			cin >> c;
			
			if (c[1]!=NULL){
				
				cout << "Invalid Entry !\n";
				
			}else {
				
				for (int i=0; i<3; i=i+1){
					if (c[0]==choice[i]){
						flag=true;
					} 
				} 
				
				if(!flag){
					cout<< "Invalid Entry !\n";
				}
			}
			
		}catch (string exceptionString) {
			cout<<exceptionString<<endl;
			return 0;
		}
		
	} while(!flag);	
	
	int b = c[0] - 48;
	return b;
	
}


void showDegreesK(double c)

{
	double kelvin = c + 273.15;	
	cout << "This is also a temperature of: " << kelvin<<endl;
}

