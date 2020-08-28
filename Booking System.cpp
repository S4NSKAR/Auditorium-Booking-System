/*
Project Title: Seat allocation plan for Auditorium
Brief Overview: It's like you will be creating a master layout seat plan and then you need to allocate the seats
                to the people/students in a specific order. At any specific point of time your program should be
                able to tell total seats, occupied seats and vacant seats.
*/
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include<windows.h>
using namespace std;

class Booking_System
{
	private:
		string Temp;
		char temp;
		int Alloted;
		string Input;
		int Row, Col;
		int Seat_No;
		int Seats[102];
		int To_Book;
		string Name;
		string Contact;
		int Count;
		string Find;
		int Default_Theme;
		
	public:
		Intro();
		Process();
		Auto_Book_Seats();
		Manual_Book_Seats();
		Seats_Info();
		Show_Booked_Seats();
		Search_Booked_Seats();
		Search_A_Seat();
		Change_Theme();
		Exit();
		
		Booking_System() {
			
	        fstream Read_Seats;
	        Read_Seats.open("Booked Seats.txt");
	        while (Read_Seats) {
	            getline(Read_Seats, Temp, '-');
	            Read_Seats >> Alloted;
	        }
	        Read_Seats.close();
	        
	        for (int i=1; i<101; i++) {
	            Seats[i]=0;
	        } Seats[101]=1;
	        
	        fstream Booked;
	        Booked.open("Booked Seats.txt");
	        while(Booked) {
	        	getline(Booked, Temp);
	        	if (Temp.find("Seat No : ")!=string::npos) {
	        		Temp.erase(0,10);
	        		stringstream Convertor(Temp);
	        		Convertor >> Seat_No;
	        		//Row=(Seat_No/10)+1;
	        		//Col=(Seat_No%10);
	        		//if (Col==0) Col=10, Row=Row-1;
	        		Seats[Seat_No]=1;
				}
			}
			Booked.close();
		}
};

Booking_System::Intro(){
	system("CLS");
	SetConsoleTitle("SEAT BOOKING SYSTEM : MAIN MENU");
	if(Default_Theme==1)
	system("color F0");
	else if(Default_Theme==2)
	system("color B0");
	else if(Default_Theme==3)
	system("color C0");
	else 
	system("color E0");
	cout << "\t\t\t\t---------------------------------------------\n";
	cout << "\t\t\t\t||*****************************************||\n";
	cout << "\t\t\t\t||                                         ||\n";
	cout << "\t\t\t\t||  WELCOME TO AUDITORIUM BOOKING SYSTEM   ||\n";
	cout << "\t\t\t\t||                                         ||\n";
	cout << "\t\t\t\t||*****************************************||\n";
	cout << "\t\t\t\t---------------------------------------------\n";
	cout << endl << endl;
	cout << "MAIN MENU :" << endl << endl;
	cout << "1. Book Your Tickets" << endl;
	cout << "\t a. Automatically assign seats" << endl;
	cout << "\t b. Manually select seats" << endl;
	cout << "2. Check Seats : \n";
	cout << "\t a. Check seats availability" << endl;
	cout << "\t b. Show all booked seats" << endl;
	cout << "\t c. Search your booking status" << endl;
	cout << "\t d. Search for a specific seat" << endl;
	cout << "3. Change Theme" << endl;
	cout << "4. Exit" << endl << endl;
}

Booking_System::Process() {
	cout << "Please enter your query...(For example - 2b)" << endl;
	INPUT : {
	cout << "---> ";
	cin >> Input;
	if (Input=="1a") Auto_Book_Seats(); else
	if (Input=="1b") Manual_Book_Seats(); else
	if (Input=="2a") Seats_Info(); else
	if (Input=="2b") Show_Booked_Seats(); else
	if (Input=="2c") Search_Booked_Seats(); else
	if (Input=="2d") Search_A_Seat(); else
	if (Input=="3")  Change_Theme(); else
	if (Input=="4")  Exit(); else
	{
		cout << "Invalid input! Please enter your query again..." << endl;
		goto INPUT;
	}
    }
}

Booking_System::Auto_Book_Seats() {
	SetConsoleTitle("SEAT BOOKING SYSTEM : BOOK SEATS");
	system("color B0");
	system("CLS");
	cout << "You have selected - \n1a. Automatically assign seats" << endl << endl;
	cout << "Enter the following information : " << endl;
	cout << "Enter the no of seats to book : ";
	cin >> To_Book;
	cout << endl;
	fstream Book_Seats;
	Book_Seats.open("Booked Seats.txt", ios::app);
	for (int i=0; i<To_Book; i++) {
		cout << "Person " << i+1+Alloted << " : " << endl;
		Book_Seats << "Person - " << i+1+Alloted << endl;
		Count=Alloted+i+1;
		cout << "Enter Name - "; 
		cin.ignore();
		getline(cin, Name);
		Book_Seats << "Name : " << Name << endl;
		cout << "Enter Contact - ";
		cin >> Contact;
		Book_Seats << "Contact : " << Contact << endl;
		for (int i=1; i<=101; i++) {
				if (Seats[i]==0) {
					cout << "Booking Seat No : " << i << endl;
					Seats[i]=1;
					Seat_No=i;
					Book_Seats << "Seat No : " << i << endl;
					Row=(Seat_No/10)+1;
	        		Col=(Seat_No%10);
	        		if (Col==0) Col=10, Row=Row-1;
	        		cout << "Row : " << Row << endl;
	        		cout << "Column : " << Col << endl;
	        		Book_Seats << "Row : " << Row << endl;
	        		Book_Seats << "Column : " << Col << endl << endl;
					cout << "Seat Booked!" << endl << endl;
					break;
				}
				if (i==101) {
				cout << "Sorry, all the Seats are Booked!" << endl;
				break;
			    }
			}
		}
		Book_Seats.close();
		Alloted=Count;
	cout << "***** ALL THE SEATS ARE BOOKED *****\n";
	cout << "Press Enter to continue...\n";
	getch();
	Booking_System::Intro();
	Booking_System::Process();
}
	
Booking_System::Manual_Book_Seats() {
	system("CLS");
	SetConsoleTitle("SEAT BOOKING SYSTEM : BOOK SEAT");
	system("color B0");
	cout << "You have selected - \n1b.Manually select seats" << endl << endl;
	cout << "Enter the following information : " << endl;
	cout << "Enter the no of seats to book : ";
	cin >> To_Book;
	cout << endl;
	fstream Book_Seats;
	Book_Seats.open("Booked Seats.txt", ios::app);
	for (int i=0; i<To_Book; i++) {
		cout << "Person " << i+1+Alloted << " : " << endl;
		Book_Seats << "Person - " << i+1+Alloted << endl;
		Count=Alloted+i+1;
		cout << "Enter Name - "; 
		cin.ignore();
		getline(cin, Name);
		Book_Seats << "Name : " << Name << endl;
		cout << "Enter Contact - ";
		cin >> Contact;
		Book_Seats << "Contact : " << Contact << endl;
		cout << "Enter Seat No - ";
		SELECT : {
		cin >> Seat_No;
		if (Seats[Seat_No]==0) {
			cout << "Booking Seat No : " << Seat_No << endl;
			Seats[Seat_No]=1;
			Book_Seats << "Seat No : " << Seat_No << endl;
			Row=(Seat_No/10)+1;
	        Col=(Seat_No%10);
	        if (Col==0) Col=10, Row=Row-1;
	        cout << "Row : " << Row << endl;
	        cout << "Column : " << Col << endl;
	        Book_Seats << "Row : " << Row << endl;
	        Book_Seats << "Column : " << Col << endl << endl;
			cout << "Seat Booked!" << endl << endl;
		} else if (Seats[Seat_No]==1) {
			cout << "Sorry, the selected seat is not available! Please select another : ";
			goto SELECT;
     	}
		}
		}
		Alloted=Count;
		Book_Seats.close();
	cout << "***** ALL THE SEATS ARE BOOKED *****\n";
	cout << "Press Enter to continue...\n";
	getch();
	Booking_System::Intro();
	Booking_System::Process();
}
	
Booking_System::Seats_Info() {
	system("CLS");
	SetConsoleTitle("SEAT BOOKING SYSTEM : CHECK SEATS");
	system("color C0");
	cout << "You have selected - \n2a.Check seats availability" << endl;
	cout << "Loading Seats that are already booked. Please wait..." << endl << endl;
	ifstream Read_Seats;
	Read_Seats.open("Booked Seats.txt");
	while (Read_Seats) {
	getline(Read_Seats, Temp, '-');
	Read_Seats >> Alloted;
    }
	cout << "Total Seats : 100" << endl;
	cout << "Remaining Seats : " << 100-Alloted << endl;
	cout << "Alloted Seats : " << Alloted << endl << endl;
	Read_Seats.close();
	cout << "Press Enter to continue...\n";
	getch();
	Booking_System::Intro();
	Booking_System::Process();
}

Booking_System::Show_Booked_Seats() {
	system("CLS");
	SetConsoleTitle("SEAT BOOKING SYSTEM : CHECK SEATS");
	system("color C0");
	cout << "You have selected - \n2b.Show all booked seats" << endl;
	
	cout << "Loading Seats that are already booked. Please wait..." << endl << endl;
	ifstream Read_Seats;
	Read_Seats.open("Booked Seats.txt");
	while (Read_Seats) {
	getline(Read_Seats, Temp);
	cout << Temp << endl;
    }
	cout << "Press Enter to continue...\n";
	getch();
	Booking_System::Intro();
	Booking_System::Process();
}

Booking_System::Search_Booked_Seats() {
	system("CLS");
	SetConsoleTitle("SEAT BOOKING SYSTEM : CHECK SEATS");
	system("color C0");
	cout << "You have selected - \n2c.Search your booking status" << endl << endl;
	ifstream Search;
	Search.open("Booked Seats.txt");
	cout << "Enter the Details (Name or Contact) to search : ";
	cin >> Find;
	int k=1;
	while(Search) {
		getline(Search, Temp);
		if (Temp.find(Find)!=string::npos) {
			cout << "The Person's seat is already booked" << endl << endl;
			k=0;
			break;
		}
	}
	if (k==1) {
		cout << "Sorry, Unable to find the person's info in our database..." << endl << endl;
	}
	Search.close();
	cout << "Press Enter to continue...\n";
	getch();
	Booking_System::Intro();
	Booking_System::Process();
}

Booking_System::Search_A_Seat() {
	system("CLS");
	SetConsoleTitle("SEAT BOOKING SYSTEM : CHECK SEATS");
	system("color C0");
	cout << "You have selected - \n2d.Search for a specific seat" << endl << endl;
	ifstream Search;
	Search.open("Booked Seats.txt");
	cout << "Enter the Seat to search : ";
	cin >> Seat_No;
	cout << endl;
	if(Seats[Seat_No]==1) {
		cout << "The Seat is already reserved." << endl << endl;
	} else if(Seats[Seat_No]==0) {
    cout << "The Seat is not reserved. You can book the seat." << endl << endl; 
    }
	Search.close();
	cout << "Press Enter to continue...\n";
	getch();
	Booking_System::Intro();
	Booking_System::Process();
}

Booking_System::Change_Theme() {
	SetConsoleTitle("SEAT BOOKING SYSTEM : CHANGE THEME");
	cout << "\n1. White\n2. Blue\n3. Red" << endl;
	cout << "Select the color : ";
	cin >> temp;
	if(temp=='1')
	system("color F0"), Default_Theme=1;
	else if(temp=='2')
	system("color B0"), Default_Theme=2;
	else if(temp=='3')
	system("color C0"), Default_Theme=3;
	else 
	system("color E0"), Default_Theme=4;
	getch();
	Booking_System::Intro();
	Booking_System::Process();
}

Booking_System::Exit() {
	system("CLS");
	SetConsoleTitle("SEAT BOOKING SYSTEM : EXIT");
	system("color F0");
	cout << "You have selected - \n3.Exit" << endl << endl;
	EXIT : {
	cout << "Are you sure you want to exit the program ?" << endl;
	cout << "1  -->  Yes" << endl << "2  -->  No" << endl;
	cout << "---> ";
	cin >> temp;
	if (temp =='1') {
		cout << "\nExiting...";
		exit(0);
	} else if (temp == '2') {
		cout << "Ok, so let's continue with the program." << endl << endl;
		cout << "Press Enter to continue...\n";
		getch();
	    Booking_System::Intro();
	    Booking_System::Process();
	} else {
		cout << "Invalid input! Please enter again : " << endl;
	    goto EXIT;
	}
    }
}

main()
{
	SetConsoleTitle("SEAT BOOKING SYSTEM : MAIN MENU");
	system("color E0");
	Booking_System book;
	book.Intro();
	book.Process();
}
