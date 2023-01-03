#include<iostream>

using namespace std;

class Rational{
    private:
        int p;
        int q;
    public:
        Rational(){
            p=1;
            q=1;
        }

        Rational(int p,int q){
            this ->p=p;
            this ->q=q; 
        }

        Rational(Rational &r){
            this ->p=r.p;
            this ->q=r.q;
        }

        int getP(){ return p;}

        int getQ(){ return q;}

        void setP(int p) {
            this ->p=p;
        }

        void setQ(int q) {
            this ->q=q;
        }

        Rational operator+ (Rational r){
            Rational t;
            t.p= this ->p*r.q+ r.p* this ->q;
            t.q= this ->q * r.q; 
            return t;
        }
        friend  ostream & operator <<(ostream &out,Rational &r);

};
ostream & operator <<(ostream &out,Rational &r){
    out<<r.p<<"/"<<r.q;
    return out;
}
int main(){
    int a;
    Rational r1(6,7),r2(5,6),r3;

    r3=r1+r2;

    cout<<"Sum of "<<r1<<" and "<<r2<<" is "<<r3;
}