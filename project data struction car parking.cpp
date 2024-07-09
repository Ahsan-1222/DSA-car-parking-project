#include<iostream>
#include<string>

using namespace std;
struct node
{

    long long phoneno;
    string dname,carname,company;
    int vno;
    int sindex=0;
	node *next;
	node *prev;
};

class parking{
    node *head;
    node *tail;
    int slots=0;
    int total_slots=3;
    public:
    parking();
    void insert_data();
    void delete_anydata();
    void modify();
    void display();
    void indexDecrement(node*ptr);
    bool isempty();
    node* searchbyvno();
    node* searchbyindex();

};
//*****************MAIN***************//
int main()
{
    parking p;

    char x;
    int option;
    menu:
    cout<< "\n\t\t\t ====== CAR PARKING RESERVATION SYSTEM ======";
	cout<< " \n\t\t\t\t\t========================";
	cout<< "\n\t\t\t\t  1. INSERT:";
	cout<< "\n\t\t\t\t  2. DELETE:";
	cout<< "\n\t\t\t\t  3. DISPLAY:";
	cout<< "\n\t\t\t\t  4. SEARCH BY VEHICAL NO:";
	cout<< "\n\t\t\t\t  5. MODIFY BY VEHICAL NO:";
	cout<< "\n\t\t\t\t  6. SEARCH BY INDEX NO:";
	cout<< "\n\t\t\t\t  7. Exit Program:";
	cout<< " \n\t\t\t\t\t======================";
	cout<< "\n\n";
	cout<< "\t\t\t\tSelect Your Choice ::";
    cin>>option;
    switch(option){
        case 1:{
        p.insert_data();
        goto menu;
        break;
        }
        case 2:{
        p.delete_anydata();
        goto menu;
        break;
        }
        case 3:{
        p.display();
        goto menu;
        break;
        }
        case 4:{
        p.searchbyvno();
        goto menu;
        break;
        }
        case 5:{
        p.modify();
        goto menu;
        break;
        }
        case 6:
        {
            p.searchbyindex();
            goto menu;
            break;
        }
        default:
        {
            cout<<"\nEnter the right choice:";
            break;
        }

    }
}
parking::parking()
{
    head = tail = NULL;
}
bool parking::isempty(){
    if(head==NULL)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
//*****************MOODIIFYYY***************//
void parking::modify(){
    node*ptr1=searchbyvno();

    if(isempty())
    {
        cout<<"\nNo data of cars is available";
    }
    else 
    {   
        cout<<"\nEnter the name of the driver:\n"<<endl;
        cin.ignore();
        getline(cin,ptr1->dname);
        cout<<"\nEnter the car name of the driver:\n"<<endl;
        getline(cin,ptr1->carname);
        cout<<"\nEnter the company name of the driver:\n"<<endl;
        getline(cin,ptr1->company);
        cout<<"\nEnter the phone no of the driver:\n"<<endl;
        cin>>ptr1->phoneno;
        cout<<"\nEnter the vehical no of the driver:\n"<<endl;
        cin>>ptr1->vno;

    }





}
//*****************IIIINNSERTTTT***************//
void parking::insert_data()
{   
    node*ptr=head;
    node*newnode=new node();
    if(slots==total_slots)
    {
        cout<<"\nParking area is full:\n";
        return;
    }
    newnode->next=NULL;
    newnode->prev=NULL;

    cout<<"\nEnter the name of the driver:\n"<<endl;
    cin.ignore();
    getline(cin,newnode->dname);
    cout<<"\nEnter the car name of the driver:\n"<<endl;
    getline(cin,newnode->carname);
    cout<<"\nEnter the company name of the driver:\n"<<endl;
    getline(cin,newnode->company);
    cout<<"\nEnter the phone no of the driver:\n"<<endl;
    cin>>newnode->phoneno;
    cout<<"\nEnter the vehical no of the driver:\n"<<endl;
    cin>>newnode->vno;

    slots++;
    newnode->sindex=slots;
    while(ptr!=NULL)
    {
        if(ptr->vno==newnode->vno)
        {
            cout<<"\nThis car already exists:";
            slots--;
            newnode->sindex=slots;
            return;
        }
        ptr=ptr->next;
        
    }
    if(isempty())
    {
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;

    }


}
//*****************SEARCHHH***************//
node*parking::searchbyindex()
{
    int index;
    cout<<"\nEnter the index :";
    cin>>index;
    node*ptr=head;
    while(ptr->sindex!=index)
    {
        ptr=ptr->next;
    }
    if(ptr->sindex==index)
    {
        cout<<endl;
        cout<<ptr->dname<<endl;
        cout<<ptr->carname<<endl;
        cout<<ptr->company<<endl;
        cout<<ptr->phoneno<<endl;
        cout<<ptr->vno<<endl;
        cout<<"\nRemaining slots:"<<total_slots-slots;
        cout<<"\nThe data is on index:"<<ptr->sindex;
    }
    else{
        cout<<"\nNo data is present";
    }
    return ptr;
}

node *parking::searchbyvno(){
    node*ptr=head;
    cout<<"\nEnter the vno:";
    int vn;
    cin>>vn;
    while(ptr->vno!=vn)
    {
        ptr=ptr->next;
    }
    if(ptr->vno==vn)
    {
        cout<<endl;
        cout<<ptr->dname<<endl;
        cout<<ptr->carname<<endl;
        cout<<ptr->company<<endl;
        cout<<ptr->phoneno<<endl;
        cout<<ptr->vno<<endl;
        cout<<"\nRemaining slots:"<<total_slots-slots;
        cout<<"\nThe data is on index:"<<ptr->sindex;
    }
    else{
        cout<<"\nNo data is present";
    }
    return ptr;
}

//*****************DELETE ANY DATA***************//
void parking::delete_anydata()
{
    int option;
    int index;
    cout<<"\nHow you want to delete the data of cars:\n1-BY index:\n2-BY vehical no:";
    cin>>option;
    node*ptr=head;
    switch(option)
    {
        case 1:
        {
            node*nptr=searchbyindex();
            if (nptr->prev == NULL)
            {
            if (nptr->next == NULL)
            {
                head = NULL;
                tail = NULL;
                return;
            }
            node *temp2 = nptr->next;
            head = temp2;
            head->prev = NULL;
            indexDecrement(nptr->next);
            slots--;
            delete nptr;
            }

            else{
            nptr->prev->next=nptr->next;
            indexDecrement(nptr->next);
            slots--;
            delete nptr;
            }
            break;

        }
        case 2:
        {
            node*ptr1=searchbyvno();
            if (ptr1->prev == NULL)
            {
            if (ptr1->next == NULL)
            {
                head = NULL;
                tail = NULL;
                return;
            }
            node *temp2 = ptr1->next;
            head = temp2;
            head->prev = NULL;
            indexDecrement(ptr1->next);
            slots--;
            delete ptr1;
            }
            else{
            ptr1->prev->next=ptr1->next;
            indexDecrement(ptr1->next);
            slots--;
            delete ptr1;
            }
            break;
        }
        default:
        {
            cout<<"\nWrong input:";
        }
    }
    }


void parking::indexDecrement(node*ptr){
    while(ptr!=NULL)
    {
        ptr->sindex--;
        ptr=ptr->next;
    }
}
//*****************DDDISSPPPPPPLLLAAYYY***************//

void parking::display()
{
    node*ptr=head;
    while(ptr!=NULL)
    {
        cout<<endl;
        cout<<ptr->dname<<endl;
        cout<<ptr->carname<<endl;
        cout<<ptr->company<<endl;
        cout<<ptr->phoneno<<endl;
        cout<<ptr->vno<<endl;
        cout<<"\nRemaining slots:"<<total_slots-ptr->sindex;
        cout<<"\nThe data is on Slot:"<<ptr->sindex;
        ptr=ptr->next;

    }
    if(head==NULL)
    {
        cout<<"\nNo data is present:\n";
    }
}
