#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<iomanip.h>
void mainmenu();
void delay()
{
	for (long double i = 0; i<100000; i++)
	{
	}
}
void design()
{

	for (int x = 0; x<78; x++)
	{
		cout << "*";
		delay();
	}
	for (int y = 0; y<24; y++)
	{
		gotoxy(x, y);
		cout << "*";
		delay();
	}
	for (; x>0; x--)
	{
		gotoxy(x, y);
		cout << "*";
		delay();
	}
	for (; y>0; y--)
	{
		gotoxy(0, y);
		cout << "*";
		delay();
	}
}
class flight
{
	char flightname[15];
	char carrier[50];
	long cost;
public:
	int ticketno;
	void assignflight();
	void assigncost();
	long retcost()
	{
		return cost;
	}
	char *returnflight()
	{
		return flightname;
	}
};
void flight::assignflight()
{
	char type[7][7] = { "GF222","IA112","UA3222" };
	int i;
	randomize();
	for (i = 0; i<3; i++)
	{
		strcpy(flightname, type[random(3)]);
	}
}
void flight::assigncost()
{
	int i;
	randomize();
	cost = random(2500) + 1500;
}
class passenger
{
	char name[50];
	long pnr;
	int age;
	char gender;
	long telno;
	char origin[40];
	char destination[40];
	char flight[40];
	int ticket_number;
public:
	int assignticketnumber();
	void input()
	{
		gotoxy(30, 5);
		cout << "Enter Name: ";
		gets(name);
		gotoxy(30, 7);
		cout << "Enter Age: ";
		cin >> age;
		gotoxy(30, 9);
		cout << "Enter Gender(M/F): ";
		cin >> gender;
		gotoxy(30, 11);
		cout << "Enter Telephone Number: ";
		cin >> telno;
		gotoxy(30, 13);
		cout << "Enter your PNR number: ";
		cin >> pnr;
		clrscr();
		design();
		flightdest();
		gotoxy(15, 11);
		cout << "Enter Origin: ";
		gotoxy(15, 12);
		gets(origin);
		gotoxy(50, 11);
		cout << "Enter Destination: ";
		gotoxy(50, 12);
		gets(destination);
		assignticketnumber();
		clrscr();
	}
	char *retdestination()
	{
		return destination;
	}
	char *retorigin()
	{
		return origin;
	}
	void flightdest()
	{
		gotoxy(15, 3);
		cout << "The destinations available are\n";
		gotoxy(15, 4);
		cout << "1.Frankfurt\n";
		gotoxy(15, 5);
		cout << "2.Bahrain\n";
		gotoxy(15, 6);
		cout << "3.Kochi\n";
		gotoxy(15, 7);
		cout << "4.Delhi\n";
		gotoxy(15, 8);
		cout << "5.Bangalore\n";
		gotoxy(15, 9);
		cout << "6.Chennai\n";
		gotoxy(15, 10);
		cout << "7.London\n";
		gotoxy(50, 3);
		cout << "The origins available are\n";
		gotoxy(50, 4);
		cout << "1.Frankfurt\n";
		gotoxy(50, 5);
		cout << "2.Bahrain\n";
		gotoxy(50, 6);
		cout << "3.Kochi\n";
		gotoxy(50, 7);
		cout << "4.Delhi\n";
		gotoxy(50, 8);
		cout << "5.Bangalore\n";
		gotoxy(50, 9);
		cout << "6.Chennai\n";
		gotoxy(50, 10);
		cout << "7.London\n";
	}
	void output()
	{
		design();
		gotoxy(30, 5);
		cout << "Name:";;
		puts(name);
		gotoxy(30, 6);
		cout << "Age:";
		cout << age << endl;
		gotoxy(30, 7);
		cout << "Gender:";
		cout << gender << endl;
		gotoxy(30, 8);
		cout << "Telephone Number:";
		cout << telno << endl;
		gotoxy(30, 9);
		cout << "PNR Number:";
		cout << pnr << endl;
		gotoxy(30, 10);
		cout << "Origin:";
		puts(origin);
		gotoxy(30, 11);
		cout << "Destination:";
		puts(destination);
		gotoxy(30, 12);

	}
	long retpnr()
	{
		return pnr;
	}
	char *retname()
	{
		return name;
	}
	int rettno()
	{
		return ticket_number;
	}
};
int passenger::assignticketnumber()
{
	randomize();
	ticket_number = random(7000);
}
void append()
{
	passenger p;
	clrscr();
	design();
	ofstream fout;
	fout.open("Bookings1.dat", ios::app | ios::binary);
	p.input();
	fout.write((char*)&p, sizeof(p));
	clrscr();
	fout.close();
}
void billing()
{
	char ch;
	passenger p;
	flight f;
	char name[40];
	char ftype[20];
	long cost;
	char origin[40];
	char destination[40];
	int flag = 0;
	int tno;
	clrscr();
	design();
	ifstream infile;
	infile.open("Bookings1.dat", ios::binary);
	gotoxy(30, 5);
	cout << "Enter your ticket number: ";
	gotoxy(30, 6);
	cin >> tno;
	while (infile.read((char*)&p, sizeof(p)))
	{
		if (tno == p.rettno())
		{
			++flag;
		}
	}
	if (flag == 1)
	{
		clrscr();
		p.output();
		getch();
		gotoxy(10, 20);
		cout << "Press any key to view final billing details";
		strcpy(name, p.retname());
		strcpy(destination, p.retdestination());
		strcpy(origin, p.retorigin());
		infile.close();
		ifstream fin;
		fin.open("ticket.dat", ios::in | ios::binary);
		while (fin.read((char*)&f, sizeof(f)))
		{
			if (tno == f.ticketno)
				strcpy(ftype, f.returnflight());
			cost = f.retcost();
		}
		getch();
		clrscr();
		design();
		gotoxy(20, 3);
		cout << "##########################################" << endl;
		gotoxy(20, 4);
		cout << "               BILLING DETAILS           " << endl;
		gotoxy(20, 5);
		cout << "Name:" << name;
		gotoxy(20, 6);
		cout << "Origin:" << origin;
		gotoxy(20, 7);
		cout << "Destination:" << destination;
		gotoxy(20, 8);
		cout << "Flight Number:" << ftype;
		gotoxy(20, 9);
		cout << "Cost:" << cost << " " << "BD";
		gotoxy(20, 11);
		cout << "Confirm Ticket?[Y/N]: ";
		gotoxy(20, 12);
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			gotoxy(20, 14);
			cout << "Confirmed! Thank you for flying with Paradise Airlines";
		}
		else if (ch == 'n' || ch == 'N')
		{
			gotoxy(20, 14);
			cout << "Press any key to exit...";
			getch();
		}
		getch();
	}
	else if (flag == 0)
	{
		gotoxy(30, 7);
		cout << "Invalid Ticket Number. Press any key...";
		getch();
		clrscr();
	}
}
void searchname()
{
	design();
	passenger B;
	char nm[20];
	gotoxy(30, 6);
	cout << "Enter the name to be searched: " << endl;
	gotoxy(30, 7);
	gets(nm);
	ifstream fin;
	fin.open("Bookings1.dat", ios::in | ios::binary);
	while (fin.read((char*)&B, sizeof(B)))
	{

		if (strcmpi(B.retname(), nm) == 0)
		{
			clrscr();
			B.output();
			gotoxy(30, 12);
			getch();
			clrscr();
		}
	}
}

void searchpnr()
{
	design();
	passenger A;

	long pr;
	gotoxy(30, 6);
	cout << "Enter the PNR number to be searched: " << endl;
	gotoxy(30, 7);
	cin >> pr;
	ifstream fin;
	fin.open("Bookings1.dat", ios::in | ios::binary);
	while (fin.read((char*)&A, sizeof(A)))
	{

		if (pr == A.retpnr())
		{
			clrscr();
			A.output();
			gotoxy(30, 12);

			getch();
			clrscr();
		}
	}
}

void searchdest()
{
	design();
	passenger C;
	char dt[30];
	gotoxy(30, 6);
	cout << "Enter the destination to be checked: " << endl;
	gotoxy(30, 7);
	gets(dt);
	ifstream fin;
	fin.open("Bookings1.dat", ios::in | ios::binary);
	while (fin.read((char*)&C, sizeof(C)))
	{
		if (strcmpi(C.retdestination(), dt) == 0)
		{
			clrscr();
			C.output();
			gotoxy(30, 12);
			getch();
			clrscr();
		}
	}
}

void reports()
{
	passenger p;
	clrscr();
	design();
	ifstream infile;
	infile.open("Bookings1.dat", ios::in | ios::binary);
	while (infile.read((char*)&p, sizeof(p)))
	{
		clrscr();
		p.output();
		getch();
	}
	gotoxy(10, 20);
	cout << "Press any key to return to main menu...";
	getch();
	clrscr();
}

void search()
{
	char name[20], dest[20];
	int option;

	do
	{
		clrscr();
		design();
		gotoxy(36, 4);
		cout << "SEARCH  MENU" << endl;
		gotoxy(36, 6);
		cout << "1. By PNR Number" << endl;
		gotoxy(36, 8);
		cout << "2. By Name " << endl;
		gotoxy(36, 10);
		cout << "3. By Destination " << endl;
		gotoxy(36, 12);
		cout << "4. Back to main menu " << endl;
		gotoxy(36, 14);
		cout << "Enter your option: ";
		cin >> option;
		switch (option)
		{
		case 1: clrscr();

			searchpnr();
			break;

		case 2: clrscr();
			searchname();
			break;

		case 3: clrscr();
			searchdest();
			break;


		case 4:clrscr();
			mainmenu();

			break;
		}
	} while (1);
}
void ticketissue()
{
again:flight f;
	int flag = 0;
	int ticketno;
	char dest[40];
	char name[45];
	long pnrnumber;
	char origin[40];
	clrscr();
	design();
	passenger q;
	gotoxy(25, 6);
	cout << "Confirm your name:";
	gotoxy(25, 7);
	gets(name);
	gotoxy(25, 8);
	cout << "Confirm your PNR number:";
	gotoxy(25, 9);
	cin >> pnrnumber;
	gotoxy(25, 10);
	cout << "Confirm your origin:";
	gotoxy(25, 11);
	gets(origin);
	gotoxy(25, 12);
	cout << "Confirm your destination:";
	gotoxy(25, 13);
	gets(dest);
	ifstream fin;
	fin.open("Bookings1.dat", ios::binary);
	while (fin.read((char*)&q, sizeof(q)))
	{
		if (strcmpi(q.retdestination(), dest) == 0 && strcmpi(q.retorigin(), origin) == 0 && strcmpi(q.retname(), name) == 0 && q.retpnr() == pnrnumber)
		{
			++flag;
		}
	}
	if (flag == 1)
	{
		ticketno = q.rettno();
		f.ticketno = q.rettno();
		f.assigncost();
		f.assignflight();
		gotoxy(25, 14);
		cout << "Your ticket number: " << ticketno << endl;
		gotoxy(10, 20);
		cout << "Press any key to go to mainmenu and then proceed to Billing.";
		ofstream fout;
		fout.open("ticket.dat", ios::out | ios::app | ios::binary);
		fout.write((char*)&f, sizeof(f));
		getch();
		clrscr();
	}
	else if (flag == 0)
	{
		cout << "Unable to confirm." << endl;
		cout << "Press Esc to go back to main menu or press any key to enter again: " << endl;
		getch();
		if (getch() == 27)
		{
			clrscr();
			mainmenu();
		}
		else if (getch() != 27)
		{
			goto again;
		}
	}
}
void mainmenu()
{
	int option;
	do
	{
		clrscr();
		design();
		gotoxy(39, 4);
		cout << "MAIN  MENU" << endl;
		gotoxy(36, 6);
		cout << "1. Book a Ticket" << endl;
		gotoxy(36, 8);
		cout << "2. Search " << endl;
		gotoxy(36, 10);
		cout << "3. Issue Ticket " << endl;
		gotoxy(36, 12);
		cout << "4. Billing " << endl;
		gotoxy(36, 14);
		cout << "5. Reports " << endl;
		gotoxy(36, 16);
		cout << "6. Exit" << endl;
		gotoxy(36, 18);
		cout << "Enter your option: ";
		cin >> option;
		switch (option)
		{
		case 1:append();
			break;
		case 2:search();
			break;
		case 3:ticketissue();
			break;
		case 4:billing();
			break;
		case 5:reports();
			break;
		case 6:exit(1);
			break;
		default:gotoxy(36, 20);
			cout << "Invalid option..";
			getch();
			break;



		}
	} while (1);
}

void login()
{
	char ch;
	char pass[25];
	char password[] = "airline";
	int i = 0;
	gotoxy(20, 6);
	cout << "Enter the password: ";
	gotoxy(20, 8);
	while (ch != 13)
	{
		ch = getch();
		pass[i] = ch;
		cout << "*";
		if (ch == 13)
		{
			break;
		}
		i++;
	}
	pass[i] = '\0';
	if (strcmp(pass, password) == 0)
	{
		clrscr();
		delay();
	}
	else
	{
		exit(1);
	}
}
void main()
{
	login();
	mainmenu();
	getch();
}


