#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class temporary{
    string username,email,password,confirmpass;
    string searchname,searchemail,searchpass;
    fstream file;

    public:
    void login();
    void signup();
    void forgot();
}form;

int main(){
    int choice;
    while(true){
        cout<<"\n=====Login/Signup/Forgot System=====\n";
        cout<<"1. Signup\n2. Login\n3. Forgot\n4. Exit\n";
        cout<<"Enter your choice(1/2/3/4):";
        cin>>choice;
        if(choice!=4){
            switch(choice){
                case 1:
                cin.ignore();
                form.signup();
                break;

                case 2:
                cin.ignore();
                form.login();
                break;

                case 3:
                cin.ignore();
                form.forgot();
                break;

                default:
                cout<<"Invalid Input......!";

            }
        }
        else if(choice==4){
            cout<<"byeeeee.....";
            return 0;
        }
        else{
            cout<<"Invalid input";
        }
    }
}

void temporary::signup(){
    cout<<"===Signup===\n";
    cout<<"Enter your username:";
    getline(cin,username);
    cout<<"\nEnter your email:";
    getline(cin,email);
    cout<<"\nEnter your password:";
    getline(cin,password);
    cout<<"\nConfirm your password:";
    getline(cin,confirmpass);
    while(password!=confirmpass){
        cout<<"Passwords dont match, please try again\n";
        cout<<"Enter your password:\n";
        getline(cin,password);
        cout<<"Confirm your password:\n";
        getline(cin,confirmpass);
    }
    if(password==confirmpass){
        file.open("login.txt",ios::out|ios::app);
        file<<username<<'*'<<email<<'*'<<password<<endl;
        file.close();
    }
    cout<<"Signup successful.....\n";

}

void temporary::login(){
    cout<<"===Login===\n";
    cout<<"Enter your username:";
    getline(cin,searchname);
    cout<<"\nEnter your password:";
    getline(cin,searchpass);
    file.open("login.txt",ios::in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');

    bool userfound=false;

    while(getline(file,username,'*')&&
        getline(file,email,'*')&&
        getline(file,password,'\n')){
        if(username==searchname){
            if(password==searchpass){
                cout<<"\nLogin Successful.....!";
                userfound=true;
                break;
            }
            else{
                cout<<"\nPassword does not match";
            }
            userfound = true;
            break;
        }
        getline(file,username,'*');
        getline(file,email,'*');
        getline(file,password,'\n');
    }
    if(!userfound) {
        cout << "\nUsername does not match any record....!\n";
    }

    file.close();

}

void temporary::forgot(){
    cout<<"===Forgot Password===\n";
    cout<<"Enter your username:";
    getline(cin,searchname);
    cout<<"\nEnter your email:";
    getline(cin,searchemail);
    file.open("login.txt",ios::in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');

    bool userfound=false;

    while(getline(file,username,'*')&&
        getline(file,email,'*')&&
        getline(file,password,'\n')){
        if(searchname==username){
            if(email==searchemail){
                cout<<"Account successfully found!\n";
                cout<<"Password: "<<password<<endl;
                break;
            }
            else{
                cout<<"Account email doesnot match with the username\n";
            }
            userfound=true;
            break;
        }
        getline(file,username,'*');
        getline(file,email,'*');
        getline(file,password,'\n');

    }
    file.close();
}