#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void regist();
void forgot();

int main(){
    int choice;
    cout<<"\t\t\t_____________________________\n\n\n";
    cout<<"\t\t\t  Welcome to the login page                \n\n\n";   
    cout<<"\t\t\t________   MENU    __________\n\n";
    cout<<"\t\t| Press 1 for LOGIN \n";
    cout<<"\t\t| Press 2 for REGISTER \n";
    cout<<"\t\t| Press 3 if you FORGOT PASSWORD \n";
    cout<<"\t\t| Press 4 to EXIT \n";
    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>choice;
    cout<<endl;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2: 
        regist();
        break;
    case 3: 
        forgot();
    case 4: 
        cout<<"\t\t\t Thank you! \n\n ";
        break;
    default:
        system("cls");
        cout<<"Please enter a valid option!\n"<<endl;
        main();
    }
    
}
void login(){
    int count;
    string userId,password,id,pass;
    system("cls");
    cout<<"\t\t\t Please enter the username and password : "<<endl;
    cout<<"\t\t\t USERNAME : ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD : ";
    cin>>password;
    
    ifstream input("records.txt");
    while(input>>id>>pass){
        if(id == userId && pass == password){
            count = 1;
            system("cls");
        }
    }
    input.close();
    
    if(count == 1){
        cout<<userId<<"\n Your login is successfull \n Thanks for logging in! \n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password \n";
        main();
    }
}

void regist(){
    string ruserId, rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;

    ofstream f1("records.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successfull! \n";
    main();
}
void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to main menu "<<endl;
    cout<<"\t\t\t Enter your choice ";
    cin>>option;
    switch (option)
    {
    case 1:
        {
            int count =0;
            string suserId,sid,spass;
            cout<<"\n\t\t\t Enter the username that you remember ";
            cin>>suserId;
            
            ifstream f2("records.txt");
            while (f2>>sid>>spass)
            {
                if(sid == suserId){
                    count = 1;
                }
            }
            f2.close();
            if(count == 1){
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your password is : "<<spass;
                main();
            }
            else{
                cout<<"Sorry! Your account is not found! \n";
            }
            break;
        }
    case 2:
        {
            main();
        }
    
    default:
        cout<<"\t\t\t Wrong choice! Please try again "<<endl;
        forgot(); 
    }
}