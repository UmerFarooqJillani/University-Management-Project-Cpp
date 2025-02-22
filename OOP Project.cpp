#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Person{		//Abstract Class or Base Class
	protected:
		double ID;
		string name;
		double phoneNo;
    public:
    	Person():ID(0), name("Null"), phoneNo(0.0){}
    	Person(double i, string n, double p):ID(i), name(n), phoneNo(p){}
    	virtual void setData() = 0;		//pure virtual function
    	virtual void display()const = 0;		//pure virtual function
    	~Person(){
    		cout<<"Person Destructor Called."<<endl;
		}
};
class Student: public Person{
		double age;
		string fatherName, address, courseEnrolled;
	public:
		Student():age(0), fatherName("Null"), address("Null"), courseEnrolled("Null"){}
		void setData();
		void display()const {
			cout<<endl<<endl;
			cout<<"\t\t\tStudent Name : "<<name<<endl;
			cout<<"\t\t\tStudent ID : "<<ID<<endl;
			cout<<"\t\t\tStudent Age : "<<age<<endl;
			cout<<"\t\t\tStudent Father Name : "<<fatherName<<endl;
			cout<<"\t\t\tStudent Address : "<<address<<endl;
			cout<<"\t\t\tStudent Phone Number : "<<phoneNo<<endl;
			cout<<"\t\t\tStudent Enrolled course : "<<courseEnrolled<<endl;
			return;
		}
		string getCourse(){
			return courseEnrolled;
		}
		double getStdId(){
			return ID;	
		}
		Student* next1;  
		Student* next1_stc; 
		~Student(){
			cout<<"Student Destructor Called."<<endl;
		}
};
void Student::setData(){
		cout<<endl<<endl;
		cout<<"\t\t\tEnter the Name of Student : ";
		cin.ignore();
		getline(cin,name);
		cout<<"\t\t\tEnter the ID of Student : ";
		cin>>ID;
		cout<<"\t\t\tEnter you age : ";
		cin>>age;
		cout<<"\t\t\tEnter you Father name : ";
		cin.ignore();
		getline(cin,fatherName);
		cout<<"\t\t\twho you would like to enroll in a course ?"<<endl;
		cout<<"\t\t\t-> BSCS"<<endl<<"\t\t\t-> BSSE"<<endl<<"\t\t\t-> BSIT"<<endl<<"\t\t\t-> BSAI"<<endl<<"\t\t\t-> BSDS"<<endl;
		cout<<"\t\t\tEnter the Name of course : ";
		cin.ignore();
		getline(cin,courseEnrolled);
		cout<<"\t\t\tEnter you Phone Number : ";
		cin>>phoneNo;
		cout<<"\t\t\tEnter you address : ";
		cin.ignore();
		getline(cin,address);
		return;
}
class Professor: public Person{
		string subjectExpertise, eMail;
	public:
		Professor():subjectExpertise("Null"), eMail("Null"){}
		void setData();
		void display()const {
			cout<<endl<<endl;
			cout<<"\t\t\tProfessor Name : "<<name<<endl;
			cout<<"\t\t\tProfessor ID : "<<ID<<endl;
			cout<<"\t\t\tProfessor Phone Number : "<<phoneNo<<endl;
			cout<<"\t\t\tProfessor E-mail : "<<eMail<<endl;
			cout<<"\t\t\tProfessor subject expertise in : "<<subjectExpertise<<endl;
			return;
		}
		string getExpert(){
			return subjectExpertise;
		}
		double getPrfId(){
			return ID;	
		}
		Professor* next2;
		Professor* next2_pro;
		~Professor(){
			cout<<"Professor Destructor Called."<<endl;
		}
};
void Professor::setData(){
		cout<<endl<<endl;
		cout<<"\t\t\tEnter the Name of Professor : ";
		cin.ignore();
		getline(cin,name);
		cout<<"\t\t\tEnter the ID of Professor : ";
		cin>>ID;
		cout<<"\t\t\tEnter the Professor Phone Number : ";
		cin>>phoneNo;
		cout<<"\t\t\tEnter the E-mail of Professor : ";
		cin.ignore();
		getline(cin,eMail);
		cout<<"\t\t\tEnter you subject expertise ?"<<endl<<"\t\t\t-> BSCS"<<endl<<"\t\t\t-> BSSE"<<endl<<"\t\t\t-> BSIT"<<endl;
		cout<<"\t\t\t-> BSDS"<<endl<<"\t\t\t-> BSAI"<<endl;
		cout<<"\t\t\tChoise one of the above options : ";
		cin.ignore();
		getline(cin,subjectExpertise);
		return;
}
class Course: public Person{
		double creditHours;
		string addCourse;
	public:
		Course():creditHours(0.0), addCourse("Null"){}
		void setData();
		void display() const {
			cout<<endl<<endl;
			cout<<"\t\t\tCourse ID : "<<ID<<endl;
			cout<<"\t\t\tCourse Name : "<<name<<endl;
			cout<<"\t\t\tCredit Hours : "<<creditHours<<endl;
			cout<<"\t\t\tThis course is added in it :"<<addCourse<<endl;
			return;
		}
		string getCourse(){
			return addCourse;
		}
		double getCosId(){
			return ID;	
		}
		Course* next3;
		~Course(){
			cout<<"Course Destructor Called."<<endl;
		}
};
void Course::setData(){
		cout<<endl<<endl;
		cout<<"\t\t\tEnter a Course ID : ";
		cin>>ID;
		cout<<"\t\t\tEnter a course Name : ";
		cin.ignore();
		getline(cin,name);
		cout<<"\t\t\tEnter a credit Hours : ";
		cin>>creditHours;
		cout<<"\t\t\tIn what category would you like to add this course ?"<<endl<<"\t\t\t-> BSCS"<<endl<<"\t\t\t-> BSSE"<<endl<<"\t\t\t-> BSIT"<<endl;
		cout<<"\t\t\t-> BSDS"<<endl<<"\t\t\t-> BSAI"<<endl;
		cout<<"\t\t\tChoise one of the above options : ";
		cin.ignore();
		getline(cin,addCourse);
		return;
}
class Registrar{
	protected:
		Student* first;
		Student* top;
		Professor* firstPrf;
		Professor* top1;
		Course* firstCos;
	public:	
		Registrar(){ 
			first=NULL;
			top=NULL;
			top1=NULL;
			firstPrf=NULL;
			firstCos=NULL;
		}
//----------------------------------------------------------------------------
		void addNewStudent(){		//Enter a New Student
			Student* newobj1 = new Student;
			newobj1->setData();
			newobj1->next1=first;
			first=newobj1;
			return;
		}
		void displayAllStudent(){		//Display all Student
			Student* current1=first;
			while(current1!=NULL){
				current1->display();
				current1=current1->next1;
			}
			return;
		}
		void removeStudent(){		//remove the student
    		double num;
    		cout<<"\n\t\t\tEnter the ID of the student to delete : ";
    		cin>>num;
			Student* current1 = first;
    		Student* previous1;
    		if(current1!=nullptr && current1->getStdId()==num){
	        	first=current1->next1;
	        	push_std(current1);
//    	    	delete current1;
        		cout<<"\n\t\t\tStudent with ID "<<num<<" removed successfully."<<endl;
				return;
	   		}
    		while(current1!=nullptr && current1->getStdId()!=num){
        		previous1=current1;
        		current1=current1->next1;
	    	}
	    	if(current1==nullptr){
        		cout<<"\n\t\t\tNot Found."<<endl;
        		return;
   			}
    		previous1->next1=current1->next1;
    		push_std(current1);
//    		delete current1; 
    		cout<<"\n\t\t\tStudent with ID "<<num<<" removed successfully."<<endl;
    		return;
		}
		void push_std(Student* value) {			//push student in stack
      		Student* newNode = new Student;
      		newNode = value;
        	newNode->next1_stc = top;
        	top = newNode;
    	}
    	void pop_std() {					//stack pop fnc for student
        	if (isEmpty_std()) {
            	cout << "Stack is empty." << endl;
            	return;
        	}
        	top->display();
        	Student* newobj1 = new Student;
			newobj1=top;
			newobj1->next1=first;
			first=newobj1;
        	top = top->next1_stc;
    	}
    	bool isEmpty_std() {						//if stack is empty
        	return top == NULL;
    	}
    	void TOP_std(){                   //stack top print student
        if (isEmpty_std()) {
            cout << "\n\t\t\tStack is empty."<< endl;
            return; 
        }
        	top->display();
        	Student* newobj1 = new Student;
			newobj1=top;
			newobj1->next1=first;
			first=newobj1;
			top = top->next1_stc;
        	return;
    	}
    	void display_std() {					//display student stack
        	if (isEmpty_std()){
            	cout << "Stack is empty." << endl;
            	return;
        	}
        	Student* current = top;
        	while(current!=NULL) {
            	current->display();
            	current = current->next1_stc;
        	}
        	return;
    	}
		void searchStudent(){			//Search Student 
			double num, i=-1;
    		cout<<"\n\t\t\tEnter the ID of the student for search : ";
    		cin>>num;
			Student* current1 = first;
			while(current1!=NULL){
				if(current1->getStdId()==num){
					current1->display();
					i=0;
					return;
				}
				else{
					current1=current1->next1;
				}
			}
			if(i==-1){
				cout<<"\n\t\t\tNot Found."<<endl;
				return;
			}
			return;
		}
//-----------------------------------------------------------------------------
		void addNewProfessor(); 		//Add the new professor
		void displayAllProfessor();		//Display all Professor
		void removeProfessor();			//Remove the professor
		void searchProfessor();			//Search the Professor
		void push_pro(Professor* value) {			//push professor in stack
      		Professor* newNode = new Professor;
      		newNode = value;
        	newNode->next2_pro = top1;
        	top1 = newNode;
    	}
    	bool isEmpty_pro() {						//if stack is empty
        	return top1 == NULL;
    	}
    	void pop_pro() {					//stack pop fnc for professor
        	if (isEmpty_pro()) {
            	cout << "Stack is empty." << endl;
            	return;
        	}
        	top1->display();
        	Professor* newobj1 = new Professor;
			newobj1=top1;
			newobj1->next2=firstPrf;
			firstPrf=newobj1;
        	top1 = top1->next2_pro;
    	}
    	void TOP_pro(){                   //stack top print Professor
        if (isEmpty_pro()) {
            cout << "\n\t\t\tStack is empty."<< endl;
            return; 
        }
        	top1->display();
        	Professor* newobj1 = new Professor;
			newobj1=top1;
			newobj1->next2=firstPrf;
			firstPrf=newobj1;
			top1 = top1->next2_pro;
        	return;
    	}
    	void display_pro() {					//display Professor stack
        	if (isEmpty_pro()){
            	cout << "Stack is empty." << endl;
            	return;
        	}
        	Professor* current = top1;
        	while(current!=NULL) {
            	current->display();
            	current = current->next2_pro;
        	}
        	return;
    	}
    	
//-----------------------------------------------------------------------------
		void addNewCourse(); 		//Add the new Course
		void displayAllCourse();	//Display all Course
		void removeCourse();		//Remove the Course
		void searchCourse();		//Search the Course
//-----------------------------------------------------------------------------
		~Registrar(){				//Registrar Destructor 
    		Student* current1 = first;
    		while(current1!=NULL){
        	Student* next1 = current1->next1;
        	delete current1;
        	current1 = next1;
    		}
    		cout<<"Student Destructor Called."<<endl;
    		Professor* current2=firstPrf;
    		while(current2!=NULL){
    			Professor* next2 = current2->next2;
    			delete current2;
    			current2 = next2;
			}
			cout<<"Professor Destructor Called."<<endl;
    		Course* current3=firstCos;
    		while(current3!=NULL){
    			Course* next3=current3->next3;
    			delete current3;
    			current3 = next3;
			}
			cout<<"Course Destructor Called."<<endl;
			cout<<"Registrar Destructor Called."<<endl;
		}
};
void Registrar::addNewProfessor(){
	Professor* newobj2 = new Professor;
	newobj2->setData();
	newobj2->next2=firstPrf;
	firstPrf=newobj2;
	return;
}
void Registrar::displayAllProfessor(){
	Professor* current2=firstPrf;
	while(current2!=NULL){
		current2->display();
		current2=current2->next2;
	}
	return;
}
void Registrar::removeProfessor(){
	double num;
    cout<<"\n\t\t\tEnter the ID of the Professor to delete : ";
    cin>>num;
	Professor* current2 = firstPrf;
    Professor* previous2;
    if(current2!=nullptr && current2->getPrfId()==num){
	   	firstPrf=current2->next2;
	   	push_pro(current2);
//    	delete current2;
       	cout<<"\n\t\t\tProfessor with ID "<<num<<" removed successfully."<<endl;
		return;
   	}
    while(current2!=nullptr && current2->getPrfId()!=num){
    	previous2=current2;
 		current2=current2->next2;
 	}
	if(current2==nullptr){
       	cout<<"\n\t\t\tNot Found."<<endl;
       	return;
   	}
    previous2->next2 = current2->next2;
    push_pro(current2);
//    delete current2;
    cout<<"\n\t\t\tProfessor with ID "<<num<<" removed successfully."<<endl;
    return;
}
void Registrar::searchProfessor(){
	double num, i=-1;
    cout<<"\n\t\t\tEnter the ID of the Professor for search : ";
    cin>>num;
	Professor* current2 = firstPrf;
	while(current2!=NULL){
		if(current2->getPrfId()==num){
			current2->display();
			i=0;
			return;
		}
		else{
			current2=current2->next2;
		}
	}
	if(i==-1){
		cout<<"\n\t\t\tNot Found."<<endl;
		return;
	}
	return;
}
//-----------------------------------------------------
void Registrar::addNewCourse(){
	Course* newobj3 = new Course;
	newobj3->setData();
	newobj3->next3=firstCos;
	firstCos=newobj3;
	return;
}
void Registrar::displayAllCourse(){
	Course* current3=firstCos;
	while(current3!=NULL){
		current3->display();
		current3=current3->next3;
	}
	return;
}
void Registrar::removeCourse(){
	double num;
    cout<<"\n\t\t\tEnter the ID of the Course to delete : ";
    cin>>num;
	Course* current3 = firstCos;
    Course* previous3;
    if(current3!=nullptr && current3->getCosId()==num){
	   	firstCos=current3->next3;
    	delete current3;
       	cout<<"\n\t\t\tCourse with ID "<<num<<" removed successfully."<<endl;
		return;
   	}
    while(current3!=nullptr && current3->getCosId()!=num){
    	previous3=current3;
 		current3=current3->next3;
 	}
	if(current3==nullptr){
       	cout<<"\n\t\t\tNot Found."<<endl;
       	return;
   	}
    previous3->next3=current3->next3;
    delete current3;
    cout<<"\n\t\t\tCourse with ID "<<num<<" removed successfully."<<endl;
    return;
}
void Registrar::searchCourse(){
	double num, i=-1;
    cout<<"\n\t\t\tEnter the ID of the Course for search : ";
    cin>>num;
	Course* current3 = firstCos;
	while(current3!=NULL){
		if(current3->getCosId()==num){
			current3->display();
			i=0;
			return;
		}
		else{
			current3=current3->next3;
		}
	}
	if(i==-1){
		cout<<"\n\t\t\tNot Found."<<endl;
		return;
	}
	return;
}

class University: public Registrar{
	public:
		void BSCSEnroll(){			//Display BSCS Enrolled person
			cout<<"\n\t\t\tThese professors teaching this course :\n\n";
			Professor* current2 = firstPrf;
			while(current2!=NULL){
				if(current2->getExpert()=="BSCS"){
					current2->display();
				}
				current2=current2->next2;
			}
			cout<<"\n\t\t\tThese subjects are being taught in this course :\n\n";
			Course* current3 = firstCos;
			while(current3!=NULL){
				if(current3->getCourse()=="BSCS"){
					current3->display();
				}
				current3=current3->next3;
			}
			cout<<"\n\t\t\tThese students are studying in this course :\n\n";
			Student* current1 = first;
			while(current1!=NULL){
				if(current1->getCourse()=="BSCS"){
				current1->display();
				}
				current1=current1->next1;	
			}
			return;
		}
		void BSSEEnroll(){			//Display BSSE Enrolled person
			cout<<"\n\t\t\tThese professors teaching this course :\n\n";
			Professor* current2 = firstPrf;
			while(current2!=NULL){
				if(current2->getExpert()=="BSSE"){
					current2->display();
				}
				current2=current2->next2;
			}
			cout<<"\n\t\t\tThese subjects are being taught in this course :\n\n";
			Course* current3 = firstCos;
			while(current3!=NULL){
				if(current3->getCourse()=="BSSE"){
					current3->display();
				}
				current3=current3->next3;
			}
			cout<<"\n\t\t\tThese students are studying in this course :\n\n";
			Student* current1 = first;
			while(current1!=NULL){
				if(current1->getCourse()=="BSSE"){
					current1->display();
				}
				current1=current1->next1;
			}
			return;
		}
		void BSITEnroll(){			//Display BSIT Enrolled person
			cout<<"\n\t\t\tThese professors teaching this course :\n\n";
			Professor* current2 = firstPrf;
			while(current2!=NULL){
				if(current2->getExpert()=="BSIT"){
					current2->display();
				}
				current2=current2->next2;
			}
			cout<<"\n\t\t\tThese subjects are being taught in this course :\n\n";
			Course* current3 = firstCos;
			while(current3!=NULL){
				if(current3->getCourse()=="BSIT"){
					current3->display();
				}
				current3=current3->next3;
			}
			cout<<"\n\t\t\tThese students are studying in this course :\n\n";
			Student* current1 = first;
			while(current1!=NULL){
				if(current1->getCourse()=="BSIT"){
					current1->display();
				}
				current1=current1->next1;
			}
			return;
		}
		void BSAIEnroll(){			//Display BSAI Enrolled person
			cout<<"\n\t\t\tThese professors teaching this course :\n\n";
			Professor* current2 = firstPrf;
			while(current2!=NULL){
				if(current2->getExpert()=="BSAI"){
					current2->display();
				}
				current2=current2->next2;
			}
			cout<<"\n\t\t\tThese subjects are being taught in this course :\n\n";
			Course* current3 = firstCos;
			while(current3!=NULL){
				if(current3->getCourse()=="BSAI"){
					current3->display();
				}
				current3=current3->next3;
			}
			cout<<"\n\t\t\tThese students are studying in this course :\n\n";
			Student* current1 = first;
			while(current1!=NULL){
				if(current1->getCourse()=="BSAI"){
					current1->display();
				}
				current1=current1->next1;
			}
			return;
		}
		void BSDSEnroll(){			//Display BSDS Enrolled person
			cout<<"\n\t\t\tThese professors teaching this course :\n\n";
			Professor* current2 = firstPrf;
			while(current2!=NULL){
				if(current2->getExpert()=="BSDS"){
					current2->display();
				}
				current2=current2->next2;
			}
			cout<<"\n\t\t\tThese subjects are being taught in this course :\n\n";
			Course* current3 = firstCos;
			while(current3!=NULL){
				if(current3->getCourse()=="BSDS"){
					current3->display();
				}
				current3=current3->next3;
			}
			cout<<"\n\t\t\tThese students are studying in this course :\n\n";
			Student* current1 = first;
			while(current1!=NULL){
				if(current1->getCourse()=="BSDS"){
					current1->display();
				}
				current1=current1->next1;
			}
			return;
		}
		~University(){
			cout<<"University Destructor Called."<<endl;
		}
};
void menu(){
	cout<<"\n\t\t\t\t\t\t MENU\n";
	cout<<"\t\t\t\t\t\t------\n\n";
	cout<<"\t\t\tPress 1 to Add, Remove, Search, and Display all Students.\n";
	cout<<"\t\t\tPress 2 to Add, Remove, Search, and Display all Professor.\n";
	cout<<"\t\t\tPress 3 to Add, Remove, Search, and Display all Course.\n";
	cout<<"\t\t\tPress 4 to Check the Course Enrollment Details.\n";
	cout<<"\t\t\tPress 5 to Check the Removed Student Details.\n";
	cout<<"\t\t\tPress 6 to Check the Removed Professor Details.\n";
	cout<<"\t\t\tPress 0 to Exit.\n\t\t\t";
	return;
}
void stdProcess(){
	cout<<endl<<endl;
	cout<<"\n\t\t\t\t\t\tStudent Menu\n";
	cout<<"\t\t\t\t\t\t------------\n\n";
	cout<<"\t\t\tPress 1 to Add a new Students.\n";
	cout<<"\t\t\tPress 2 to Display all the Student.\n";
	cout<<"\t\t\tPress 3 to Search the Student.\n";
	cout<<"\t\t\tPress 4 to Remove a Student.\n";
	cout<<"\t\t\tpress 5 to go back MENU.\n\t\t\t";
	return;
}
void prfProcess(){
	cout<<endl<<endl;
	cout<<"\n\t\t\t\t\t\tProfessor Menu\n";
	cout<<"\t\t\t\t\t\t--------------\n\n";
	cout<<"\t\t\tPress 1 to Add a new Professor.\n";
	cout<<"\t\t\tPress 2 to Display all the Professor.\n";
	cout<<"\t\t\tPress 3 to Search the Professor.\n";
	cout<<"\t\t\tPress 4 to Remove a Professor.\n";
	cout<<"\t\t\tpress 5 to go back MENU.\n\t\t\t";
	return;
}
void cosProcess(){
	cout<<endl<<endl;
	cout<<"\n\t\t\t\t\t\tCourse Menu\n";
	cout<<"\t\t\t\t\t\t-----------\n\n";
	cout<<"\t\t\tPress 1 to Add a new Course.\n";
	cout<<"\t\t\tPress 2 to Display all the Course.\n";
	cout<<"\t\t\tPress 3 to Search the Course.\n";
	cout<<"\t\t\tPress 4 to Remove a Course.\n";
	cout<<"\t\t\tpress 5 to go back MENU.\n\t\t\t";
	return;
}
void courseEnroll(){
	cout<<endl<<endl;
	cout<<"\n\t\t\t\t\t\tCourse Enrolled Menu\n";
	cout<<"\t\t\t\t\t\t--------------------\n\n";
	cout<<"\t\t\tPress 1 to check the details of the BSCS course."<<endl;
	cout<<"\t\t\tPress 2 to check the details of the BSSE course."<<endl;
	cout<<"\t\t\tPress 3 to check the details of the BSIT course."<<endl;
	cout<<"\t\t\tPress 4 to check the details of the BSAI course."<<endl;
	cout<<"\t\t\tPress 5 to check the details of the BSDS course."<<endl;
	cout<<"\t\t\tpress 6 to go back MENU.\n\t\t\t";
	return;
}
void removeNode(){
	cout<<endl<<endl;
	cout<<"\n\t\t\t\t\t\t Removed Students Detail Menu\n";
	cout<<"\t\t\t\t\t\t-----------------------------\n\n";
	cout<<"\t\t\tPress 1 to display Top student in stack."<<endl;
	cout<<"\t\t\tPress 2 to pop in stack."<<endl;
	cout<<"\t\t\tPress 3 to Display Stack."<<endl;
	cout<<"\t\t\tPress 4 to check if Stack is Empty."<<endl;	
	cout<<"\t\t\tpress 5 to go back MENU.\n\t\t\t";
	return;	
}
void removeNode_pro(){
	cout<<endl<<endl;
	cout<<"\n\t\t\t\t\t\t Removed Professor Detail Menu\n";
	cout<<"\t\t\t\t\t\t-----------------------------\n\n";
	cout<<"\t\t\tPress 1 to display Top Professor in stack."<<endl;
	cout<<"\t\t\tPress 2 to pop in stack."<<endl;
	cout<<"\t\t\tPress 3 to Display Stack."<<endl;
	cout<<"\t\t\tPress 4 to check if Stack is Empty."<<endl;	
	cout<<"\t\t\tpress 5 to go back MENU.\n\t\t\t";
	return;	
}

void processor(University* ptr){
	double selector;
	bool a=true;
	menu();
	cin>>selector;
	while(a!=false){
		if(selector==1){
			double std;
			bool stdb=true;
			stdProcess();
			cin>>std;
			while(stdb!=false){
				if(std==1){
					ptr->addNewStudent();
					stdProcess();
					cin>>std;
				}
				else if(std==2){
					ptr->displayAllStudent();
					stdProcess();
					cin>>std;
				}
				else if(std==3){
					ptr->searchStudent();
					stdProcess();
					cin>>std;
				}
				else if(std==4){
					ptr->removeStudent();
					stdProcess();
					cin>>std;
				}
				else if(std==5){
					menu();
					cin>>selector;
					stdb=false;
				}
				else{
					cout<<endl<<endl;
					cout<<"\t\t\t\tWrong Input!"<<endl;
					cout<<"\t\t\tSelect the correct option :"<<endl<<endl;
					stdProcess();
					cin>>std;
				}
			}
		} 
		else if(selector==2){
			double prf;
			bool prfb=true;
			prfProcess();
			cin>>prf;
			while(prfb!=false){
				if(prf==1){
					ptr->addNewProfessor();
					prfProcess();
					cin>>prf;
				}
				else if(prf==2){
					ptr->displayAllProfessor();
					prfProcess();
					cin>>prf;
				}
				else if(prf==3){
					ptr->searchProfessor();
					prfProcess();
					cin>>prf;
				}
				else if(prf==4){
					ptr->removeProfessor();
					prfProcess();
					cin>>prf;
				}
				else if(prf==5){
					menu();
					cin>>selector;
					prfb=false;
				}
				else{
					cout<<endl<<endl;
					cout<<"\t\t\t\tWrong Input!"<<endl;
					cout<<"\t\t\tSelect the correct option :"<<endl<<endl;
					prfProcess();
					cin>>prf;
				}
			}
		}
		else if(selector==3){
			double cos;
			bool cosb=true;
			cosProcess();
			cin>>cos;
			while(cosb!=false){
				if(cos==1){
					ptr->addNewCourse();
					cosProcess();
					cin>>cos;
				}
				else if(cos==2){
					ptr->displayAllCourse();
					cosProcess();
					cin>>cos;
				}
				else if(cos==3){
					ptr->searchCourse();
					cosProcess();
					cin>>cos;
				}
				else if(cos==4){
					ptr->removeCourse();
					cosProcess();
					cin>>cos;
				}
				else if(cos==5){
					menu();
					cin>>selector;
					cosb=false;
				}
				else{
					cout<<endl<<endl;
					cout<<"\t\t\t\tWrong Input!"<<endl;
					cout<<"\t\t\tSelect the correct option :"<<endl<<endl;
					cosProcess();
					cin>>cos;
				}
			}
		}
		else if(selector==4){
			double enr;
			bool enrb=true;
			courseEnroll();
			cin>>enr;
			while(enrb!=false){
				if(enr==1){
					ptr->BSCSEnroll();
					courseEnroll();
					cin>>enr;
				}
				else if(enr==2){
					ptr->BSSEEnroll();
					courseEnroll();
					cin>>enr;
				}
				else if(enr==3){
					ptr->BSITEnroll();
					courseEnroll();
					cin>>enr;
				}
				else if(enr==4){
					ptr->BSAIEnroll();
					courseEnroll();
					cin>>enr;
				}
				else if(enr==5){
					ptr->BSDSEnroll();
					courseEnroll();
					cin>>enr;
				}
				else if(enr==6){
					menu();
					cin>>selector;
					enrb=false;
				}
				else{
					cout<<endl<<endl;
					cout<<"\t\t\t\tWrong Input!"<<endl;
					cout<<"\t\t\tSelect the correct option :"<<endl<<endl;
					courseEnroll();
					cin>>enr;
				}
			}
		}
		else if(selector==5){
			double stc;
			bool stcb=true;
			removeNode();
			cin>>stc;
			while(stcb!=false){
				if(stc==1){
					ptr->TOP_std();
					removeNode();
					cin>>stc;
				}
				else if(stc==2){
					ptr->pop_std();
					removeNode();
					cin>>stc;
				}
				else if(stc==3){
					ptr->display_std();
					removeNode();
					cin>>stc;
				}
				else if(stc==4){
					if (ptr->isEmpty_std()) {
                    	cout <<"\n\t\t\tStack is empty.\n";
                	} 
					else {
                    	cout << "\n\t\t\tStack is not empty.\n";
                	}
					removeNode();
					cin>>stc;
				}
				else if(stc==5){
					menu();
					cin>>selector;
					stcb=false;
				}
				else{
					cout<<endl<<endl;
					cout<<"\t\t\t\tWrong Input!"<<endl;
					cout<<"\t\t\tSelect the correct option :"<<endl<<endl;
					removeNode();
					cin>>stc;
				}
			}			
		}
		else if(selector==6){
			double stc_pro;
			bool stc_prob=true;
			removeNode_pro();
			cin>>stc_pro;
			while(stc_prob!=false){
				if(stc_pro==1){
					ptr->TOP_pro();
					removeNode_pro();
					cin>>stc_pro;
				}
				else if(stc_pro==2){
					ptr->pop_pro();
					removeNode_pro();
					cin>>stc_pro;
				}
				else if(stc_pro==3){
					ptr->display_pro();
					removeNode_pro();
					cin>>stc_pro;
				}
				else if(stc_pro==4){
					if (ptr->isEmpty_pro()) {
                    	cout <<"\n\t\t\tStack is empty.\n";
                	} 
					else {
                    	cout << "\n\t\t\tStack is not empty.\n";
                	}
					removeNode_pro();
					cin>>stc_pro;
				}
				else if(stc_pro==5){
					menu();
					cin>>selector;
					stc_prob=false;
				}
				else{
					cout<<endl<<endl;
					cout<<"\t\t\t\tWrong Input!"<<endl;
					cout<<"\t\t\tSelect the correct option :"<<endl<<endl;
					removeNode_pro();
					cin>>stc_pro;
				}
			}			
		}
		else if(selector==0){
			cout<<"\n\n\n\t\t\t\t\tExit..."<<endl;
			a=false;
		}
		else{
			cout<<endl<<endl;
			cout<<"\t\t\t\tWrong Input!"<<endl;
			cout<<"\t\t\tSelect the correct option :"<<endl<<endl;
			menu();
			cin>>selector;
		}
	}
	delete ptr;
	return;
}

int main(){
	
	cout<<endl<<endl<<setw(100)<<right<<"University Management system"<<endl;
	cout<<setw(101)<<right<<"------------------------------"<<endl<<endl<<endl;
	
	processor(new University);
	
    return 0;
}