/*Implement Circular Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 ” for a linked list holding integers in the order 1,2,3,4. */


#include<iostream>
using namespace std;

//create node

class circles{
	//make publuic
	
	public:
	//data
	int data;
	//node pointer t next one 
	circles * next;
	//constructor t defultly pint t null
	circles(){	
		next =NULL;
	}



};



//create linklist 

class clinkedlist{
	public:

	//head and link cicles (and tail4 convinience)
	
	//create head &tail : node type pointer

	circles* head;
	circles*tail;
	//default values via cnstructor
	
	clinkedlist(){

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
		}

		tail= temp;
		tail->next=head;
	}


	//have insertAt(int pos, int data) - It includes the position at which the insertion happens.
	void insertAt(int pos, int value){
		int i=1;
		//find positin and create a pointer for curent node
		circles * current = head;
	
		//fr 1st pos
		if(pos == 1){
	
			//create node
			circles*temp = new circles;
			// give its pointer 2nds address
			temp->next=head->next;
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
	
		//give its adress to b4 node
		current-> next=temp;
	
	}

	//delete() - Deletes the element at the end of the list.
	void del(){
		//store tail in temp
		circles* temp = tail;
		//change  tail to the now last node
		circles *current = head;
		while(current->next != tail){
			current=current->next;
		}
		tail=current;
		
		tail->next =head;
		//delete temp
		delete temp;

	}

	//deleteAt(int pos) - Deletes the element(or node) at the position pos)
	void delat (int pos){

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
		//delete temp
		delete temp;


	}

	//countItems() - Returns the number of items in the linked list. 
	int count(){
		int i=0;
		circles*current=head;
		while(current->next !=head ){
			current=current->next ;
			i++;
	
		}
		i++;//for last element
		return i;

	}
	//display() - Displays all the elements in the linked list. 
	void disp(){

		circles* current= head;
		
		while(current->next != head){
			cout<<current->data <<"->";
			current=current->next;

		}
			cout<<current->data <<"->";
			cout<<"and the cycle continues"<<endl;



		}
	

	// recurtion
	void rd1(){
			//gethead
			rd2(head);
	}
	void rd2(circles* current){
		
		
		//move tlast
		if(current->next != head){
		rd2(current->next);
		cout<<current->data<<"->";
		}
		else
		{

		cout<<current->data<<"->";

		return;}
		
		


	} 
};



int main(){circles* c;
	clinkedlist l1;
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
	l1.rd1();
	cout<<"and repeats"<<endl;
	cout<<endl;
return 0;
}




