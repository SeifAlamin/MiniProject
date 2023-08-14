/*
 ============================================================================
 Name        : miniproject.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Data {
	char Lights;
	int RoomTemp;
	int EngiTem;
	int Speed;
	char On , On_1;
	char engine;
};
struct Data Car1={'G' , 25 , 125 , 0 , 0 , 0 , 0 };




void TrafficLights(char input);   // ALL THE FUNCTION I HAVE USED
void RoomTemperature(int input);  // **************************
void RoomTemperture2(void);       // **************************
void EngineTemperature(int input);// **************************
void EngineTemperature2(void);
void repeat(char input);
void repeat2(char input);
void printstate(void);


void Ask(void){// this is the first input that the user will chose from .
	printf("a-Turn on the vehicle engine\n");
	printf("b-Turn off the vehicle engine\n");
	printf("c-Quit the system\n\n");
}

void Ask2(void){//this is the second input that the user will chose from .
	printf("a-Turn off the engine\n");//these for sensors set menu
	printf("b-Set the traffic light color\n");
	printf("c-Set the room temperature\n");
	printf("d-Set the engine temperature\n");
}

void  ChooseTheProgram(char input){// this function is for available options

	switch(input){
	case 'c':printf("You quitted the program\n");break;
	case 'b':printf("You turned off ur engine\n\n");break;
	case 'a':printf("You Turned on your engine\n\n");break;
	}
}
void SensorsSetMenu(char input){//this function is used to set up the sensors settings
	char value;
	if(input == 'a'){
		Car1.engine=1;
		Ask2();
		scanf(" %c",&value);
		switch(value){
		case 'a':
			input = 'b' ;
			Car1.engine=0;printf("Engine is OFF\n\n");
			repeat(input);return;
		case'b':
			printf("Enter ur traffic light:\n");
			TrafficLights(Car1.Lights);
			break;
		case 'c':
			printf("Enter your temperature:\n");
			RoomTemperature(Car1.RoomTemp);
			break;
		case 'd':
			printf("Enter your engine temperature:\n");
			EngineTemperature(Car1.EngiTem);
			break;
		}
		printstate();
		repeat2(input);
	}
}

void repeat2(char input){// Is to repeat the previous function
	input='a';
	SensorsSetMenu(input);
}

void repeat(char input){// To repeat these function if user keep chosing B
	while(input == 'b'){
		Ask();
		scanf(" %c",&input);
		ChooseTheProgram(input);
		SensorsSetMenu(input);
	}
}
void TrafficLights(char input){
	scanf(" %c",&input);
	if(input== 'G'|| input == 'g'){
		Car1.Speed= 100 ;
		Car1.Lights=input;
	}
	else if(input== 'O' || input == 'o'){
		Car1.Speed=30 ;
		Car1.Lights=input;
		RoomTemperture2();
		EngineTemperature2();
	}
	else if (input == 'R' || input == 'r'){
		Car1.Speed=0;
		Car1.Lights=input;
	}
}
void RoomTemperature(int input){
	scanf(" %d",&input);
	if(input <= 10 || input >= 30){
		Car1.On=1 ;
		Car1.RoomTemp=input;
	}
	else {
		Car1.On=0;
		Car1.RoomTemp=input;
	}
}
void EngineTemperature(int input){
	scanf(" %d",&input);
	if(input <= 100 || input >= 150){
		Car1.On_1=1;
		Car1.EngiTem=input;
	}
	else{
		Car1.On_1=0;
		Car1.EngiTem=input;
	}
}
void RoomTemperture2(void){
	Car1.RoomTemp=Car1.RoomTemp*(5/4)+1;
	Car1.On=1;
}
void EngineTemperature2(void){
	Car1.EngiTem=Car1.EngiTem*(5/4)+1;
	Car1.On_1=1;
}
void printstate(void){
	Car1.engine==1?printf("Engine is ON\n"):printf("Engine is OFF\n");
	printf("vehicle speed to %d km/hr\n",Car1.Speed);
	Car1.On==1?printf("Turn AC ON\n"):printf("Turn AC OFF\n");
	printf("Temperature = %d\n", Car1.RoomTemp);
	Car1.On_1==1?printf("“Engine TemperatureController” ON\n"):printf("“Engine TemperatureController” OFF\n");
	printf("Engine Temperature = %d\n\n",Car1.EngiTem);
}



int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char input = 0 ;
	Ask();
	scanf(" %c",&input);
	ChooseTheProgram(input);
	repeat(input);
	SensorsSetMenu(input);
}
