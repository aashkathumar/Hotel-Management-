#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<fstream>
using namespace std;
struct Customer
{
    int room_no;
    char name[30];
    int phone_no;
    char passport_no[9];
    int cin_date;
    int cin_month;
    int cin_year;
    int cout_date;
    int cout_month;
    int cout_year;
    int cstay;
    Customer *next;
} *start, *rear, *save, *ptr, *np, *newptr;

Customer* add_customer(char n[30], int r, int pn, char pass[9], int id, int im, int iy, int od, int om, int oy);//CREATES A CUSTOMER NODE
void bookingmenu();//THIS MENU ALLOWS ACCESS TO FUNCTIONS TO BOOK A ROOM, MAIN MENU AND EXIT
void Insert(Customer*);//INSERTS THE DATA OF THE CUSTOMER TO THE LINKED LIST
void enter();
class Hotel
{
    public:

        int ctr=0;
        void display_allrooms();    //DISPLAYS THE DETAILS OF ALL THE OCCUPIED ROOMS
        void display_specific();    //DISPLAYS THE DETAILS OF A SPECIFIC CUSTOMER
        void modify();              //ALLOWS YOU TO MODIFY DATA OF THE CUSTOMER
        void Delete(Customer **, int);//ALLOWS YOU TO DELETE A SPECIFIC CUSTOMER RECORD
        void mainmenu();              /*MENU ALLOWING YOU TO ACCESS TO FUNCTIONS:- VIEW, MODIFY AND DELETE SPECIFIC CUSTOMER RECORDS,
                                        VIEW ALL CUSTOMER RECORDS, BILL AND VIEW PREVIOUS RECORDS*/
        void bill(int);               //DISPLAYS THE BILL OF THE CUSTOMER
        int status(int);              //LETS US KNOW WHETHER THE ROOM IS OCCUPIED OR NOT
        void intro();                //DETAILS OF THE STUDENT
        void add_tofile();           //ADDS THE NAME OF THE USER BOOKING THE ROOM TO THE FILE
        void read_file();            //DISPLAYS THE NAMES OF PEOPLE WHO BOOKED A ROOM IN THE HOTEL
        int stay(int);               //CALCULATES THE DURATION OF STAY OF THE CUSTOMER
};
/*MENU ALLOWING YOU TO ACCESS TO FUNCTIONS:- VIEW, MODIFY AND DELETE SPECIFIC CUSTOMER RECORDS,
VIEW ALL CUSTOMER RECORDS, BILL AND VIEW PREVIOUS RECORDS*/
void Hotel::mainmenu()
{
    Hotel h2;
    int ch2, rn, flag=0, r, st;
    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\t\t===================================";
    cout<<"\n\t\t\t\t\t\t\t\t            MAIN MENU ";
    cout<<"\n\t\t\t\t\t\t\t\t===================================";
    cout<<"\n\t\t\t\t\t\t\t\t1.VIEW ALL ROOM DETAILS";
    cout<<"\n\t\t\t\t\t\t\t\t2.VIEW SPECIFIC CUSTOMER DETAILS";
    cout<<"\n\t\t\t\t\t\t\t\t3.MODIFY CUSTOMER DETAILS";
    cout<<"\n\t\t\t\t\t\t\t\t4.DELETE A CUSTOMER RECORD";
    cout<<"\n\t\t\t\t\t\t\t\t5.BILL";
    cout<<"\n\t\t\t\t\t\t\t\t6.VIEW PREVIOUS RECORDS FROM FILE";
    cout<<"\n\t\t\t\t\t\t\t\t7.BACK TO BOOKING MENU";
    cout<<endl<<"\n\t\t\t\t\t\t\t\tENTER CHOICE (1-7): ";
    cin>>ch2;
    switch(ch2)
    {
	    case 1: system("cls");
                display_allrooms();
                break;
	    case 2: system("cls");
                display_specific();
                break;
	    case 3: system("cls");
                modify();
                break;
        case 4: system("cls");
                cout<<"\t\t\t\t\t\t\t\tENTER ROOM NUMBER TO DELETE: ";
                cin>>r;
                Delete(&start,r);
                break;
        case 5: system("cls");
                cout<<endl<<"\t\t\t\t\t\t\t\tENTER ROOM NUMBER FOR CALCULATING BILLING: ";
                cin>>rn;
                bill(rn);
                break;
        case 6: system("cls");
                read_file();
                break;
        case 7: bookingmenu();
                break;
       default: cout<<"\t\t\t\t\t\t\t\tINCORRECT CHOICE!!!TRY AGAIN!!!"<<endl;
    }
    mainmenu();
}
//CREATES A CUSTOMER NODE
Customer *add_customer(char n[30], int r, int pn, char pass[9], int id, int im, int iy, int od, int om, int oy)
{
    ptr = new Customer;
    ptr->room_no=r;
    strcpy(ptr->name,n);
    ptr->phone_no=pn;
    strcpy(ptr->passport_no,pass);
    ptr->cin_date=id;
    ptr->cin_month=im;
    ptr->cin_year=iy;
    ptr->cout_date=od;
    ptr->cout_month=om;
    ptr->cout_year=oy;
    ptr->next=NULL;
    return ptr;
}
//INSERTS THE DATA OF THE CUSTOMER TO THE LINKED LIST
void Insert(Customer* np)
{
    if(start==NULL)
    {
        start=rear=np;
    }
    else
    {
        rear->next=np;
        rear=np;
    }
    cout<<endl<<"\t\t\t\t\t\t\t\tROOM BOOKED!!!"<<endl;

    enter();
}
//DISPLAYS THE DETAILS OF ALL THE OCCUPIED ROOMS
void Hotel::display_allrooms()
{
    np=start;
    cout<<endl<<"\n\n\t\t\tLIST OF ALLOTTED ROOMS\n\n";
    cout<<"\n==================================================================================";
    cout<<"\n    ROOM NUMBER    NAME          PASSPORT NUMBER     PHONE NUMBER";
    cout<<"\n==================================================================================";
    while(np!=NULL)
    {
        cout<<endl<<"       "<<np->room_no<<"         "<<np->name<<"        "<<np->passport_no<<"            "<<np->phone_no<<endl;
        np=np->next;
    }
    cout<<endl;
    enter();
}
//DISPLAYS THE DETAILS OF A SPECIFIC CUSTOMER
void Hotel::display_specific()
{
    int r, flag=0;
    np=start;
    cout<<"\n\t\t\t\t\t\t\t\tENTER ROOM NUMBER: ";
    cin>>r;
    while(np!=NULL)
    {
        if(np->room_no==r)
        {
            cout<<endl<<"\n\t\t\t\t\t\t\t\t======================";
            cout<<endl<<"\t\t\t\t\t\t\t\t   CUSTOMER DETAILS";
            cout<<endl<<"\t\t\t\t\t\t\t\t======================";
            cout<<endl<<"\t\t\t\t\t\t\t\tROOM NUMBER: "<<np->room_no;
            cout<<endl<<"\t\t\t\t\t\t\t\tNAME: "<<np->name;
            cout<<endl<<"\t\t\t\t\t\t\t\tPHONE NUMBER: "<<np->phone_no;
            cout<<endl<<"\t\t\t\t\t\t\t\tPASSPORT NUMBER: "<<np->passport_no;
            cout<<endl<<"\t\t\t\t\t\t\t\tCHECK - IN: "<<np->cin_date<<"/"<<np->cin_month<<"/"<<np->cin_year;
            cout<<endl<<"\t\t\t\t\t\t\t\tCHECK - OUT: "<<np->cout_date<<"/"<<np->cout_month<<"/"<<np->cout_year;
            cout<<endl;
            flag=1;
        }
        np=np->next;
    }
    if(flag!=1)
        cout<<endl<<"\t\t\t\t\t\t\t\tROOM NOT FOUND/ VACANT!!!"<<endl;

    enter();
}
//ALLOWS YOU TO MODIFY DATA OF THE CUSTOMER
void Hotel::modify()
{
    int r, flag=0;
    np=start;
    cout<<"\t\t\t\t\t\t\t\tENTER ROOM NUMBER: ";
    cin>>r;
    while(np!=NULL)
    {
        if(np->room_no==r)
        {
            cout<<"\n\n\t\t\t\t\t\t\t\t=============================";
            cout<<"\n\t\t\t\t\t\t\t\t   ENTER DETAILS TO UPDATE";
            cout<<"\n\t\t\t\t\t\t\t\t=============================";
            cout<<"\n\t\t\t\t\t\t\t\tNAME: ";
            cin>>np->name;
            cout<<"\n\t\t\t\t\t\t\t\tPASSPORT NUMBER: ";
            cin>>np->passport_no;
            cout<<"\n\t\t\t\t\t\t\t\tPHONE NUMBER: ";
            cin>>np->phone_no;
            cout<<"\n\t\t\t\t\t\t\t\tRECORD UPDATED!!!"<<endl;
            flag=1;
        }
        np=np->next;
    }
    if(flag!=1)
        cout<<endl<<"\t\t\t\t\t\t\t\tROOM NOT FOUND/ VACANT!!!"<<endl;

    enter();
}
//ALLOWS YOU TO DELETE A SPECIFIC CUSTOMER RECORD
void Hotel::Delete(Customer** head, int rn)
{
    int flag=0;
    Customer* temp=*head;
    Customer* prev=NULL;
    if (temp!=NULL&&temp->room_no==rn)
    {
        *head=temp->next;
        delete temp;
        flag=1;
        return;
    }
    else
    {
        while (temp!=NULL&&temp->room_no!=rn)
        {
            prev=temp;
            temp=temp->next;
        }
        if (temp==NULL)
            return;
        prev->next=temp->next;
        delete temp;
        flag=1;
    }
    if(flag!=1)
        cout<<endl<<"\t\t\t\t\t\t\t\tROOM NOT FOUND/ VACANT!!!"<<endl;
    else
    {
        cout<<endl<<"\t\t\t\t\t\t\t\tCUSTOMER RECORD DELETED!!!"<<endl;
    }
    enter();
}
//DISPLAYS THE BILL OF THE CUSTOMER
void Hotel::bill(int r)
{
    system("cls");
    int flag=0, b, s;
    float gst, f;
    s=stay(r);
    np=start;
    while(np!=NULL)
    {
        if(np->room_no==r)
        {
            cout<<"\n\t\t\t\t\t\t\t\t===============================\n";
            cout<<"\n\t\t\t\t\t\t\t\t          || BILL ||"<<endl<<endl;
            if(np->room_no>=101&&np->room_no<=120)
            {
                b = s*1000;
                gst = b*0.18;
                f = b+gst;
                cout<<"\t\t\t\t\t\t\t\tROOM NUMBER: "<<r<<endl;
                cout<<"\t\t\t\t\t\t\t\tDURATION: "<<s<<" days"<<endl;
                cout<<"\t\t\t\t\t\t\t\tRATE PER DAY: Rs 1000"<<endl;
                cout<<"\t\t\t\t\t\t\t\tBILL: Rs "<<b<<endl;
                cout<<"\t\t\t\t\t\t\t\tGST(18%): Rs "<<gst<<endl;
                cout<<"\t\t\t\t\t\t\t\tFINAL BILL: Rs "<<f<<endl;
            }
            else if(np->room_no>=201&&np->room_no<=220)
            {
                b = s*2000;
                gst = b*0.18;
                f = b+gst;
                cout<<"\t\t\t\t\t\t\t\tROOM NUMBER: "<<r<<endl;
                cout<<"\t\t\t\t\t\t\t\tDURATION: "<<s<<" days"<<endl;
                cout<<"\t\t\t\t\t\t\t\tRATE PER DAY: Rs 2000"<<endl;
                cout<<"\t\t\t\t\t\t\t\tBILL: Rs "<<b<<endl;
                cout<<"\t\t\t\t\t\t\t\tGST(18%): Rs "<<gst<<endl;
                cout<<"\t\t\t\t\t\t\t\tFINAL BILL: Rs "<<f<<endl;
            }
            else
            {
                b = s*5000;
                gst = b*0.18;
                f = b+gst;
                cout<<"\t\t\t\t\t\t\t\tROOM NUMBER: "<<r<<endl;
                cout<<"\t\t\t\t\t\t\t\tDURATION: "<<s<<" days"<<endl;
                cout<<"\t\t\t\t\t\t\t\tRATE PER DAY: Rs 5000"<<endl;
                cout<<"\t\t\t\t\t\t\t\tBILL = Rs "<<b<<endl;
                cout<<"\t\t\t\t\t\t\t\tGST(18%): Rs "<<gst<<endl;
                cout<<"\t\t\t\t\t\t\t\tFINAL BILL: Rs "<<f<<endl;
            }
            cout<<"\n\t\t\t\t\t\t\t\t===============================";
        }
        np=np->next;
    }

    enter();
}
//LETS US KNOW WHETHER THE ROOM IS OCCUPIED OR NOT
int Hotel::status(int r)
{
    int flag=0;
    np=start;
    while(np!=NULL)
    {
        if(np->room_no==r)
        {
            flag=1;
            break;
        }

        np = np->next;
    }
    return flag;

}
//CALCULATES THE DURATION OF STAY OF THE CUSTOMER
int Hotel::stay(int r)
{
    int days;
    np=start;
    while(np!=NULL)
    {
        if(np->room_no==r)
        {
            if((np->cin_month%2!=0)&&(np->cin_month!=2)&&(np->cout_month%2==0))
            {
                days = np->cout_date + ((31-np->cin_date) + 1);
            }
            else if((np->cin_month%2==0)&&(np->cout_month%2!=0))
            {
                days = np->cout_date + ((30-np->cin_date) + 1);
            }
            else if (np->cin_month==np->cout_month)
            {
                days = (np->cout_date - np->cin_date) + 1;
            }
            //SPECIAL CASE FOR LEAP YEAR
            else if((((np->cin_year%4==0)&&(np->cin_year%100!=0))||(np->cin_year%400==0))&&((np->cin_month==2)&&(np->cout_month==3)))
            {
                days = np->cout_date + ((29-np->cin_date) + 1);
            }
            else if((np->cin_month==2)&&(np->cout_month==3))
            {
                days = np->cout_date + ((28-np->cin_date) + 1);
            }
        }
        np=np->next;
    }
        return days;
}
void Hotel::intro()
{
    system("cls");
    cout<<endl<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPROJECT ON HOTEL MANAGEMENT"<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\tSTUDENT 1";
    cout<<endl<<"\t\t\t\t\t\t\t\tNAME: AASHKA ARVINDBHAI THUMAR";
    cout<<endl<<"\t\t\t\t\t\t\t\tSTUDENT ID : 202001205";
    cout<<endl<<endl<<"\t\t\t\t\t\t\t\tSTUDENT 2";
    cout<<endl<<"\t\t\t\t\t\t\t\tNAME: HITARTH VYAS";
    cout<<endl<<"\t\t\t\t\t\t\t\tSTUDENT ID: 202001457"<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE!!!";
    getch();
}
//ADDS THE NAME OF THE USER BOOKING THE ROOM TO THE FILE
void Hotel::add_tofile()
{
    system("cls");
    string user;
    cout<<"\n\n\t\t\t\t\t\t\t\t========================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\tDETAILS OF THE PERSON MAKING THE BOOKING"<<endl;
    cout<<"\t\t\t\t\t\t\t\t========================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\tENTER YOUR NAME: ";
    cin>>user;
    ofstream fout;
    fout.open("userrecords.txt",ios::app);
    fout<<user<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\tNAME ADDED TO FILE"<<endl;
    fout.close();
    cout<<endl<<"\t\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE!!!";
    getch();
}
//DISPLAYS THE NAMES OF PEOPLE WHO BOOKED A ROOM IN THE HOTEL
void Hotel::read_file()
{
    int i=1;
    cout<<"\n\n\t\t\t\t\t\t\t\t================"<<endl;
    cout<<"\t\t\t\t\t\t\t\tPREVIOUS RECORDS"<<endl;
    cout<<"\t\t\t\t\t\t\t\t================"<<endl;
    string u;
    ifstream fin;
    fin.open("userrecords.txt",ios::in);
    while(getline(fin, u))
    {
        fin>>u;
        cout<<"\t\t\t\t\t\t\t\t"<<"    "<<u<<endl;
    }
    fin.close();
    cout<<endl<<"\t\t\t\t\t\t\t\tPRESS ENTER TO CONTINUE!!!"<<endl;
    getch();
}
//THIS MENU ALLOWS ACCESS TO FUNCTIONS TO BOOK A ROOM, MAIN MENU AND EXIT
void bookingmenu()
{
    Hotel h1;
    int ch, flag1=0;
    system("cls");
    cout<<endl;
    cout<<endl<<"\n\t\t\t\t\t\t\t\t==================="<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\t    BOOKING MENU"<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\t==================="<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\t1. BOOK A ROOM"<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\t2. MAIN MENU"<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\t3. EXIT"<<endl;
    cout<<endl<<"\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
    cin>>ch;
    switch(ch)
    {
        case 1: {
                    h1.add_tofile();
                    system("cls");
                    char cname[30], pno[9];
                    int r, phno, ind, inm, iny, outd, outm, outy, flag=0, rs, cho;
                    cout<<endl<<"\n\t\t\t\t\t\t\t\t=================================";
                    cout<<endl<<"\t\t\t\t\t\t\t\t           ROOM GUIDE";
                    cout<<endl<<"\t\t\t\t\t\t\t\t=================================";
                    cout<<endl<<"\t\t\t\t\t\t\t\tROOMS NUMBER: ";
                    cout<<endl<<"\t\t\t\t\t\t\t\t1. TOTAL NO. OF ROOMS - 50";
                    cout<<endl<<"\t\t\t\t\t\t\t\t2. BASIC ROOMS from 101 - 120";
                    cout<<endl<<"\t\t\t\t\t\t\t\t3. PREMIUM ROOMS from 201 - 220";
                    cout<<endl<<"\t\t\t\t\t\t\t\t4. SUITES from 301 - 310";
                    cout<<endl<<"\t\t\t\t\t\t\t\tSELECT ROOMS NUMBER: ";
                    cin>>r;
                    if(((r>=101)&&(r<=120))||((r>=201)&&(r<=220))||((r>=301)&&(r<=310)))
                    {
                        rs=h1.status(r);
                        if(rs)
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\tSORRY!!!ROOM NOT AVAILABLE....TRY LOOKING FOR ANOTHER ROOM"<<endl;
                            goto Continue;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\tBOOKING UNDER THE NAME OF: ";
                            cin>>cname;
                            cout<<endl;
                            cout<<"\t\t\t\t\t\t\t\tPHONE NUMBER: ";
                            cin>>phno;
                            cout<<endl;
                            cout<<"\t\t\t\t\t\t\t\tPASSPORT NUMBER: ";
                            cin>>pno;
                            cout<<endl;
                            cout<<"\t\t\t\t\t\t\t\tCHECK - IN DATE (dd): ";
                            cin>>ind;
                            cout<<"\t\t\t\t\t\t\t\tCHECK - IN MONTH (mm): ";
                            cin>>inm;
                            cout<<"\t\t\t\t\t\t\t\tCHECK - IN YEAR (yyyy): ";
                            cin>>iny;
                            cout<<endl;
                            cout<<"\t\t\t\t\t\t\t\tCHECK - OUT DATE (dd): ";
                            cin>>outd;
                            cout<<"\t\t\t\t\t\t\t\tCHECK - OUT MONTH (mm): ";
                            cin>>outm;
                            cout<<"\t\t\t\t\t\t\t\tCHECK - OUT YEAR (yyyy): ";
                            cin>>outy;
                        }
                        newptr = add_customer(cname, r, phno, pno, ind, inm, iny, outd, outm, outy);
                        Insert(newptr);
                        flag=1;
                    }
                    else
                    {
                        cout<<endl<<"\t\t\t\t\t\t\t\tROOM NOT FOUND....TRY BOOKING AGAIN!!!"<<endl;
                    }
                    Continue:
                    break;
                }
        case 2: {
                    system("cls");
                    h1.mainmenu();
                    break;
                }
        case 3: {
                    flag1=1;
                    exit(0);
                    break;
                }
       default: {
                    cout<<endl<<"\t\t\t\t\t\t\t\tINCORRECT CHOICE"<<endl;
                    break;
                }
    }
    bookingmenu();
}
void enter()
{
    cout<<"\n\t\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE";
    getchar();
    getchar();
    return;
}
int main()
{
    Hotel H;
    H.intro();
    cout<<endl;
    bookingmenu();
    getch();
    return 0;
}
