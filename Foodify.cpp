#include <iostream>
#include <fstream>
#include <string>
#include "sstream"
#include<cmath>
#include "Stack.cpp"

using namespace std;


#define MAXDISH 100
class User;




template<class T>
class Node{         //node class for linked list
    public:
    T data;
    Node<T>* next;
};
class Dish
{
    string name;
    double price;
    string type;

public:
	void settype(string type){
		this->type = type;
	}
	
	string gettype(){
		return type;
	}
	
    //constructor
    Dish()
    {
        name = "NULL";
        price = 0;
  		type = "NULL";
    }
	
    Dish(string name, double price, string label)
    {
        this->name = name;
        this->price = price;
        //this->label = label;
    	this->type = label;
	}

    //setters
    void setName(string na)
    {
        name = na;
    }
    void setPrice(double r)
    {
        price = r;
    }

    //getters
    string getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }
};

template<class T>
class NodeT{         //node class for linked list
    public:
    T data;
    NodeT<T>* next;
};

template<class T>
class Queue{
	User *user;
	NodeT<T>* head;
	NodeT<T>* tail;
	int totalbill;
	int rear;	
	public:
		void clear(){
			head = tail = NULL;
			totalbill = 0;
		
			rear = 0;
		}
		
		void display(){
			NodeT<T> *ptr = head;
			cout <<endl<< "	 ITEM NAME					" << "				PRICE					" <<endl;
				
			while(ptr != NULL){
				
				cout << ptr->data.getName() ;
				for(int i = 30 - ptr->data.getName().length() ; i>= 0 ;i--){
					cout <<" ";
				}
				cout <<" 							";
				cout << ptr->data.getPrice();
				cout << endl;
				ptr = ptr->next;
			}
			cout << endl << "\t\t\tBILL = " << this->totalbill << endl;
			
			cout<< endl << "\t\t\tPRESS ANY KEY TO GO BACK" << endl;
			cout << "PRESS P TO PLACE ORDER" << endl;
			cout << "PRESS X to POP THE FIRST ITEM OF THE CART" <<endl;
			string x ;
			cin >> x;
			if(x == "P" || x == "p"){
				system("cls");
				cout<< endl<< endl << endl << "\t\t\tYOUR ORDER HAS BEEN PLACED RESTAURANT WILL CONTACT U SOON!! THANKS FOR YOUR O0RDER" << endl;
			}else if(x == "X" || x == "x"){
				if(!this->empty()){
					T d = head->data;
					this->deque();
					system("cls");
					
					cout << endl <<  "\tKicked out " <<d.getName() << " from  CART" <<endl; 
					this->display();
				}else{
					cout << endl << "\t\tCart already empty " << endl;
				}
			}
			
		}

		
		int gettotalbill(){
			return totalbill;
		}
		void setUser(User *user){
			this->user = user;
		}
		Queue()
		{
			this->user = NULL;
			totalbill = 0;
			head = NULL;
			tail = NULL;
			rear = 0;
		}
		
		void enque(T el)
		{
			NodeT<T>* temp = head;
			NodeT<T>* newnode = new NodeT<T>();
			newnode->next = NULL;
			newnode->data = el;
			
			if(head == NULL && tail == NULL)
			{
		
				head = newnode;
				tail = newnode;
				rear++;
			}
			else{
				
				tail->next = newnode;
				tail = newnode;
				rear++;
			}
			totalbill += el.getPrice();			
		}
		
		void deque()
		{
			if(empty())
			{
				cout << "queue is empty" << endl;
				return ;
			}
			else{
				
				NodeT<T>* temp = head;
				int p = temp->data.getPrice();
				totalbill -= p;
				head = head->next;
				NodeT<T>* el = temp;
				temp->next = NULL;
				rear--;
				
				
			}
			
		}
		int size()
		{
			return rear;
		}
		T front()
		{
			if(!empty()){
				return head->data;
				
			}
		}
		int empty()
		{
			if(size() == 0)
			{
				return 1;
			}
			else{
				return 0;
			}
		}	
};

typedef Queue<Dish> CART;

class FRONTEND{
	string menu1_options[6] = {"SIGN IN" , "Create a Free Account" , "Watch recommendations by others" , "Explore Restaurants" ,"Contact Foodify" , "EXIT" };
	string user_menu[7] = {"Change Address" ,"ORDER HISTORY" ,"Watch recommendations by others" ,"Explore Restaurants" , "Change contact number" , "Register Complaint" , "Logout"};
			
	

	int print_general_menu(string *arr , int size){
		cout << endl;
		cout << endl;
		for(int i = 0 ; i < size ; i++){
			cout << i+1 << " )   " << arr[i] << endl << endl; 	
		}
		cout << endl;
		return this->input();
		
	}	
		
	int printmenu1(){
		cout << endl;
		cout << endl;
		
		for(int i = 0 ; i < 6 ; i++){
			cout << i+1 << " )   " << menu1_options[i] << endl << endl; 	
		}
		cout << endl;
		return this->input();
	}
	
	
		
	
	
	
	
	
	
	
	
	
	public:
	void stop(){
		string x;
		cout << endl << "press any key to continue"<<endl;
		cin >> x;
		
	}
	
		int printmenu2(){
		cout << endl;
		cout << endl;
		
		for(int i = 0 ; i < 7 ; i++){
			cout << i+1 << " )   " << user_menu[i] << endl << endl; 	
		}
		cout << endl;
		return this->input();
	}

	
		
	void print_title(){
		cout<<endl << "\t\t.   .\t\t      " << "> > >> >> >>>> FOODIFY <<<< << << < < " << endl<<endl;
		cout << "\t\t . . \t\t\t   /// We Deliver Quality ///"  << endl<<endl;
		cout<<"\t\t  .  "<<endl;
	}	

	int front_screen(){
		cout << endl;
		print_title();
		return this->printmenu1();
	}	
	static void getgaps(int gaps){
		for(int i = 0 ; i < gaps ; i++){
			cout << " ";	
		}
	}
		int input(){
		string in;
		int num;
		cout << ">>>  ";
		cin >> in;
		istringstream(in)  >> num;
		return num;
	}	
};




class MENU{
		
	Dish *dishes ;
	Dish *fdishes;
	int ndishes;
	int totaldishes;
	public:
		void filter(string *arr , int n){
			for(int i = 0 ; i < n ;i++){
				this->print_menu_selected(arr[i]);		
			}
		}
		
		MENU(){
			
			totaldishes = 0;
			ndishes = 200;
			dishes = new Dish[ndishes];
			fdishes = new Dish[100];
			get_dishes();
		}
		
		Dish getdish(int i , string x){
			if(i < ndishes && i>=0){
				return dishes[i];
			}
			Dish d;
			d.setName(x);
			
			return d;
		}
		
		Dish  getdishatindex(int i){
			if(i < totaldishes && i>=0){
				return fdishes[i];
			}
			Dish d;
			d.setName("NULL");
			return d;
		}
		
		
		void get_dishes(){
			ifstream in;
			in.open("FOOD.csv");
			string line;
			int i = 0;
			while(in.good()){
				getline(in , line , ',');
				dishes[i].settype(line);
				getline(in , line , ',');
				dishes[i].setName(line);
				getline(in , line , ',');
				double dou;
				istringstream(line) >> dou;
				dishes[i].setPrice(dou);				
				getline(in , line , '\n');
				
				i++;
							
			}
			
			ndishes = i;
		}
		
		void print_Dishes(){
			int maxchar = 40;
			cout << "		NAME		" << "		PRICE			" << " 		TYPE		 " << endl;
			for(int i = 0 ; i < this->ndishes ; i++){
				cout <<i+1 <<" ) " << dishes[i].getName() ;
				int len = 45-dishes[i].getName().length();
				for(int i = 0 ; i < len ;i++){
					cout << " ";
				}
				cout << dishes[i].getPrice() << "  					" << dishes[i].gettype() << endl;
			}
		}
		
		void compare_stirngs(string &s1 , string &s2){
			for(int i = 0 ; i < s1.length() ; i++){
				cout << endl << s1[i];
			}
		}
		string &tolowercase(string &s1 ){
			for(int i = 0 ; i < s1.length() ; i++){
				if(s1[i] >= 65 && s1[i] <= 90){
					s1[i] = s1[i]+32;
				}
			}
			return s1;	
		}
		
		void print_menu_selected(string s){
			
			int j = 0;
			for(int i = 0 ; i < this->ndishes ; i++){
				string s1 = dishes[i].gettype();
				
				//cout <<"lc = " <<this->tolowercase(s1) << "     lc2 = " <<  this->tolowercase(s) << endl;
				if(this->tolowercase(s1) == this->tolowercase(s)){
				
					this->fdishes[j] = dishes[i];
					cout << ++j << "  )  " << dishes[i].getName() << "                                " <<  dishes[i].getPrice() << endl;  
				}
			}
			totaldishes = j;
			if(totaldishes == 0){
				cout << "restauanrats has no food uptil now" << endl;
			}
		}
		
};

class Restaurant
{
    string website;
    int restID;
    static int restCount;
    string name;
    string location;
    string *types;
    int ntypes;
    int numOfDishes;
    string disharr;
	MENU menu;    
    string city;
    string locaity;
	string cuisines;
	int for_two;
	double rating;
	string comments;
	int votes;
	Dish *all_dishes;
	
public:
	
	void print_a_restaunt(int n){
	
		cout << n <<" ) " << this->restID << "			" << this->name;
		for(int i = 50 ; i>=0 ;i--){
			cout <<" ";
		}
		cout << this->getRatings() << "			" << this->location << endl;
		
	}
	
	Dish menu_prompt(){
			string x ;
			//menu.print_menu_selected(types[0]);
			menu.print_Dishes();
			cout <<  endl<<" \t\tPRESS C to display Cart | PRESS B to exit | Press r for recommended restaurants " << endl << endl;
			cin >> x;
			int i;
			istringstream(x) >> i;
			
			//return menu.getdishatindex(i-1);
			return menu.getdish(i-1, x);
	}
	
	
	void break_string(string &s,string*arr){
	ofstream out;
	out.open("practice.txt");
	out << s;
	out.close();
	
	ifstream in;
	
	in.open("practice.txt",ios::in)	;
	char bin;
	
	while(in.good()){
		string line;
		getline(in ,line , ',' );
		arr[ntypes++] = line;	
	}
	in.close();
}

		void set_for_two(int s){
		for_two = s;
	}
	int get_for_two(){
		return this->for_two;	
	}
	void set_comments(string s){
		comments = s;
	}
	string get_comment(){
		return this->comments;
	}
	
	void setlocality(string l){
		this->locaity = l;
	}
	string getlocality(){
		return this->locaity;
	}
	void setcity(string city){
		this->city = city;
	}
	string getcity(){
		return this->city;
	}
	void setcusines(string c){
		cuisines = c;
		this->break_string(c , this->types);
	}
	string getcuisines(){
		return this->cuisines;
	}
	void setnumber_of_votes(int v){
		this->votes = v;
	}
	
	
    Restaurant()
    {
    	types = new string[10];
        restID = restCount;
        restCount++;
        name = "NULL";
        location = "NULL";
        numOfDishes = 0;
      	all_dishes = new Dish[200];
	    //ratings = 0;
//        contactNo = "NULL";
//        website = "NULL";
//        type = "NULL";
    }
    Restaurant(string name, string loc, string cont, string web, string type)
    {
        restID = restCount;
        restCount++;
        this->name = name;
        location = loc;
        numOfDishes = 0;
      	all_dishes = new Dish[200];

    }

    //setter
    void setName(string nam)
    {
        name = nam;
    }
    void setLocation(string loc)
    {
        location = loc;
    }
    void setID(int id)
    {
        restID = id;
    }
    void setRatings(double r)
    {
        rating = r;
    }
    void setNumOfVotes(int n)
    {
        votes = n;
    }
    //add,remove,search

    void addARating(double r)
    {
        if (r >= 0 && r <= 5)
        {
            /// TODO: apply formula
        }
    }




    //getters
    string getName()
    {
        return name;
    }
    string getLocation()
    {
        return location;
    }
    int getID()
    {
        return restID;
    }
    int getntypes(){
    	return this->ntypes;
	}
    string gettype(int i){
    	return this->types[i];
	}
    int getNumOfDishes()
    {
        return numOfDishes;
    }
    int getNumOfvotes()
    {
        return votes;
    }
    double getRatings()
    {
        return rating;
    }
};
int Restaurant::restCount = 1;

class paymentMethod
{
    string cardNum;
    string name;
    int securityCode;

public:
    //constructor
    paymentMethod()
    {
        name = cardNum = "NULL";
        securityCode = 0;
    }

    paymentMethod(string num, string nam, int code)
    {
        name = nam;
        cardNum = num;
        securityCode = code;
    }

    //setters
    void setCardNum(string num)
    {
        cardNum = num;
    }
    void setName(string nam)
    {
        name = nam;
    }
    void setCode(int sc)
    {
        securityCode = sc;
    }

    //getters
    string getName()
    {
        return name;
    }
    string getCardNum()
    {
        return cardNum;
    }
    int getSecurityCode()
    {
        return securityCode;
    }
};

class Order
{
    int userID;
    int restID;
    double bill;
    double rating;
public:
    Order() {
        
    }
    void setrating(double b){
		rating =b;
	}
    double getrating(){
		return rating;
	}
    Order(int user,int rest,double billy) {
        userID=user;
        restID=rest;
        bill=billy;
    }
    
    void display()
    {
    	cout << endl;
    	cout << "restaturant id = " << restID << endl;
    	cout << "user id = " << userID << endl;
    	cout << "Total amountt= " << bill << endl;
    	
    	cout << endl;
    
	}

    //setters
    void setBill(double b) {
        bill=b;
    }
    void setRestID(int id) {
        restID=id;
    }
    void setUserID(int id) {
        userID=id;
    }
    
    //getters
    double getBill() const{
        return bill;
    }
    int getUserID() const{
        return userID;
    }
    int getRestID() const{
        return restID;
    }

    void writeToFile() {
        ofstream write("orders.csv",ios::app);
        if(!write) {
            cout<<"Order File error\n";
            return;
        }
        write<<userID<<','<<restID<<','<<bill << ',' <<rating <<endl;
        write.close();
    }

};

class User
{
    
   
    int numOfOrder;
	int norders;
	int userCount;
    int userID;
    string name;
    string contactNo;
    string address;
    string email;
    paymentMethod *card;
    string passcode;
    bool writeFlag;
	int MAXPAYMENT = 50000;
public:
	string getemail(){
		return email;
	}
	int getnorders(){
		return norders;
	}
	
	 Order* order;
    //constructor
    void setAddress(string s){
    	address = s;
	}
    User()
    {
    	norders = 0;
      numOfOrder=100;
        order=new Order[numOfOrder];
    
        name = "";
        contactNo = "";
        email = "";
        passcode = "";
        card = new paymentMethod[MAXPAYMENT];
        writeFlag=false;
        address="";
    }

	void readOrderFromFile() {
        ifstream read("CHAMAN.csv");
        if(!read) {
            cout<<"Orders file error\n";
            return;
        }
        string line;
        int integer;
        norders = 0;
        double d;

        getline(read,line,'\n');

        while (read.good())
        {
            getline(read,line,',');
            istringstream(line) >> integer;

            if(integer==userID) {
                order[norders].setUserID(integer);

                getline(read,line,',');
                istringstream(line) >> integer;
                order[norders].setRestID(integer);

                getline(read,line,',');
                istringstream(line) >> d;
                order[norders].setBill(d);
                double dou;
                 getline(read,line,'\n');
                istringstream(line) >> dou;
                order[norders].setrating(dou);
                
                norders++;
                //resize function if count > 5
                // here or after fetching all orders
            }
            else{
                getline(read,line,'\n');
            }
        }
		
		
        read.close();   
    }

    User(string name, string contact,int id, string address, string email, paymentMethod pm, string pass)
    {
        userID = id;
        this->name = name;
        writeFlag=false;
        passcode = pass; /// TODO: encrypt

        while (isContactPresent(contact) && !checkContactDigits(contact))
        { //check if contact is valid and doesnot repeat
            cout << "Enter correct contact number: ";
            cin >> contact;
        }
        this->contactNo = contact;

        int length = (sizeof(address) / sizeof(address[0]));
        this->address = address;
        this->email = email;
        card = new paymentMethod[MAXPAYMENT];
        card[0] = pm;
    }

    // getters
    int getID()
    {
        return userID;
    }
    string getContactNumber()
    {
        return contactNo;
    }
    string getAddresses()
    {
        return address;
    }
    string getName()
    {
        return name;
    }
    paymentMethod *getPaymentMethods()
    {
        return card;
    }
    string getPasscode()
    {
        return passcode; /// TODO: decrypt
    }

    // setters
    void setName(string name)
    {
        this->name = name;
    }
    void addAddress(string add)
    {
        address = add;
    }
    void setEmail(string em)
    {
        email = em;
    }
    void setPasscode(string pass)
    {
        passcode = pass; //encrypt
    }
    void set_get_contact(string c){
    	this->contactNo = c;
	}
    void setContact(string contact)
    {
        while (isContactPresent(contact) || !checkContactDigits(contact))
        { //check if contact is valid and doesnot repeat
            cout << "Enter correct contact number: ";
            cin >> contact;
        }
        this->contactNo = contact;
        fflush(stdin);
    }
    
    void setId(int id)
    {
        userID = id;
    }

	//ORDER
	//SEARCH
    void addPaymentMethod(paymentMethod pm)
    {
        int c = (sizeof(card) / sizeof(card[0]));
        if (c < MAXPAYMENT)
        {
            card[c] = pm;
        }
    }

    // checking contact validation
    bool checkContactDigits(string contact)
    {
        int count = contact.length();

        if ((count != 13 || count != 12) && contact[0] == '+')
        {
            return false;
        }
        else if (count != 11 && contact[0] == '0' && contact[1] != '0')
        {
            return false;
        }
        else if (count != 14 && contact[0] == '0' && contact[1] == '0')
        {
            return false;
        }
        for (int i = 0; i < count; i++)
        {
            if ((contact[i] < 48 && contact[i] > 57) && (contact[0] != 43 || contact[0] != 48))
            {
                return false;
            }
        }

        return true;
    }

    // checking if contact already exists
    bool isContactPresent(string contact)
    {

        ifstream read("users.csv");
        if(!read) {
            cout<<"users file error\n";
            return true;
        }
        string line;

        getline(read,line,'\n');
       while (read.good())
        {
            getline(read,line,',');
         		
		    if(line==contact) {
             
			    read.close();
                return true;
            }
            getline(read,line,'\n');
        }
        read.close();
        return false;
    }

    void writeUserToFile() {
        if(writeFlag) {
            cout<<"User already written\n";
            return;
        }
        ofstream write("users.csv",ios::app);
        if(!write) {
            cout<<"users file error\n";
            return;
        }

        write<<contactNo<<','<<passcode<<','<<userID<<','<<name<<','<<address<<':'<<email<<','<<card->getCardNum()<<','<<card->getName()<<','<<card->getSecurityCode()<<endl;
        write.close();
    }
};


class Offers
{
    /// TODO: after implementing deep learning
};


class HASHNODE{
	public:
		HASHNODE *next;
		Restaurant* data;	
	
	
	
	
	HASHNODE(){
		next = NULL;
		data= NULL;
	}
	HASHNODE(Restaurant *data){
		this->data = data;
		next = NULL;
	}	
};
class BNODE{
	public:
		int index;
		BNODE *LEFT;
		BNODE *RIGHT;
		Restaurant* data;	
	
	
	
	
	BNODE(){
	
		data= NULL;
		LEFT= NULL;
		RIGHT = NULL;
	}
	BNODE(Restaurant *data , int index){
		this->data = data;
		this->index = index;
		LEFT= NULL;
		RIGHT = NULL;
	}	
};


class BinaryTree{

	public:
	BNODE *root;
		void display(){
			print(root);
		}
				
		Restaurant * search(int id){
			return this->search_back(root , id);
		}
		
		Restaurant* search_back(BNODE *node , int id){
				
				if(node == NULL){
				return NULL;
			}
			if(id == node->data->getID()){
				
			
				return node->data;
			}
			return search_back(node->LEFT , id);
			
			
			return search_back(node->RIGHT,id);
				
		}
		
		void print(BNODE *node){
		
			if(node == NULL){
				return ;
			}
		
			print(node->LEFT);
			cout << node->data->getID() << node->data->getName() << " ";
			print(node->RIGHT);
				
		}
		
		
		BinaryTree(){
			root = NULL;
		}
		void add_node(BNODE *node , Restaurant *user , int index){
		if(root == NULL ){
			root = new BNODE(user , index);
			return;
		}
		if(user->getID() < node->data->getID()){
			if(node->LEFT != NULL){
				add_node(node->LEFT , user , index);
			}else{
				node->LEFT = new BNODE(user , index);
				return;
			}	
		}else{
			if(node->RIGHT != NULL){
				add_node(node->RIGHT , user , index);
			}else{
				node->RIGHT = new BNODE(user ,  index);
				return;
			}	
		}	
		
		
	
	
			
		
	}
	bool isempty(){
		if(root == NULL){
			return true;
		}
		return false;
	}	
		
	void insert(Restaurant *user , int index){
	
		add_node(root , user ,index);
		
		
	}	
	
};


class BHASHTABLE{
	
	BinaryTree *table;
	int n;
	public:
		BHASHTABLE(int n){
			this->n =n;
			table = new BinaryTree[n];
		}
		int hash_function(int d){
			return d%n;	
		}	
		void insert(Restaurant* num , int index){
			int place = this->hash_function(num->getID());
			table[place].insert(num , index);
		}
		
		
		void display(){
			for(int i = 0 ;i < n ; i++){
				table[i].display();
				cout << endl;
			}
			
		}
		int get_index(int id){
			return id%n;
		}
		
			Restaurant* search(int id){
			int index = get_index(id);
			BinaryTree L = table[index];
			Restaurant *node = L.search(id);
			cout << node->getName() <<" ";
			return node;
		}
	
};




class NEURALNETWORK{
	
	public:
	int restSize;	
	User *users;
	int nusers;
	BHASHTABLE *table;
	Restaurant *restaurants;
	double **MATRIX;
	double **weights;
		//[nuser][restaurantnumber]
	void create_a_neural_network_with_weights(){
		//creatae a neural network
		MATRIX = new double*[nusers];
		weights = new double*[restSize*restSize];
		for(int i = 0 ; i < nusers;i++){
			MATRIX[i] = new double[restSize];
		
		}
		for(int i = 0 ; i < nusers ; i++){
			for(int j = 0 ; j < restSize ; j++){
				MATRIX[i][j] = 0.0;
				
			}
			
		}
	
		for(int i = 0 ; i < restSize*restSize;i++){
			weights[i] = new double[restSize];
		}
		for(int i = 0 ; i < restSize*restSize ; i++){
			for(int j = 0 ; j < restSize ; j++){
				weights[i][j] = 0.0;
				
			}
			
		}
		
		
	}
	
	void print_neural_network(){
		for(int i = 0 ; i < nusers ; i++){
			for(int j = 0 ; j < restSize ; j++){
			
				cout << MATRIX[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	
	void fill_neural_network_from_file(){
		//import data from file
	//	for(int i = 0 ; i < )
	
		
	}
	
	int search_by_id(int Id){
		for(int i = 0 ; i < restSize ; i++){
			if(this->restaurants[i].getID() == Id){
				return i; 
			}
		}
		return 0;
	}
	//x = column1    y = colum2
	double calculate_correlation(int x , int y ,  int n){		//calculate similarity between suers
		double sumx = 0.0 , sumy = 0.0 , sumxy = 0.0;
		double sqsumx = 0.0 , sqsumy = 0.0;
		for(int i = 0 ; i < n ; i++){
			
			sumx += MATRIX[i][x];
			sumy += MATRIX[i][y];
			sumxy += (MATRIX[i][x]*MATRIX[i][y] );
			sqsumx += (MATRIX[i][x] * MATRIX[i][x]);
			sqsumy += (MATRIX[i][y]  *MATRIX[i][y] ); 
		}
		double coor = (double(n) * sumxy - sumx * sumy) / sqrt((n * sqsumx - sumx * sumx) * (n * sqsumy - sumy * sumy));		
		return coor;
	}
	
	void learn_relation(){
		ofstream of("leaningoutput.txt" , ios::out);
		if(!of){
			cout << "file doesnot exist";
			exit(0);
		}
		for(int i = 0 ; i < restSize ; i++){
			for(int j = 0 ; j < restSize ; j++){
				if(i  != j){
				weights[i][j] = this->calculate_correlation(i , j , nusers);
				
				if(!isnan(weights[i][j])){
					if(weights[i][j] > 0.0 && weights[i][j] != 1){
						of <<i << " " << j << "  "<< weights[i][j] << endl;		
						cout  <<i << " " << j << "  "<< weights[i][j] << endl;		
						
					}
					
					
				}else{
					
				}
				}
			}
		}
		
		of.close();
		
	}
	
	void print_coorelations(){
		for(int i =0 ; i <restSize;  i++){
			for(int j = 0 ; j < restSize ; j++){
				cout << weights[i][j] << " ";
			}
			cout << endl;
		}
		
	}
	
double find_coefficient(int *X, int *Y, int n){
   int sum_X = 0, sum_Y = 0, sum_XY = 0;
   int squareSum_X = 0, squareSum_Y = 0;
   for (int i = 0; i < n; i++){
      sum_X = sum_X + X[i];
      sum_Y = sum_Y + Y[i];
      sum_XY = sum_XY + X[i] * Y[i];
      squareSum_X = squareSum_X + X[i] * X[i];
      squareSum_Y = squareSum_Y + Y[i] * Y[i];
   }
   double corr = (double)(n * sum_XY - sum_X * sum_Y) / sqrt((n * squareSum_X - sum_X * sum_X) * (n * squareSum_Y - sum_Y * sum_Y));
   return corr;
}
	
	
	void fill_neural_network(){
		
		for(int i = 0 ; i < nusers ; i++ ){
			int numOrders = users[i].getnorders();
			cout << "USER" << i+1 << endl;
		for(int j = 0 ; j < numOrders ; j++){
			
			Order *order = &users[i].order[j];
			
			
			int pos = search_by_id(order->getRestID()) ;
			MATRIX[i][pos] = order->getrating();
		
		}
			
		}
		
	}
	
	int  *is = NULL;
	int *js = NULL;
	double *w = NULL;
	int total = 0;
	
	void compile_correlation_results(){
		
		double lel = 0.0;
		int l = 0;
		for(int i = 0 ; i < restSize ; i++){
			for(int j = 0 ; j < restSize ; j++){
			
				if(!isnan(weights[i][j])  ){
						cout << ++l;		
					is[total] = i;
					js[total] = j;
					w[total] = weights[i][j];
					total++;
				}
			}
			
		}
		
	}
	
	void see_results(){
		ofstream of("outputsorted.txt" , ios::out);
		for(int i = 0 ; i< total ; i++){
			of<< w[i] << endl;
			
		}
		of.close();
		cout << endl;
	}
	
	void sort_results(){
		cout << "total = " << total << endl;
		for(int i = 0 ; i < total-1 ; i++){
			for(int j = 0 ; j < total-1 ; j++){
				
				if(double(w[j]) < (double)w[j+1]){
					double temp = w[j];
					w[j] = w[j+1];
					w[j+1] = temp;	
					
				}
			}
		}
	}
	
	
	
	
	void fetch_ALL_users(){
	ifstream in;
	in.open("number_of_users.txt" , ios::in);
	int n ;
	in >> nusers;
	
	in.close();
		
		 ifstream read("users.csv" , ios::in);
    if (!read)
    {
        cout << "File error\n";
       return;
    }
		string line;
    
    
  	getline(read , line , '\n');
	  for(int i = 0 ; i < nusers ; i++)
    {
    	User *user = NULL;
	user = new User();
    //	getline(read, line, '\n');
    
    	getline(read , line , ',' );
    	 user->set_get_contact(line);
    	
    	getline(read, line, ',');
    	user->setPasscode(line);
    	
    	 getline(read, line, ',');
    int integer;
    istringstream(line) >> integer;

    user->setId(integer);

    getline(read, line, ',');
    user->setName(line);

    getline(read, line, ':');
    user->addAddress(line); //only doing for one address
	
    getline(read, line, ',');
    user->setEmail(line);

    paymentMethod pms;
    getline(read, line, ',');
    pms.setCardNum(line);

    getline(read, line, ',');
    pms.setName(line);

    getline(read, line, '\n');
   
	istringstream(line) >> integer;

	pms.setCode(integer);

    user->addPaymentMethod(pms);

   user->readOrderFromFile();
   
	users[i] = *user;
	cout << "bill = "<< user->order[0].getrating() << endl;
			
        
    }
	
	
	
	}
	
	NEURALNETWORK(){
		restSize  = 500;
		users = new User[restSize];
		table = new BHASHTABLE(10);
		restaurants = new Restaurant[restSize];
		is = new int[restSize*restSize];
		js = new int[restSize*restSize];
		w = new double[restSize*restSize];
		
	}
	
			void fetchResstaurants()
    {
        ifstream read("zomato2.csv");
   
        if (!read)
        {
            cout << "File error\n";
            return;
        }
        restaurants = new Restaurant[restSize];

        int i = 0;
        string line;
        int intbuffer;
        double dbuffer;
		char bin;
        getline(read, line, '\n');
		ofstream outputw;
		outputw.open("weights_rest.txt" , ios::out);
        while (read.good() && i < restSize)
        { //check
            getline(read, line, ',');
			istringstream(line) >> intbuffer;
			restaurants[i].setID(intbuffer);
			
			read >> bin;
			getline(read, line, ',');
            restaurants[i].setName(line);
            
			read>>bin;
			
			getline(read, line, ',');
		//	cout << line;
            restaurants[i].setcity(line);
          	
			  read >> bin;
			  read >> bin;  
            getline(read, line, ':');
			restaurants[i].setLocation(line);
            
            getline(read, line, ':');
            restaurants[i].setlocality(line);
			
			getline(read, line, ':');
            restaurants[i].setcusines(line);
			
			getline(read , line , ',');
			istringstream(line) >> intbuffer;
			restaurants[i].set_for_two(intbuffer);
			
			read >> bin;
					    
            getline(read , line , ':');
			istringstream(line) >> dbuffer;
			restaurants[i].setRatings(dbuffer);
			
			getline(read , line , ',');
			restaurants[i].set_comments(line);
			
			read >> bin;
			
			getline(read , line , '\n');
			istringstream(line) >> intbuffer;
			restaurants[i].setNumOfVotes(intbuffer);
			
		
			table->insert(&restaurants[i], i);
			//outputw <<  restaurants[i].getName() << "  " <<  restaurants[i].getNumOfvotes()<< endl;
			
			
							
            i++;
        	
		
		}
		outputw.close();
        read.close();
    }
	
	 void printRestaurants()
    {
        if (restaurants == NULL)
        {
            return;
        }
        for (int i = 0; i < restSize; i++) //150 hogae restaurants main se
        {
            cout << "Restaurant # " << i + 1 << endl;
            cout << "Name: " << restaurants[i].getName() << endl;
              cout << "Ratings: " << restaurants[i].getRatings() << endl;
            cout << "votes: " << restaurants[i].getNumOfvotes() << endl
                 << endl;
        }
    }
	
	void print_users(){
		for(int i = 0 ; i <nusers ; i++ ){
			cout << users[i].getID() << endl;
		}
	}	
	
};




class SYSTEM{
	string info[4][2]={
		{"Caption : " , "We deliver Quaity"},
		{"Location"  , "Burj khalifa , FLOOR # 211 , Florence Garden , Bangalore" },
		{"Email : " , "foodify@gmail.com"},
		{"Contact Number : " , "03322411712"},
		
		
	};

	Restaurant *recommended_restaurants;
	
	double *weighted_averages;
	int restSize;    
    
    
    
	
	void make_model_file(){
    	//put weighted averages in file;
    	//put sorted restaruarnts info in file;
    	
	}
	
	
	
	public:
			Restaurant *restaurants;
			int *similar;
	double *rw8;
	int countsimilar = 0;
	
	void getsimilarrestaurants(int i){
		countsimilar = 0;
		similar = new int[100];
		rw8 = new double[100];
		ifstream in;
		in.open("leaningoutput.txt" , ios::in);
		if(!in){
			cout << "model not trained to give recommendations" << endl;
			return;
			
		}
		int r , rto ;
		
		double similarity;
		while(in.good()){
			in >> r;
			in >> rto;
			in >> similarity;
			string l;
			getline(in , l , '\n' );
			if(r == i){
				cout << " "<< r <<" " <<rto << " "<<similarity << endl;
				this->similar[this->countsimilar++] = rto;
			}
			if(r > i){
				break;;
			}
		//	cout << " "<< r <<" " <<rto << " "<<similarity << endl;
		}
		
		in.close();
	}
	
	
		string* get_info(int i){
			return this->info[i];
		}
		
				
			void display_one(Restaurant &r , int num){
    			int largeststirng = 30;
    			int gaps = 50-r.getName().length();
    			int fixed_gaps = 10;
		cout << num << ") " <<r.getID() << "            " << r.getName() ;
		FRONTEND::getgaps(gaps+fixed_gaps);
		
		cout <<  r.getRatings() << "         " << r.getlocality() << endl;  
	}
	
	void print_restaurants_in_order(int soffset , int eoffset){
		cout << "\r";
		
		for(int i = soffset ; i <= eoffset ; i++){
			cout << endl;
			this->display_one(restaurants[i], i+1);
		}
		
	}
	
	void print_recommended_restaurants_in_order(int soffset , int eoffset){
		cout << "\r";
		
		for(int i = soffset ; i <= eoffset ; i++){
			cout << endl;
			this->display_one(recommended_restaurants[i], i+1);
		}
		
	}
	
		double calculate_mean(){
    		double sum = 0.0;
			for(int i = 0 ; i < restSize ; i++ ){
    			sum += restaurants[i].getRatings();
			}
			return sum/restSize;
			
		}
		double calculate_weighted_average(double avg_rating ,int tvoters ,double meanvalue, double minvotes   ){
			double res = ((avg_rating*(double)tvoters ) + (meanvalue*minvotes))/(((double)tvoters + minvotes));
			return res;
		}
		void sort(int *arr , int size){
			for(int i = 0 ; i < size; i++){
				for(int j = 0 ; j < size-1 ; j++){
					if(arr[j] > arr[j+1]){
						int t = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = t;
					}
				}
			}
		}
		int calculate_upper_percentile(double per){
			int *temp = new int[restSize];
			for(int i = 0 ; i < restSize ; i++){
				temp[i] = restaurants[i].getNumOfvotes();
			}	
			sort(temp , restSize);
			int pos = restSize*per;
			return temp[pos];			
		}
		
		Restaurant* sort_movies_on_weighted_average(Restaurant *rest){
			Restaurant *arr = new Restaurant[restSize];
			for(int i = 0 ; i < restSize ; i++){
				arr[i] = rest[i]; 
			}
			for(int i = 0 ; i < restSize ; i++){
				for(int j = 0 ; j < restSize-1 ; j++){
					if(this->weighted_averages[j] < this->weighted_averages[j+1]){
						swap(weighted_averages[j] ,weighted_averages[j+1]  );
						Restaurant temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					} 
				}
			}
			cout << endl;
//			for(int i = 0 ; i < restSize ; i++){
//				cout << arr[i].getName() << " " << this->weighted_averages[i] << endl;
//				
//			}
			this->recommended_restaurants = arr;
			return arr;
		}
		
    	void recommend_movies(){
    		double mean = this->calculate_mean();
    		double minvotes = this->calculate_upper_percentile(0.70);

			for(int i = 0 ; i <restSize ; i++ ){
    			
				double average_rating  = restaurants[i].getRatings();
    			int nvoters = restaurants[i].getNumOfvotes();
    			if(nvoters != 0 ){
    				this->weighted_averages[i] = this->calculate_weighted_average(average_rating , nvoters , mean , minvotes);	
				}else{
					this->weighted_averages[i] = 0.0;
				}
    				
				//make calculate mean function
    		//	cout <<  i+1<<"   " << average_rating << "   " <<nvoters << "   "  << this->weighted_averages[i] << endl;
    			
    		}
		   		this->sort_movies_on_weighted_average(this->restaurants);
				this->printRestaurants();
				
		}
			
			void put_recommendations_in_file(){
				ofstream out;
				out.open("output1.txt");
					out << "Restaurant ID" << ",";
					out << ":" << "Restaurant Name" << ",";
					out << ":" << "City"<< ",";
					out << ":" << "Location"<< ",";
					out << ":" << "Locality"<< ",";
					out << ":" << "Cuisines"<< ",";
					out << ":" << "avg_for_two"<< ",";
					out << ":" << "Aggregate Ratinng"<< ",";
					out << ":" << "Comments"<< ",";
					out << ":"	<< "Votes" << "\n";	
					
				for(int i = 0 ; i < restSize ; i++){
					out << this->recommended_restaurants[i].getID() << ",";
					out << ":" <<this->recommended_restaurants[i].getName() << ",";
					out << ":" << this->recommended_restaurants[i].getcity()<< ",";
					out << ":" << this->recommended_restaurants[i].getLocation();
					out << ":" << this->recommended_restaurants[i].getlocality()<< ",";
					out << ":" << this->recommended_restaurants[i].getcuisines();
					out << ":" << this->recommended_restaurants[i].get_for_two()<< ",";
					out << ":" << this->recommended_restaurants[i].getRatings()<< ",";
					out << ":" << this->recommended_restaurants[i].get_comment()<< ",";
					out << ":"	<<this->recommended_restaurants[i].getNumOfvotes() << "\n";	
				}
				
			}
	void get_recommendations_from_file(){
				        ifstream read("output1.txt" , ios::in);
   
        if (!read)
        {
            cout << "File error\n";
            return;
        }
        
        int i = 0;
        string line;
        int intbuffer;
        double dbuffer;
		char bin;
        getline(read, line, '\n');

        while (read.good() && i < restSize)
        { //check
            getline(read, line, ',');
			istringstream(line) >> intbuffer;
		recommended_restaurants[i].setID(intbuffer);
			
			read >> bin;
			getline(read, line, ',');
            recommended_restaurants[i].setName(line);
            
			read>>bin;
			
			getline(read, line, ',');
		//	cout << line;
           recommended_restaurants[i].setcity(line);
          	
			  read >> bin;
			  read >> bin;  
            getline(read, line, ':');
			recommended_restaurants[i].setLocation(line);
            
            getline(read, line, ':');
            recommended_restaurants[i].setlocality(line);
			
			getline(read, line, ':');
            recommended_restaurants[i].setcusines(line);
			
			getline(read , line , ',');
			istringstream(line) >> intbuffer;
			recommended_restaurants[i].set_for_two(intbuffer);
			
			read >> bin;
					    
            getline(read , line , ':');
			istringstream(line) >> dbuffer;
			recommended_restaurants[i].setRatings(dbuffer);
			
			getline(read , line , ',');
			recommended_restaurants[i].set_comments(line);
			
			read >> bin;
			
			getline(read , line , '\n');
			istringstream(line) >> intbuffer;
			recommended_restaurants[i].setNumOfVotes(intbuffer);
			
//			cout <<  recommended_restaurants[i].getName() << "  " << recommended_restaurants[i].getRatings() << "  " << recommended_restaurants[i].getNumOfvotes()<< endl;
			
			
							
            i++;
        	
		
		}
        read.close();

				
			}
		
    			void fetchResstaurants()
    {
        ifstream read("zomato2.csv");
   
        if (!read)
        {
            cout << "File error\n";
            return;
        }
        
	
        int i = 0;
        string line;
        int intbuffer;
        double dbuffer;
		char bin;
        getline(read, line, '\n');
		ofstream outputw;
		outputw.open("weights_rest.txt" , ios::out);
        while (read.good() && i < restSize)
        { //check
            getline(read, line, ',');
			istringstream(line) >> intbuffer;
			restaurants[i].setID(intbuffer);
			
			read >> bin;
			getline(read, line, ',');
            restaurants[i].setName(line);
            
			read>>bin;
			
			getline(read, line, ',');
		//	cout << line;
            restaurants[i].setcity(line);
          	
			  read >> bin;
			  read >> bin;  
            getline(read, line, ':');
			restaurants[i].setLocation(line);
            
            getline(read, line, ':');
            restaurants[i].setlocality(line);
			
			getline(read, line, ':');
            restaurants[i].setcusines(line);
			
			getline(read , line , ',');
			istringstream(line) >> intbuffer;
			restaurants[i].set_for_two(intbuffer);
			
			read >> bin;
					    
            getline(read , line , ':');
			istringstream(line) >> dbuffer;
			restaurants[i].setRatings(dbuffer);
			
			getline(read , line , ',');
			restaurants[i].set_comments(line);
			
			read >> bin;
			
			getline(read , line , '\n');
			istringstream(line) >> intbuffer;
			restaurants[i].setNumOfVotes(intbuffer);
			
			
		//	table->insert(&restaurants[i], i);
		//	cout << i << " " << restaurants[i].getName() << "  " <<  restaurants[i].getNumOfvotes()<< endl;
			
			
							
            i++;
        	
		
		}
		outputw.close();
        read.close();
    }
    	Restaurant& get_a_recommended_restaurant(int i){
    	 	if(i < restSize){
    	 		return this->recommended_restaurants[i];
			 }
		}
    	
    	Restaurant& get_a_simple_restaurant(int i){
    	 	if(i < restSize){
    	 		return this->restaurants[i];
			 }
		}
    	
	   void printRestaurants()
    {
        if (restaurants == NULL)
        {
            return;
        }
        for (int i = 0; i < restSize; i++) //150 hogae restaurants main se
        {
            cout << "Restaurant # " << i + 1 << endl;
            cout << "Name: " << restaurants[i].getName() << endl;
              cout << "Ratings: " << restaurants[i].getRatings() << endl;
            cout << "votes: " << restaurants[i].getNumOfvotes() << endl
                 << endl;
        }
    }
	SYSTEM(){
		restSize = 500;
		similar = new int[100];
		rw8 = new double[100];
		restaurants = new Restaurant[restSize];
		recommended_restaurants = new Restaurant[10000];
		this->weighted_averages = new double[restSize];
		

	}
};

class Foodify
{
    User *user;
    CART cart;
    FRONTEND frontend;
    
    
    
    Restaurant *restaurants;
    int restSize;
		User *readUserFile(string contact, string passcode)
{
    ifstream read("users.csv");
    if (!read)
    {
        cout << "File error\n";
        exit(0);
    }

    string line;
    User *user = NULL;

    getline(read, line, '\n');
    getline(read, line, ',');

    while (read.good() && line != contact)
    {
        getline(read, line, '\n');
        getline(read, line, ',');
    }

    if (line != contact)
    {
        cout << "User not found. Enter correct contact Number or Sign up.\n";
        read.close();
        return NULL;
    }

    user = new User();
   	user->set_get_contact(line);
	    
	getline(read, line, ',');
    if (line != passcode)
    {
        cout << "Incorrect passcode\n";
        read.close();
        return NULL;
    }

    user->setPasscode(passcode);

    getline(read, line, ',');
    int integer;
    istringstream(line) >> integer;

    user->setId(integer);

    getline(read, line, ',');
    user->setName(line);

    getline(read, line, ':');
    user->addAddress(line); //only doing for one address

    getline(read, line, ',');
    user->setEmail(line);

    paymentMethod pms;
    getline(read, line, ',');
    pms.setCardNum(line);

    getline(read, line, ',');
    pms.setName(line);

    getline(read, line, ',');
    //int integer;
	istringstream(line) >> integer;

	pms.setCode(integer);

    user->addPaymentMethod(pms);

    getline(read, line, '\n'); //didnt do for order history

    read.close();
    

    return user;
}

	
	void UserSignUp() {
    user = new User();
    
    string line;
    int i,id;

    ifstream file("number_of_users.txt");
    if(!file) {
        cout<<"number_of_users file error\n";
        return;
    }
    file>>id;
    id=10000+id;
    user->setId(id);
	fflush(stdin);
    cout<<"Enter contact number: \t\tNote: Incorrect contact number will fail SignUp!\n";
    getline(cin,line);
    user->setContact(line);

    cout<<"Enter Passcode: ";
    getline(cin,line);
    user->setPasscode(line);

    cout<<"Enter Your name: ";
    getline(cin,line);
    user->setName(line);

    cout<<"Enter your current address: ";
    getline(cin,line);
    user->addAddress(line);

    cout<<"Enter email: ";
    getline(cin,line);
    user->setEmail(line);

    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    paymentMethod p;
    cout<<"Payment details! \n";

    cout<<"Enter the Name: ";
    getline(cin,line);
    p.setName(line);

    cout<<"Enter card Number: ";
    getline(cin,line);
    p.setCardNum(line);

    cout<<"Enter pin Code: ";
    cin>>i;
    p.setCode(i);
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    user->addPaymentMethod(p);

    cout<<"~~~SignUp succesfull~~~\n";

    user->writeUserToFile();

    file.close();
    
    ofstream of;
    of.open("number_of_users.txt", ios::out);
	
    id=id-10000+1;
    of<<id;
    of.close();
}
	
	
	
	
	
	
	
	
	
int UserSignIn(string contact , string passcode)
{
    do
    {
        
        user = readUserFile(contact, passcode);

        if (user == NULL)
        {
            int x;
            cout << "1 for signUp\n2 for recovering password\nAny key to try again\nENTER: ";
            cin >> x;

            if (x == 1) {
                return 5;
                break;

            } else if (x==2) {
				ofstream recover ("Recovering_File.txt",ios::app);
				if(!recover) {
					cout<<"Under Maintainance..Please try later :)"<<endl<<endl;
					break;
				}

				cout<<endl<<"\t\t\t Details noted ! Our team will contact you shortly..Your co-operation will be highly apppreciated : )"<<endl<<endl;
                
				recover<<contact<<" "<<passcode<<endl;
				recover.close();

				return 0;
				break;
            }

        } else {
            cout << "~~~~~~Login succesfull~~~~~~\n"; //user details are in user
            //goes to user functionalities
			return 1;
        }

    } while (user == NULL);

}

public:
	
	User* getuser()
	{
		return user;
	}
	
	void empty_Cart(){
		cart.clear();
	}
	
	int SignIn(){
		
		
		string contact, passcode;
        cout << "Enter contact Number: ";
        cin >> contact;
        cout << "Enter Passcode: ";
        cin >> passcode;
		
		int ret=this->UserSignIn(contact , passcode);

		return ret;
		
	}	
		
	void SignUp(){
		
		this->UserSignUp();
	}
	void LogOut(){
		
		user = NULL;	
	}	
	Stack rstack;
		
	void get_recommended_restaurants(SYSTEM &s){
		
				int lower = 0;
		int plus = restSize * 0.01;
		int upper = plus;
		if(!rstack.isEmpty()){
			upper=  rstack.pop();
		}else{
			
			 upper = plus;
	}
	
		
		while(upper < restSize){
			s.print_recommended_restaurants_in_order(lower , upper);
			string w8;
			cout<<endl << "press M key to display more restaurants.... X to exit ....R to display similar restaurants ... Index to select " << endl;
			cin >> w8;
			if(w8 == "X" || w8 == "x"){
				return;
			}else{
				int num;
				istringstream(w8) >> num;
				
				if(num != 0){
					
				
				Restaurant t = s.get_a_recommended_restaurant(num-1);
				system("cls");
					//print menu
				bool finish = true;	
				while(finish){
				
				
				Dish d = t.menu_prompt();	
				cout <<  endl<<" \t\tPRESS C to display Cart | PRESS X to exot " << endl << endl;
				
				cout << d.getName()<<endl;
				
			
				
				
				if(	!(d.getName() == "NULL" ||d.getName() == "C" ||d.getName() == "c" ||d.getName() == "B" || d.getName() == "b"||d.getName() == "P" || d.getName() =="p") ){
					cart.enque(d);
					cout << cart.front().getName();
						
				} 
				
				if(d.getName() == "C" ||d.getName() == "c"  ){
					system("cls");
					cout << endl;
					cout << endl;
					cart.display();
					
					
					cout << endl;
					FRONTEND f;
					f.stop();
					
					//cart display
				}else if(d.getName() == "R" ||d.getName() == "r"  ){
					system("cls");
					s.getsimilarrestaurants(num-1);
					for(int i = 0 ; i < s.countsimilar ;i++){
						s.get_a_simple_restaurant(s.similar[i]).print_a_restaunt(i+1);
						
					}
					int x = frontend.input();
					if(x > 0 && x <= s.countsimilar){
						
					
					Restaurant t = s.get_a_simple_restaurant(s.similar[x-1]);
					bool finish1 = true;
					while(finish1){
						
						Dish d = t.menu_prompt();	
						cout <<  endl<<" \t\tPRESS C to display Cart | PRESS X to exot " << endl << endl;
							if(	!(d.getName() == "NULL" ||d.getName() == "C" ||d.getName() == "c" ||d.getName() == "B" || d.getName() == "b"||d.getName() == "P" || d.getName() =="p") ){
								cart.enque(d);
									cout << cart.front().getName();
						
							} 
						if(d.getName() == "C" ||d.getName() == "c"  ){
						system("cls");
						cout << endl;
						cout << endl;
						cart.display();
					
					
						cout << endl;
						FRONTEND f;
						f.stop();
					
					//cart display
				}else if(d.getName() == "B" ||d.getName() == "b"){
						system("cls");
					FRONTEND f;
					f.print_title();
					cout << endl;
					stack.push(upper);
					
					this->get_restaurants(s);
					return;
					finish1  = false;
				}
					}
				}
					//cart display
				}else if(d.getName() == "B" || d.getName() == "b"){
					
					system("cls");
					FRONTEND f;
					f.print_title();
					cout << endl;
					stack.push(upper);
					
					this->get_restaurants(s);
							// <--
					return;
					finish  = false;
				}else{
					cout << endl << ">>>>>>>>>>>>>>>>> wrong input provided <<<<<<<<<<<<<<<" << endl;
				}
				
						
				
				}
					
					
				}
				
			}
		
			lower = upper;
			upper += plus;
				
			
			
		}
		
	}
    Foodify()
    {
        user = NULL;
        restaurants = NULL;
        restSize = 1000;
    }
	void ABOUT_US(SYSTEM &s){
		
		for(int i = 0 ; i < 4 ; i++ ){
			 cout<<"\t\t\t  " << s.get_info(i)[0] << " " << s.get_info(i)[1] << endl;
		}
	}
	
	void set_CART_USER(){
		if(user != NULL){
			cart.setUser(user);
			return;
		}
		User *user = new User();
		string in;
		cout <<"enter name : ";
		cin >> in;
		user->setName(in);
		cout << endl;
		cout <<"enter A valid Contact Number : ";
		cin >> in;
		user->setContact(in);
		cout << endl;
		cout <<"enter A valid Address : ";
		cin >> in;
		user->setAddress(in);
		cout << endl;
		cart.setUser(user);
	}
	
	Stack stack;
	void get_restaurants(SYSTEM &s ){
			int lower = 0;
		int plus = restSize * 0.01;
		int upper = plus;
		if(!stack.isEmpty()){
			upper=  stack.pop();
		}else{
			
			 upper = plus;
	}
	
		
		while(upper < restSize){
			s.print_restaurants_in_order(lower , upper);
			string w8;
			cout<<endl << "press M key to display more restaurants.... X to exit ... Index to select " << endl;
			cin >> w8;
			if(w8 == "X" || w8 == "x"){
				return;
			}else{
				int num;
				istringstream(w8) >> num;
				
				if(num != 0){
					
				
				Restaurant t = s.get_a_simple_restaurant(num-1);
					system("cls");
				cout << endl <<"\t\t\t" <<t.getName() << endl;
			
					//print menu
				bool finish = true;	
				while(finish){
				
				
				Dish d = t.menu_prompt();	
				cout <<  endl<<" \t\tPRESS C to display Cart | PRESS X to exot " << endl << endl;
				
				cout << d.getName()<<endl;
				
				/////have to delet
				
				/////have to delet
				
				
				if(	!(d.getName() == "NULL" ||d.getName() == "C" ||d.getName() == "c" ||d.getName() == "B" || d.getName() == "b"||d.getName() == "P" || d.getName() =="p") ){
					cart.enque(d);
					
					cout << cart.front().getName();
						
				} 
				
				if(d.getName() == "C" ||d.getName() == "c"  ){
					system("cls");
					cout << endl;
					cout << endl;
					cout << "\t\t\t" << t.getName() << endl;
					
					cart.display();
					
					
					cout << endl;
					FRONTEND f;
					f.stop();
					
					//cart display
				}else if(d.getName() == "R" || d.getName() == "r"){
					system("cls");
					s.getsimilarrestaurants(num-1);
					for(int i = 0 ; i < s.countsimilar ;i++){
						s.get_a_simple_restaurant(s.similar[i]).print_a_restaunt(i+1);
						
					}
					int x = frontend.input();
					if(x >0 && x <= s.countsimilar ){
						
					
					Restaurant t = s.get_a_simple_restaurant(s.similar[x-1]);
						bool finish1 = true;	
						while(finish1){
				
							cout << endl << "\t\t       " << t.getName() << endl << endl;
						Dish d = t.menu_prompt();	
						cout <<  endl<<" \t\tPRESS C to display Cart | PRESS X to exot " << endl << endl;
							if(	!(d.getName() == "NULL" ||d.getName() == "C" ||d.getName() == "c" ||d.getName() == "B" || d.getName() == "b"||d.getName() == "P" || d.getName() =="p") ){
								cart.enque(d);
									cout << cart.front().getName();
						
							} 
				
							if(d.getName() == "C" ||d.getName() == "c"  ){
						system("cls");
						cout << endl;
						cout << endl;
						cart.display();
					
					
						cout << endl;
						FRONTEND f;
						f.stop();
					
					//cart display
				}else if(d.getName() == "B" || d.getName() == "b"){
						system("cls");
					FRONTEND f;
					f.print_title();
					cout << endl;
					stack.push(upper);
					
					this->get_restaurants(s);
					return;
					finish  = false;
				}
					}
					}//
				}else if(d.getName() == "B" || d.getName() == "b"){
					
					system("cls");
					FRONTEND f;
					f.print_title();
					cout << endl;
					stack.push(upper);
					
					this->get_restaurants(s);
					return;
					finish  = false;
				}else{
					cout << endl << ">>>>>>>>>>>>>>>>> wrong input provided <<<<<<<<<<<<<<<" << endl;
					continue;
				}
				
						
				
				}
					
					
				}
				
			}
		
			lower = upper;
			upper += plus;
				
			
			
		}
	}
	
	
    
};
void putreadUserFIle(User *users , int i){
	ofstream out;
	out.open("users.csv");
	out << "contact number" << "," << "passcode" << "," << "userID" << "," << "name" << "," << "addresses" << ":" << "email" << "," << "card number" << "," << "card name" << "," << "pin code" << endl;
	
	for(int j = 0 ; j < i ; j++){
		out << users[j].getContactNumber() << "," << users[j].getPasscode() << "," << users[j].getID() << "," << users[j].getName() << "," << users[j].getAddresses() << ":" << users[j].getemail() << "," << users[j].getPaymentMethods()->getCardNum() << "," << users[j].getPaymentMethods()->getName() << "," <<users[j].getPaymentMethods()->getSecurityCode() << endl;	
		 
	}

}


 User* getreadUserFile(User *u )
{
	User *users = new User[50];
    ifstream read("users.csv");
    if (!read)
    {
        cout << "File error\n";
        exit(0);
    }

    string line;
   	getline(read, line, '\n');
	int i = 0;
	while (read.good())
    {
	
//    	getline(read, line, '\n');
    	getline(read, line, ',');

   
     

  

   	
    users[i].set_get_contact(line);
    
	getline(read, line, ',');
  

    users[i].setPasscode(line);

    getline(read, line, ',');
    int integer;
    istringstream(line) >> integer;
	  
   users[i].setId(integer);
	
    getline(read, line, ',');
    users[i].setName(line);

    getline(read, line, ':');
    users[i].addAddress(line); //only doing for one address
 
    getline(read, line, ',');
    users[i].setEmail(line);
	 
    paymentMethod pms;
    getline(read, line, ',');
    pms.setCardNum(line);

    getline(read, line, ',');
    pms.setName(line);
 
    getline(read, line, '\n');
    //int integer;
	istringstream(line) >> integer;

	pms.setCode(integer);

    users[i].addPaymentMethod(pms);
    if(users[i].getID() == u->getID()){
    	users[i].setAddress(u->getAddresses());
    	users[i].set_get_contact(u->getContactNumber());
	}
    
	i++;
}
	
    getline(read, line, '\n'); //didnt do for order history
	

	putreadUserFIle(users , i-1);
	
	
    read.close();
   return users;
}


////////////////////////////////////
User *readUserFile(string contact, string passcode)
{
    ifstream read("users.csv");
    if (!read)
    {
        cout << "File error\n";
        exit(0);
    }

    string line;
    User *user = NULL;

    getline(read, line, '\n');
    getline(read, line, ',');

    while (read.good() && line != contact)
    {
        getline(read, line, '\n');
        getline(read, line, ',');
    }

    if (line != contact)
    {
        cout << "User not found. Enter correct contact Number or Sign up.\n";
        read.close();
        return NULL;
    }

    user = new User();
    user->setContact(line);
    
	getline(read, line, ',');
    if (line != passcode)
    {
        cout << "Incorrect passcode\n";
        read.close();
        return NULL;
    }

    user->setPasscode(passcode);

    getline(read, line, ',');
    int integer;
    istringstream(line) >> integer;

    user->setId(integer);

    getline(read, line, ',');
    user->setName(line);

    getline(read, line, ':');
    user->addAddress(line); //only doing for one address

    getline(read, line, ',');
    user->setEmail(line);

    paymentMethod pms;
    getline(read, line, ',');
    pms.setCardNum(line);

    getline(read, line, ',');
    pms.setName(line);

    getline(read, line, ',');
    //int integer;
	istringstream(line) >> integer;

	pms.setCode(integer);

    user->addPaymentMethod(pms);

    getline(read, line, '\n'); //didnt do for order history

    read.close();
    return user;
}


void initiate_deep_learning(){
	
	NEURALNETWORK network;   
	network.fetchResstaurants();
	
	cout << "done fetching data" <<endl;
//	system("cls");
	
	cout << "FETCHING USERS FROM DATABASE" <<endl;
	network.fetch_ALL_users();
	network.table->display();
	//cout << endl;
	cout << "createing our neural network" << endl;
	network.create_a_neural_network_with_weights();
	network.fill_neural_network();
	cout << "created neural network model" << endl;
	
	network.print_neural_network();
//	system("cls");
	cout << "starting learning for each item" << endl;
	
	network.learn_relation();
	cout << "created a model file learned from database" << endl;
	cout << "compiling resilt" << endl;
	//network.compile_correlation_results();
	cout << "process finished  learningoutput.txt file created in folder" << endl;
	//network.print_coorelations();
	SYSTEM sy;
	sy.fetchResstaurants();
	sy.recommend_movies();
	sy.put_recommendations_in_file();
	cout << "stored restaurants in weighted order" << endl;
	cout << "you may restart the program" << endl;
}


int main()
{
//	initiate_deep_learning();				//only when learning
	

	
//    
	cout <<endl<< "\n\n\t\t.   .\t\tFOODIFY :-)"<<endl;
	cout << "\n\t\t . .\t   We deliver quality :-)"<<endl;
	cout<<"\n\t\t  .  "<<endl;
	SYSTEM s;
	s.fetchResstaurants();

	
	Foodify food;
	system("cls");
	s.get_recommendations_from_file();
	FRONTEND intface;
	bool running = true;
	while(running){
		
		fflush(stdin);
	
	int choice = intface.front_screen();
	if(choice == 1 ){
		cout <<"\t\t\t SignIn "<<endl<<endl;
   		int aalo = food.SignIn();
   		User *u = NULL;
			if(aalo == 1){
				u = food.getuser();
			}
			else if(aalo == 5) {
				choice=2;
			}
		while(aalo == 1)
		{
			intface.print_title();
			cout << endl <<"WELCOME " << u->getName() << " !!!!!!" << endl;	
		//	intface.printmenu2();
			//int choi;
			int choi =  intface.printmenu2();
						
			if(choi == 1)
			{
				system("cls");
				string ad;
				fflush(stdin);
				getline(cin , ad , '\n');
				food.getuser()->setAddress(ad);
				getreadUserFile(food.getuser());
			//	Change Address" ,"ORDER HISTORY" , "Explore Restaurants" , "Change contact number" , "Register Complaint" 
			}
			else if(choi == 2)
			{
				system("cls");
				food.getuser()->readOrderFromFile();
				for(int i = 0; i<food.getuser()->getnorders();i++)
				{
					food.getuser()->order[i].display();
				}
			}
			else if(choi == 3)
			{
					food.empty_Cart();
					food.get_recommended_restaurants(s);
					system("cls");
						
					intface.stop();
			}
			else if(choi == 4)
			{
					food.empty_Cart();
					system("cls");
					food.get_restaurants(s);
					intface.stop();	
						}
			else if(choi == 5)
			{
				system("cls");
				string eds;
				cout << "Enter new number = ";
				fflush(stdin);
				getline(cin , eds , '\n');
				food.getuser()->setContact(eds);
				getreadUserFile(food.getuser());
			}
			else if(choi == 6)
			{
				system("cls");
				cout << "Enter your complain = " << endl;
				string s;
				cin >> s;
				cout << "your complain is registered" << endl;
			}
			else if(choi == 7)
			{
				food.LogOut();
				aalo = 0;
				// recommended
			}
		
			
			//	running = false; 
			intface.stop();
			system("cls");
		}
		
   	}if(choice == 2){
		//sign up

		cout<<endl<<endl<<"\t\t\t SignUp"<<endl<<endl;
		
		food.SignUp();
		int aalo = 1;
		User* u = food.getuser();
		system("cls");
		while(aalo)
		{
			intface.print_title();
			cout << endl <<"WELCOME " << u->getName() << "!!!!!!" << endl;
		//	intface.printmenu2();
			//int choi;
			int choi =  intface.printmenu2();
						
			if(choi == 1)
			{
				system("cls");
				string ad;
					fflush(stdin);
				getline(cin , ad , '\n');
				food.getuser()->setAddress(ad);
				getreadUserFile(food.getuser());
			//	Change Address" ,"ORDER HISTORY" , "Explore Restaurants" , "Change contact number" , "Register Complaint" 
			}
			else if(choi == 2)
			{
				system("cls");
				food.getuser()->readOrderFromFile();
				for(int i = 0; i<food.getuser()->getnorders();i++)
				{
					food.getuser()->order[i].display();
				}
			}
			else if(choi == 3)
			{
					food.empty_Cart();
					food.get_recommended_restaurants(s);
					system("cls");
						
					intface.stop();
			}
			else if(choi == 4)
			{
					food.empty_Cart();
					system("cls");
					food.get_restaurants(s);
					intface.stop();	
						}
			else if(choi == 5)
			{
				system("cls");
				string eds;
				cout << "Enter new number = ";
				fflush(stdin);
				getline(cin , eds , '\n');
				food.getuser()->setContact(eds);
				getreadUserFile(food.getuser());
			}
			else if(choi == 6)
			{
				system("cls");
				cout << "Enter your complain = " << endl;
				string s;
				cin >> s;
				cout << "your complain is registered" << endl;
			}
			else if(choi == 7)
			{
				food.LogOut();
				aalo = 0;
				// recommended
			}
		
				intface.stop();
			system("cls");
			//	running = false; 
		}
	
		
		
	}else if(choice == 3){
		//recommended restaurnats;
	food.empty_Cart();		
	//	food.set_CART_USER();
		food.get_recommended_restaurants(s);
		system("cls");
		
		intface.stop();
	}else if(choice == 4){

		food.empty_Cart();

		system("cls");
		food.get_restaurants(s);
		intface.stop();
	}else if(choice == 5){
		system("cls");
		cout << endl;
		intface.print_title();
		
		food.ABOUT_US(s);
		intface.stop();		
	}else if(choice == 6){
		running = false;	
		intface.stop();
	
	}
	system("cls");
    }
    
    	cout << "\n\n\t\tthanking for choosing foodify... We exist to serve for complaint call 111=222=333" << endl << endl;
		cout << "\tDEVELOPED BY ";
		string credits[4] = {"MUHAMMAD ASAD" , "HASSAN ATTARI" , "HAMZA USMANI" , "ESPECIAL THANKS TO YOUTUBE AND GOOGLE FOR THEIR SUPPORT"};
		for(int i = 0 ; i < 4;i++){
			cout << endl <<"\t\t\t\t"<<credits[i] << endl << endl << endl;
		}
	return 0;
}
