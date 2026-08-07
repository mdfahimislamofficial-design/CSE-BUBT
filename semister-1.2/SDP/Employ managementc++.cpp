#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include <vector>
using namespace std;

void Titel()
{
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
}

class employ{
public:
    string ID,Name,sex,D,position,mobile,email,addres;
    int salary,salary2,age,incr;
    employ() {
        salary = 0;
        salary2 = 0;
        incr=0;
        age = 0;
        Name = ID = sex = D = position = mobile = email = addres = "";
    }
    void set_Data(){
        cout << "\t\tEmployee Id: ";
        cin >> ID;
        cin.ignore();
        cout << "\t\tEmployee Name: ";
        getline(cin, Name);
        cout << "\t\tEmployee Age: ";
        cin >> age;
        cin.ignore();
        cout << "\t\tEmployee Sex: ";
        getline(cin, sex);
        cout << "\t\tEmployee Department: ";
        getline(cin, D);
        cout << "\t\tEmployee Position: ";
        getline(cin, position);
        cout << "\t\tEmployee Base Salary Per Month: ";
        cin >> salary;
        cin.ignore();
        cout << "\t\tEmployee Mobile Number: ";
        getline(cin, mobile);
        cout << "\t\tEmployee Email Address: ";
        getline(cin, email);
        cout << "\t\tEmployee Address: ";
        getline(cin, addres);
    }
    void set_Data2(){
        cout << "\t\tEmployee Name: ";
        getline(cin, Name);
        cout << "\t\tEmployee Age: ";
        cin >> age;
        cin.ignore();
        cout << "\t\tEmployee Sex: ";
        getline(cin, sex);
        cout << "\t\tEmployee Department: ";
        getline(cin, D);
        cout << "\t\tEmployee Position: ";
        getline(cin, position);
        cout << "\t\tEmployee Base Salary Per Month: ";
        cin >> salary;
        cin.ignore();
        cout << "\t\tEmployee Mobile Number: ";
        getline(cin, mobile);
        cout << "\t\tEmployee Email Address: ";
        getline(cin, email);
        cout << "\t\tEmployee Address: ";
        getline(cin, addres);
    }
    void saveToFile1() {
        ofstream outFile("C:/Users/Fuad/Downloads/Data.bin", ios::binary | ios::app);
        if (!outFile) {
            cout << "Error opening file for saving.\n";
            return;
        }

        outFile.write(reinterpret_cast<char*>(&salary), sizeof(salary));
        outFile.write(reinterpret_cast<char*>(&salary2), sizeof(salary2));
        outFile.write(reinterpret_cast<char*>(&incr), sizeof(incr));
        outFile.write(reinterpret_cast<char*>(&age), sizeof(age));

        saveString(outFile, Name);
        saveString(outFile, ID);
        saveString(outFile, sex);
        saveString(outFile, D);
        saveString(outFile, position);
        saveString(outFile, mobile);
        saveString(outFile, email);
        saveString(outFile, addres);

        outFile.close();
        cout << "Employee data saved successfully.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
    }
    void saveToFile2(employ employees[]) {
        ofstream outFile("C:/Users/Fuad/Downloads/Data.bin", ios::binary );
        if (!outFile) {
            cout << "Error opening file for saving.\n";
            return;
        }

    for (int i = 0; i < 60; ++i) {
        outFile.write(reinterpret_cast<char*>(&employees[i].salary), sizeof(employees[i].salary));
        outFile.write(reinterpret_cast<char*>(&employees[i].salary2), sizeof(employees[i].salary2));
        outFile.write(reinterpret_cast<char*>(&employees[i].incr), sizeof(employees[i].incr));
        outFile.write(reinterpret_cast<char*>(&employees[i].age), sizeof(employees[i].age));

        saveString(outFile, employees[i].Name);
        saveString(outFile, employees[i].ID);
        saveString(outFile, employees[i].sex);
        saveString(outFile, employees[i].D);
        saveString(outFile, employees[i].position);
        saveString(outFile, employees[i].mobile);
        saveString(outFile, employees[i].email);
        saveString(outFile, employees[i].addres);
    }

        outFile.close();
        cout << "Employee data saved successfully.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
    }
    int searchData(employ employees[]){
    string DI;Titel();
    cout<<"\t\tEnter Employee ID :";
    cin >> DI;
    cin.ignore();
    int emp=0;
    for(int i=0;i<60;++i){
        if(employees[i].ID==DI){
    cout<<"\t\tEmployee Data Found.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
    return i;
        }
        if(i==59){
    cout<<"\t\tInvalide Employee ID :"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        }
    }
    return -1;
    }
    void loadFromFile(employ employees[], int total=60) {
        ifstream inFile("C:/Users/Fuad/Downloads/Data.bin", ios::binary);
        if (!inFile) {
            cout << "Error opening file for loading.\n";
            return;
        }

        for (int i = 0; i < total && !inFile.eof(); ++i) {
            inFile.read(reinterpret_cast<char*>(&employees[i].salary), sizeof(employees[i].salary));
            inFile.read(reinterpret_cast<char*>(&employees[i].salary2), sizeof(employees[i].salary2));
            inFile.read(reinterpret_cast<char*>(&employees[i].incr), sizeof(employees[i].incr));
            inFile.read(reinterpret_cast<char*>(&employees[i].age), sizeof(employees[i].age));
            loadString(inFile, employees[i].Name);
            loadString(inFile, employees[i].ID);
            loadString(inFile, employees[i].sex);
            loadString(inFile, employees[i].D);
            loadString(inFile, employees[i].position);
            loadString(inFile, employees[i].mobile);
            loadString(inFile, employees[i].email);
            loadString(inFile, employees[i].addres);
        }
        inFile.close();
    }
    void saveString(ofstream &outFile, const string &str) {
        size_t length = str.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
        outFile.write(str.c_str(), length);
    }
    void loadString(ifstream &inFile, string &str) {
        size_t length;
        inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
        str.resize(length);
        inFile.read(&str[0], length);
    }
    void display() {
            int Pa=0;
        cout << "\t\tEmployee Id: "<<ID<<endl;
        cout << "\t\tEmployee Name: "<<Name<<endl;
        cout << "\t\tEmployee Age: "<<age;
        cout << "\tEmployee Sex: "<<sex<<endl;
        cout << "\t\tEmployee Department: "<<D;
        cout << "\t\tEmployee Position: "<<position<<endl;
        cout << "\t\tEmployee Base Salary Per Month: "<<salary<<endl;
        cout << "\t\tEmployee Current Salary Per Month: "<<salary+((salary*incr)/100)<<endl;
        cout << "\t\tEmployee Mobile Number: "<<mobile<<endl;
        cout << "\t\tEmployee Email Address: "<<email<<endl;
        cout << "\t\tEmployee Address: "<<addres<<endl;
    }
    int Salary(employ e){
        int ab=0,bon=0,deduc=0,total=0;
    cout<<"\t   Employee Id :"<<e.ID<<endl;
    cout<<"\t   Employee Name :"<<e.Name<<endl;
        cout << "\t\tEnter number of days absent in a month :";
        cin>>ab;
        cout << "\t\tEnter the percentage of bonus :";
        cin>>bon;
        cout << "\t\tEnter the percentage of salary deduction :";
        cin>>deduc;
        total=(e.salary-((ab*e.salary)/30))+(e.salary*bon/100)-(e.salary*deduc/100);
        cout << "\t\tSalary :"<<total<<endl;
        return total;
    }
};

int log_in(){
    system("CLS");Titel();
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

int main(){
    X:
    int a=0;Titel();
    cout<<"\t1.\tAdministretor."<<endl;
    cout<<"\t2.\tGuest."<<endl;
    cout<<"\t3.\tExit."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        a=0;
        a=log_in();
    if (a==0){
        goto X;
        system("CLS");}
    system("CLS");
    Y:
    a=0;Titel();
    cout<<"\t1.\tAdd Staff Details."<<endl;
    cout<<"\t2.\tManage Single Employee."<<endl;
    cout<<"\t3.\tManage Multiple Employee."<<endl;
    cout<<"\t4.\tChange Admin Login."<<endl;
    cout<<"\t5.\tSign Out."<<endl;
    cout<<"\t6.\tExit."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a==1){
    system("CLS");Titel();
    cout<<"\t\t\t\t\t\t Enter Employee Data"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~"<<endl;
    employ xa;
    xa.set_Data();
    xa.saveToFile1();
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
        else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto Y;
    }
    else if(a==2){
    system("CLS");
    employ employees[100];
    employees[0].loadFromFile(employees);
    int emp=0;
    emp=employees[0].searchData(employees);
    if(emp==-1){
        goto Y;}else{
        Z:
    a=0;Titel();
    cout << "\t\t\t\t\t<Single Employee Management>" << endl;
    cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout<<"\t1.\tView Staff Details."<<endl;
    cout<<"\t2.\tEdit Staff Details."<<endl;
    cout<<"\t3.\tRemove Staff Details."<<endl;
    cout<<"\t4.\tSalary Management."<<endl;
    cout<<"\t5.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        a=0;
    system("CLS");Titel();
    cout<<"\t\t\t\t\t             <Employee Data>"<<endl;
    cout<<"\t\t\t\t\t             ~~~~~~~~~~~~~~~"<<endl;
            employees[emp].display();
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto Z;
    }
    else if(a==2){
    system("CLS");Titel();
    cout<<"\t\t\t\t\t\t\tReEnter Employee Data."<<endl;
    employees[emp].set_Data();
    employees[emp].saveToFile2(employees);
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto Z;
    }
    else if(a==3){
            for (int i = emp; i < 60; ++i) {
                employees[i] = employees[i + 1];
            }
    employees[emp].saveToFile2(employees);
            cout << "\n\t\tEmployee Data removed.\n";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;
    }
    else if(a==4){
    system("CLS");Titel();
    cout<<"\t\t\t\t\t           <Salary Management>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~~~~"<<endl;
            int sal=employees[emp].Salary(employees[emp]);
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto Z;
    }
    else if(a==5){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;
    }
    else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Z;
    }
    }}
    else if(a==3){
            int p=0;
    system("CLS");Titel();
    cout<<"\t\tEnter The number of Staff you want to manage from '0' to '5' ('0' is for all staff): ";
    cin>>p;
    if(p==0){
    system("CLS");
    employ employees[100];
    employees[0].loadFromFile(employees);
    A:
    a=0;Titel();
    cout << "\t\t\t\t\t<Multiple Employee Management>" << endl;
    cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"\t1.\tView Staff Details."<<endl;
    cout<<"\t2.\tRemove Staff Details."<<endl;
    cout<<"\t3.\tSalary Management."<<endl;
    cout<<"\t4.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        a=0;
    system("CLS");Titel();
    cout<<"\t\t\t\t\t             <Employee Data>"<<endl;
    cout<<"\t\t\t\t\t             ~~~~~~~~~~~~~~~"<<endl;
        for(int i=0;i<60&&employees[i].age!=0;++i){
        cout << "\t Employee Data: "<<i<<endl;
            employees[i].display();
            cout<<"\n\n";
            }
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a==1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto A;
    }
    else if(a==2){
    ofstream outFile("C:/Users/Fuad/Downloads/Data.bin", ios::binary | ios::trunc);
    if (!outFile) {
        cout << "Error opening file for clearing.\n";
        exit (1);
    }
    outFile.close();
            cout << "\t\tAll Employee Data removed.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;
    }
    else if(a==3){
    system("CLS");Titel();
    cout<<"\t\t\t\t\t           <Salary Management>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~~~~"<<endl;
    int ta_sa=0;
    for(int i=0; i<60&&employees[i].age!=0;++i){
            int sal=employees[i].Salary(employees[i]);
            ta_sa+=sal;
            }
        cout << "\t\tTotal Salary :"<<ta_sa<<endl;
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto A;
    }
    else if(a==4){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;
    }
    else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto A;
    }
    }
    else if(p<=5){
    system("CLS");
    employ employees[100];
    employees[0].loadFromFile(employees);
    int em[p];
    for(int i=0;i<p&&employees[i].age!=0;++i){
            P:
    system("CLS");
    em[i]=0;
    em[i]=employees[0].searchData(employees);
    if(em[i]==-1){Titel();
    cout<<"\t\tRe-Enter Data.\n"<<endl;
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        goto P;}
    }
    Zz:
    a=0;Titel();
    cout << "\t\t\t\t\t<Multiple Employee Management>" << endl;
    cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"\t1.\tView Staff Details."<<endl;
    cout<<"\t2.\tEdit Staff Details."<<endl;
    cout<<"\t3.\tSalary Management."<<endl;
    cout<<"\t4.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        a=0;
    system("CLS");Titel();
    cout<<"\t\t\t\t\t             <Employee Data>"<<endl;
    cout<<"\t\t\t\t\t             ~~~~~~~~~~~~~~~"<<endl;
        for(int i=0;i<p&&employees[em[i]].age!=0;++i){
        cout << "\t Employee Data: "<<i<<endl;
            employees[em[i]].display();
            cout<<"\n\n";
            }
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto Zz;
    }
    else if(a==2){
    system("CLS");Titel();
        for(int i=0;i<p&&employees[em[i]].age!=0;++i){
    cout<<"\t\tReEnter Employee ID :"<<employees[em[i]].ID<<endl;
    employees[em[i]].set_Data();
    cout<<"\n\n";}
    employees[em[0]].saveToFile2(employees);
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto Zz;
    }
    else if(a==3){
    system("CLS");Titel();
    cout<<"\t\t\t\t\t           <Salary Management>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~~~~"<<endl;
    int ta_sa=0;
    for(int i=0; i<p;++i){
            int sal=employees[em[i]].Salary(employees[em[i]]);
            ta_sa+=sal;
            }
        cout << "\t\tTotal Salary :"<<ta_sa<<endl;
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto Zz;
    }
    else if(a==4){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;
    }
    else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Zz;
    }

        }
        else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;}
    }
    else if(a==4){
        a=0;
        a=log_in();
    if (a==0){
        goto Y;
        system("CLS");}
        change_username_password();
        goto Y;
    }
    else if(a==5){
        cout<<"\n\t\tSigning Out.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto X;
    }
    else if(a==6){
        cout<<"\n\t\tExiting Program.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);}
        system("CLS");
        exit(0);
    }
    else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;
    }}
    else if(a==2){
    system("CLS");
    employ employees[100];
    employees[0].loadFromFile(employees);
    int emp=0;
    emp=employees[0].searchData(employees);
    if(emp==-1){
        goto X;}else{
        Xa:
    a=0;Titel();
    cout<<"\t1.\tView Staff Details."<<endl;
    cout<<"\t2.\tSalary Management."<<endl;
    cout<<"\t3.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        a=0;
    system("CLS");Titel();
    cout<<"\t\t\t\t\t             <Employee Data>"<<endl;
    cout<<"\t\t\t\t\t             ~~~~~~~~~~~~~~~"<<endl;
            employees[emp].display();
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto Xa;
    }
    else if(a==2){
    system("CLS");Titel();
    cout<<"\t\t\t\t\t           <Salary Management>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~~~~"<<endl;
            int sal=employees[emp].Salary(employees[emp]);
    cout<<"\n";
    cout<<"\t1.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}else {
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }}
    system("CLS");
    goto Xa;
    }
    else if(a==3){
        cout<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto X;
    }
    else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Xa;
    }
    }}
    else if(a==3){
        cout<<"\n\t\tExiting Program.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        exit(0);
    }
    else{
        cout<<"\n\t\tInvalid Input"<<endl<<"\n\t\tGoing Back.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto X;
    }}
