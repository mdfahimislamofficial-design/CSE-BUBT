#include<iostream>
#include<string>
using namespace std;
class student
{
    protected:
     string student_name;
     string student_id;
     public:
        student(string a, string b)
        {
            student_name = a;
            student_id = b;
        }
};
class course
{
    protected:
    string course_name;
    string course_code;
    public:
    course(string c, string d)
    {
        course_name = c;
        course_code=d;
    }
};
class university
{
    protected:
    string university_name;
    string university_address;
    public:
    university(string e , string f)
    {
        university_name=e;
        university_address =f;
    }

};
class enrollment:public student, public course, public university
{
    protected:
    string enrollment_date;
    public:
    enrollment(string a, string b, string c, string d, string e, string f, string g):student(a,b),course(c,d), university(e,f)
    {
        enrollment_date=g;
    }
    void display()
    {
        cout<<student_name<<endl<<student_id<<endl<<course_name<<endl<<course_code<<endl<<university_name<<endl<<university_address<<endl<<enrollment_date<<endl;
    }
};
int main()
{
    enrollment sam("Sami","2024","oopl","cse112","BUBT","Mirpur","20 january");
    sam.display();
    return 0;
}
