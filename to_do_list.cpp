/*
	TO DO LIST C++ - 08/12/2023 - Create by Quoc Khanh
*/

#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

//data
const int MAXN = 10;
string todo , toDoList[MAXN];
int choose,counting = 0,idx;
char inp;

//function
void init();
void add();
void edit();
void del();
void views();
void menu();

int main(){
	menu();
	return 0;
}
void init(){
	for(int i = 0 ; i < MAXN ; i++){
		toDoList[i] = " ";
	}
}
void add(){
	cin.ignore();
	cout<<"Add :";
	getline(cin,todo);
	
	//add
	if(counting < 10){
		for(int i = 0 ; i < MAXN ; i++){
			if(toDoList[i] == " "){
				toDoList[i] = todo;
				counting++;
				break;
			}
		}
		cout<<"Complete!!!"<<endl;
	}else{
		cout<<"List full!!!"<<endl;
	}	
}
void edit(){
	if(counting < 1){
		cout<<"\nList empty!!!\n";
		return;
	}
	
	cout<<"\nEnter a key index :";
	cin>>idx;
	
	if(idx < 0 || idx > 10){
		cout<<"Not found!!!";
		return;
	}
	
	for(int i = 0 ; i < MAXN ; i++){
		if(i == idx - 1){
			cout<<"\n---------------";
			cout<<"\n1.Change new."
				<<"\n2.Default.";
			cout<<"\n---------------";
			cout<<"You choose :";
			int c ;
			cin>>c;
			if(c == 1){
				cin.ignore();
				cout<<"Edit task "<<(i+1)<<" :";
				getline(cin,todo);
				toDoList[i] = todo;
				cout<<"Finish!!!"<<endl;
			}
			if(c == 2){
				cout<<"Complete!!!"<<endl;
			}
		}
	}
}
void del(){
	if(counting < 1){
		cout<<"List empty!!!"<<endl;
		return;
	}
	
	cout<<"\nEnter a key index :";
	cin>>idx;
	
	if(idx < 0 || idx > 10){
		cout<<"Not found!!!";
		return;
	}
	
	for(int i = idx - 1 ; i < counting; i++){
		toDoList[i] = toDoList[i + 1];
	}
	counting--;
	cout<<"Completed!!!"<<endl;
}
void views(){
	if(counting < 1){
		cout<<"\nList empty!!!\n";
		return;
	}
	cout<<"\n  LIST TO DO\n";
	cout<<"-------------------\n";
	for(int i = 0 ; i < MAXN ; i++ ){
		if(toDoList[i] != " "){
			cout<<(i+1)<<". "<<toDoList[i]<<endl;
		}	
	}
	cout<<"-------------------\n";
}
void menu(){
	
	init();
	do{
		system("cls");
		cout<<"-------------------\n";
		cout<<"  TO DO LIST C++\n";
		cout<<"-------------------\n";
		cout<<"1.Add a task\n";
		cout<<"2.Delete a task\n";
		cout<<"3.Edit a task\n";
		cout<<"4.View list\n";
		cout<<"5.Exit\n";
		cout<<"-------------------\n";
		cout<<"\nYou choose :";
		cin>>choose;
		switch(choose){
			case 1:
				add();
				break;
			case 2:
				del();
				break;
			case 3:
				edit();
				break;
			case 4:
				views();
				break;
			case 5: 
				cout<<"Good bye!!! See you again."<<endl;
			break;
			default:
				cout<<"Not found!!!"<<endl;
		}
		cout<<"DO YOU WANT TO CONTINUE ? (Y/N) :";
		cin>>inp;
	}while(inp == 'Y' || inp == 'y');
}

