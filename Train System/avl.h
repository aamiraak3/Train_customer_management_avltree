
//#include "train sys.cpp"
#include <iostream>
#include <string>
using namespace std;


/*
* Node for Train sys list
*/

struct Person{
	
	int ticket_id;
	int CNIC; 				
	string destination;
	string name;
	char gender;
	Person* next;
	string departure_time;
};

struct node{
	int id,hgt;
	node *left,*right;
	Person pData;
	bool check;
	
	
	node() {  // constructor for struct
		hgt=0;
		left=right=NULL;
		check=false;
	}
};
int find_height(node* ,bool );


class Avl_tree{
public:
	node* root; 
	int count,max,aa;

Avl_tree(){
	count=0;
	max=0;
	root=NULL;
}
		
void print(node *temp){	
		
	if(temp==NULL){
		cout<<"\t\t\t\t\tTree is so Empty.\n"<<endl;
		return;
	}		
	if( temp->left!=NULL ){    //swap if condition of left with right to print in decending order		
    	 print(temp->left);
   	} 	
	//cout<<temp->id<<"  height is :  "<<temp->hgt<<" bf is :  "<<(find_bf(temp))<<endl;    // inorder	
	cout << "\nTicket ID : " << temp->pData.ticket_id << "\tCustomer CNIC : " << temp->pData.CNIC << "\tCustomer Name : " << temp->pData.name<< "\tDestination : " << temp->pData.destination<< endl;
	cout << "\n------------------------------------------------------------------------------------------------------------------\n";
	if( temp->right!=NULL )
		print(temp->right);	 
}
		
int find_height(node* temp,bool a){
	if(a){
		max=0;
		a=false;
	}
	if( temp->left!=NULL ){  	
   		find_height(temp->left,false);	 
    }
	if(temp->hgt>=max){
		max=temp->hgt;			
	}
   	if( temp->right!=NULL ){
   		find_height(temp->right,false);
	}	 
    	//int z=max;
    return max;		
}

node* succ(node* suc){
	while(suc->left!=NULL){
		suc=suc->left;
	}
	return suc;
}
		
int find_bf(node* temp){
	int t=temp->hgt;	
	if(temp->left ==NULL && temp->right==NULL){
		return 0;
	}	
	else if(temp->left==NULL){
		return t-find_height(temp->right,true);
	}	
	else if(temp->right==NULL){
		return find_height(temp->left,true)-t;
	}
	else{
//			cout<<find_height(temp->left,true)<<" - "<<find_height(temp->right,true)<<endl;
		return find_height(temp->left,true)-find_height(temp->right,true);
	}
	
}
		
void update_height(node* temp, bool a)   // increment or decrement height
{
	if(temp==NULL){
		return;
	}				
	if( temp->left!=NULL ){    		
    	update_height(temp->left,a);
    }	
	if(a){
		temp->hgt++;
	}
	else{
		temp->hgt--;
	}
	if( temp->right!=NULL )
    	update_height(temp->right,a);	 
}
		
node* cc(node* temp_root){
	if(find_bf(temp_root)==-2)// || find_bf(temp_root)==-2)  // also change height    left rotation
{
		bool j=false;
		if(temp_root->hgt==0)  // checking root
			j=true;
			if(find_bf(temp_root->right)==1)  // double rotaito
			{		
				update_height(temp_root->right->right,true);
				update_height(temp_root->right->left,false);
				temp_root->right->hgt++;
				
				if(temp_root->right->left->right!=NULL)
				update_height(temp_root->right->left->right,true);
				
				node* temp2=temp_root->right;  
				
				temp_root->right=temp2->left;   	
				
				temp2->left=temp_root->right->right;     

				temp_root->right->right=temp2;				
				}
			
				update_height(temp_root->right,false);
				
				update_height(temp_root->left,true);
				
				temp_root->hgt++;
			
				if(temp_root->right->left!=NULL)
				update_height(temp_root->right->left,true);
				
				node* temp2=temp_root;  
				
				temp_root=temp2->right;	
				
					 	
				temp2->right=temp_root->left;

				temp_root->left=temp2;
				
			if(j)	
			root=temp_root;			
			}
			if(find_bf(temp_root)==2)//  // also change height     // right rotation
			{
				bool j=false;
				if(temp_root->hgt==0)  // checking root
					j=true;
				
				if(find_bf(temp_root->left)==-1)  // double rotaito
				{	
				update_height(temp_root->left->right,false);
				update_height(temp_root->left->left,true);
				temp_root->left->hgt++;
			
				if(temp_root->left->right->left!=NULL)
				update_height(temp_root->left->right->left,true);
				
				node* temp2=temp_root->left;  
				temp_root->left=temp2->right;			
				temp2->right=temp_root->left->left;
				temp_root->left->left=temp2;
									
				}
				
				update_height(temp_root->right,true);
				update_height(temp_root->left,false);
				temp_root->hgt++;
				
				if(temp_root->left->right!=NULL)
				update_height(temp_root->left->right,true);
				
				node* temp2=temp_root;  
				temp_root=temp2->left;   	
				temp2->left=temp_root->right;     
				temp_root->right=temp2;
				
			if(j)	
			root=temp_root;				
			}
			return temp_root;
	}
	
		
node* insert(node* temp_root,Person d){
	
	/*
	*	function reieves Person Node as argument
	*	copies data from Person Node to avl Node
	*/
	
	count+=1;   

	if(temp_root==NULL){
		count=0;
		node* temp = new node;
		temp->id = d.ticket_id;
		temp->pData = d;
		root  =temp;
		
		return root;
	}
	if (d.ticket_id > temp_root->id){
		if(temp_root->right!=NULL){
			// Case : when right child is not null
			temp_root->right  =insert(temp_root->right,d);
		}
		else{
			// Case : when right child is null
			temp_root->check = true;
			node* temp =  new node;
			temp->id = d.ticket_id;
			temp->pData = d;
			temp->hgt=count;
			count=0;
			temp_root->right = temp;
			return temp_root;
		}
	}
	else if (d.ticket_id < temp_root->id){
		if(temp_root->left!=NULL){
			// Case : Left Child is not NULL
			temp_root->left=insert(temp_root->left,d);
		}
		else{
			// Case : Left Child is NULL
			temp_root->check=true;
			node* temp=new node;
			temp->id=d.ticket_id;
			temp->pData = d;
			temp->hgt=count;
			count=0;
			temp_root->left = temp;
			return temp_root;
		}				
	}
			
	else{
		cout<<"\t\t\t\t\tDuplicate Item found in the Tree .\n"<<endl;
		return 0;
	}
	temp_root = cc(temp_root);		
}
	
node* del(node* temp_root,Person d){
	if(temp_root==NULL){
		cout<<"\t\t\t\t\tTree is so Empty.\n"<<endl;
		return 0;
	}
	if(temp_root->id==d.ticket_id){
		if(temp_root->left==NULL && temp_root->right==NULL)  // first case
		{
			node* tt=NULL;
			if (temp_root==root){
					root=tt;
			}
			delete temp_root;
			temp_root=NULL;
			return tt;
		}
			
		if(temp_root->left==NULL && temp_root->right!=NULL)  // second case
		{
			node* tt=temp_root->right;
			if (temp_root==root){
					root=tt;
			}
			delete temp_root;
			temp_root=NULL;  
			return tt;
		}
		if(temp_root->left!=NULL && temp_root->right==NULL)  // second case  2
		{
			node* tt=temp_root->left;
			if (temp_root==root){
				root=tt;
			}	
			delete temp_root;
			temp_root=NULL;
			return tt;
		}
		if(temp_root->left!=NULL && temp_root->right!=NULL)  //  case  3
		{
			node *temp_root1=temp_root;
			node* min=succ(temp_root1->right);
			int n;
			n=temp_root->id;
				
			temp_root->id=min->id;
			min->id=n;
				
			temp_root->right= del(temp_root->right,d);
			return temp_root;
		}
	}
	if(temp_root->right!=NULL){
		if(temp_root->id<d.ticket_id){
			temp_root->right=del(temp_root->right,d);
			temp_root=cc(temp_root);	
			return temp_root;
		}
	}
	temp_root=cc(temp_root);	
	if(temp_root->left!=NULL){
		if(temp_root->id>d.ticket_id){
			temp_root->left=del(temp_root->left,d);
			temp_root=cc(temp_root);		
		}
	}	
}		
};
