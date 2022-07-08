/*Project name:Rental Bike
  Student name + ID:
  	+Leader: Dang Tran Nhat Minh  20193231
  	+Member: Chu Dinh Hai         20193214
  			 Ban Thi Thuy 		  20193239
  			 Nguyen Minh Chau     20193206
  			 Le Tri Trung Kien    20193225
*/





#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
#include <type_traits>
#include <iomanip>
#include <windows.h>
#include <unistd.h>

using namespace std;
class Money{
private:
    int charge;
    int day;
public:
    Money(int charge, int day){
        this->charge=charge;
        this->day=day;
    }
    int getCharge(){
        return charge;
    }
    void serCharge(int charge){
        this->charge=charge;
    }
    int getDay(){
        return day;
    }
    void setDay(int day){
        this->day=day;
    }
    void display(){
        cout << "The bill is: " << day*charge << endl;
    }
};
class Overdue : public Money {
private:
    int over;
public:
    Overdue(int charge, int day, int over) : Money(charge, day){
        this->over=over;
    }
    int getOver(){
        return over;
    }
    void setOver(int over){
        this->over=over;
    }
    void display(){
        int a=getCharge();
        int b=getDay();
        cout << "The bill is: " << a*b+over*2*a << endl;
    }
};
void mainmenu();
void add();
void list();
void Remove();
string temp(string k){
    string g;
    g=k;
    return g;
}
void SetColor(int background_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = background_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
bool IsloggedIn()
{
    string username,password,un,pw;
    cout<<"Enter username: ";cin >> username;
    cout<<"Enter password: ";cin >> password;
    ifstream read("acc." + username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password )
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool CheckFileIdExisting(string id)
{
  ifstream data_file(id + ".txt");
  if (data_file.fail())
  {
    return false;
  }
    data_file.close();

    return true;
}
bool CheckFileAccExisting(string username)
{
  ifstream data_file("acc." + username + ".txt");
  if (data_file.fail())
  {
    return false;
  }
    data_file.close();

    return true;
}
void signup(){
    string username, password, id;
//id
	T:
	    cout << "Insert your ID: "; cin >> id;
	    bool status = CheckFileIdExisting(id);
	    if(status) {
	        cout << "This id has been resigned already." << endl << "Try again." << endl;
    	    goto T;
   		}
		else
    	{
	U:
        cout << "Insert your username: "; cin >> username;
        bool status = CheckFileAccExisting(username);
        if(status)
        {
            cout << "This username has been resigned already." << endl << "Try again." << endl;
            goto U;
        } else {
            cout << "Select a password: "; cin >> password;
        }
    }
    ofstream file;
    file.open(id +".txt");
    file.close();
    file.open("acc." + username + ".txt");
    file << username << endl << password << endl << id << endl;
    file.close();
}
void login(){
    int choose;
    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    cout << "-----------------"<<endl;
    cin >> choose;
    if(choose == 2) return signup();
    else if(choose == 1) {
        P:
		bool status = IsloggedIn();
        if (!status) {
            cout << "False login" << endl;
            cout << "1. Login" << endl;
            cout << "2. Signup" << endl;
            cin >> choose;
            if(choose == 1) goto P;
            if(choose == 2) signup();
            }
        else  {
            cout << "Successfully logged in!" << endl;
        }
    }
    system("cls");
}

struct CustomerDetails
{   int bikenumber;
    char name[20];
    char address[20];
    char phonenumber[15];
    int period;
}s;

void add(){
    int a,i;
    char test;
    int number;
    string id;
    system("cls");
    cout << "Insert your ID: "; cin >> id;
    bool status = CheckFileIdExisting(id);
    if(status) {
    fstream file;
    file.open(id + ".txt", ios::out | ios::app);
    if(!file.eof())
    {
        N:
        cout<<"\n Enter bike number\t: ";
        cin>>number;
            if(number == s.bikenumber)
            {
                cout<<"\n\tTHIS BIKE IS ALREADY ON RENT.";
                goto N;
            }
        s.bikenumber = number;
        K:
            cout << "\n Enter Name\t\t: ";
            fflush(stdin);
            cin.getline(s.name, 20);
            if (strlen(s.name) > 20 || strlen(s.name) < 2)
            {
                cout << "\nInvalid!!\n\tThe maximum number for customer's name is less than 21 and more than 1.\n";
                goto K;
            }
            else
            {
                for (i = 0; i < strlen(s.name); i++)
                {
                    if (!isalpha(s.name[i]) && s.name[i] != ' ')
                    {
                        cout << "\nName contain invalid character. Please enter again.\n";
                        goto K;
                    }
                }
            }

        B:
            cout << "\n Enter Address\t\t:";
            cin.getline(s.address, 20);
            if (strlen(s.address) > 20 || strlen(s.address) < 2)
            {
                cout << "\nInvalid!!\n\tThe maximum number for customer's address is less than 21 and more than 1.\n";
                goto B;
            }
            else
            {
                for (i = 0; i < strlen(s.address); ++i)
                {
                    if (!isalnum(s.address[i]) && !isalpha(s.address[i]) && s.address[i] != ' ')
                    {
                        cout << "\nName contain invalid character. Please enter again.\n";
                    }
                }
            }
        O:
            cout << "\n Enter Phone Number\t: ";
            cin.getline(s.phonenumber, 15);
            if (strlen(s.phonenumber) != 10 || strlen(s.phonenumber) > 10)
            {
                cout << "\nPhone number should be of 10 numbers from 0-9. Please, enter valid number.\n";
                goto O;
            }
            for (i = 0; i < strlen(s.phonenumber); i++)
            {
                if (!isalnum(s.phonenumber[i]))
                {
                    cout << "\nThe phone number is invalid. Please, enter numbers only.\n";
                }
            }
        do
        {
            cout<<"\nEnter Time Period(\'x\'days)\t: ";
            cin>>s.period;
            if(s.period>10 || s.period<=0)
            {
                cout<<"\tInvalid!!\n\tThe maximum bike rental days for customer  is upto 10 days .\n";
            }
        }while(s.period>10 || s.period<=0);
        file << s.bikenumber << setw(19) << s.name << setw(13) << s.address << setw(20) << s.phonenumber << setw(15) << s.period << endl;
        cout<<"\n\n Your Desired Bike is rented successfully!!";
        file.close();
    }
    cout << "\n Press e key to exit,  any other key to add another customer detail: ";
    cin >> test;
    if (test != 'e')
        add();
    else
        mainmenu();
    }
}
void list()
{
    char test;
    string id;
    int ch;
    system("cls");
    cout << "enter your ID: ";
    cin >> id;
    ifstream file;
    file.open(id + ".txt");
    if(!file){
        cout << "Wrong id: " << endl;
        T:
        cout << "1. Continue enter another id: " << endl;
        cout << "2. Signup";
        cin >> ch;
        if(ch == 1) list();
        else if(ch == 2) signup();
        else {
            cout << "Invalid value, please try again. ";
            goto T;
        }
    } else
    {
    cout << setw(49) << "TABLE OF INFORMATION" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(5) << "Bikenumber" << setw(10)  << "Name" << setw(13) << "Address" << setw(21) << "Phonenumber" << setw(16) << "Period" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    while (!file.eof())
    {
        char line[255];
        file.getline(line, 255);
        cout << line << std::endl;
    }
    file.close();
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout <<"\n Press e key to exit,  any other key to add another customer detail:";
    cin >> test;
    if (test == 'e')
        mainmenu();
    else
        add();
    }
}
void Remove(){
    int linenum;
    string id;
    string line;
    system("cls");
    cout << "Enter your id: "; cin >> id;
    ifstream file(id + ".txt");
    string filename =  id + ".txt";
    ofstream temps("temp.txt");
if(!file)
{
cout << "No record added." << endl;
}
else{
    T:
    cout << "Enter the number of line you want to delete from the database: ";
    cin >> linenum;
    int count = 1;
    do{
        getline(file, line);
        if(count!=linenum){
            if(!file.eof()){
            temps << line << endl;}
         }
        else if(file.eof()){
            temps << line;
        }
        count++;
    }while(!file.eof());
    cout<<"\n\tSuccessfully deleted.\n";
    temps.close();
    file.close();
    remove(filename.c_str());
    rename("temp.txt",filename.c_str());
    mainmenu();
}
}
void getMoney(){
	system("cls");
	char test;
    string id;
    int num;
    char q;
    cout << "enter your ID: ";
    cin >> id;
    int overcharge;
    cout << "Enter bikenumber: " << endl;
    cin >> num;
    cout << "Is the bike overdue?(y/n)" << endl;
    cin >> q;
    if(q=='y'){
        cout << "Enter the number of days overdue: " << endl;
        cin>>overcharge;
        ifstream file(id+".txt");
        while(!file.eof()){
            file>>s.bikenumber>>s.name>>s.address>>s.phonenumber>>s.period;
            int day= s.period;
            if(num==s.bikenumber){
                Overdue p(2, day, overcharge);
                p.display();
                cout <<"\n Press e key to exit,  any other key to get another customer bill:";
    cin >> test;
    if (test == 'e')
        mainmenu();
    else
        getMoney();
            }
        }
    }
    else{
        ifstream file(id+".txt");
        while(!file.eof()){
            file>>s.bikenumber>>s.name>>s.address>>s.phonenumber>>s.period;
            int day= s.period;
            if(num==s.bikenumber){
                Money p(2, day);
                p.display();
                cout <<"\n Press e key to exit,  any other key to get another customer billl:";
    cin >> test;
    if (test == 'e')
        mainmenu();
    else
        getMoney();
            }
        }
    }
}
void mainmenu(){
    int i=0;
    int option;
    system("cls");
    while (1)
    {
        system("cls");
        for(i=0;i<80;i++)
        cout << "-";
        cout << "\n";
        cout << "   ---------------------->>>>  |MAIN MENU|  <<<<------------------------ \n";
        for(i=0;i<80;i++)
        cout << "-";
        cout << "\n";
        cout << "\t\t *Select and Enter Your Choice From Menu*:";
        cout << "\n\n";
        cout << "\n==========================";
        cout << " \n Enter 1 ->> Rent a bike";
        cout << "\n==========================";
        cout << "\n Enter 2 ->> View Rental Record";
        cout << "\n=================================";
        cout << " \n Enter 3 ->> Remove Rental Record";
        cout << "\n===================================";
        cout << " \n Enter 4 ->> Get Rental Bill";
        cout << "\n===================================";
        cout << " \n Enter 5 ->> Exit";
        cout << "\n=================";
        cout <<"\n \n";
        cin >> option;
        switch(option)
        {
            case 1:
                add();break;
            case 2:
                list();break;
            case 3:
                Remove();break;
            case 4:
                getMoney(); break;
            case 5:
                system("cls");
                cout << "\n\t THANK YOU FOR USING OUR SERVICE";
                exit(0);
                break;
            default:
                system("cls");
                cout << "Incorrect Input";
                cout << "\n Press any key to continue";
        }
    }
}
int main(int argc,char*argv[]){
	int x=0,y=3;
    cout << endl << endl << endl << endl;
	SetColor(0,0);cout << "\t\t\t";
	SetColor(x,y);cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
	SetColor(0,0);cout << "\t\t\t";
	SetColor(x,y);cout << "\xB2\xB2                                                       \xB2\xB2" << endl;
	SetColor(0,0);cout << "\t\t\t";
	SetColor(x,y);cout << "\xB2\xB2" << "      W E L C O M E   T O   B O O K I N G   A P P" << "      \xB2\xB2" << endl;
	SetColor(0,0);cout << "\t\t\t";
	SetColor(x,y);cout << "\xB2\xB2                                                       \xB2\xB2" << endl;
	SetColor(0,0);cout << "\t\t\t" ;
	SetColor(x,y);cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    SetColor(0,0);cout << "\t\t\t";
	SetColor(x,y);cout << "\n\n\n";
	SetColor(0,0);cout << "\t\t\t\t\t";
    SetColor(0,3);
    sleep(3);
    system("cls");
    login();
    mainmenu();
}
