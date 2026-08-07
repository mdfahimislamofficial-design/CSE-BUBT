#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include <iomanip>
using namespace std;

void Titl()
{
    cout<<"\n\n========================================================================================================================"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t\t\t<Employee Data Management>"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"========================================================================================================================\n\n"<<endl;
}

class employ{
public:
    string Name,sex,D,position,mobile,email;
    double salary,bonus,decr,incr,Att;
    int ID,age,grade;
    employ() {
        salary = 0;
        age =ID = 0;
        Name =  sex = D = position = mobile = email = "";
    }
    employ& operator=(const employ& other){
        if (this == &other)
            return *this;

        Name = other.Name;
        sex = other.sex;
        D = other.D;
        position = other.position;
        mobile = other.mobile;
        email = other.email;
        salary = other.salary;
        bonus = other.bonus;
        decr = other.decr;
        incr = other.incr;
        Att = other.Att;
        ID = other.ID;
        age = other.age;
        grade = other.grade;

        return *this;
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
        cout << "\t\tEmployee Grade: ";
        cin >> grade;
        cin.ignore();
    switch (grade) {
        case 5: break;
        case 4: break;
        case 3: break;
        case 2: break;
        case 1: break;
        default:
            cout<<"Invalid Grade,Seting Grade as 5"<<endl;
            grade = 5;
    }
        cout << "\t\tEmployee Mobile Number: ";
        getline(cin, mobile);
        cout << "\t\tEmployee Email Address: ";
        getline(cin, email);
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
        cout << "\t\tEmployee Grade: ";
        cin >> grade;
        cin.ignore();
    switch (grade) {
        case 5: break;
        case 4: break;
        case 3: break;
        case 2: break;
        case 1: break;
        default:
            cout<<"Invalid Grade,Seting Grade as 5"<<endl;
            grade = 5;
    }
        cout << "\t\tEmployee Mobile Number: ";
        getline(cin, mobile);
        cout << "\t\tEmployee Email Address: ";
        getline(cin, email);
    }
    void saveToFile1() {
        ofstream outFile("C:/Users/My PC/Downloads/SDP/Data.bin", ios::binary | ios::app);
        if (!outFile) {
            cout << "Error opening file for saving.\n";
            return;
        }

        outFile.write(reinterpret_cast<char*>(&ID), sizeof(ID));
        outFile.write(reinterpret_cast<char*>(&salary), sizeof(salary));
        outFile.write(reinterpret_cast<char*>(&age), sizeof(age));
        outFile.write(reinterpret_cast<char*>(&grade), sizeof(grade));
        outFile.write(reinterpret_cast<char*>(&bonus), sizeof(bonus));
        outFile.write(reinterpret_cast<char*>(&decr), sizeof(decr));
        outFile.write(reinterpret_cast<char*>(&incr), sizeof(incr));
        outFile.write(reinterpret_cast<char*>(&Att), sizeof(Att));

        saveString(outFile, Name);
        saveString(outFile, sex);
        saveString(outFile, D);
        saveString(outFile, position);
        saveString(outFile, mobile);
        saveString(outFile, email);

        outFile.close();
        cout << "Employee data saved successfully.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
    }
    void saveToFile2(employ employees[]) {
        ofstream outFile("C:/Users/My PC/Downloads/SDP/Data.bin", ios::binary );
        if (!outFile) {
            cout << "Error opening file for saving.\n";
            return;
        }

    for (int i = 0; i < 60; ++i) {
        outFile.write(reinterpret_cast<char*>(&employees[i].ID), sizeof(employees[i].ID));
        outFile.write(reinterpret_cast<char*>(&employees[i].salary), sizeof(employees[i].salary));
        outFile.write(reinterpret_cast<char*>(&employees[i].age), sizeof(employees[i].age));
        outFile.write(reinterpret_cast<char*>(&employees[i].grade), sizeof(employees[i].grade));
        outFile.write(reinterpret_cast<char*>(&employees[i].bonus), sizeof(employees[i].bonus));
        outFile.write(reinterpret_cast<char*>(&employees[i].decr), sizeof(employees[i].decr));
        outFile.write(reinterpret_cast<char*>(&employees[i].incr), sizeof(employees[i].incr));
        outFile.write(reinterpret_cast<char*>(&employees[i].Att), sizeof(employees[i].Att));

        saveString(outFile, employees[i].Name);
        saveString(outFile, employees[i].sex);
        saveString(outFile, employees[i].D);
        saveString(outFile, employees[i].position);
        saveString(outFile, employees[i].mobile);
        saveString(outFile, employees[i].email);
    }

        outFile.close();
        cout << "\n\t\tloading.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
    }
    int searchData(employ employees[]){
    int DI;Titl();
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
        ifstream inFile("C:/Users/My PC/Downloads/SDP/Data.bin", ios::binary);
        if (!inFile) {
            cout << "Error opening file for loading.\n";
            return;
        }

        for (int i = 0; i < total && !inFile.eof(); ++i) {
            inFile.read(reinterpret_cast<char*>(&employees[i].ID), sizeof(employees[i].ID));
            inFile.read(reinterpret_cast<char*>(&employees[i].salary), sizeof(employees[i].salary));
            inFile.read(reinterpret_cast<char*>(&employees[i].age), sizeof(employees[i].age));
            inFile.read(reinterpret_cast<char*>(&employees[i].grade), sizeof(employees[i].grade));
            inFile.read(reinterpret_cast<char*>(&employees[i].bonus), sizeof(employees[i].bonus));
            inFile.read(reinterpret_cast<char*>(&employees[i].decr), sizeof(employees[i].decr));
            inFile.read(reinterpret_cast<char*>(&employees[i].incr), sizeof(employees[i].incr));
            inFile.read(reinterpret_cast<char*>(&employees[i].Att), sizeof(employees[i].Att));
            loadString(inFile, employees[i].Name);
            loadString(inFile, employees[i].sex);
            loadString(inFile, employees[i].D);
            loadString(inFile, employees[i].position);
            loadString(inFile, employees[i].mobile);
            loadString(inFile, employees[i].email);
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
    cout << string(5, ' ') << string(75, '-') << endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Employee Details" << setw(40) << "Job Details" <<"  |"<< endl;
    cout << string(5, ' ') << string(75, '-') << endl;

    cout << string(5, ' ') <<"| "<< left << setw(30) << "Employee ID" << setw(40) << ID <<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Employee Name" << setw(40) << Name <<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Employee Age" << setw(40) << age <<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Employee Sex" << setw(40) << sex <<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Employee Department" << setw(40) << D <<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Employee Position" << setw(40) << position <<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Employee Grade" << setw(40) << grade<<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Mobile Number" << setw(40) << mobile <<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Email Address" << setw(40) << email <<"  |"<< endl;
    cout << string(5, ' ') << string(75, '-') << endl;
    }
    double SalaryM(){
        double aaa=0,bbb=0,ccc=0,ddd=0;
    cout<<"\t   Employee Id :"<<ID<<endl;
    cout<<"\t   Employee Name :"<<Name<<endl;
    double Salary=0;
    switch (grade) {
        case 5: Salary = 1200; break;
        case 4: Salary = 1800; break;
        case 3: Salary = 2400; break;
        case 2: Salary = 3200; break;
        case 1: Salary = 4500; break;
        default:Salary = 1200;
    }
        cout << "\t\tEnter number of days absent in a month :";
        cin>>aaa;
        cin.ignore();
        Att=aaa;
        cout << "\t\tEnter the percentage of bonus :";
        cin>>bbb;
        cin.ignore();
        bonus=bbb;
        cout << "\t\tEnter the percentage of salary Increment :";
        cin>>ccc;
        cin.ignore();
        incr=ccc;
        cout << "\t\tEnter the percentage of salary deduction :";
        cin>>ddd;
        cin.ignore();
        decr=ddd;
        salary=Salary-(aaa*Salary/30)+(Salary*bbb/100)-(Salary*ddd/100)+(Salary*ccc/100);
        cout<<"\n\t\tEntry Complete.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        return salary;
    }
    double SalaryV(){
    cout<<"\t\tEmployee :"<<Name<<" (ID:"<<ID<<")"<<endl;
    double Salary=0;
    switch (grade) {
        case 5: Salary = 1200; break;
        case 4: Salary = 1800; break;
        case 3: Salary = 2400; break;
        case 2: Salary = 3200; break;
        case 1: Salary = 4500; break;
        default:Salary = 1200;
    }
    cout << string(5, ' ') <<"|"<< string(73, '-') <<"|"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Detail" << setw(40) << "Amount" <<"  |"<< endl;
    cout << string(5, ' ') <<"|"<< string(73, '-') <<"|"<< endl;

    cout << string(5, ' ') <<"| "<< left << setw(30) << "Base Salary" << setw(40) << Salary <<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Increment" << setw(36) <<Salary*incr/100<<"("<< incr <<"%)"<<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Bonuses" << setw(36) << Salary*bonus/100 <<"("<< bonus <<"%)"<<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Deductions" << setw(36) << Salary*decr/100 <<"("<< decr <<"%)"<<"  |"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Absenteeism Charge" << setw(36) << Salary*Att/30 <<"("<<fixed <<setprecision(1) << Att/30*100 <<"%)"<<"|"<< endl;
    cout << string(5, ' ') <<"| "<< left << setw(30) << "Final Salary" << setw(40) << salary <<"  |"<< endl;
    cout << string(5, ' ') <<"|"<< string(73, '-') <<"|"<< endl;
    return salary;
    }
};

void  change_username_password() {
    string newUsername, newPassword;
    Titl();
    cout << "\t\t\t\t\t<Change Username & Password>" << endl;
    cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "\t\tNew Username: ";
    cin >> newUsername;
    cout << "\n\n";
    cout << "\t\tNew Password: ";
    cin >> newPassword;
    cout << "\n\n";

    ofstream file("C:/Users/My PC/Downloads/SDP/Login.bin", ios::binary);
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

void clearBinaryFile(const string& fileName) {
    ofstream file(fileName, ios::out | ios::binary | ios::trunc);
    if (file.is_open()) {
        cout << "\t\tAll Employee data has been removed.";
        file.close();
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
    } else {
        cout << "Data File Error.";
    }
}

int log_in(){
    system("CLS");Titl();
    cout<<"\t\t\t\t\t   <Administrator Access Verification>"<<endl;
    cout<<"\t\t\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    string Username_0,Username_1,Password_0,Password_1;
    ifstream file("C:/Users/My PC/Downloads/SDP/Login.bin",ios::binary);
    if (!file) {
        cout <<"\n\t\t\t\t\t   Invalid User Data Sign up.\n";
        cout<<"\n\n";
        ofstream newFile("C:/Users/My PC/Downloads/SDP/Login.bin", ios::binary);
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
    X:
    int a=0;Titl();
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
    a=0;Titl();
    cout<<"\t1.\tAdd Staff Details."<<endl;
    cout<<"\t2.\tManage Single Employee."<<endl;
    cout<<"\t3.\tManage Multiple Employee."<<endl;
    cout<<"\t4.\tChange Admin Login."<<endl;
    cout<<"\t5.\tSign Out."<<endl;
    cout<<"\t6.\tExit."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a==1){
    system("CLS");Titl();
    cout<<"\t\t\t\t\t\t Enter Employee Data"<<endl;
    cout<<"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~"<<endl;
    employ employees[60];
    employees[0].loadFromFile(employees);
    int LL=0;
    for(LL=0;LL<60;++LL){
        if(employees[LL].ID==0)
            break;
    }
    employees[LL].set_Data();
    employees[LL].saveToFile2(employees);
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
    employ employees[60];
    employees[0].loadFromFile(employees);
    int emp=0;
    emp=employees[0].searchData(employees);
    if(emp==-1){
        goto Y;}else{
        Z:
    a=0;Titl();
    cout << "\t\t\t\t\t<Single Employee Management>" << endl;
    cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout<<"\t1.\tView Staff Details."<<endl;
    cout<<"\t2.\tEdit Staff Details."<<endl;
    cout<<"\t3.\tRemove Staff Details."<<endl;
    cout<<"\t4.\tSalary Management."<<endl;
    cout<<"\t5.\tView Salary Details."<<endl;
    cout<<"\t6.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        a=0;
    system("CLS");Titl();
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
    system("CLS");Titl();
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
        system("CLS");
    Titl();
            cout << "\n\t\tRemoving Employee Data.\n";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        for(int i=emp;i<30;++i)
        {
    employees[i]=employees[i+1];
        }
    employees[emp].saveToFile2(employees);
        system("CLS");
    Titl();
            cout << "\n\t\tEmployee Data Removed.\n";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;
    }
    else if(a==4){
    system("CLS");Titl();
    cout<<"\t\t\t\t\t           <Salary Management>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~~~~"<<endl;
            double sal=employees[emp].SalaryM();
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
    else if(a==5){
    system("CLS");Titl();
    cout<<"\t\t\t\t\t           <Salary Details>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~"<<endl;
            double sal=employees[emp].SalaryV();
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
    else if(a==6){
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
    system("CLS");Titl();
    cout<<"\t\tEnter The number of Staff you want to manage from '0' to '5' ('0' is for all staff): ";
    cin>>p;
    if(p==0){
    system("CLS");
    employ employees[60];
    employees[0].loadFromFile(employees);
    A:
    a=0;Titl();
    cout << "\t\t\t\t\t<Multiple Employee Management>" << endl;
    cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"\t1.\tView Staff Details."<<endl;
    cout<<"\t2.\tRemove Staff Details."<<endl;
    cout<<"\t3.\tSalary Management."<<endl;
    cout<<"\t4.\tView Salary Details."<<endl;
    cout<<"\t5.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        a=0;
    system("CLS");Titl();
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
            clearBinaryFile("C:/Users/My PC/Downloads/SDP/Data.bin");
            cout << "\n\t\tAll Employee Data removed.";
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        system("CLS");
        goto Y;
    }
    else if(a==3){
    system("CLS");Titl();
    cout<<"\t\t\t\t\t           <Salary Management>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~~~~"<<endl;
    double ta_sa=0;
    for(int i=0; i<60&&employees[i].age!=0;++i){
            double sal=employees[i].SalaryM();
    employees[i].saveToFile2(employees);
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
    system("CLS");Titl();
    cout<<"\t\t\t\t\t           <Salary details>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~"<<endl;
    double ta_sa=0;
    for(int i=0; i<60&&employees[i].age!=0;++i){
            double sal=employees[i].SalaryV();
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
    if(em[i]==-1){Titl();
    cout<<"\t\tRe-Enter Data.\n"<<endl;
        for(int i=0;i<4;i++){
            cout<<".";
            Sleep(500);
        }
        goto P;}
    }
    Zz:
    a=0;Titl();
    cout << "\t\t\t\t\t<Multiple Employee Management>" << endl;
    cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"\t1.\tView Staff Details."<<endl;
    cout<<"\t2.\tEdit Staff Details."<<endl;
    cout<<"\t3.\tSalary Management."<<endl;
    cout<<"\t4.\tView Salary Details."<<endl;
    cout<<"\t5.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        a=0;
    system("CLS");Titl();
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
    system("CLS");Titl();
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
    system("CLS");Titl();
    cout<<"\t\t\t\t\t           <Salary Management>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~~~~"<<endl;
    double ta_sa=0;
    for(int i=0; i<p;++i){
            double sal=employees[em[i]].SalaryM();
            ta_sa+=sal;
            }
    employees[em[0]].saveToFile2(employees);
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
    system("CLS");Titl();
    cout<<"\t\t\t\t\t           <Salary details>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~"<<endl;
    double ta_sa=0;
    for(int i=0; i<p;++i){
            double sal=employees[em[i]].SalaryV();
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
    a=0;Titl();
    cout<<"\t1.\tView Staff Details."<<endl;
    cout<<"\t2.\tView Salary Details."<<endl;
    cout<<"\t3.\tBack."<<endl;
    cout<<"\t\t";
    cin>>a;
    if(a == 1){
        a=0;
    system("CLS");Titl();
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
    system("CLS");Titl();
    cout<<"\t\t\t\t\t           <Salary Details>"<<endl;
    cout<<"\t\t\t\t\t           ~~~~~~~~~~~~~~~~~~~"<<endl;
            double sal=employees[emp].SalaryV();
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

