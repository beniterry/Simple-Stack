// Ben Terry

#include <iostream>
#include <string>

#define SIZE 5

using namespace std;

class Inventory
{
private:
    int serialNum;
    string manufactDate;
    int lotNum;
    
public:
    Inventory(){
        serialNum = 0;
        manufactDate = "";
        lotNum = 0;
    }
    
    void setserialNum(int s){
        serialNum = s;
    }
    void setmanufactDate(string m){
        manufactDate = m;
    }
    void setlotNum(int l){
        lotNum = l;
    }
    int getserialNum() const{
        return serialNum;
    }
    string getmanufactDate() const{
        return manufactDate;
    }
    int getlotNum() const{
        return lotNum;
    }
    
};


class Stack
{
private:
    Inventory arr[SIZE];
    int top;
public:
    Stack();
    int push(Inventory);
    int pop();
    int isEmpty();
    int isFull();
    void displayItems();
};

Stack::Stack(){
    top=-1;
}

int Stack::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

int Stack::isFull(){
    if(top==(SIZE-1))
        return 1;
    else
        return 0;
}

int Stack::push(Inventory n){
    if(isFull()){
        return 0;
    }
    ++top;
    arr[top]=n;
    return n.getserialNum();
}

int Stack::pop(){
    Inventory temp;
    if(isEmpty())
        return 0;
    temp=arr[top];
    --top;
    return temp.getserialNum();
}

void Stack::displayItems(){
    int i;
    cout<<"STACK is: ";
    for(i=(top); i>=0; i--){
        cout<<"Serial number: "<<arr[i].getserialNum()<<"\n";
        cout<<"Lot number: "<<arr[i].getlotNum()<<"\n";
        cout<<"Manufacturing date: "<<arr[i].getmanufactDate()<<"\n";
        cout<<endl;
    }
}

int main(){
    Stack stk;
    int choice, n,temp;
    Inventory i;
    int serialNum;
    string manufactDate;
    do
    {
        cout<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items (Print STACK)."<<endl;
        
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice){
            case 0: break;
                
            case 1:
                
                int lotNum;
                cout<<"Enter serial number: ";
                cin>>serialNum;
                i.setserialNum(serialNum);
                cout<<"Enter lot number: ";
                cin>>lotNum;
                i.setlotNum(lotNum);
                cout<<"Enter manufacturing date: ";
                cin>>manufactDate;
                i.setmanufactDate(manufactDate);
                temp=stk.push(i);
                if(temp==0)
                    cout<<"STACK is FULL."<<endl;
                else
                    cout<<"\nSerial number "<<temp<<" inserted."<<endl;
                break;
                
            case 2:
                temp=stk.pop();
                if(temp==0)
                    cout<<"STACK IS EMPTY."<<endl;
                else
                    cout<<"\nSerial number "<<temp<<" is removed (popped)."<<endl;
                break;
                
            case 3:
                stk.displayItems();
                break;
                
            default:
                cout<<"An Invalid choice."<<endl;
        }
    }while(choice!=0);
    
    
    return 0;
    
}
