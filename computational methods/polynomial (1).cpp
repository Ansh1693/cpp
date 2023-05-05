#include "utility.h"

int main(){
    cout<<"Enter maximum power of your polynomial: ";
    int pw;
    cin>>pw;
    Polynomial poly(pw);
    int insert = 0;
    bool flag = true;
    while(flag){
        cout<<endl<<"1. Print Polynomial"<<endl;
        cout<<"2. Insert in Polynomial"<<endl;
        cout<<"3. Add a Constant to Polynomial"<<endl;
        cout<<"4. Subtract a Constant to Polynomial"<<endl;
        cout<<"5. Add a new Polynomial to Polynomial"<<endl;
        cout<<"6. Derivative of the polynomial"<<endl;
        cout<<"7. Exit"<<endl<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            if(insert>0){
                cout<<"Polynomial Created is: "<<endl;
                poly.print();
            }
            else
                cout<<"Create a Polynomial"<<endl;
            break;
        case 2:
            if(!insert){
                poly.insert();
                insert++;
            }
            else{
                cout<<"Polynomial Already Created"<<endl;
            }
            break;
        case 3:
            if(insert>0){
                cout<<"Enter constant number to add: ";
                int addNum;
                cin>>addNum;
                poly.addConstant(addNum);   
            }
            else
                cout<<"Create a Polynomial"<<endl;
            break;
        case 4:
            if(insert>0){
            cout<<"Enter constant number to subtract: ";
            int subtNum;
            cin>>subtNum;
            poly.subtConstant(subtNum);
            }
            else
                cout<<"Create a Polynomial"<<endl;
            break;
        
        case 5:
            if(insert>0){
                poly.addPoly();
            }
            else
                cout<<"Create a Polynomial"<<endl;
            break;
        case 6:
            if(insert>0){
                int val;
                cout<<"Enter value of x to find derivative: ";
                cin>>val;
                poly.findDerivative(val);
            }
            else
                cout<<"Create a Polynomial"<<endl;
            break;
        case 7:
            flag = false;
            break;
        
        default:
            cout<<"INVALD INPUT"<<endl;
            break;
        }
    }
    return 0;
}