# Luxury Taxis :taxi:
#### Gabriel Esteban Castillo 
#### Andres Felipe Peralta
#### Andres Felipe Perez
### Introduction
Administrate the Taxis service Luxury Taxis, register, activate, move taxis, consult information
and request a service which best fits to the customer's preferences.

### General information
Each taxi has the next information:

1. License plate. Example : ABC-123
2. Type. 1 (Automobile), 2 (Van).
3. Capacity. Example : 3 people.
4. Calle. Example : Calle 2 [Y Coordinate].
5. Carrera. Example : Carrera 3 [X Coordinate].
6. Time. Example : 3 times the taxi hasn't received a service.
7. Active. Example : Active for receiving services [Could be busy with a customer]. 
8. Free. Example : Able for receiving clients. 

Each user has the next information, this information is related to the taxi 
to be requested:

1. Type. Example : 1 (Automobile).
2. Pasengers. Example : 3 customers.
3. Calle. Example : Calle 2 [Y Coordinate].
4. Carrera. Example : Carrera 3 [X Coordinate].

The map of the city is basically defined with coordinates, each pair of 
coordinates is referenced as zones, the city has 5 carreras and 3 calles:

<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">

The Calles increases from top to bottom and the Carreras from left to right. For example the vehicle ZZZ-243 is located in
the calle 2 and the carrera 3.

### User's guide
In this section we are going to explain the different interactions the user is able to do in this software.

#### Registering the taxis
This action can be done only once, although, you can delete the register and do it once again,
you can register the number of taxis that you need ( consider the fact that a zone contains maximum 3
taxis at the same time, meaning 45 taxis in total ).
After the number of taxis is typed, you will be requested to fill the information of each taxi.

<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">

#### Visualize the taxis' information
You can visualize the complete information of the registered taxis including their activity, plate, type, capicity and location.

<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">

#### Visualize the map
As seen before, the user can see the location of active taxis, printing the zone they are located at the moment of executing the
option. 

#### Activating or inactivating a taxi
Activating or inactivating a taxi sets the avaialability of a taxi to offer the service.

<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">
<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">

#### Consulting a specific taxi
Consult the information of an specific taxi by inserting its license plate.

<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">

#### Consulting a specific zone
Consult the information of an specific zone by inserting its calle and carrera.

<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">

#### Moving a taxi from zone
Take a registered taxi and move it, you can choose where to move it by pressing W,A,R os D.

<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">

Map Changed
<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">

#### Deleting the taxis
If you press three times 0, a verification message will appear, at the moment you press 1, the taxis will be
deleted. 

<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">

#### Request a service
You can request a taxi by entering your preferences to request a taxi, the software will send a message whether 
a taxi is available based on these preferences or not.

<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">
<img src="https://user-images.githubusercontent.com/43209755/60149719-4b444080-979b-11e9-981c-fa76689d7db6.png" width="560">



### Software structure
The software uses only a language which is C++.

#### Concepts used
This software uses the following concepts:
1. Data structures.
2. Arrays and multidimensional Matrixes.
3. Functions.
4. Files manipulation.

#### Visualization and its interaction 
The interface is displayed in console and with the help of 'iomanip.h' by configuring the colors and
patterns of printing.
The interaction is a menu which has different options to execute the different actions mentioned in
the user's guide, every function is called depending on the selected case. 

#### Functionality
Every action mentioned has specific structures which are managed with common structures, these are:
1. The city's map, which contains the information of every taxi.
2. A user that works as reference to introduce information.
3. A taxi that also works as reference to introduce information.
4. An array containing the license plate of a vehicle.

Those elements are used in different situations, these structures are located in the main() function,
so the functions in charge of specific tasks can treat the incoming information.

In addition, each action mentioned in the user's guide has its own function, except for others that
support the functions mentioned or to initialize values, these functions are:
* bool verificarPlaca(char ingreso[]).
* bool repitePlaca(char ingreso[]).
* bool verificarRegistro().
* void inicializarMapa(taxi mapa[3][5][3]).
* int ingresarNumero(char ingreso[]).

Other function work as the visual presentation, this function is:
* void desplegarLogo().

The other functions work as the principal functions of the software and are the actions executed
by the user:
* void visualizarTaxis().
* void visualizarTaxis(char ingreso[]).
* void visualizarCuadrante(int calle, int carrera).
* void desplegarMapa().
* void registrarTaxis(int cantidad).
* void moverTaxi(char ingreso[]).
* void inactivarTaxi(char ingreso[]).
* void activarTaxi(char ingreso[]).
* void solicitarTaxi().

Each function has a description (input and output if it is necessary) inside the file 
"LuxuryTaxis.cpp" which can be opened with a text editior, it contains detailed information 
and the source code of the software. 


### Execution
By cloning this repository, the user will only has to double click the "LuxuryTaxis" executable file and the software will deploy.
DO NOT REMOVE THE "Agencia" file, this files saves the information of the taxis, without it, the software will not work.
