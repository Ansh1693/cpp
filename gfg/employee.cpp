#include<iostream>

using namespace std;

class Employee{
    private:
        int eid;
        string name;
    public:
        Employee(){
            eid=0;
            name=" ";
        }
        Employee(int e, string a){
            eid=e;
            name=a;
        }
        string getname() {return name;}
};

class Fulltime:public Employee{
    private:
        int salary;
    public:
        Fulltime(int e,string a, int s):Employee(e,a){
            salary=s;
        }
        int getSalary(){return salary;}
};

class Parttime:public Employee{
    private:
        int salary;
    public:
        Parttime(int e,string a, int s):Employee(e,a){
            salary=s;
        }
        int getSalary(){return salary;}
};

int main(){
    Fulltime p1(25,"RAJAT",5000);
    Parttime p2(30,"RAJAN",500);
    cout<<"name:"<<p1.getname()<<" salary:"<<p1.getSalary()<<endl;
    cout<<"name:"<<p2.getname()<<" salary:"<<p2.getSalary()<<endl;

}