#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;

class employ{
public:
    int id,sal;
    string name;
    employ(int a, int b, string c){
        id=a;
        name=c;
        sal=b;
    }

};

void  change_username_password() {
    string newUsername, newPassword;

    cout << "\n\n========================================================================================================================" << endl;
    cout << "\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t\t\t\t<Employee Data Management>" << endl;
    cout << "\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl << "========================================================================================================================\n\n" << endl;
    cout << "\t\t\t\t\t<Change Username & Password>" << endl;
    cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "\t\tNew Username: ";
    cin >> newUsername;
    cout << "\n\n";
    cout << "\t\tNew Password: ";
    cin >> newPassword;
    cout << "\n\n";

    ofstream file("C:/Users/Fuad/Downloads/Login.bin", ios::binary);
    if (!file) {
        cout << "Error opening file for updating credentials." << endl;
        return;
    }

    size_t username_len = newUsername.size();
    file.write(reinterpret_cast<char*>(&username_len), sizeof(username_len));
    file.write(newUsername.c_str(), username_len);

    size_t password_len = newPassword.size();
    file.write(reinterpret_cast<char*>(&password_len), sizeof(password_len));
    file.write(newPassword.c_str(), password_len);

    file.close();

    cout << "Username and Password have been changed successfully!";
    for (int i = 0; i < 4; i++) {
        cout << ".";
        Sleep(500);
    }
    system("CLS");
}

int log_in(){
    system("CLS");
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    cout<<"\t\t\t\t\t   <Administrator Access Verification>"<<endl;
    cout<<"\t\t\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    string Username_0,Username_1,Password_0,Password_1;
    ifstream file("C:/Users/Fuad/Downloads/Login.bin",ios::binary);
    if (!file) {
        cout <<"\n\t\t\t\t\t   Invalid User Data Sign up.\n";
        cout<<"\n\n";
        ofstream newFile("C:/Users/Fuad/Downloads/Login.bin", ios::binary);
        if (!newFile) {
            cerr << "Error: Unable to Sign up..\n";
            return 0;
        }
        cout << "\t\tSet new username: ";
        cin >> Username_0;
        cout<<"\n\n";
        cout << "\t\tSet new password: ";
        cin >> Password_0;
        cout<<"\n\n";

        size_t username_len = Username_0.size();
        newFile.write(reinterpret_cast<char*>(&username_len), sizeof(username_len));
        newFile.write(Username_0.c_str(), username_len);

        size_t password_len = Password_0.size();
        newFile.write(reinterpret_cast<char*>(&password_len), sizeof(password_len));
        newFile.write(Password_0.c_str(), password_len);

        newFile.close();

        cout << "Sign Up successful.\n";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
            }
        return 1;
    }

    size_t username_len;
    file.read(reinterpret_cast<char*>(&username_len), sizeof(username_len));

    char* username_buffer = new char[username_len];
    file.read(username_buffer, username_len);
    Username_0.assign(username_buffer, username_len);

    delete[] username_buffer;

    size_t password_len;
    file.read(reinterpret_cast<char*>(&password_len), sizeof(password_len));

    char* password_buffer = new char[password_len];
    file.read(password_buffer, password_len);
    Password_0.assign(password_buffer, password_len);
    delete[] password_buffer;

    file.close();
    cout<<"\t\tUsername :";
    cin>>Username_1;
    cout<<"\n\n";
    cout<<"\t\tPassword :";
    cin>>Password_1;
    cout<<"\n\n";
    if(Username_0==Username_1&&Password_0==Password_1){
    cout<<"\n\n\t\t\t\tPassword is correct.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
    system("CLS");
        return 1;
    }
    else if(Username_0!=Username_1||Password_0==Password_1){
    cout<<"\n\n\t\t\t\tUsername is Incorrect.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
    system("CLS");
        return 0;
    }else    if(Username_0==Username_1||Password_0!=Password_1){
    cout<<"\n\n\t\t\t\tPassword is Incorrect.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
    system("CLS");
        return 0;
}}

int main(){
    int a;
    X:
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    cout<<"\t1.\tAdministretor."<<endl;
    cout<<"\t2.\tGust."<<endl;
    cout<<"\t3.\tExit."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        int ai1=0;
        ai1=log_in();
    if (ai1==0)
        goto X;
        system("CLS");
    int b=0;
    Y:
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    cout<<"\t1.\tAdd Staff Details."<<endl;
    cout<<"\t2.\tView All Staff Details."<<endl;
    cout<<"\t3.\tSearch Employee Details."<<endl;
    cout<<"\t4.\tUpdate Staff Details."<<endl;
    cout<<"\t5.\tRemove Employee Details."<<endl;
    cout<<"\t6.\tCalculate Salary."<<endl;
    cout<<"\t7.\tChange Username & Password."<<endl;
    cout<<"\t8.\tSign Out."<<endl;
    cout<<"\t9.\tExit."<<endl;
    cout<<"\t\t";
    cin>>b;
    if(b == 1){
        system("CLS");
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    cout<<"\t\t\t\t\tEnter Employee Data :\n\n"<<endl;
    }
    else if(b==2){
        system("CLS");
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    cout<<"\t\t\t Employee Data :\n\n"<<endl;
    }
    else if(b==3){
        system("CLS");
    }
    else if(b==4){
        system("CLS");
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    cout<<"\t\t\t\t\tEnter Employee ID :\n\n"<<endl;

    }
    else if(b==5){
            int ba1;
        system("CLS");
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    cout<<"\t1.\tRemove Single Employee Data."<<endl;
    cout<<"\t2.\tRemove All Data."<<endl;
    cout<<"\t\t";
    cin>>ba1;
    if(ba1 == 1){
    cout<<"\t\t\t\t\tDo you want erase all data ?\n"<<endl;
    cout<<"\t\t\t\t\tEnter 'Y'/'y' for Yes or 'N'/'n' for No\n\n"<<endl;
    char l;
    cin>>l;
    if(l=='Y'||l=='y'){
    cout<<"\t\t\t\t\tErasing all data \n\n"<<endl;
    }else if(l=='N'||l=='n'){
    cout<<"\t\t\t\t\tErasing all data \n\n"<<endl;
    }
    }}
    else if(b==6){}
    else if(b==7){

        int ai2=0;
        ai2=log_in();
    if (ai2==0)
        goto Y;
        system("CLS");
        change_username_password();
        goto Y;
    }
    else if(b==8){
        cout<<"\n\t\tSigning Out.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto X;
    }
    else if(b==9){
        cout<<"\n\t\tExiting Program.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        exit(0);
    }else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;
    }
    }
    else if(a==2){
        system("CLS");
        int c=0;
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    cout<<"\t1.\tView All Staff Details."<<endl;
    cout<<"\t2.\tSearch Employee Details."<<endl;
    cout<<"\t3.\tCalculate Salary."<<endl;
    cout<<"\t4.\tBack."<<endl;
    cout<<"\t5.\tExit."<<endl;
    cout<<"\t\t";
    cin>>c;
    if(c == 1){
        system("CLS");
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    }
    else if(c==2){
        system("CLS");
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    }
    else if(c==3){
        system("CLS");
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
    }
    else if(c==4){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto X;
    }
    else if(c==5){
        cout<<"\n\t\tExiting Program.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        exit(0);
    }else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto X;
    }
    }
    else if(a==3){
        cout<<"\n\t\tExiting Program.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        exit(0);
    }else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto X;
    }}
