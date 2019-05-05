#include <iostream>
#include <string>
#include "avl.h"
using namespace std;


class Train_Sys{

private:
Person * head,*temp;

public:

Train_Sys(){
	head = NULL;
}
	
void option(){
	cout <<"    Select One of The Following Option:\n01. Customers Detail. \n02. Ticket Booking \n03. Deleating Customers\n";
	cout << "04. Storing Customer's data into AVL.\n05. Print Customers Through AVL.\n06. Delete Whole AVL.\n";
	cout<<"00. Quit The Program.\n";
}	
	
	
void insert(int id,string nam,char gen){
	Person *  temp = head;
	if (head == NULL){
		head = new Person;
		head->CNIC = id;
		
		head->name = nam;
		head->gender = gen;
		head->next = NULL;
		
		return;
	}
	else {
		temp = head;
		while(temp->next != NULL){		
			temp=temp->next;
		}
		Person * temp1 = new Person;
		temp1->CNIC = id;
		temp1->name = nam;
		temp1->gender = gen;
		temp1->next = NULL;
		temp->next = temp1;
		return;		
	}
}
void tkt_book(int tk_id,int cnic,string dest,string na,char ge, string timing){
	
	Person * temp = head; 
	if(temp == NULL ){
		temp = new Person;
		temp->ticket_id = tk_id;
		temp->CNIC = cnic;
		temp->destination = dest;
		temp->name = na;
		temp->gender = ge;
		temp->departure_time = timing;
		temp->next = NULL;
		head = temp;
		return;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		Person * temp1 = temp;
		temp1 = new Person;
		temp1->ticket_id = tk_id;
		temp1->CNIC = cnic;
		temp1->destination = dest;
		temp1->name = na;
		temp1->gender = ge;
		temp1->departure_time = timing;
		temp1->next = NULL;
		temp->next = temp1;
		return;
		
		
	}
}
void del_person(int x){
	Person* temp=head;
	if(head==NULL){
		return;
	}
	while(temp->next!=NULL){
		if(head->CNIC==x){
			head=head->next;
		}
		if(temp->next->CNIC==x){
			temp->next=temp->next->next;
			continue;
		}
		temp=temp->next;
	}	
}

void print(){
	Person * temp = head;
	while(temp != NULL){
		cout<<"Customer CNIC: "<<temp->CNIC<<"    ";
		cout<<"Name : "<<temp->name<<"    ";
		cout<<"Gender : "<<temp->gender<<"    ";
				
		cout <<"\n";
		cout <<"\n";
		
		temp=temp->next;
	}
	cout <<"\n";
}
void print_tkt(){
	Person * temp = head;
	while(temp != NULL){
		cout<<"Ticket ID: "<<temp->ticket_id<<"    ";
		cout<<"Destination : "<< temp->destination <<"    ";
		cout<<"Name : "<< temp->name <<"    ";
		cout<<"Gender : "<< temp->gender <<"    ";
		cout << "Departure Time : "<< temp->departure_time;
				
		cout <<"\n";
		temp = temp->next;
		cout <<"\n";
	}
	cout <<"\n";
}

int getLength() {
	
	/*
	 * Return current Length of List
	 */
	
	int count = 0;
	Person* temp = new Person;
	temp = this->head;
	
	while(temp != NULL) {
		temp = temp->next;
		count++;
		
	}
	
	return count;
}

Person* getHead() {
	
	/*
	 * Returns Head of Train_Sys List
     */
     return this->head;
}


};

Avl_tree movePersonToNode(Train_Sys ts, Avl_tree avlt) {
	
	/*
	* function recieves complete Train_Sys List and 
	* the complete avl tree and moves data from train_sys 
	* to avl_tree
	*/
	
	int len = ts.getLength();
	cout << "\t\tTotal Number of Customer is : " << len-1 << endl;  
	Person *temp = ts.getHead();
	
	
	for(int i = 0; i < len; i++) {
		cout << "Moving Person Through Ticket ID = " << temp->ticket_id << endl;
		Person temp2 = *temp;
		avlt.insert(avlt.root, temp2);
		temp = temp->next;
	}
	
//	cout << "\n\n\t\t\t\tPrinting Customers Detail Through AVL\n" << endl;
//	cout <<      "\t\t\t\t`````````````````````````````````````\n";
//	avlt.print(avlt.root);
	
	return avlt;
}

Avl_tree dltPersonToNode(Train_Sys ts, Avl_tree avlt) {
	
	/*
	* function recieves complete Train_Sys List and 
	* the complete avl tree and delete data from avl_tree
	*/
	
	int len = ts.getLength();
	cout << "\t\tTotal Number of Customer is : " << len-1 << endl;  
	Person *temp = ts.getHead();
	
	
	for(int i = 0; i < len; i++) {
		cout << "Deleting Person Through Ticket ID = " << temp->ticket_id << endl;
		Person temp2 = *temp;
		avlt.del(avlt.root, temp2);
		temp = temp->next;
	}
	
//	cout << "\n\n\t\t\t\tPrinting Customers Detail Through AVL\n" << endl;
//	cout <<      "\t\t\t\t`````````````````````````````````````\n";
//	avlt.print(avlt.root);
	
	return avlt;
}



int main(){
	
	Train_Sys a,b;
	
	Avl_tree avl;
	
	// Dumpning Data into AVL
	
//	avl.insert(avl.root, 1);
//	avl.insert(avl.root, 2);
//	avl.insert(avl.root, 3);
//	avl.insert(avl.root, 4);
//	avl.insert(avl.root, 5);
	
	// Dumping Data into ticket_list
	
	a.tkt_book(1000,35201,"Waziristan","Aamir Ahmad Wazir",'M',"12:00");
    a.tkt_book(1001,35202,"Peshawar","Sara Ahmad Khan",'F',"13:15");
	a.tkt_book(1002,35203,"Kohat","Huzaifa Afridi khan",'M',"21:15");
	a.tkt_book(1003,35204,"Karachi","Salma Khan Wazir",'F',"23:15");
	a.tkt_book(1004,35205,"Islamabad","Abu bakar Mahsood",'M',"15:15");
	a.tkt_book(1005,35206,"Qutta","Iman Shah Mehsood",'F',"02:15");
	a.tkt_book(1006,35207,"Bannu","Sahar  Ali Khan",'M',"13:15");
	a.tkt_book(1007,35208,"Sargodha","Amir Ahmad Khan",'F',"13:15");
	a.tkt_book(1008,35209,"Chitral","Sajdda Ameer Khan",'F',"13:15");
	a.tkt_book(1009,35210,"ParaChinnar","Ali Ghulam Khan",'M',"13:15");
	a.tkt_book(1010,35211,"Nowshara","Shah Hussain Khan",'F',"13:15");

				
	
	int ch;
	cout <<"\t\t\t\t\t|WELCOME  TO   TRAIN TRACK MANAGMENT SYSTEM|\n";
	cout <<"\t\t\t\t\t````````````````````````````````````````````\n";
		while(1){
		a.option();
		cout<<"\t\tEnter One Of The Above Choice : ";
		cin>>ch;

		system ("CLS");
		switch(ch){
			case 1:
				//cout <<"\n";
				cout<<"\t\t\t\tCustomers Detail: \n\n";
				
				a.print();
				cout <<"\n";
				break;
			case 2:
				//cout <<"\n";
				cout<<"\t\t\t\tTicket Booking Details: \n\n";
				a.print_tkt();
				cout <<"\n";
				break;
			case 3:
				//cout <<"\n";
				cout<<"\t\t\t\tAfter Deletion of Customers\n\n";
				a.del_person(101);
				a.print();	
				cout <<"\n\n";
				break;
			case 4:
				cout << "Moving Data to AVL ..." << endl;
				avl = movePersonToNode(a, avl);
				cout << "\t\t\tData Successfully Moved to AVL ...\n" << endl;
				break;
			case 5: 
				cout << "\n\n\t\t\t\tPrinting Customers Data through AVL.\n" << endl;
				cout <<"\t\t\t\t````````````````````````````````````\n";
				avl.print(avl.root);
				break;
			case 6:
				cout << "Deleting  Data from AVL ..." << endl;
				avl = dltPersonToNode(a, avl);
				cout << "\t\t\tData Successfully Deleted from AVL ...\n" << endl;
				break;
			case 0:
				cout <<"You Pressed an EXIT Button\n\n\t\tEXIT SUCCESSFULLY . . .";
				exit(0);
				break;
			default:
				cout<<"\tSorry Wrong Input. Please Try Again. ";
				cout <<"\n\n";
				break;
		}	
	}
	
}
