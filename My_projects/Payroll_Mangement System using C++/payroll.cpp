#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define max 100
using namespace std;

int num=0;
class employee
{
public:
	char name[20],AnyLoan,designation[20];
	int code,exp,age,salary,HRA,PF,DA,tax,MealAllowance,TransportAllowance,MedicalAllowance,LoanBalance,LoanDebit,grosspay,workingHours,h=20;
};
employee emp[max],temp[max];

void Cdelay(int msec)
{
    long goal = msec + (clock());
    while (goal > (clock()));
}

void gotoXY(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void intro()
{
    gotoXY(42,6); printf("WELCOME TO");
    gotoXY(41,7); for(int i=0;i<12;i++) printf("%c",196);
	gotoXY(34,9); printf("PAYROLL MANAGEMENT SYSTEM");
    gotoXY(33,10); for(int i=0;i<29;i++) printf("%c",196);
    gotoXY(45,13); printf("Made by: AYUSH RAWAT");
    gotoXY(45,14); for(int i=0;i<8;i++) printf("%c",196);
    gotoXY(45,15); printf("Section: AI&DS");
    gotoXY(45,16); for(int i=0;i<8;i++) printf("%c",196);
    gotoXY(45,17); printf("University Roll No.: 2017639");
    gotoXY(45,18); for(int i=0;i<20;i++) printf("%c",196);
    gotoXY(24,20);printf("Press Any key to continue...");
    getch();

}

void loading()
{
	system("cls");
    gotoXY(55,20);
    printf("Loading...");
    gotoXY(50,22);
    for(int i = 0; i<20; i++)
    {
        Cdelay(200);
        printf("%c",254);
    }
}

void login()
{
    system("cls");
	char UserName[30],Password[30],ch;
	int i=0;
	gotoXY(20,10);
    printf("Enter UserName : ");
    cin>>UserName;
    gotoXY(20,12);
    cout<<"Enter Password : ";
    while(1)
    {
    	ch = getch();
    	if(ch==13)
            break;
    	if(ch==32||ch==9)
    		continue;
    	else
    	{
			cout<<"*";
			Password[i]=ch;
			i++;
    	}
	}
	Password[i] = '\0';
    if(strcmp(UserName,"hello")==0 && strcmp(Password,"welcome")==0)
    {
    	system("cls");
    	gotoXY(27,10);
    	cout<<"Login Success!!!";
    	Cdelay(1000);
	}
	else
	{
		system("cls");
    	gotoXY(27,10);
		printf("Access Denied!!!\a");
    	Cdelay(1000);
    	system("cls");
    	login();
	}
}

void menu()
{
	system("cls");
	gotoXY(20,3);
	printf("       Payroll Management System  !!! ");
	gotoXY(26,4);for(int i=0;i<27;i++)printf("%c",196);
	gotoXY(12,6);
	cout<<"Press  i. Insert New Record.";
	gotoXY(12,8);
	cout<<"Press  e. Edit a Record.";
	gotoXY(12,10);
	cout<<"Press  d. Delete a Record.";
	gotoXY(12,12);
	cout<<"Press  s. Search a Record.";
	gotoXY(12,14);
	cout<<"Press  l. List The Employee Table.";
	gotoXY(12,16);
	cout<<"Press  p. Print Employee PaySlip.";
	gotoXY(12,18);
	cout<<"Press  h. Holidays.";
	gotoXY(12,20);
	cout<<"Press  q. Quit Program.";
	gotoXY(16,24);
	cout<<"Select Your Option ====> ";
}

void insert()
{
    system("cls");
	int i=num;
	int sal,PF,TAX,HRA,Meal,Medical,Transport,LoanBal,LoanDeb,hours,DA;
	char loan;
	num+=1;
	gotoXY(28,4);
	printf("Insert New Record");
	gotoXY(10,6);
	cout<<"Name : ";
	cin>>emp[i].name;
	gotoXY(10,8);
	cout<<"Code : ";
	cin>>emp[i].code;
	gotoXY(10,10);
	cout<<"Designation : ";
	cin>>emp[i].designation;
	gotoXY(10,12);
	cout<<"Years of Experience : ";
	cin>>emp[i].exp;
	gotoXY(10,14);
	cout<<"Age : ";
	cin>>emp[i].age;
	gotoXY(10,16);
	cout<<"Enter Working Hours Of Per Day : ";
	cin>>hours;
	sal = hours*200*30;
	emp[i].workingHours = hours;
	do
	{
		gotoXY(10,18);
		cout<<"Any Loan (Y/N) ?: \b \b";
		cin>>loan;
		if(loan=='Y'|| loan == 'y' || loan =='n' || loan == 'N')
			break;
	}while(1);
	if(loan=='y'|| loan=='Y')
	{
	gotoXY(10,20);
	cout<<"Enter Loan Balance : ";
	cin>>LoanBal;
	}
	else
	{
		LoanBal=0;
	}
	gotoXY(14,22);
	cout<<"Recorded Succesfully...!!!";

	TAX =  0.09 * sal;
	DA = 0.30 * sal;
	PF = 0.15 * sal;
	HRA = 0.20 * sal;
	Meal = 500;
	Medical = 500;
	Transport = 300;
	LoanDeb = sal * 0.10;
	if(LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	emp[i].salary = sal;
	emp[i].DA = DA;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].HRA = HRA;
	emp[i].MealAllowance = Meal;
	emp[i].MedicalAllowance = Medical;
	emp[i].TransportAllowance = Transport;
	emp[i].LoanBalance = LoanBal-LoanDeb;
	emp[i].AnyLoan = loan;
	emp[i].LoanDebit = LoanDeb;
	emp[i].grosspay = (sal+Meal+Medical+Transport+HRA+DA)-(PF+TAX+LoanDeb) ;
	getch();
}

void editmenu()
{
	system("cls");
	gotoXY(28,4);
	printf("Edit An Entry");
	gotoXY(10,6);
	cout<<"What Do You Want To edit:";
	gotoXY(12,8);
	cout<<"n --> Name ";
	gotoXY(12,9);
	cout<<"c --> Code ";
	gotoXY(12,10);
	cout<<"d --> Designation";
	gotoXY(12,11);
	cout<<"e --> Experience ";
	gotoXY(12,12);
	cout<<"a --> Age";
	gotoXY(12,13);
	cout<<"s --> Salary";
	gotoXY(12,14);
	cout<<"q --> QUIT";
	gotoXY(10,16);
	cout<<"Enter Choice ==>  ";
}

void deletes()
{
    system("cls");
	for(int i=0;i<num;i++)
	{
		temp[i]=emp[i];
	}
	int code;
	int flag=-1;
	gotoXY(28,4);
	printf("Delete a Record");
	gotoXY(10,6);
	cout<<"Enter the JobCode To Delete That Record  :";
	cin>>code;
	int i,j;
	for(i=0;i<=num-1;i++)
	{
	 	if(emp[i].code==code)
		{
			flag=i;
		}
	}
	if(flag!=-1)
	{
		for(i=0,j=0;i<=num-1;i++,j++)
		{
			if(i==flag)
			{
				i++;
			}
			emp[j]=temp[i];
		}
		num--;
	}
}

void search()
{
	system("cls");
	int jobcode;
	bool found = false;
	//gotoXY(10,4);
	//cout<<"You can Search only through the Jobcode of an Employee";
	gotoXY(10,6);
	cout<<"Enter jobcode Of the Employee : ";
	cin>>jobcode;
	for(int i=0;i<=num-1;i++)
	{
		if(emp[i].code==jobcode)
		{
			gotoXY(6,8);
			cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
			gotoXY(6,9);
			cout<<"------------------------------------------------------------------"<<endl;
			gotoXY(6,11);
			cout<<emp[i].name;
			gotoXY(19,11);
			cout<<emp[i].code;
			gotoXY(26,11);
			cout<<emp[i].designation;
			gotoXY(47,11);
			cout<<emp[i].exp;
			gotoXY(58,11);
			cout<<emp[i].age;
			gotoXY(66,11);
			cout<<emp[i].grosspay;
			found = true;
		}
	}
	if(!found)
	{
		gotoXY(26,11);
		cout<<"No records Found...!!!\a";
	}
	getch();
}

void holidays()
{
    int opt,ht,code;
    system("cls");
    cout<<"enter the jobcode:";
    cin>>code;
    for(int i=0;i<num-1;i++)
    {
     if(emp[i].code==code)
     {
      do{
      system("cls");
      gotoXY(12,4);
      cout<<"\n1. take holiday.";
      gotoXY(12,6);
      cout<<"\n2. check remaining holiday.";
      gotoXY(12,8);
      cout<<"\n3. Exit.";
      gotoXY(10,12);
      cout<<"\nenter your option:";
      cin>>opt;
     switch(opt)
     {
      case 1:
        cout<<"enter the number of holidays you want to take:";
        cin>>ht;
        if(ht<=emp[i].h)
        {
            cout<<"happy holidays";
            emp[i].h=emp[i].h-ht;
        }
        else
            cout<<"sorry you don't have enough holidays";
            getch();
        break;
      case 2:
        cout<<"number of holidays left------->"<<emp[i].h;
        getch();
        break;
      default:
        cout<<"invalid option";
     }
     }while(opt!=3);
    }
   }
}

void  list()
{
	system("cls");
	gotoXY(20,4);
	printf("       ******** List of the Employees ********");
	gotoXY(6,6);
	cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
	gotoXY(6,7);
	cout<<"------------------------------------------------------------------"<<endl;
	for(int i=0,j=8;i<=num-1;i++,j++)
	{
		gotoXY(6,j);
		cout<<emp[i].name;
		gotoXY(19,j);
		cout<<emp[i].code;
		gotoXY(26,j);
		cout<<emp[i].designation;
		gotoXY(47,j);
		cout<<emp[i].exp;
		gotoXY(58,j);
		cout<<emp[i].age;
		gotoXY(66,j);
		cout<<emp[i].grosspay;
	}
	getch();
}

void displayPayslip()
{
	system("cls");
	gotoXY(10,4);
	int code,i;
	cout<<"Enter Employee Job Code :";
	cin>>code;
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==code)
		{
			gotoXY(12,6);
			cout<<"Name : "<<emp[i].name;
			gotoXY(45,6);
			cout<<"Working Hours(Per Day) : "<<emp[i].workingHours<<" Hrs";
			gotoXY(6,8);
			cout<<"Earnings :-";
			gotoXY(8,10);
			cout<<"Basic Pay : "<<emp[i].salary<<endl;
			gotoXY(8,12);
			cout<<"HRA(20% of Basic): "<<emp[i].HRA<<endl;
			gotoXY(8,14);
			cout<<"DA (30% of Basic):"<<emp[i].DA;
			gotoXY(8,16);
			cout<<"Meal Allowance : "<<emp[i].MealAllowance<<endl;
			gotoXY(8,18);
			cout<<"Medical Alowance : "<<emp[i].MedicalAllowance<<endl;
			gotoXY(8,20);
			cout<<"Transport Allowance : "<<emp[i].TransportAllowance<<endl;
			gotoXY(40,8);
			cout<<"Deductions :- "<<endl<<endl;
			gotoXY(42,10);
			cout<<"PF : "<<emp[i].PF<<endl;
			gotoXY(42,12);
			cout<<"Tax : "<<emp[i].tax<<endl;
			gotoXY(42,14);
			char l = toupper(emp[i].AnyLoan);
			cout<<"Loan Status : "<<l<<endl;
			gotoXY(42,16);
			cout<<"Loan Taken : "<<emp[i].LoanDebit+emp[i].LoanBalance<<endl;
			gotoXY(42,18);
			cout<<"Loan Debit This Month : "<<emp[i].LoanDebit<<endl;
			gotoXY(42,20);
			cout<<"Loan Balance : "<<emp[i].LoanBalance<<endl;
			gotoXY(32,24);
			cout<<"Total Gross Pay : "<<emp[i].grosspay;
		}
	}
	getch();
}

void getrecords()
{
	FILE *fp;
	fp = fopen("Employee","r");   //opens file in read mode
	int c=0;
	if(fp!=NULL)
	{
		while(feof(fp)==0)
		{
			fscanf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&emp[c].name,&emp[c].code,&emp[c].designation,&emp[c].exp,&emp[c].age,&emp[c].salary,
          &emp[c].AnyLoan,&emp[c].HRA,&emp[c].PF,&emp[c].tax,&emp[c].MealAllowance,&emp[c].TransportAllowance,&emp[c].MedicalAllowance,&emp[c].LoanBalance,&emp[c].LoanDebit,
          &emp[c].grosspay,&emp[c].workingHours,&emp[c].DA,&emp[c].h);
			c++;
		}
		num=c;
	}
	fclose(fp);
}

void saverecords()
{
	if(num==0)
	{
		return;
	}
	else
	{
		FILE *fp;
		fp = fopen("Employee","w");    //opens file in write mode
		for(int i=0;i<num;i++)
		{
			fprintf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",emp[i].name,emp[i].code,emp[i].designation,emp[i].exp,emp[i].age,emp[i].salary,
           emp[i].AnyLoan,emp[i].HRA,emp[i].PF,emp[i].tax,emp[i].MealAllowance,emp[i].TransportAllowance,emp[i].MedicalAllowance,emp[i].LoanBalance,emp[i].LoanDebit,emp[i].grosspay,
           emp[i].workingHours,emp[i].DA,emp[i].h);
		}
		fclose(fp);
	}
}

void editname(int i)
{
	gotoXY(10,18);
	cout<<"Enter New Name----->  ";
	cin>>emp[i].name;
}

void editcode(int i)
{
	gotoXY(10,18);
	cout<<"Enter New Job Code----->  ";
	cin>>emp[i].code;
}
void editdes(int i)
{
	gotoXY(10,18);
	cout<<"enter new designation----->  ";
	cin>>emp[i].designation;
}

void editexp(int i)
{
	gotoXY(10,18);
	cout<<"Enter new Years of Experience";
	cin>>emp[i].exp;
}
void editage(int i)
{
	gotoXY(10,18);
	cout<<"Enter new Age ";
	cin>>emp[i].age;
}

void editsalary(int i)
{
	int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal=emp[i].LoanBalance,LoanDeb,DA;
	char loan;
	gotoXY(10,18);
	cout<<"Enter new Salary ";
	cin>>sal;
	DA = 0.30 * sal;
	TAX =  0.09 * sal;
	PF = 0.15 * sal;
	HRA = 0.20 * sal;
	MealA = 500;
	MedicalA = 500;
	TransportA = 300;
	LoanDeb = sal * 1.0;
	if(LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	emp[i].salary = sal;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].HRA = HRA;
	emp[i].MealAllowance = MealA;
	emp[i].MedicalAllowance = MedicalA;
	emp[i].TransportAllowance = TransportA;
	emp[i].LoanBalance = LoanBal;
	emp[i].AnyLoan = loan;
	emp[i].LoanDebit = LoanDeb;
	emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
}

void edit()
{
	system("cls");
	int jobcode;
	gotoXY(28,4);
	printf("Edit a Record");
	int i;
	char option;
	gotoXY(10,6);
	cout<<"Enter the jobcode To Edit : ";
	cin>>jobcode;
	editmenu();
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==jobcode)
		{
			while((option=cin.get())!='q')
			{
				switch(option)
				{
					case 'n':
						editname(i);
						break;
					case 'c':
						editcode(i);
						break;
					case 'd':
						editdes(i);
						break;
					case 'e':
						editexp(i);
						break;
					case 'a':
						editage(i);
						break;
					case 's':
						editsalary(i);
						break;
				}
   				editmenu();
			}
		}
	}
}

int main()
{
	intro();
	loading();
    login();
    menu();
    getrecords();
    char option;
	while(1)
	{
		cin>>option;
		switch(option)
		{
			case 'l':
				list();
				break;
			case 'i':
				insert();
				break;
			case 'd':
				deletes();
				break;
			case 'e':
				edit();
				break;
			case 's':
				search();
				break;
			case 'p':
				displayPayslip();
				break;
	        case 'h':
                holidays();
                break;
			case 'q':
				saverecords();
				exit(0);
		}
		menu();
	}
	return 0;
}
