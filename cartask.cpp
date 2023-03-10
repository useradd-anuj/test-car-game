#include<iostream>
#include<conio.h>
#include<dos.h>
#include <windows.h>
using namespace std;

int carx=45;
int cary=21;
char f[26][90];
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);  
COORD coord;
void gotoxy(int x, int y) { 
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}

bool collision(){
	if(carx+4>89||carx<1||cary<1||cary+4>25)return true;
	for(int i=carx;i<carx+4;i++){
		for(int j=cary;j<cary+4;j++){
			if(f[j][i]=='±')return true;
		}
	}
	return false;
}

void eraseCar(){
	for(int i=cary;i<cary+4;i++){
		for(int j=carx;j<carx+4;j++){
			gotoxy(j,i);
			cout<<" ";
		}
	}
}

void field(){
		for(int j=0;j<90;j++){
			gotoxy(j,0);
			f[0][j]='±';
			cout<<"±";
			gotoxy(j,25);
			f[25][j]='±';
			cout<<"±";
		}
		for(int j=1;j<25;j++){
			gotoxy(0,j);
			f[j][0]='±';
			cout<<"±";
			gotoxy(89,j);
			f[j][89]='±';
			cout<<"±";
		}
		for(int i=1;i<5;i++){
			for(int j=1;j<85;j++){
				gotoxy(j,i);
				f[i][j]='±';
				cout<<"±";
			}
		}
		for(int i=9;i<13;i++){
			for(int j=5;j<89;j++){
				gotoxy(j,i);
				f[i][j]='±';
				cout<<"±";
			}
		}
		for(int i=13;i<25;i++){
			for(int j=49;j<89;j++){
				gotoxy(j,i);
				f[i][j]='±';
				cout<<"±";
			}
		}
		for(int i=17;i<25;i++){
			for(int j=1;j<45;j++){
				gotoxy(j,i);
				f[i][j]='±';
				cout<<"±";
			}
		}
		gotoxy(94,11);cout<<"Controls";
		gotoxy(92,12);cout<<"---------";
		gotoxy(93,14);cout<<"w - up";
		gotoxy(93,15);cout<<"a - left";
		gotoxy(93,16);cout<<"s - down";
		gotoxy(93,17);cout<<"d - right";
		gotoxy(0,26);
}

void drawCar(){
	for(int i=cary;i<cary+4;i++){
		for(int j=carx;j<carx+4;j++){
			gotoxy(j,i);
			cout<<"*";
		}
	}
}

int main(){
	cout<<"Press any key to start the game";
	getch();
	system("cls");
	field();
	while(1){		
		if(kbhit()){
			char ch = getch();  
            if( ch== 'w'){
                    cary-= 4;
            }
            if(ch=='a'){
                    carx-= 4;
			}
			if(ch=='d'){
                    carx+= 4;
			}
			if(ch=='s'){
                    cary+= 4;
			}
            if(ch==27){
            	system("cls");
                break;
            }
		}
		if(collision()){
			system("cls");
			gotoxy(20,15);
			cout<<"------Game over!!!------";
			gotoxy(20,16);
			cout<<"collided";
			return 0;
		}
		if(carx==85&&cary==1){
			drawCar();
			Sleep(500);
			system("cls");
			gotoxy(20,15);
			cout<<"------YOU WIN!!!------";
			return 0;
		}
		drawCar();
		Sleep(100);
		eraseCar();	
	}
}
