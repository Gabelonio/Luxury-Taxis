/*
	Libraries usage:
	1. iostream : input and output of data.
	2. conio.h : instantaneous input from keyboard.
	3. string.h : manage of char arrays.
	4. iomanip : specific printing inside the software.
	5. windows.h : execution times in the software (timers).
	6. math.h : specific and necessary math operations. 	
*/
#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
#include<math.h>
using namespace std;
/*
	Defining clear references for keys. 
*/
#define ESCAPE 27
#define ENTER  13
/*
	Data Structures:
	
	struct taxi: 
				1. License plate : char[7]. Example : ABC-123
				2. Type : int. Example : 1 (Automobile), 2 (Van).
				3. Capacity : int. Example : 3 people [Maximum].
				4. Calle : int. Example : Calle 2 [Y Coordinate].
				5. Carrera : int. Example : Carrera 3 [X Coordinate].
				6. Time : int. Example : 3 times the taxi hasn't received a service.
				7. Active : bool. Example : true-active for receiving services [Could be busy with a customer]. 
				8. Free : bool. Example : true-able for receiving clients.
	
	struct usuario: 
				1. type : int. Example : 1 (Automobile).
				2. Pasengers : int. Example : 3 customers.
				3. Calle : int. Example : 2nd Street [Y Coordinate].
				4. Carrera : int. Example : 3rd Career [X Coordinate].	 
*/
struct taxi
{
	char Placa[7];
	int Tipo,Capacidad,Carrera,Calle,Tiempo; 
	bool Activo,Libre;	
};
struct usuario
{
	int Tipo,Pasajeros,Carrera,Calle; 
};
/*
	Functions:
	
	Map and logo:
				1. void desplegarLogo().
				2. void visualizarTaxis().
				3. void visualizarTaxis(char ingreso[]). 
				4. void visualizarCuadrante(int calle, int carrera). 
				5. void desplegarMapa(). 
				6. void inicializarMapa(taxi mapa[3][5][3]).
				
	Taxis:
				1. void registrarTaxis(int cantidad).
				2. void moverTaxi(char ingreso[]). 
				3. bool verificarRegistro().
				4. int ingresarNumero(char ingreso[]).
				5. bool verificarPlaca(char ingreso[]).
				6. bool repitePlaca(char ingreso[]).
				7. void inactivarTaxi(char ingreso[]).
				8. void activarTaxi(char ingreso[]).
	
	User: 
				1. void solicitarTaxi().
				
	Descriptions bellow, before each function's code. 
*/

/*
	MAP AND LOGO
*/
void desplegarLogo();
void visualizarTaxis();
void visualizarTaxis(char ingreso[]); 
void visualizarCuadrante(int calle, int carrera);
void desplegarMapa();
void inicializarMapa(taxi mapa[3][5][3]);
/*
	TAXIS 
*/
void registrarTaxis(int cantidad);
void moverTaxi(char ingreso[]);
bool verificarRegistro();
int ingresarNumero(char ingreso[]);
bool verificarPlaca(char ingreso[]); 
bool repitePlaca(char ingreso[]);
void inactivarTaxi(char ingreso[]);
void activarTaxi(char ingreso[]);
/*
	USER
*/
void solicitarTaxi();

/*
	SIGNIFICANT VARIABLES
*/
/*
	Agency : Reference of a taxi. 
	
	User : Controls everything from the user's view. 
	
	Map : The software's map. [3] : Taxis per zone. [5] : Horizontal Coordinate. [3] : Vertical Coordinate. 
*/
taxi Agencia;
usuario Usuario; 
taxi mapa[3][5][3];
int main(){
	/*
		Deployment and color configuration of the interface.
	*/
	desplegarLogo();
	system("color E0");
	
	//Variables for the different inputs.
	char opcion,ingreso[90],cantidad=0; 
	int eliminar=0;
	
	do{
		//Initialize the map.
		inicializarMapa(mapa);
		
		system("color E0");
		
		//Prints the menu.
		cout<<"같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같\n  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  ";
		cout<<"\n LUXURY TAXIS \n\n\n\n\t\t\t\t   .: Menu :.\n\nPress\nEnter. To Register taxis (Action only once)\n1. Visualize the Taxis' Information\n2. To Visualize the City's map\n3. Activate a Taxi\n4. Inactivate a Taxi\n5. Request a taxi service\n6. Consult a specific taxi\n7. Consult a specific zone\n8. Move a Taxi from zone\n Three times 0 to delete the Taxis' Register\nEsc Exit\n";
		cout<<"\n같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같\n  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  ";				
		opcion=getch();
		system("cls"); 
		switch(opcion){
			case ENTER:{
				if(verificarRegistro()==false){
					do{ 
						cout<<"\nEnter the quantity of Taxis: ";
						cin.getline(ingreso,90);
						cantidad=ingresarNumero(ingreso); 
						if(cantidad==-1)
							cout<<"\nWrong quantity, please enter it again"; 
					}while(cantidad==-1); 
					registrarTaxis(cantidad); 
				}
				else{
					cout<<"\nTaxis Already Registered\n";
				}									
				break;
			}
			case '1':{
				if(verificarRegistro()){
					visualizarTaxis();
				}
				else
					cout<<"\nYou haven't registered taxis'\n";
				break;
			}
			case '2':{
				desplegarMapa();		
				break;
			}
			case '3':{
				if(verificarRegistro()){
					do{
						cout<<"\nEnter the taxi's license plate to activate: " ;
						cin.getline(ingreso,90);
						if(verificarPlaca(ingreso))
							cout<<"This license plate is not valid, please enter a valid plate\n"; 
					}while((verificarPlaca(ingreso)));	
					activarTaxi(ingreso);
				}
				else
					cout<<"\nYou haven't registered taxis'\n";
				break;
			}
			case '4':{
				if(verificarRegistro()){
					do{
						cout<<"\nEnter the taxi's license plate to inactivate: " ;
						cin.getline(ingreso,90);
						if(verificarPlaca(ingreso))
							cout<<"This license plate is not valid, please enter a valid plate\n";
					}while((verificarPlaca(ingreso)));	
					inactivarTaxi(ingreso);
				}
				else
					cout<<"\nYou haven't registered taxis'\n";
				break;
			}
			case '5':{
				if(verificarRegistro()){
					solicitarTaxi();
				}
				else
					cout<<"\nWe are sorry, there are no taxis registered\n";
				break;
			}
			case '6':{
				if(verificarRegistro()){
					do{
						cout<<"\nEnter the taxi's license plate:  " ;
						cin.getline(ingreso,90);
						if(verificarPlaca(ingreso))
							cout<<"This license plate is not valid, please enter a valid plate\n";
					}while((verificarPlaca(ingreso)));	
					visualizarTaxis(ingreso);
				}
				else
					cout<<"\nYou haven't registered taxis'\n";
				break;
			}
			case '7':{
				if(verificarRegistro()){
							
					//Inserts and validates the Calle  
					int numero; 
					do{
						cout<<"\n\nCalle\nEnter the Calle: ";
						cin.getline(ingreso,90);
						numero=ingresarNumero(ingreso); 
						if(numero==-1||numero>3)
						cout<<"\nIncorrect Calle"; 
					}while(numero==-1||numero>3);
					int calle=numero; 
			
					//Inserts and validates the Carrera  
					do{
						cout<<"\n\nCarrera\nEnter the Carrera: ";
						cin.getline(ingreso,90);
						numero=ingresarNumero(ingreso); 
						if(numero==-1||numero>5)
							cout<<"\nIncorrect Carrera"; 
					}while(numero==-1||numero>5);
					int carrera=numero; 
					
					//Deploys the selected zone
					visualizarCuadrante(calle-1,carrera-1);
				}
				else{
					cout<<"\nYou haven't registered taxis'\n";
				}		
				break;
			}
			case '8':{
				if(verificarRegistro()){
					do{
						cout<<"\nEnter the taxis' license plate to move:  " ;
						cin.getline(ingreso,90);
						if(verificarPlaca(ingreso))
							cout<<"This license plate is not valid, please enter a valid plate\n";
					}while((verificarPlaca(ingreso)));		
				}
				else{
					cout<<"\nYou haven't registered taxis'\n";
				}			
				moverTaxi(ingreso);
				break;
			}
			case '0':{
				eliminar++;
				if(eliminar==3){
					eliminar=0; 
					FILE *archivo=fopen("Agencia","r");
					if (verificarRegistro()==false){
		 				cout<<"\nThere is not Taxis' register to delete\n";
		 				fclose(archivo); 
						system("pause"); 
						system("cls"); 
		 				break; 
	 				}
					else{
						cout<<"Are you sure you want to delete the taxis' register?\nPress 1 for Yes\nPress another key for No";
						char opc=getch();
						if(opc=='1'){
							for(int i=0;i<3;i++){
								system("cls");
								cout<<"Deleting\n";
								for(int j=0;j<5;j++){
									cout<<". ";
									Sleep(85);  
								}
							}					
							cout<<"\nRegister Deleted successfully\n";
         	     	 		fclose(archivo);
		     				system("del Agencia");
		     				system("pause"); 
							//Initalize the map with the new configuration.
							inicializarMapa(mapa); 			
						}
						fclose(archivo);
						system("cls"); 	
						break; 	
					}			
				}	
				break;
			}
			case ESCAPE:{
				cout<<"\nProgram finished, have a nice day ^-^\n";
				break;
			}
			default:{
				cout<<"\nNon valid option, please enter a correct option\n"; 
				break;
			}
		}
		if(opcion!='0'){
			//Pause the console and clean the screen.
			system("pause");
			system("cls"); 
			eliminar=0; 
		}
	}while(opcion!=ESCAPE);
	return 0; 
}
/*
	Description : Deploys the Company's logo. 
*/
void desplegarLogo(){
	
	system("color E0");	
	cout<<"같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같";
	cout<<"\n  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같";
	cout<<"같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  \n";	
	cout<<"\t\t\t	 .----------------. \n";
	cout<<"\t\t\t	| .--------------. |\n";
	cout<<"\t\t\t	| |  _________   | |\n";
	cout<<"\t\t\t	| | |  _   _  |  | |\n";
	cout<<"\t\t\t	| | |_/ | |  \_|  | |\n";
	cout<<"\t\t\t	| |     | |      | |\n";
	cout<<"\t\t\t	| |    _| |_     | |\n";
	cout<<"\t\t\t	| |   |_____|    | |\n";
	cout<<"\t\t\t	| |              | |\n";
	cout<<"\t\t\t	| '--------------' |\n";
	cout<<"\t\t\t 	'------------------' \n";
	cout<<"\n\t\t\t            LUXURY TAXIS";
	cout<<"\n\n\t\t\t \t      Elegant\n\t\t\t \t       Fast\n\t\t\t \t      Simple\n\n";
	cout<<"같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같";
	cout<<"\n  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같";
	cout<<"같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  같  ";
	getch();
	system("cls");
}
/*
	Description : Deploys the taxis' information.
*/
void visualizarTaxis(){
	
 	//Opens the file meant for containing the program's data.
	FILE *archivo = fopen("Agencia", "r");
	
	//Controls the inexistence of taxis. 
	if(archivo == NULL){
		
		cout<<"\nYou haven't registered Taxis'";
		fclose(archivo); 
		return;
	}
	
	//Prints the Taxis. 
	int contador= 1;
	fread(&Agencia, sizeof(struct taxi), 1, archivo);
	cout<<"\n\tPlate\t  type\t     Capacity"<<setw(22)<<"Calle    Carrera  "<<setw(10)<<"Activity";
	while(!feof(archivo)){
		
		cout<<"\n"<<contador<<"\t"<<Agencia.Placa<<"\t  ";
		if(Agencia.Tipo==1)
			cout<<"Automobile";
		else
			cout<<"Van      ";
		cout<<setw(3)<<Agencia.Capacidad<<setw(14)<<Agencia.Calle<<"\t   "<<Agencia.Carrera<<"\t     ";
		if(Agencia.Activo){
			if(Agencia.Libre)
				cout<<"Available  ";
			else
				cout<<"Unavailable "; 
		}
		else
			cout<<"Inactive";
				
		fread(&Agencia, sizeof(struct taxi), 1, archivo);	
		contador++;
	}
 	cout<<"\n";

 	//Closes the file.
	fclose(archivo);
}
/*
	Description : Deploys the information of a specific taxi. 
	Input : The taxi's plate. 
*/
void visualizarTaxis(char ingreso[]){
	
 	//Opens the file meant for containing the program's data.	
	FILE *archivo = fopen("Agencia", "r");
	fread(&Agencia, sizeof(struct taxi), 1, archivo);
	
	//Searches the specific taxi, verifying its searching.
	bool exito=false; 
	while(!feof(archivo)){
				
		if(strcmp(Agencia.Placa,ingreso)==0){
			
			cout<<"\n\tPlate\t  type\t     Capacity"<<setw(22)<<"Calle    Carrera  "<<setw(10)<<"Activity";
			cout<<"\n   \t"<<Agencia.Placa<<"\t  ";
			if(Agencia.Tipo==1)
				cout<<"Automobile";
			else
				cout<<"Van      ";
			cout<<setw(3)<<Agencia.Capacidad<<setw(14)<<Agencia.Calle<<"\t   "<<Agencia.Carrera<<"\t     ";
			if(Agencia.Activo){
				
				if(Agencia.Libre)
					cout<<"Available  ";
				else
					cout<<"Unavailable "; 
			}
			else
				cout<<"Inactive";
			exito=true; 
		}
		fread(&Agencia, sizeof(struct taxi), 1, archivo);	
	}
 	cout<<"\n\n\n";	
 	
	//Closes the file.
	fclose(archivo);
	//If the search fails, deploys a message.
	if(exito==false){
		cout<<"\nPlate not found\n"; 	
	}
}
/*
	Description : Deploys the zone with the given coordinates.
	Input : Calle and Carrera.	
*/
void visualizarCuadrante(int calle, int carrera){
	//Creates the pattern for the information's deployment.
	cout<<"\n\tPlate\t  type\t     Capacity"<<setw(22)<<"Calle    Carrera  "<<setw(10)<<"Activity";
	
	//For each automobile, sets the logic for printing its information.
	for(int i=0;i<3;i++){
		cout<<"\n"<<i+1;
		if(mapa[calle][carrera][i].Placa[0]!=' '){
			cout<<"\t"<<mapa[calle][carrera][i].Placa<<"\t  ";
			if(mapa[calle][carrera][i].Tipo==1)
				cout<<"Automobile";
			else
				cout<<"Van      ";
			cout<<setw(3)<<mapa[calle][carrera][i].Capacidad<<setw(14)<<mapa[calle][carrera][i].Calle<<"\t   "<<mapa[calle][carrera][i].Calle<<"\t     ";
			if(mapa[calle][carrera][i].Activo){
				
				if(Agencia.Activo){
					
					if(mapa[calle][carrera][i].Libre)
						cout<<"Available  ";
					else
						cout<<"Unavailable "; 
				}	
			}
			else
			cout<<"Inactive";	
		}	
	}
	cout<<"\n\n";
}
/*
	Description : Verifies the correct input of a given license plate.
	Input : The license plate to be verified. 
	Output : A boolean which represents whether a license plate is
			 well typed or not (False is well typed, True is wrong typed).
*/
bool verificarPlaca(char ingreso[]){
	//Verifies the quantity of characters.
	if(strlen(ingreso)!=7){
		return true; 
	}
	
	//Verifies the alphabetic characters of the input.
	for(int i=0;i<3;i++){
		if(isalpha(ingreso[i])==false)
			return true;
		else
			ingreso[i]=toupper(ingreso[i]);
	}
	
	//Verifies the hyphen of the input (position and existence).
	if(ingreso[3]!='-')
		return true; 
	
	//Verifies the numeric characters of the input.
	for(int i=4;i<7;i++){
		if(isdigit(ingreso[i])==false)
			return true;
	}
	return false;
}
/*
	Description : Verifies the uniqueness of a given license plate.
	Input : The license plate to be verified. 
	Output : A boolean which represents whether a license plate is repeated or not 
			 (False means it is a new plate, True means it is a repeated plate).	
*/
bool repitePlaca(char ingreso[]){
	FILE *archivo = fopen("Agencia", "r");

	//Verifies the existence of the file.
	if(archivo == NULL){
		return false;
	}
	else{
		//Compares every plate in the file with the given plate.
		fread(&Agencia, sizeof(struct taxi), 1, archivo);
		while(!feof(archivo)){
			if(strcmp(Agencia.Placa,ingreso)==0)
					return true; 
			fread(&Agencia, sizeof(struct taxi), 1, archivo);	
		}
	}
	fclose(archivo);
	return false;
}
/*
	Description : Registers a given quantity of taxis.
	Input : Quantity of taxis the user wants to register.
*/
void registrarTaxis(int cantidad){	
	//Variables meant for the input and its validation.
	char ingreso[90];
	int  ubicacion; 
	bool validacion; 
	for(int i=0;i<cantidad;i++){
		
		system("cls"); 
		
		//Opens the file meant for containing the program's data.
		FILE *archivo= fopen("Agencia", "a");	
		
		//Input for the Calle and Carrera.
		int numero=0; 
		
		//Taxi's default activation. 	
		Agencia.Activo=true; 
		Agencia.Libre=true; 
		Agencia.Tiempo=0; 
		
		//License plate input, it verifies the correct input and the uniqueness of it.
		do{
			cout<<"\nTaxi Number: "<<i+1<<"\nEnter the License Plate (3 Letters \"-\" 3 Numbers): ";
			cin.getline(ingreso,90);
			if(verificarPlaca(ingreso))
				cout<<"The plate isn't valid\n";
			if(repitePlaca(ingreso))
				cout<<"The plate is already registered\n";
		}while(verificarPlaca(ingreso)||repitePlaca(ingreso));
		for(int j=0;j<7;j++)
			Agencia.Placa[j]=ingreso[j];
		
		//Vehicle type input, it verifies the correct input. 
		do{
			cout<<"\n\nTaxi Type\nPress:\n1.For Automobile\n2.For Van";
			ingreso[0]=getch();
			if(isdigit(ingreso[0])==false||(ingreso[0]!='1'&&ingreso[0]!='2'))
				cout<<"\nThe input isn't valid\n";	
		}while(isdigit(ingreso[0])==false||(ingreso[0]!='1'&&ingreso[0]!='2'));
		Agencia.Tipo=ingreso[0]-48;
		
		//Capacity input (passengers), it verifies the correct input.
		do{
			cout<<"\n\nPassengers' Capacity:\nPress the quantity of passengers(Maximum 9)";
			cin.getline(ingreso,90);
			numero=ingresarNumero(ingreso); 
			if((numero==-1||(numero>4&&Agencia.Tipo==1)||numero>9))
				cout<<"\nThe input isn't valid\n";	
		}while((numero==-1||(numero>4&&Agencia.Tipo==1)||numero>9)); 
		Agencia.Capacidad=ingreso[0]-48;
		
		
		do{
			validacion=true;
			
			//Taxi's Calle, it verifies the correct input.
			do{
				cout<<"\n\nCalle\nEnter the Calle (from 1 to 3): ";
				cin.getline(ingreso,90);
				numero=ingresarNumero(ingreso); 
				if(numero==-1||numero>3)
					cout<<"\nThe input isn't valid"; 
			}while(numero==-1||numero>3);
			Agencia.Calle=numero;
			
			//Taxi's Carrera, it verifies the correct input.
			do{
				cout<<"\n\nCarrera\nEnter the Carrera (from 1 to 5): ";
				cin.getline(ingreso,90);
				numero=ingresarNumero(ingreso); 
				if(numero==-1||numero>5)
					cout<<"\nThe input isn't valid"; 
			}while(numero==-1||numero>5);
			Agencia.Carrera=numero;
			
			//Verifies the abailability of the selected zone (Carrera, Calle). 
			for(ubicacion=0;ubicacion<3;ubicacion++){
				if(mapa[Agencia.Calle-1][Agencia.Carrera-1][ubicacion].Placa[0]==' '){
					validacion=false;
					
					//Puts the taxi on the map and exits from the cycle.
					mapa[Agencia.Calle-1][Agencia.Carrera-1][ubicacion] = Agencia;
					break;
				}
			}
			if(validacion){
				cout<<"\nThis location has reached the maximum capacity of taxis\n";
			}
		}while(validacion);
		
		//Writes the taxi on the file and closes it.
		fwrite(&Agencia, sizeof(struct taxi), 1, archivo);
		fclose(archivo);
	}
}
/*
	Description : Moves to another zone a given taxi [Coordinates X and Y].
	Input : License plate of the taxi.
*/
void moverTaxi(char ingreso[]){
	bool limite,validacion=true; 
	int calle,carrera; 
	char mov; 
	
 	//Opens the file meant for containing the software's data.
	FILE *archivo= fopen("Agencia","r+b");	
	fread(&Agencia, sizeof(struct taxi), 1, archivo);
		
	while(!feof(archivo)){
		if(strcmp(Agencia.Placa,ingreso)==0){
			do{
				calle = 0; 
				carrera = 0;
				limite = false;
				cout<<"\nPlate found!\nPress to move the vehicle: \nW. One zone up\nS. One zone down\nD. One zone right\nA. One zone left"	;
				mov=getch();
				mov=toupper(mov);
				//Verifies the input of the user.
				if(mov!='W'&&mov!='A'&&mov!='S'&&mov!='D'){
					cout<<"\nThe input isn't valid\n";
				}
				//Verifies that the vehicle doesn't move beyond the map's bounds.
				else{
					switch(mov){
						case 'W':{
							limite=((Agencia.Calle-1)==0); 
							calle= Agencia.Calle-1;
							carrera=Agencia.Carrera;
							break;
						}
						case 'A':{
							limite=((Agencia.Carrera-1)==0);
							calle= Agencia.Calle;
							carrera=Agencia.Carrera-1; 
							break;
						}
						case 'S':{
							limite=((Agencia.Calle-1)==2); 
							calle= Agencia.Calle+1;
							carrera=Agencia.Carrera;
							break;
						}
						case 'D':{
							limite=((Agencia.Carrera-1)==4); 
							calle= Agencia.Calle;
							carrera=Agencia.Carrera+1;
							break;
						}
					}
					if(limite){
						cout<<"\nTrying to move the vehicle out of the map's bounds\n"; 	
					}	
				}		
			}while(mov!='W'&&mov!='A'&&mov!='S'&&mov!='D'||limite);	
			
			//Verifies whether the vehicle has the space to move into the selected zone.		 
			for(int ubicacion=0;ubicacion<3;ubicacion++){ 
				if(mapa[calle-1][carrera-1][ubicacion].Placa[0]==' '){
					validacion=false;
					break;
				}
			}
			if(validacion){
				cout<<"\nThis zone has reached the limit of taxis\n";
				fclose(archivo); 
				return; 
			}
			
			
			for(int i=0;i<3;i++){
				system("cls");
				cout<<"Processing Request\n";
				for(int j=0;j<5;j++)
				{
					cout<<". ";
					Sleep(50);  
				}
    		}
    		//Setting the new zone of the vehicle.
    		Agencia.Calle=calle;
    		Agencia.Carrera=carrera; 
			fseek(archivo,-1*sizeof(Agencia),SEEK_CUR);
         	fwrite(&Agencia, sizeof(Agencia), 1, archivo);
         	fclose(archivo);
        	cout<<"\nThe taxi has moved successfully\n";
			return;  
		}	
		fread(&Agencia, sizeof(struct taxi), 1, archivo);
	}
 	//Closes the file.
	fclose(archivo);
	cout<<"\nLicense plate not found\n"; 			
}
/*
	Description : Changes the current state of activeness of a given taxi to inactive.
	Input : License plate of the taxi.
*/
void inactivarTaxi(char ingreso[]){	
	for(int i=0;i<3;i++){
		system("cls");
		cout<<"Processing Request\n";
		for(int j=0;j<5;j++){
			cout<<". ";
			Sleep(50);  
		}
    }
    
 	//Opens the file meant for containing the software's data.
	FILE *archivo= fopen("Agencia","r+b");	
	fread(&Agencia, sizeof(struct taxi), 1, archivo);
	
	//Searches the introduced plate.	
	while(!feof(archivo)){
		if(strcmp(Agencia.Placa,ingreso)==0){
			
			//Once the plate is found, it changes the taxi's state from active to inactive.
			if(Agencia.Activo&&Agencia.Libre){
				Agencia.Tiempo=0; 
				Agencia.Activo= false;
				Agencia.Libre=false; 
				fseek(archivo,-1*sizeof(Agencia),SEEK_CUR);
         		fwrite(&Agencia, sizeof(Agencia), 1, archivo);
         		fclose(archivo);
         		cout<<"\nThe taxi has inactivated successfully\n";
				return;  
			}
			
			//If it finds the taxi but the taxi is already inactive or busy, it prints the message.
			else{
				if(Agencia.Activo==false)
					cout<<"\nThe taxi is already inactive\n";
				if(Agencia.Libre==false)
					cout<<"\nThe taxi is already giving a service\n";  
				return;	
			} 
		}	
		fread(&Agencia, sizeof(struct taxi), 1, archivo);
	}
 	//Closes the file
	fclose(archivo);
	cout<<"\nLicense plate not found\n"; 		
}
/*
	Description : Changes the current state of activeness of a given taxi to active.
	Input : License plate of the taxi.
*/
void activarTaxi(char ingreso[]){
	for(int i=0;i<3;i++){
		system("cls");
		cout<<"Processing Request\n";
		for(int j=0;j<5;j++){
			cout<<". ";
			Sleep(50);  
		}
    }
    
 	//Opens the file meant for containing the software's data.
	FILE *archivo= fopen("Agencia","r+b");
	fread(&Agencia, sizeof(struct taxi), 1, archivo);
	
	//Searches the introduced plate.		
	while(!feof(archivo)){
		if(strcmp(Agencia.Placa,ingreso)==0){
			
			//Once the plate is found, it changes the taxi's state from inactive to active. 
			if(Agencia.Activo==false||Agencia.Libre==false){
				Agencia.Tiempo=0; 
				Agencia.Activo= true;
				Agencia.Libre=true; 
				fseek(archivo,-1*sizeof(Agencia),SEEK_CUR);
         		fwrite(&Agencia, sizeof(Agencia), 1, archivo);
         		fclose(archivo);
         		cout<<"\nThe taxi has activated successfully\n";
				return;  
			}
			
			//If it finds the taxi but the taxi is already active, it prints the message.
			else{
				cout<<"\nThe taxi is already active\n";  
				return;	
			}  
		}	
		fread(&Agencia, sizeof(struct taxi), 1, archivo);
	}
  	//Closes the file
	fclose(archivo);
	cout<<"\nLicense plate not found\n"; 		
}
/*
	Description : Deploys the map of the software with the current taxis (active and available taxis).
*/
void desplegarMapa(){
	//Color configuration and printing.
	system("color f0");
	cout<<"\n\t\t\t\tCITY MAP\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";	
    for(int i=0;i<3;i++){
		cout<<"\n\n    같같같같�      같같같같�      같같같같�      같같같같�      같같같같�";		
		for(int j=0;j<3;j++){
			cout<<"\n    "; 
			for(int k=0;k<5;k++){
				//Prints every plate where the taxi is currently.
				cout<<"�"<<mapa[i][k][j].Placa<<"�      ";  
			}
		}
		cout<<"\n    같같같같�      같같같같�      같같같같�      같같같같�      같같같같�\n"; 
	} 
	cout<<"\n\n";                           
}
/*
	Description : Verifies the existence of the file meant for controlling the automobiles.
	Output : A boolean which determines the existence of the file (True if it existe, False if it doesn't).
*/
bool verificarRegistro()
{
	//Verifies the existence of the file by trying to open it.
	FILE *archivo= fopen("Agencia", "r");
 	if(archivo==NULL){
 		fclose(archivo);
 		return false; 	
	}
	else{	
 		fclose(archivo);
 		return true;
	} 
}
/*
	Description : Sets the information inside the map by initializing the values or
	              loading the existing information if it exists. 
	Input : The software's map.
*/
void inicializarMapa(taxi mapa[3][5][3]){
	int ubicacion; 
	//Sets the initial configuration of the map. 
	for(int i=0;i<3;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<7;l++){
						mapa[i][j][k].Placa[l]=' '; 
					}
					mapa[i][j][k].Tipo=0;
					mapa[i][j][k].Capacidad=0; 
					mapa[i][j][k].Carrera=0; 
					mapa[i][j][k].Calle=0;  
					mapa[i][j][k].Activo=true; 
					mapa[i][j][k].Libre=true; 
					mapa[i][j][k].Tiempo=0; 
			}
		}
	}
	//If there is already information in the file, it loads it in the map.
	for(int i=0;i<3;i++){
		for(int j=0;j<5;j++){
				FILE *archivo = fopen("Agencia", "r");
				//If the file doesn't exist nothing is done.
				if(verificarRegistro()==false){
					fclose(archivo); 
				}
				else{
					fread(&Agencia, sizeof(struct taxi), 1, archivo);
					while(!feof(archivo)){
						//Sets the taxis' information depending on the location. 		
						if(Agencia.Calle-1==i&&Agencia.Carrera-1==j){
							for(ubicacion=0;ubicacion<3;ubicacion++){
								if(mapa[Agencia.Calle-1][Agencia.Carrera-1][ubicacion].Placa[0]==' '){
									//Puts the taxi on the map if it is active and available. 
									if(Agencia.Activo&&Agencia.Libre){
										mapa[Agencia.Calle-1][Agencia.Carrera-1][ubicacion]=Agencia;
										break;	
									}			
								}
							}
						}
						fread(&Agencia, sizeof(struct taxi), 1, archivo);
					}
				}
 				//Closes the file.
				fclose(archivo);
		}
	}
}
/*
	Description : Verifies the correct input and returns the char[] input to an integer type.
	Input : Char Array to parse.
	Output : Parsed Array.
*/
int ingresarNumero(char ingreso[]){
	int retorno;
	//If there is one digit.
	if(strlen(ingreso)==1){ 
		//Verifies if the input is a digit and different from zero.
		if(isdigit(ingreso[0])==false||(ingreso[0]=='0'))
			retorno=-1;
		else
			retorno=ingreso[0]-48; 
	}	
	//If there are two digits.
	else if(strlen(ingreso)==2){ 	
		//Verifies if the input is composed with only digits and different from zero.
		if(isdigit(ingreso[0])==false||isdigit(ingreso[1])==false||(int)(((ingreso[0]-48)*10)+(ingreso[1]-48))==0)
				retorno=-1;
		else
			retorno=(((ingreso[0]-48)*10)+(ingreso[1]-48));
	}
	else{
		retorno=-1; 
	}
	return retorno; 
}
/*
	Description : Request a taxi by entering the user's preferences, changing every variable
				  necessary for executing the operation.
*/
void solicitarTaxi(){
	//Variable para guardar el taxi mas apropiado para la operacion; 
	taxi Seleccionado; 
	Seleccionado.Placa[0]='0'; 
	
	char ingreso[90];
	int  ubicacion,numero,diferenciaActual=0,diferenciaMenor=99;  
	cout<<"Welcome!\nPlease insert your location:\n";
	//User's Calle, it verifies the correct input.
	do{
		cout<<"\n\nEnter the Calle (from 1 to 3): ";
		cin.getline(ingreso,90);
		numero=ingresarNumero(ingreso); 
		if(numero==-1||numero>3)
			cout<<"\nWrong Calle\nEnter a valid Calle please\n "; 
	}while(numero==-1||numero>3);
	Usuario.Calle=numero;
	
	//User's Carrera, it verifies the correct input.
	do{
		cout<<"\n\nEnter the Carrera (from 1 to 5): ";
		cin.getline(ingreso,90);
		numero=ingresarNumero(ingreso); 
		if(numero==-1||numero>5)
			cout<<"\nWrong Carrera\nEnter a valid Calle please\n"; 
	}while(numero==-1||numero>5);
	Usuario.Carrera=numero;
	
	//Vehicle type input, it verifies the correct input. 
	do{
		cout<<"\n\nWhich type of taxi de you need?\nPress\n1.For Automobile\n2.For Van";
		ingreso[0]=getch();
		if(isdigit(ingreso[0])==false||(ingreso[0]!='1'&&ingreso[0]!='2'))
			cout<<"\nWrong input, please enter again\n";	
	}while(isdigit(ingreso[0])==false||(ingreso[0]!='1'&&ingreso[0]!='2'));
	Usuario.Tipo=ingreso[0]-48;
	
	//Capacity input (passengers), it verifies the correct input.
	do{
		cout<<"\n\nHow many passengers are you going to request?\nEnter the quantity of passengers: ";
		cin.getline(ingreso,90);
		numero=ingresarNumero(ingreso); 
		if((numero==-1||(numero>4&&Agencia.Tipo==1)||numero>9))
			cout<<"\nWrong input, please enter again\n";	
	}while((numero==-1||(numero>4&&Agencia.Tipo==1)||numero>9));
	Usuario.Pasajeros=ingreso[0]-48;
	
	for(int i=0;i<3;i++){
		system("cls");
		cout<<"Processing Request\n";
		for(int j=0;j<5;j++)
		{
			cout<<". ";
			Sleep(70);  
		}
    }
    
	//Opens the file meant for containing the program's data.
	FILE *archivo= fopen("Agencia","r");	
	fread(&Agencia, sizeof(struct taxi), 1, archivo);
	
	//Selects the best option for picking a taxi.	
	while(!feof(archivo)){
		//Picks the User's preferences.
		if(Usuario.Tipo==Agencia.Tipo&&Usuario.Pasajeros<=Agencia.Capacidad&&Agencia.Activo&&Agencia.Libre){
			//Picks the best option based on the user's location.
			diferenciaActual=abs(Usuario.Calle-Agencia.Calle)+abs(Usuario.Carrera-Agencia.Carrera);
			if(diferenciaMenor>=diferenciaActual){
				diferenciaMenor=diferenciaActual; 
				if( Seleccionado.Placa[0]=='0'){
					Seleccionado=Agencia; 
				}
				else{
					//Discriminates with the time of the picked car.
					if(Seleccionado.Tiempo>=Agencia.Tiempo){
						Seleccionado=Agencia; 
					}
				}	
			}
		}
		fread(&Agencia, sizeof(struct taxi), 1, archivo);
	}
	fclose(archivo);
	//Selects a taxi if there is a taxi available depending on the user's preferences.
	if( Seleccionado.Placa[0]=='0'){
		cout<<"\nWe are sorry, there are not taxis available for your necesities\n"; 
	}
	else{
		//Increases the taxis' time and refreshes the state of the selected taxis. 
		archivo= fopen("Agencia","r+b");
		fread(&Agencia, sizeof(struct taxi), 1, archivo);
		
		while(!feof(archivo)){
			if(strcmp(Agencia.Placa,Seleccionado.Placa)==0){
				Agencia.Tiempo=0; 
				Agencia.Libre=false; 
				fseek(archivo,-1*sizeof(Agencia),SEEK_CUR);
      		   	fwrite(&Agencia, sizeof(Agencia), 1, archivo);
      		   	cout<<"\nThe taxi "<<Agencia.Placa<<" Will pick you up\n";
      		   	fclose(archivo);
      		   	return; 
			}	
			fread(&Agencia, sizeof(struct taxi), 1, archivo);
		}
		//Closes the file.
		fclose(archivo);		
	}
}
