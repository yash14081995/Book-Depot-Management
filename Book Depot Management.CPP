#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct book
{
double ucode;
int classno;
char name[30];
float price;
int qty;
};

struct order
{
double orderno;
char cname[30];
float total;
int tbook;
book obook[10];
};

//FOR MANAGE BOOK STOCK
void searchbook();
void addbook();
void delbook();
void editbook();

//FOR MANAGE ORDER
void neworder();
void searchorder();
void delorder();

//FOR OTHER TASKS
void tbookdetail();
void torderdetail();

void main()
{
clrscr();
int mchoice=0, mbook=0, morder=0, mtask = 0;
cout<<"-----------------------------Swiss Book Depot-----------------------------------";
book2main :
order2main :
task2main :
clrscr();
cout<<endl<<endl<<"Welcome To The Main Menu. Select A Task."<<endl;
cout<<endl<<"1.Manage Book Stock."<<endl;
cout<<endl<<"2.Manage Book Orders"<<endl;
cout<<endl<<"3.Other Tasks."<<endl;
cout<<endl<<"(PRESS 0 TO QUIT)";
cout<<endl<<endl;
cout<<"Enter Your Choice  -  ";
cin>>mchoice;

if(mchoice==0)
goto end ;

//BOOK OPERATION
if(mchoice==1)
{
btop:
clrscr();
cout<<endl<<endl<<endl<<"Available Book Operations Are  -  ";
cout<<endl<<endl<<endl;
cout<<"1. Add A New Book";
cout<<endl<<endl<<"2. Search For A Book";
cout<<endl<<endl<<"3. Delete A Book";
cout<<endl<<endl<<"4. Edit Existing Book Details";
cout<<endl<<endl<<"5. Return To The Main Menu";
cout<<endl<<endl;
cout<<"Enter Your Choice  -  ";
cin>>mbook;
if(mbook==1)
addbook();
if(mbook==2)
searchbook();
if(mbook==3)
delbook();
if(mbook==4)
editbook();
if(mbook==5)
goto book2main ;
clrscr();
goto btop ;
}//END OF MCHOICE == 1

//ORDER OPERATION
if(mchoice==2)
{
otop :
clrscr();
cout<<endl<<endl<<endl<<"Available Order Operations Are  -  ";
cout<<endl<<endl<<endl;
cout<<"1. Place A New Order";
cout<<endl<<endl<<"2. Search Order Details";
cout<<endl<<endl<<"3. Delete An Order";
cout<<endl<<endl<<"4. Return To The Main Menu";
cout<<endl<<endl;
cout<<"Enter Your Choice  -  ";
cin>>morder;
if(morder==1)
neworder();
if(morder==2)
searchorder();
if(morder==3)
delorder();
if(morder==4)
goto order2main ;
clrscr();
goto otop ;
}
//END OF MCHOICE == 2

//OTHER TASKS
if(mchoice==3)
{
ttop :
clrscr();
cout<<endl<<endl<<endl<<"Available Utility Tasks Are  -  ";
cout<<endl<<endl<<endl;
cout<<"1. View Details Of All Books In The Depot.";
cout<<endl<<endl<<"2. View All Orders Placed. ";
cout<<endl<<endl<<"3. Return To The Main Menu";
cout<<endl<<endl;
cout<<"Enter Your Choice  -  ";
cin>>mtask;
if(mtask==1)
tbookdetail();
if(mtask==2)
torderdetail();
if(mtask==3)
goto task2main ;
clrscr();
goto ttop ;
}//END OF MCHOICE == 3

end:
getch();
}//END OF MAIN

//SEARCH FUNCTION FOR BOOK MENU
void searchbook()
{
clrscr();
int flag = 0;
book b1;
ifstream sfile;
sfile.open("mainbookstock", ios::in | ios::binary);
sfile.seekg(0);
int schoice=0 ;
cout<<endl<<endl<<"----------Select The Preferred Search Category----------";
cout<<endl<<endl<<endl;
cout<<"1. By Unique Book Code"<<endl<<endl;
cout<<"2. By Book Name "<<endl<<endl;
cout<<endl<<"Enter Your Choice  -  ";
cin>>schoice;
cout<<endl<<endl;
if(schoice==1)
{
double uno=0 ;
cout<<endl<<"Enter The Unique Number Of The Book - ";
cin>>uno;
while(sfile.read((char*)&b1, sizeof(b1)))
{
if(uno==b1.ucode)
{
cout<<endl<<endl;
cout<<"THE DETAILS OF THE BOOK ARE  -  ";
cout<<endl<<endl;
cout<<"UNIQUE CODE = "<<b1.ucode;
cout<<endl<<endl<<"CLASS = "<<b1.classno;
cout<<endl<<endl<<"NAME = ";
puts(b1.name);
cout<<endl<<endl<<"PRICE = "<<b1.price;
cout<<endl<<endl<<"STOCK = "<<b1.qty;
cout<<endl<<endl;
flag = 1;
}
}
if(flag==0)
cout<<endl<<endl<<"!!!!!!!!!!!!!!!BOOK NOT FOUND!!!!!!!!!!!!!!!";
}
if(schoice==2)
{
char sname[30];
cout<<endl<<"Enter The Name Of The Book -  ";
gets(sname);
while(sfile.read((char*)&b1, sizeof(b1)))
{
if((strcmp(sname,b1.name)==0))
{
cout<<endl<<endl;
cout<<"THE DETAILS OF THE BOOK ARE  -  ";
cout<<endl<<endl;
cout<<"UNIQUE CODE = "<<b1.ucode;
cout<<endl<<endl<<"CLASS = "<<b1.classno;
cout<<endl<<endl<<"NAME = ";
puts(b1.name);
cout<<endl<<endl<<"PRICE = "<<b1.price;
cout<<endl<<endl<<"STOCK = "<<b1.qty;
cout<<endl<<endl;
flag = 1;
}
}
if(flag==0)
cout<<endl<<endl<<"!!!!!!!!!!!!!!!BOOK NOT FOUND!!!!!!!!!!!!!!!";
}
cout<<endl<<endl<<endl<<"TASK EXECUTED. RETURNING TO THE MENU.";
sfile.close();
getch();
}
//END

//ADD FUNCTION FOR BOOK MENU
void addbook()
{
clrscr();
book b2;
char ch;
ofstream fadd;
fadd.open("mainbookstock", ios::out | ios::app | ios::binary);
char cadd='y';
while(cadd=='y' || cadd=='Y')
{
cout<<"ENTER BOOK DETAILS";
cout<<endl<<endl;
cout<<"ENTER THE BOOK UNIQUE CODE - ";
cin>>b2.ucode;
cin.get(ch);
cout<<endl<<"ENTER THE BOOK NAME -  ";
cin.getline(b2.name,30);
cout<<endl<<"ENTER THE BOOK CLASS - ";
cin>>b2.classno;
cout<<endl<<"ENTER THE BOOK PRICE - ";
cin>>b2.price;
cout<<endl<<"ENTER THE BOOK STOCK AVAILABLE - ";
cin>>b2.qty;
fadd.write((char*)&b2, sizeof(b2));
cout<<endl<<endl<<endl<<"WANT TO ENTER ADD MORE BOOKS  -  (y/n) ";
cin>>cadd;
clrscr();
}
cout<<endl<<endl<<"TASK EXECUTED. RETURNING TO THE MENU";
fadd.close();
getch();
}
//END

//DELETE FUNCTION FOR BOOK
void delbook()
{
book b3;
double dbno=0 ;
int flag=0;
char confirm = 'n';
ifstream mainfile;
ofstream temp;
mainfile.open("mainbookstock", ios::in | ios::binary);
temp.open("newmbs", ios::out | ios::binary);
mainfile.seekg(0);
clrscr();
cout<<"Enter The Unique Book Code Of The Book You Want To Delete - ";
cin>>dbno;
while(mainfile.read((char*)&b3, sizeof(b3)))
{
if(b3.ucode==dbno)
{
cout<<endl<<endl<<"The Details Of The Book Are - ";
cout<<endl<<endl;
cout<<"UNIQUE CODE = "<<b3.ucode;
cout<<endl<<endl<<"CLASS = "<<b3.classno;
cout<<endl<<endl<<"NAME = ";
puts(b3.name);
cout<<endl<<endl<<"PRICE = "<<b3.price;
cout<<endl<<endl<<"STOCK = "<<b3.qty;
flag = 1;
cout<<endl<<endl<<"Are You Sure You Want To Delete This Book - (y/n) ";
cin>>confirm;
if(confirm=='y'|| confirm=='Y')
cout<<endl<<endl<<"THE BOOK HAS BEEN DELETED FROM THE RECORD. ";
if(confirm == 'n'||confirm == 'N')
temp.write((char*)&b3, sizeof(b3));
}
else
temp.write((char*)&b3, sizeof(b3));
}
if(!flag)
cout<<endl<<endl<<"!!!!!!!!!!!!!!!NO SUCH BOOK EXISTS!!!!!!!!!!!!!!!";
mainfile.close();
temp.close();
remove("mainbookstock");
rename("newmbs","mainbookstock");
cout<<endl<<endl<<"TASK EXECUTED. RETURNING TO THE MENU";
getch();
}
//END

//EDIT FUNCTION FOR BOOK
void editbook()
{
clrscr();
book b4;
fstream efile;
efile.open("mainbookstock", ios::in | ios::out | ios::binary);
efile.seekg(0);
double mbno=0 ;
int flag = 0;
cout<<"Enter The Unique Book Code Of The Book To Be Edited - ";
cin>>mbno;
while(efile.read((char*)&b4, sizeof(b4)))
{
if(b4.ucode==mbno)
{
cout<<endl<<endl<<"The PRESENT Details Of The Book Are - ";
cout<<endl<<endl;
cout<<"UNIQUE CODE = "<<b4.ucode;
cout<<endl<<endl<<"CLASS = "<<b4.classno;
cout<<endl<<endl<<"NAME = ";
puts(b4.name);
cout<<endl<<endl<<"PRICE = "<<b4.price;
cout<<endl<<endl<<"STOCK = "<<b4.qty;
cout<<endl<<endl<<"ENTER THE NEW DETAILS FOR THE BOOK  -  ";
char mname[30];
double mucode;
int mclassno;
float mprice;
int mqty;
cout<<endl<<endl;
cout<<endl<<"ENTER NEW UNIQUE CODE - ";
cin>>mucode;
cout<<endl<<"ENTER NEW CLASS NUMBER - ";
cin>>mclassno;
cout<<endl<<"ENTER NEW NAME - ";
gets(mname);
fflush(stdin);
cout<<endl<<"ENTER NEW PRICE - ";
cin>>mprice;
cout<<endl<<"ENTER NEW STOCK - ";
cin>>mqty;
b4.ucode=mucode;
b4.classno=mclassno;
strcpy(b4.name,mname);
b4.price=mprice;
b4.qty+=mqty;
efile.seekp(-46,ios::cur);
efile.write((char*)&b4, sizeof(b4));
cout<<endl<<endl<<"BOOK IS MODIFIED";
flag = 1;
break;
}
}
if(flag==0)
cout<<endl<<endl<<"!!!!!!!!!!!!!!!NO SUCH BOOK EXISTS!!!!!!!!!!!!!!!";
cout<<endl<<endl<<"TASK EXECUTED. RETURNING TO THE MENU. ";
efile.close();
getch();
}
//END

//FUNCTION TO CREATE AN ORDER
void neworder()
{
clrscr();
char oname[30];
int i=0, oqty=0 ;
int flag=0, flage=0;
char ochoice='y';
order o1;
book b5;
fstream file5;
file5.open("orders", ios::in | ios::out | ios::app | ios::binary);
fstream file6;
file6.open("mainbookstock", ios::in | ios::out | ios::ate | ios::binary);
o1.total=0;
long no=0;
file5.seekp(0,ios::end);
no=file5.tellp();
int bno;
bno=no/sizeof(o1);
o1.orderno=bno+1;
cout<<"ORDER NUMBER - "<<o1.orderno;
cout<<endl<<endl<<"ONLY TEN DIFFERENT TYPES OF BOOKS WILL BE INCLUDED PER BILL ";
cout<<endl<<endl<<"ENTER THE NAME OF THE BUYING PARTY - ";
gets(o1.cname);
while(ochoice=='y'||ochoice=='Y'&&i<10)
{
flag=0;
file6.seekg(0);
cout<<endl<<"ENTER THE NAME OF BOOK YOU WANT TO ORDER - ";
gets(oname);
file6.seekg(0);
while(file6.read((char*)&b5, sizeof(b5)))
{
if((strcmp(oname,b5.name)==0))
{
cout<<endl<<endl<<"BOOK FOUND! "<<endl<<endl;
cout<<"AVAILABLE STOCK IS - "<<b5.qty;
flage=1;
if(b5.qty==0)
goto ends ;
getch();
break;
}
}
if(flage==0)
goto nflage ;
fflush(stdin);
cout<<endl<<endl<<"ENTER THE QUANTITY YOU WANT TO ORDER - ";
cin>>oqty;
if(oqty==0)
goto endf ;
file6.seekg(0);
while(file6.read((char*)&b5, sizeof(b5)))
{
if((strcmp(oname,b5.name)==0))
{
flag = 1;
if(oqty<=b5.qty)
{
cout<<endl<<endl<<"BOOK QUANTITY REQUIRED IS AVAILABLE. BOOK HAS BEEN ADDED TO YOUR ORDER.";
o1.obook[i]=b5;
b5.qty-=oqty;
o1.obook[i].qty=oqty;
o1.total+=(b5.price*oqty);
file6.seekp(-46,ios::cur);
file6.write((char*)&b5, sizeof(b5));
i++;
break ;
}
else
{
ends :
cout<<endl<<endl<<"SORRY, BOOK IS SHORT OF STOCK REQUIRED."<<endl;
goto shortstock;
}
}
}
if(flag==0)
{
nflage :
cout<<endl<<endl<<"!!!!!!!!!!!!!!!SORRY, BOOK NOT FOUND!!!!!!!!!!!!!!!";
cout<<endl;
goto shortstock ;
}
shortstock :
cout<<endl<<endl<<"Do You Want To Add More Books - (y/n)";
cin>>ochoice;
clrscr();
}
if(i==10)
cout<<endl<<"MAXIMUM ORDER LIMIT HAS BEEN REACHED OF TEN BOOKS PER ORDER. ";
if(o1.total==0)
goto endf;
o1.tbook=i;
file5.write((char*)&o1, sizeof(o1));
cout<<endl<<endl<<"ORDER SUCCESSFULLY CREATED. THANK YOU FOR SHOPPING. ";
endf :
file5.close();
file6.close();
cout<<endl<<endl<<"TASK EXECUTED. RETURNING TO THE MAIN MENU. ";
getch();
}//END

//SEARCH FUNCTION FOR ORDER
void searchorder()
{
clrscr();
int flag = 0;
order o2;
ifstream ofile;
ofile.open("orders", ios::in | ios::binary);
ofile.seekg(0);
int schoice=0 ;
cout<<endl<<endl<<"----------Select The Preferred Search Category----------";
cout<<endl<<endl<<endl;
cout<<"1. By Order Number "<<endl<<endl;
cout<<"2. By Customer Name "<<endl<<endl;
cout<<endl<<"Enter Your Choice  -  ";
cin>>schoice;
cout<<endl<<endl;
if(schoice==1)
{
double ono=0 ;
cout<<endl<<"Enter The Order Number - ";
cin>>ono;
while(ofile.read((char*)&o2, sizeof(o2)))
{
if(ono==o2.orderno)
{
cout<<endl<<endl;
cout<<"THE DETAILS OF THE ORDER ARE  -  ";
cout<<endl<<endl;
cout<<"ORDER NUMBER = "<<o2.orderno;
cout<<endl<<endl<<"CUSTOMER NAME = ";
puts(o2.cname);
cout<<endl<<endl<<"BOOKS ORDERED BY CUSTOMER ARE  -  ";
cout<<endl<<endl;
for(int j=0;j<o2.tbook;j++)
{
cout<<o2.obook[j].name<<" ";
cout<<"Class - "<<o2.obook[j].classno;
cout<<" "<<"Price Per Unit - "<<o2.obook[j].price<<" "<<"Total Units - ";
cout<<o2.obook[j].qty;
cout<<endl<<endl;
}
cout<<"TOTAL AMOUNT PAYABLE IS - "<<o2.total;
cout<<endl<<endl;
flag = 1;
}
}
if(flag==0)
cout<<endl<<endl<<"!!!!!!!!!!!!!!!ORDER NOT FOUND!!!!!!!!!!!!!!!";
}
if(schoice==2)
{
char oname[30];
cout<<endl<<"Enter The Name Of The Buying Party - ";
gets(oname);
while(ofile.read((char*)&o2, sizeof(o2)))
{
if((strcmp(oname,o2.cname)==0))
{
cout<<endl<<endl;
cout<<"THE DETAILS OF THE ORDER ARE  -  ";
cout<<endl<<endl;
cout<<"ORDER NUMBER - "<<o2.orderno;
cout<<endl<<endl<<"CUSTOMER NAME - ";
puts(o2.cname);
cout<<endl<<endl<<"BOOKS ORDERED BY CUSTOMER ARE  -  ";
cout<<endl<<endl;
for(int j=0;j<o2.tbook;j++)
{
cout<<o2.obook[j].name<<" ";
cout<<"Class - "<<o2.obook[j].classno;
cout<<" "<<"Price Per Unit - "<<o2.obook[j].price<<" "<<"Total Units - ";
cout<<o2.obook[j].qty;
cout<<endl<<endl;
}
cout<<"TOTAL AMOUNT PAYABLE IS - "<<o2.total;
cout<<endl<<endl;
flag = 1;
}
}
if(flag==0)
cout<<endl<<endl<<"!!!!!!!!!!!!!!!ORDER NOT FOUND!!!!!!!!!!!!!!!";
}
cout<<endl<<endl<<endl<<"TASK EXECUTED. RETURNING TO THE MENU.";
ofile.close();
getch();
}//END

//DELETE FUNCTION FOR ORDER
void delorder()
{
order o3;
double dono=0 ;
int flag=0;
char confirm = 'n';
ifstream mainfile;
ofstream temp;
mainfile.open("orders", ios::in | ios::binary);
temp.open("neworders", ios::out | ios::binary);
mainfile.seekg(0);
clrscr();
cout<<"Enter Order Number Of The Order You Want To Delete - ";
cin>>dono;
while(mainfile.read((char*)&o3, sizeof(o3)))
{
if(o3.orderno==dono)
{
cout<<endl<<endl;
cout<<"ORDER NUMBER - "<<o3.orderno;
cout<<endl<<endl<<"CUSTOMER NAME - ";
puts(o3.cname);
cout<<endl<<endl<<"BOOKS ORDERED BY CUSTOMER ARE  -  ";
cout<<endl<<endl;
for(int j=0;j<o3.tbook;j++)
{
cout<<o3.obook[j].name<<" ";
cout<<"Class - "<<o3.obook[j].classno;
cout<<" "<<"Price Per Unit - "<<o3.obook[j].price<<" "<<"Total Units - ";
cout<<o3.obook[j].qty;
cout<<endl<<endl;
}
cout<<"TOTAL AMOUNT PAYABLE IS - "<<o3.total;
cout<<endl<<endl;
flag = 1;
cout<<endl<<endl<<"Are You Sure You Want To Delete This Order - (y/n) ";
cin>>confirm;
if(confirm=='y'|| confirm=='Y')
cout<<endl<<endl<<"THE ORDER HAS BEEN DELETED FROM THE RECORD. ";
if(confirm == 'n'||confirm == 'N')
temp.write((char*)&o3, sizeof(o3));
}
else
temp.write((char*)&o3, sizeof(o3));
}
if(!flag)
cout<<endl<<endl<<"!!!!!!!!!!!!!!!ORDER NOT FOUND!!!!!!!!!!!!!!!";
mainfile.close();
temp.close();
remove("orders");
rename("neworders","orders");
cout<<endl<<endl<<"TASK EXECUTED. RETURNING TO THE MENU";
getch();
}// END

//Show All Books In The Inventory
void tbookdetail()
{
char ch = 'y';
int i=1, j=0;
book b6;
fstream tbookd;
tbookd.open("mainbookstock", ios::in | ios::binary);
long no=0;
tbookd.seekp(0,ios::end);
no=tbookd.tellp();
int bno;
bno=no/sizeof(b6);
clrscr();
cout<<endl<<"!!!!!Welcome To The Book Inventory Of The Swiss Book Depot!!!!!  ";
cout<<endl<<endl;
cout<<"Following Are The Details Of The Books Present At The Depot - ";
cout<<endl<<endl;
cout<<"Press Enter To Proceed  -  ";
getch();
if(!tbookd)
{
cout<<endl<<endl<<"!!!!!!!!!!NO BOOKS IN THE INVENTORY!!!!!!!!!!";
goto endd;
}
cout<<endl;
tbookd.seekg(0);
while(tbookd.read((char*)&b6, sizeof(b6))&&ch=='y'&&j<=bno)
{
cout<<endl<<i<<". ";
cout<<"Unique Book Code - "<<b6.ucode<<endl;
cout<<"Title - ";
cout<<b6.name;
cout<<endl<<"Class - "<<b6.classno;
cout<<endl<<"Price - "<<b6.price;
cout<<endl<<"Stock Quantity - "<<b6.qty;
cout<<endl<<endl<<"Want To View More - (y/n) ";
cin>>ch;
j++;
i++;
}
cout<<endl<<endl;
if(j==bno)
cout<<"END OF BOOK INVENTORY";
tbookd.close();
endd :
getch();
clrscr();
cout<<endl<<"TASK EXECUTED. RETURNING TO THE MAIN MENU. ";
tbookd.close();
getch();
}//END

//SHOW ALL ORDERS IN THE INVENTORY
void torderdetail()
{
clrscr();
char ch = 'y';
int i=1, k=0;
order o4;
fstream torderd;
torderd.open("orders", ios::in | ios::binary);
long no=0;
torderd.seekp(0,ios::end);
no=torderd.tellp();
int bno;
bno=no/sizeof(o4);
clrscr();
cout<<endl<<"!!!!!Welcome To The Order Inventory Of The Swiss Book Depot!!!!!  ";
cout<<endl<<endl;
cout<<"Following Are The Details Of The Orders Placed At The Depot -  ";
cout<<endl<<endl;
cout<<"Press Enter To Proceed  -  ";
getch();
if(!torderd)
{
cout<<endl<<endl<<"!!!!!!!!!!NO ORDERS IN THE INVENTORY!!!!!!!!!!"<<endl;
goto endo;
}
cout<<endl;
torderd.seekg(0);
while(torderd.read((char*)&o4, sizeof(o4))&&ch=='y'&&k<=bno)
{
cout<<endl<<endl<<i<<". ";
cout<<endl<<endl;
cout<<"ORDER NUMBER - "<<o4.orderno;
cout<<endl<<endl<<"CUSTOMER NAME =-";
puts(o4.cname);
cout<<endl<<endl<<"BOOKS ORDERED BY CUSTOMER ARE  -  ";
cout<<endl<<endl;
for(int j=0;j<o4.tbook;j++)
{
cout<<o4.obook[j].name<<" ";
cout<<"Class - "<<o4.obook[j].classno;
cout<<" "<<"Price Per Unit - "<<o4.obook[j].price<<" "<<"Total Units - ";
cout<<o4.obook[j].qty;
cout<<endl<<endl;
}
cout<<"TOTAL AMOUNT PAYABLE IS - "<<o4.total;
cout<<endl<<endl;
cout<<endl<<endl<<"Want To View More - (y/n) ";
cin>>ch;
i++;
k++;
}
cout<<endl<<endl;
if(k==bno)
cout<<"END OF ORDER INVENTORY";
endo :
getch();
clrscr();
cout<<endl<<"TASK EXECUTED. RETURNING TO THE MAIN MENU. ";
torderd.close();
getch();
}//END
