/*
Implement Doubly Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4.

*/



#include<iostream>
using namespace std;

//create node

class circles{
	//make publuic
	
	public:
	//data
	int data;
	//node pointer 
	circles * next;
	circles* prev;
	//constructor t defultly pint t null
	circles(){	
		next =NULL;
		prev =NULL;
	}
};

class linkedlist{
	public:

	//head and link cicles (and tail4 convinience)
	
	//create head &tail : node type pointer

	circles* head;
	circles*tail;
	//default values via cnstructor
	
	linkedlist(){

		head= NULL;
		tail = NULL;
	
	}

	//insert(int data) - Adds a new element to the end of the linked list.
	//additin of  nodes
	void insert(int value){
		//creation of  node
		circles * temp = new circles;
		temp->data = value;
		//for first node
		if(head==NULL){
				head=temp;
		}
		//additin f any other node (using tail)

		else
			{
				tail->next=temp;
				temp-> prev = tail;
		}

		tail= temp;
	}

	//have insertAt(int pos, int data) - It includes the position at which the insertion happens.
	void insertAt(int pos, int value){
		int i=1;
		//find positin and create a pointer for curent node
		circles * current = head;
		//checking validity of position

		if(i+1>count())
		{	cout<<"Linked List does not have that many elements"<<endl;}
		//fr 1st pos
		if(pos == 1){
	
			//create node
			circles*temp = new circles;
			// give its pointer 2nds address
			temp->next=head->next;
			//prev remains null
			//give head its adress
			head=temp;
		}
		
		while(i < pos-1){
			i++;
			current=current->next;
		}
		//add a nde
		circles * temp = new circles;
		temp->data = value;
		//give its pointer adressof next node
		temp->next = current-> next;
		temp->prev= current;
		//give its adress to b4 node
		current-> next->prev=temp;
		current-> next=temp;
	}

	//delete() - Deletes the element at the end of the list.
	void del(){
		//store tail in temp
		circles* temp = tail;
		//change  tail to the now last node
		
		tail=tail->prev;
		
		tail->next =NULL;
		//delete temp
		delete temp;

	}

	//deleteAt(int pos) - Deletes the element(or node) at the position pos)
	void delat (int pos){
		//validity of i
		if(pos>count())
		{	cout<<"Linked List does not have that many elements"<<endl;}
		//fr 1st pos
		//for 1st position
		if(pos==1){
	
			//assign temp head
	
			circles *temp = head;
			//assign head its next
	
			head = head->next;
			//delete temp
			delete temp;
		
		}
	
	
	
		//reach pos -1th position(pointed current)
		int i=1 ;
		circles* current = head;
		while(i< pos-1){
			current =current->next;
			i++;
		}
		//store its next in temp

		circles *temp = current->next;
	

		//stoe temps next in currents next
		current-> next= temp->next;
		current ->next->prev= current;
		//delete temp
		delete temp;


	}


	//countItems() - Returns the number of items in the linked list. 
	int count(){
		int i=0;
		circles*current=head;
		while(current != NULL){
			current=current->next ;
			i++;
	
		}
	
		return i;

	}
	//display() - Displays all the elements in the linked list. 
	void disp(){

		circles* current= head;
		
		while(current != NULL){
			cout<<current->data <<"->";
			current=current->next;

		}
			cout<<"NULL"<<endl;



		}
	
};


int main(){circles* c;
	linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.del();
	l1.insertAt(3,8);
	
	l1.delat(3);
	cout<<"number of items linked is: "<<l1.count()<<endl;
	l1.disp();
	
	cout<<endl;
return 0;
}
