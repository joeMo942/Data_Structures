/// transportation services app 



#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

 

static int company_ticket_counter = 0;
static int student_ticket_counter = 0;

template <class T> class linked_list;
class Stack;
class Queue;
template <class T> class Hash;
class pickup_point;
class Line;
class Person;
class Student;
class driver;
class company;
class Student_Table;
class company_table;
class driver_table;
class car;
class ticket;
class company_ticket;
class student_ticket;


enum type { high_s, super_jet, mini_bus };




// ---------- TOOLS HEADER ---------- //

// ---------- LINKED LIST HEADER ---------- //
template <class T> class linked_list
{
private:
    struct node
    {
        T data;
        node* next;
    };
    typedef node* link;
    link head;
    link tail;
    link current;
    int num_of_ele;
public:

    linked_list();
    bool Push_Front(T x);
    bool Push_Back(T x);
    void Push_between(link pre, link new_node);
    bool sort_insert(int x);
    bool isEmpty();
    void makeEmpty();
    //linked_list<T> copy();
    void print();
    bool linear_search(T x);
    int size();
    bool is_contained(T x);
    void add_if_not_contained(T x);
    void deleteNode(T key);
    //ex
    bool Return_Data(T* data);
    bool go_head(T* data);
    bool Next(T* data);

};

// ---------- PICKUP POINT HEADER ---------- //
class pickup_point
{
private:
    string pickup_point_Name;
    int count_go = 0;
    int count_come = 0;
public:
    pickup_point();
    pickup_point(string Name);

    // ---- set ---- //
    void set_pickup_point_Name(string Name);
    void set_count_go();
    void set_count_come();
    void set_count_both();
    // ---- get ---- //
    string get_pickup_point_Name();
    int  get_count_go();
    int  get_count_come();
    // ---- Other---- //
    void print_pikup_poin();


};

// ---------- Stack ---------- //
class Stack {
private:
    struct Stack_Node {
        pickup_point data;
        Stack_Node* next;

        Stack_Node(pickup_point p)
        {
            this->data = p;
            this->next = NULL;
        }
    };
    typedef Stack_Node* link;
    link top;

public:
    Stack() { top = NULL; }

    void push(pickup_point data)
    {
        link temp = new Stack_Node(data);
        if (!temp) {
            std::cout << "\nStack Overflow";
            exit(1);
        }
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    std::string peek()
    {
        if (!isEmpty())
            return top->data.get_pickup_point_Name();
        else
            exit(1);
    }

    void pop()
    {
        link temp;

        if (top == NULL) {
            std::cout << "\nStack Underflow" << std::endl;
            exit(1);
        }
        else {
            temp = top;
            top = top->next;
            free(temp);
        }
    }

    void display()
    {
        link temp;
        if (top == NULL) {
            std::cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {
                std::cout << temp->data.get_pickup_point_Name();
                temp = temp->next;
                if (temp != NULL)
                    std::cout << " -> ";
            }
        }
    }
};

// ---------- Queue ---------- //
class Queue {
private:
    struct QNode {
        pickup_point data;
        QNode* next;
        QNode(pickup_point d)
        {
            data = d;
            next = NULL;
        }
    };
    typedef QNode* link;
    link front;
    link rear;
    int num_of_ele;
public:
    Queue()
    {
        front = rear = NULL;
    }

    void enQueue(pickup_point x)
    {
        link temp = new QNode(x);

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
        num_of_ele++;
    }

    void deQueue()
    {
        if (front == NULL)
            return;

        link temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete (temp);
        num_of_ele++;
    }
};

// ---------- LINE HEADER ---------- //
class Line
{
private:
    string Line_Name;
    string car_type = "null";
    linked_list<pickup_point>  pickup_point_Names;
    int count_go = 0;
    int count_come = 0;
    int count_both = 0;
    int count = 0;
    double bus_cost;
    Queue Q;
    Stack S;
public:
    Line();
    Line(string Name);
    // ---- set ---- //
    void set_Line_Name(string Name);
    void set_count();
    void set_count_go();
    void set_count_come();
    void set_count_both();
    void set_car_type(string type);
    void set_bus_cost(double cost);
    void set_reserved_go(Queue q);
    void set_reserved_come(Stack s);
    // ---- get ---- //
    string get_Line_point_Name();
    int  get_count();
    int  get_count_go();
    int  get_count_come();
    int  get_count_both();
    double get_bus_cost();
    Queue  get_reserved_go();
    Stack get_reserved_come();
    string get_carType();
    // ---- Other---- //
    void add_pickup_point(pickup_point point);
    void delete_pickup_point(pickup_point point);
    void print_line();
    void Display_pickup_point();
    pickup_point select_pickup_point();
    linked_list<pickup_point> get_linkedlist_pickup_point();

};

// ---------- CAR HEADER ---------- //
class car
{
private:
    type car_type;//		High-S = 0		Super-Jet = 1		Mini-Bus = 2
    string car_plate;
    int car_cost;
    int car_capacity;
    int car_status;//		Empty = 0		Used = 1
    Line car_Line;
    string car_driver;

public:
    car();
    car(type name, string plate, int cost, int capacity);
    // ---- set ---- //
    void set_status(int status);
    void set_Line(Line line);
    void set_driver(string driver);
    // ---- get ---- //
    int get_status();
    Line get_Line();
    string get_driver();
    type get_type();
    string get_car_plate();
    // ---- Other---- //

};

// ---------- COMPANY HEADER ---------- //
class company
{
private:
    string user_name;
    string name;
    string pass;
    string email;
    string phone_number;
    string address;
    linked_list <Line> lines;
    int profit;

public:
    company();
    // ---- set ---- //
    void set_name(string name);
    void set_user_name(string uname);
    void set_pass(string pass);
    void set_email(string mail);
    void set_address(string address);
    void set_lines(Line l);
    int set_phone_number(string num);
    void set_profit(int profit);
    // ---- get ---- //
    string get_name();
    string get_user_name();
    string get_email();
    string get_pass();
    string get_address();
    int get_profit();
    linked_list<Line> get_lines();
    // ---- Other---- //
    void delet_line(Line l);
    void view_lines();
    void print_company();
    //new//
    void view_company_lines();
    Line select_company_line();
    //new//



};

// ---------- TICKET HEADER ---------- //
class ticket
{
private:
    int ticket_id;
    car ticket_car;
    int ticket_price;
    Line ticket_line;
    int ticket_statues; //0= zahab w 3awda   1= zahab   2= 3awda
    company ticket_company;
public:
    ticket();
    //ticket(car car,  string company, Line line);

    // ---- set ---- //
    void set_car(car car);
    void set_price(int company_price);
    void set_line(Line line);
    void set_statues(int chioce);
    void set_company(company company);
    // ---- get ---- //
    int get_id();
    car get_car();
    int get_price();
    Line get_line();
    int get_statues();
    company get_company();
    // ---- Other---- //
};


// ---------- PERSON HEADER ---------- //
class Person
{
private:
    string name;
    string age; //If 0 is unknown.
    string national_id;
    string gender;
    string password;
    string phone_number;
public:
    Person();
    Person(string Name, string Age, string National_id, string Gender, string Password, string phone_number);
    // ---- set ---- //
    int set_person(string Name, string Age, string National_id, string Gender, string Password, string phone_number);
    void set_name(string name);
    int set_age(string age);
    int  set_national_id(string nationalID);
    void set_gender(string gender);
    void set_password(string password);
    int set_phone_number(string phone_number);
    // ---- get ---- //
    string get_name() const;
    string get_age() const;
    string get_national_id() const;
    string get_gender() const;
    string get_password() const;
    string get_phone_number() const;
    // ---- Other---- //
    //void print() const;
};

// ---------- STUDENT HEADER ---------- //
class Student :public Person
{

private:
    int id;
    string address;
    string mail;
    Line student_line;
    pickup_point student_pickup_point;
    ticket student_ticket;
    //string name;
    //double GPA;
    //linked_list <> p1;

public:
    Student();
    Student(int id, string Address, string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail);
    // ---- set ---- //
    void set_student(int id, string Address, string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail);
    void set_id(int id);
    int set_mail(string mail);
    void set_address(string address);
    void set_student_line(Line l);
    void set_student_pickup_point(pickup_point p);
    // ---- get ---- //
    int get_id();
    string get_address();
    string get_mail();
    Line get_student_line();
    pickup_point get_student_pickup_point();
    // ---- Other---- //
    void class_print_Student();
    //new//
    void print_line_pickupPoint();
    pickup_point get_student_pickupPoint();
    //new//
    // string getName();
    // double getGPA();
   //  void print();

};

// ---------- DRIVER HEADER ---------- //
class driver :public Person
{
private:
    string Campany_name;
    string Mail;
public:
    driver();
    driver(string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail);
    // ---- set ---- //
    void set_driver(string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail);
    void set_camany_name(string campany_name);
    void set_mail(string mail);
    // ---- get ---- //
    string get_camany_name();
    string get_mail();
    // ---- Other---- //
   // void class_print_driver();

};


// ---------- HASHING HEADER ---------- //
template <class T> class Hash
{
protected:
    linked_list<T>* Table;
    int Bucket;
    int Hash_Function(int x)
    {
        return (x % 13);
    }
public:
    Hash();
    Hash(int Bucket);
    void Insert_Item(int key, T data);
    void Delete_Item(int key, T data);
    //void Display_Hash();

};

// ---------- TABLE HEADER ---------- //

// ---------- Student HEADER ---------- //
class Student_Table :public Hash<Student>
{
private:
    Student s1;
public:
    Student_Table();
    Student_Table(int Bucket);
    Student Search_Item(int key);
    void Student_print();
    void Table_Student_save();
    void Table_Student_load();
};

// ---------- company HEADER ---------- //
class company_table :public Hash<company>
{

private:
    company c1;

public:
    int convert_to_key(string mail);
    company_table();
    company_table(int Bucket);
    void all_companys_print();
    company Search_Item(string mail);

};

// ---------- driver HEADER ---------- //
class driver_table :public Hash<driver>
{

private:
    driver d1;

public:
    int convert_to_key(string mail);
    driver_table();
    driver_table(int Bucket);
    driver Search_Item(string mail);
};

// ---------- COMAPNY TICKET HEADER ---------- //
class company_ticket
{
private:
    int company_ticket_id;
    car company_ticket_car;
    string company_ticket_price;
    Line company_ticket_line;

public:
    company_ticket();
    company_ticket(car t_car, string price, Line t_line);
    void set_company_ticket_car(car car);
    void set_company_ticket_price(string price);
    void set_company_ticket_line(Line t_line);
    int get_company_ticket_id();
    car get_company_ticket_car();
    string get_company_ticket_price();
    Line get_company_ticket_line();
};

// ---------- STUDENT TICKET HEADER ---------- //
class student_ticket
{
private:
    int student_ticket_id;
    string student_ticket_date;
    pickup_point student_ticket_pickup_point;
    Line student_ticket_line;
    company student_ticket_company;

public:
    student_ticket();
    student_ticket(int id, string date, pickup_point t_pickup, Line t_line, company t_company);
    void set_student_ticket_id(int id);
    void set_student_ticket_date(string date);
    void set_student_ticket_pickup_point(pickup_point point);
    void set_student_ticket_line(Line t_line);
    void set_student_ticket_company(company t_company);
    int get_student_ticket_id();
    string get_student_ticket_date();
    pickup_point get_student_ticket_pickup_point();
    Line get_student_ticket_line();
    company get_student_ticket_company();
};




Student_Table s_t(13);
company_table c_t(13);
driver_table d_t(13);
linked_list<Line> ALL_LINES;
linked_list<string> ALL_COMPANYS;

// ---------- university menue ---------- //
void view();
void add_company();
void view_companys();
void view_all_students();
void edit_student();
void add_line();
void add_pickup_point_interface();
void view_all_lines();
Line select_line();

void booking_ticket();

company select_company();



// ---------- campany menue ---------- //

//buses define
#define high_s 14
#define costar 21
#define bus 52
void add_driver(string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail);
void delete_driver(string mail);
void edit_driver(string mail);
void view_driver(string mail);
void view_driver(string mail);




// ---------- bus menue ---------- //

//profit
#define high_s_cost 500
#define costar_cost 1000
#define bus_cost 1000
string max_bus(int passengers_count, double* cost);
string bus_plus(int passengers_count, double* cost);
void add_bus();
void create_line_go();
void create_line_come();
void view_line_go(Line l);
void view_line_come(Line l);
void profit();




void signup_student();
int login_page();
void signup_company();
int login_company();


/////// all menus///////

void university_menue();
void student_menue();
void company_menue();
void driver_menue();



int main()
{
    Student s;

    Line l;

    while (true)
    {

        
        int x;
        cout << "1-add line\n2-sign up student\n3-view student\n4-book ticket\n5-creat line go\n6-view line go\n7-exit\n";
        cin >> x;

        switch (x)
        {
        case 1:
        {
            add_line();
            break;
        }
        case 2:
        {
             l=select_line();
            cout << l.get_Line_point_Name();
            l.set_Line_Name("yousef");
            cout << l.get_Line_point_Name();
            break;
        }
        case 3:
        {
            l=select_line();
            l.Display_pickup_point();
            break;
        }
        case 4:
        {
            add_pickup_point_interface();
        }
        case 5:
        {
            create_line_go();
            break;
        }
        case 6:
        {
            s = s_t.Search_Item(221101573);

            view_line_go(s.get_student_line());

            break;
        }
        case 7:
        {
            return 0;
        }
        default:
            break;
        }
    }




}




//############# LINKED LIST IMPLEMENTATION #############//
template<class T> linked_list<T>::linked_list()
{
    head = 0;
    //head->next = 0;
    tail = 0;
    current = 0;
    num_of_ele = 0;
}
template<class T> bool linked_list<T>::Push_Front(T x)
{
    link new_node = new node;
    if (new_node == 0)
    {
        return false;
    }
    else
    {
        new_node->data = x;
        if (num_of_ele == 0)
        {
            current = new_node;
            head = current;
            tail = current;
            current->next = NULL;
        }
        else
        {
            current = new_node;
            current->next = head;
            head = current;
        }
        num_of_ele++;
        return true;
    }
}
template<class T> bool linked_list<T>::Push_Back(T x)
{
    link new_node = new node;
    if (new_node == 0)
    {
        return false;
    }
    else
    {
        new_node->data = x;
        if (num_of_ele == 0)
        {
            current = new_node;
            head = current;
            tail = current;
            current->next = NULL;
        }
        else
        {
            current = new_node;
            tail->next = current;
            current->next = NULL;
            tail = current;
        }
        num_of_ele++;
        return true;
    }
}
template<class T> void linked_list<T>::Push_between(link pre, link new_node)
{
    new_node->next = pre->next;
    pre->next = new_node;
    num_of_ele++;
}
template<class T> bool linked_list<T>::sort_insert(int x)
{
    link new_node = new node;
    new_node->data = x;
    if (new_node == 0)
    {
        return false;
    }
    else
    {
        current = head;
        if (num_of_ele == 0 || current->data >= new_node->data)
        {
            Push_Front(new_node->data);
        }
        else if (tail->data <= new_node->data)
        {
            Push_Back(new_node->data);
        }
        else
        {
            while (current->next->data <= new_node->data && current->next != 0)
            {
                current = current->next;
            }
            Push_between(current, new_node);
        }
        return true;
    }
}
template<class T> bool linked_list<T>::isEmpty()
{
    if (head == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<class T> void linked_list<T>::makeEmpty()
{
    current = head;
    while (current != 0)
    {
        head = current->next;
        delete(current);
        current = head;
        num_of_ele--;
    }
}
/*
template<class T>
linked_list<T> linked_list<T>::copy()
{
    linked_list<T> new_list;
    current = head;
    while (current != 0)
    {
        new_list.Push_Back(current->data);
        current = current->next;
    }
    return new_list;
}
*/
template<class T> void linked_list<T>::print()
{

    current = head;
    int i = 1;
    while (current != NULL)
    {
        cout << "ele num: " << i << " = " << current->data << endl;
        current = current->next;
        i++;
    }

}
template<class T> bool linked_list<T>::linear_search(T x)
{
    current = head;
    while (current != 0)
    {
        if (current->data == x)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
template<class T> int linked_list<T>::size()
{
    int counter = 0;
    current = head;
    while (current != 0)
    {
        current = current->next;
        counter++;
    }
    return counter;
}
template<class T> bool linked_list<T>::is_contained(T x)
{
    current = head;
    while (current != 0)
    {
        if (current->data == x)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
template<class T> void linked_list<T>::add_if_not_contained(T x)
{
    //add a value x if it is not already contained in the linked list.
    if (is_contained(x) == 0)
    {
        Push_Back(x);
    }

}
template<class T> void linked_list<T>::deleteNode(T key)
{

    link temp = head;
    link prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        delete temp;
        return;
    }
    else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        delete temp;
    }
}
template<class T> bool linked_list<T>::Return_Data(T* data)
{
    //current = head;
    if (head == 0)
    {
        return 0;
    }
    else
    {
        *data = current->data;
        return 1;
    }
}
template<class T> bool linked_list<T>::go_head(T* data)
{
    current = head;
    if (head == 0)
    {
        return 0;
    }
    else
    {
        *data = current->data;
        return 1;

    }

}
template<class T> bool linked_list<T>::Next(T* data)
{

    if (head->next == 0 || head == 0)
    {
        return 0;
    }
    else if (current->next == 0)
    {
        return 0;


    }
    else
    {
        current = current->next;
        *data = current->data;
        return 1;

    }

}


// ############# HASHING IMPLEMENTATION ############# //
template<class T> Hash<T>::Hash()
{
}
template<class T> Hash<T>::Hash(int Bucket)
{
    this->Bucket = Bucket;
    Table = new linked_list<T>[Bucket];
}
template<class T> void Hash<T>::Insert_Item(int key, T data)
{
    int index = Hash_Function(key);
    Table[index].Push_Back(data);
}
template<class T> void Hash<T>::Delete_Item(int key, T data)
{
    int index = Hash_Function(key);
    Table[index].deleteNode(data);
}
//template<class T> void Hash<T>::Display_Hash()
//{
//    for (int i = 0; i < Bucket; i++)
//    {
//        cout << "Bucket Number : " << i << endl;
//        Table[i].print();
//        cout << endl;
//    }
//}


// ############# PICKUP POINT IMPLEMENTATION ############# // 

pickup_point::pickup_point()
{
    count_come = 0;
    count_go = 0;
}
pickup_point::pickup_point(string Name)
{
    set_pickup_point_Name(Name);
}
// ---- set ---- //
void pickup_point::set_pickup_point_Name(string Name)
{
    pickup_point_Name = Name;
}
void pickup_point::set_count_go()
{
    count_go++;

}
void pickup_point::set_count_come()
{
    count_come++;

}
void pickup_point::set_count_both()
{
    count_go++;
    count_come++;
}
// ---- get ---- //
string pickup_point::get_pickup_point_Name()
{
    return pickup_point_Name;
}
int  pickup_point::get_count_go()
{
    return count_go;
}
int pickup_point::get_count_come()
{
    return count_come;
}
// ---- Other ---- //
void pickup_point::print_pikup_poin()
{
    cout << pickup_point_Name << endl;
}


// ############# LINE IMPLEMENTATION ############# // 
Line::Line()
{
    count_go = 0;
    count_come = 0;
    count_both = 0;

}
Line::Line(string Name)
{
    set_Line_Name(Name);
}
// ---- set ---- //
void Line::set_Line_Name(string Name)
{
    Line_Name = Name;
}
void Line::set_count()
{

    count++;

}
void Line::set_count_go()
{
    count_go++;

}
void Line::set_count_come()
{
    count_come++;

}
void Line::set_count_both()
{
    count_both++;
}
void Line::set_car_type(string type)
{
    car_type = type;
}
void Line::set_bus_cost(double cost)
{
    //bus_cost = cost;
}
void Line::set_reserved_go(Queue q)
{
    Q = q;

}
void Line::set_reserved_come(Stack s)
{
    S = s;
}
// ---- get ---- //
string Line::get_Line_point_Name()
{
    return Line_Name;
}
int Line::get_count() {

    return count;

}
int Line::get_count_go()
{
    return count_go;

}
int Line::get_count_come()
{
    return count_come;
}
int Line::get_count_both()
{
    return count_both;
}
double Line::get_bus_cost()
{
    return bus_cost;
}
Queue  Line::get_reserved_go()
{
    return Q;
}
Stack  Line::get_reserved_come()
{
    return S;
}
string Line::get_carType() {
    return car_type;
}
// ---- Other---- //
void Line::add_pickup_point(pickup_point point)
{
    pickup_point_Names.Push_Back(point);
}
void Line::delete_pickup_point(pickup_point point)
{
    //pickup_point_Names.deleteNode(point);
}
void Line::print_line()
{
    cout << Line_Name << endl;
}
void Line::Display_pickup_point()
{
    pickup_point p;
    pickup_point_Names.go_head(&p);
    while (true)
    {
        pickup_point_Names.Return_Data(&p);
        p.print_pikup_poin();
        if (!pickup_point_Names.Next(&p))
        {
            return;
        }
    }
}
pickup_point Line::select_pickup_point()
{
    int counter = 0;
    int x;

    pickup_point p;

    cout << "chosse the pickupoint :";
    cin >> x;
    Display_pickup_point();


    pickup_point_Names.go_head(&p);

    for (int i = 1; i < x; i++)
    {
        pickup_point_Names.Next(&p);
    }

    return p;
}
linked_list<pickup_point> Line::get_linkedlist_pickup_point()
{
    return pickup_point_Names;
}



// ############# PERSON IMPLEMENTATION ############# // 
Person::Person()
{
    name = "";
    gender = "";
    password = "";
   // set_age("");
    //set_national_id("");
    //set_phone_number("");
}
Person::Person(string Name, string Age, string National_id, string Gender, string Password, string phone_number)
{
    name = Name;
    gender = Gender;
    password = Password;

    set_age(Age);
    set_national_id(National_id);
    set_phone_number(phone_number);
}
// ---- set ---- //
int Person::set_person(string Name, string Age, string National_id, string Gender, string Password, string phone_number)
{
    name = Name;
    gender = Gender;
    password = Password;

    set_age(Age);
    set_national_id(National_id);
    set_phone_number(phone_number);
    return 1;
}
void Person::set_name(string name)
{
    this->name = name;
}
int Person::set_age(string age)
{
    if (age.length() > 17 && age.length() <= 100)
    {
        this->age = age;
        return 1;
    }
    else {
        //cout << "Invalid Age " << endl;
        return 0;
    }
}
int Person::set_national_id(string National_id)
{
    if (National_id.length() == 14) {
        this->national_id = National_id;
        return 1;
    }
    else {
        cout << "Invalid National ID";
        return 0;
    }
}
void Person::set_gender(string gender)
{
    this->gender = gender;
}
void Person::set_password(string password)
{
    this->password = password;
}
int Person::set_phone_number(string phone_number)
{

    string str;

    //str = phone_number.resize(2);
    str = phone_number.substr(0, 3);
    if (str == "010" || str == "011" || str == "012" || str == "015")
    {
        this->phone_number = phone_number;
        return 1;
    }
    else {
        cout << "Invalid phone number";
        return 0;
    }

}
// ---- get ---- //
string Person::get_name() const
{
    return name;
}
string Person::get_age() const
{
    return age;
}
string Person::get_national_id() const
{
    return national_id;
}
string Person::get_gender() const
{
    return gender;
}
string Person::get_password() const
{
    return password;
}
string Person::get_phone_number() const
{
    return phone_number;
}
// ---- Other ---- //
/*void Person::print() const
{
    cout << "Name : " << name << endl;
    cout << "Age : " << age << endl;
    cout << "National ID : " << national_id << endl;
}*/



// ############# STUDENT IMPLEMENTATION ############# // 

Student::Student()
{

}
Student::Student(int id, string Address, string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail)
{
    this->id = id;
    address = Address;

    set_mail(mail);

    Person::set_name(Name);
    Person::set_age(Age);
    Person::set_national_id(National_id);
    Person::set_gender(Gender);
    Person::set_password(Password);
    Person::set_phone_number(phone_number);




}
// ---- set ---- //
void Student::set_student(int id, string Address, string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail)
{
    this->id = id;
    address = Address;

    set_mail(mail);


    Person::set_name(Name);
    Person::set_age(Age);
    Person::set_national_id(National_id);
    Person::set_gender(Gender);
    Person::set_password(Password);
    Person::set_phone_number(phone_number);


}
void Student::set_id(int id)
{
    this->id = id;
}
void Student::set_address(string address)
{
    this->address = address;
}
int Student::set_mail(string mail)
{
    if (mail.length() <= 10)
    {
        return 0;
    }
    if (mail.substr(mail.length() - 10) == "@gu.edu.eg")
    {
        this->mail = mail;
        return 1;
    }
    else {
        cout << "Invalid Email address " << endl;
        //system("pause");
        return 0;
    }


}
void Student::set_student_line(Line l)
{
    student_line = l;
}
void Student::set_student_pickup_point(pickup_point p)
{
    student_pickup_point = p;
}
// ---- get ---- //
int Student::get_id()
{
    return id;
}
string Student::get_address()
{
    return address;
}
string Student::get_mail()
{
    return mail;
}
Line Student::get_student_line()
{
    return student_line;
}
pickup_point Student::get_student_pickup_point()
{
    return pickup_point();
}
///new//
void Student::print_line_pickupPoint()
{
    student_line.print_line();
    student_pickup_point.print_pikup_poin();
}
pickup_point Student::get_student_pickupPoint()
{
    return pickup_point();
}

// ---- Other---- //
void Student::class_print_Student()
{
    cout << get_name() << endl;
    cout << get_id() << endl;
    print_line_pickupPoint();
}
// string getName();
// double getGPA();
//  void print();




// ############# DRIVER IMPLEMENTATION ############# //
driver::driver()
{

}
driver::driver(string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail)
{

    Person::set_name(Name);
    Person::set_age(Age);
    Person::set_national_id(National_id);
    Person::set_gender(Gender);
    Person::set_password(Password);
    Person::set_phone_number(phone_number);
    driver::set_mail(mail);
}
// ---- set ---- //
void driver::set_driver(string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail) {


    Person::set_name(Name);
    Person::set_age(Age);
    Person::set_national_id(National_id);
    Person::set_gender(Gender);
    Person::set_password(Password);
    Person::set_phone_number(phone_number);
    driver::set_mail(mail);


}
void driver::set_camany_name(string name) {
    Campany_name = name;

}
void driver::set_mail(string mail) {

    Mail = mail;
}
// ---- get ---- //
string driver::get_camany_name() {
    return Campany_name;

}
string driver::get_mail() {
    return Campany_name;

}
// ---- Other---- //
// void class_print_driver();



// ############# COMPANY IMPLEMENTATION ############# // 
company::company()
{
    profit = 0;
    lines = ALL_LINES;
}
// ---- set ---- //
void company::set_name(string n)
{
    name = n;
}
void company::set_user_name(string uname)
{
    user_name = uname;
}
void company::set_pass(string password)
{
    pass = password;
}
void company::set_email(string mail)
{

    email = mail;
}
void company::set_address(string add)
{
    address = add;
}
void company::set_lines(Line l)
{
    //lines.add_if_not_contained(l);
}
int company::set_phone_number(string num)
{

    string str;

    //str = phone_number.resize(2);
    str = phone_number.substr(0, 3);
    if (str == "010" || str == "011" || str == "012" || str == "015")
    {
        this->phone_number = num;
        return 1;
    }
    else {
        cout <<"Invalid phone number" << endl;
        //system("pause");
        return 0;
    }

}
void company::set_profit(int p)
{
    profit = p;
}
// ---- get ---- //
string company::get_name()
{
    return name;
}
string company::get_user_name()
{
    return user_name;
}
string company::get_email()
{
    return email;
}
string company::get_pass()
{
    return pass;
}
string company::get_address()
{
    return address;
}
int company::get_profit()
{
    return profit;
}
linked_list<Line> company::get_lines()
{
    return lines;
}
// ---- Other---- //
void company::delet_line(Line l)
{
    //lines.deleteNode(l);
}
void company::view_lines()
{
    //lines.print();

}
void company::print_company()
{
    cout << name << endl;
}
void company::view_company_lines()
{
}
Line company::select_company_line()
{
    return Line();
}



// ############# TABLE IMPLEMENTATION ############# // 

// ############# Student Table IMPLEMENTATION ############# // 
Student_Table::Student_Table()
{

}
Student_Table::Student_Table(int Bucket) :Hash(Bucket)
{}
Student Student_Table::Search_Item(int key)
{

    int index = Hash_Function(key);
    Table[index].Return_Data(&s1);
    while (key != s1.get_id() && Table[index].Next(&s1) != 0)
    {
        //Table[index].Next(&s1);

        Table[index].Return_Data(&s1);
    }
    return s1;

}
void Student_Table::Student_print()
{
    for (int i = 0; i < Bucket; i++)
    {
        cout << "Bucket Number : " << i << endl;
        if (Table[i].go_head(&s1) == 0)
        {
            cout << "NOthing" << endl;
        }
        else
        {
            while (Table[i].Return_Data(&s1))
            {
                s1.class_print_Student();
                if (Table[i].Next(&s1) == 0)
                {
                    break;
                }

            }
        }

        cout << endl;
    }
}
void Student_Table::Table_Student_save()
{
    ifstream csv_file("shiref.csv");
    if (!csv_file.is_open())
    {
        // CSV file doesn't exist, so create it
        ofstream csv_file;
        csv_file.open("shiref.csv", ios::out | ios::trunc);
        csv_file << "Name,ID \n";
        csv_file.close();
    }
    else
    {
        ofstream csv_file;
        csv_file.open("shiref.csv", ios::out | ios::trunc);
        csv_file << "Name,ID \n";
        for (int i = 0; i < Bucket; i++)
        {
            cout << "Bucket Number : " << i << endl;
            if (Table[i].go_head(&s1) == 0)
            {
                cout << "NOthing" << endl;
            }
            else
            {
                while (Table[i].Return_Data(&s1))
                {
                    csv_file << s1.get_name() << "," << s1.get_id() << endl;
                    if (Table[i].Next(&s1) == 0)
                    {
                        break;
                    }

                }
            }

            cout << endl;
        }
        csv_file.close();
    }
}
void Student_Table::Table_Student_load()
{
    Student s1;
    ifstream csv_file("shiref.csv");
    if (!csv_file.is_open())
    {
        // CSV file doesn't exist, so create it
        cout << "no file" << endl;
    }
    else
    {
        string line;

        // Skip the header row
        getline(csv_file, line);

        while (getline(csv_file, line)) {
            stringstream lineStream(line);
            string cell;
            string name, id_string;
            int id;

            getline(lineStream, name, ',');
            getline(lineStream, id_string, ',');
            id = stoi(id_string);

            s1.set_name(name);
            s1.set_id(id);
            Insert_Item(s1.get_id(), s1);


            // Get the index and data from the CSV file

           /*getline(csv_file, cell, ',');
            s1.get_id() = stoi(cell);
            getline(csv_file, cell, ',');
            s1.get_name() = stoi(cell);*/

        }
    }
}


// ############# driver table IMPLEMENTATION ############# // 
driver_table::driver_table()
{
}
driver_table::driver_table(int Bucket) :Hash(Bucket)
{}
int driver_table::convert_to_key(string mail)
{
    int answer = 0;

    for (int i = 0; i < mail.length(); i++)
    {
        answer += (int)mail[i];
    }
    return answer;

}
driver driver_table::Search_Item(string mail)
{
    int key = convert_to_key(mail);
    int index = Hash_Function(key);
    Table[index].Return_Data(&d1);
    while (mail != d1.get_mail() && Table[index].Next(&d1) != 0)
    {
        //Table[index].Next(&c1);
        Table[index].Return_Data(&d1);
    }
    return d1;
}

// ############# company table IMPLEMENTATION ############# // 
company_table::company_table()
{
}
company_table::company_table(int Bucket) :Hash(Bucket)
{}
int company_table::convert_to_key(string mail)
{
    int answer = 0;

    for (int i = 0; i < mail.length(); i++)
    {
        answer += (int)mail[i];
    }
    return answer;

}
void company_table::all_companys_print()
{
    int counter = 0;
    for (int i = 0; i < Bucket; i++)
    {
        cout << "Bucket Number : " << i << endl;
        if (Table[i].go_head(&c1) == 0)
        {
            cout << "NOthing" << endl;
        }
        else
        {
            while (Table[i].Return_Data(&c1))
            {
                cout << counter << "-";
                c1.print_company();
                if (Table[i].Next(&c1) == 0)
                {
                    break;
                }
                counter++;
            }
        }

        cout << endl;
    }

}
company company_table::Search_Item(string mail)
{
    int key = convert_to_key(mail);
    int index = Hash_Function(key);
    Table[index].Return_Data(&c1);
    while (mail != c1.get_email() && Table[index].Next(&c1) != 0)
    {
        //Table[index].Next(&c1);
        Table[index].Return_Data(&c1);
    }
    return c1;
}



// ############# CAR IMPLEMENTATION ############# // 
car::car()
{
    
}
car::car(type name, string plate, int cost, int capacity)
{
    car_type = name;
    car_plate = plate;
    car_cost = cost;
    car_capacity = capacity;
    car_status = 0;
    car_driver = "Unknown";
}
// ---- set ---- //
void car::set_status(int status)
{
    car_status = status;
}
void car::set_Line(Line line)
{
    car_Line = line;
}
void car::set_driver(string driver)
{
    car_driver = driver;
}
// ---- get ---- //
int car::get_status()
{
    return car_status;
}
Line car::get_Line()
{
    return car_Line;
}
string car::get_driver()
{
    return car_driver;
}
type car::get_type()
{
    return car_type;

}
string car::get_car_plate()
{
    return car_plate;
}
// ---- Other---- //



// ############# TICKET IMPLEMENTATION ############# //
ticket::ticket()
{

}
//ticket(car car,  string company, Line line);

// ---- set ---- //
void ticket::set_car(car car)
{
    //ticket_car = car;
}
void ticket::set_price(int price)
{
    ticket_price = price;
}
void ticket::set_line(Line line)
{
    ticket_line = line;
}
void ticket::set_statues(int chioce)
{
    ticket_statues = chioce;
}
void ticket::set_company(company c) //(company company)
{
    ticket_company = c;
}
// ---- get ---- //
int ticket::get_id()
{
    return ticket_id;
}
car ticket::get_car()
{
    return ticket_car;
}
int ticket::get_price()
{

    return ticket_price;
}
Line ticket::get_line()
{
    return ticket_line;
}
int ticket::get_statues()
{
    return ticket_statues;
}
company ticket::get_company()
{
    return ticket_company;
}
// ---- Other---- //



// ############# COMPANY TICKET IMPLEMENTATION ############# // 
company_ticket::company_ticket()
{
    company_ticket_counter++;
    company_ticket_id = company_ticket_counter;
    company_ticket_price = "";
}
company_ticket::company_ticket(car t_car, string price, Line t_line)
{
    company_ticket_counter++;
    company_ticket_id = company_ticket_counter;
    company_ticket_car = t_car;
    company_ticket_price = price;
    company_ticket_line = t_line;
}
// ---- set ---- //
void company_ticket::set_company_ticket_car(car car)
{
    company_ticket_car = car;
}
void company_ticket::set_company_ticket_price(string price)
{
    company_ticket_price = price;
}
void company_ticket::set_company_ticket_line(Line t_line)
{
    company_ticket_line = t_line;
}
// ---- get ---- //
int company_ticket::get_company_ticket_id()
{
    return company_ticket_id;
}
car company_ticket::get_company_ticket_car()
{
    return company_ticket_car;
}
string company_ticket::get_company_ticket_price()
{
    return company_ticket_price;
}
Line company_ticket::get_company_ticket_line()
{
    return company_ticket_line;
}
// ---- Other---- //


// ############# STUDENT TICKET IMPLEMENTATION ############# // 
student_ticket::student_ticket()
{
    student_ticket_id = 0;
    student_ticket_date = "";
}
student_ticket::student_ticket(int id, string date, pickup_point t_pickup, Line t_line, company t_company)
{
    student_ticket_id = id;
    student_ticket_date = date;
    student_ticket_pickup_point = t_pickup;
    student_ticket_line = t_line;
    student_ticket_company = t_company;
}
// ---- set ---- //
void student_ticket::set_student_ticket_id(int id)
{
    student_ticket_id = id;
}
void student_ticket::set_student_ticket_date(string date)
{
    student_ticket_date = date;
}
void student_ticket::set_student_ticket_pickup_point(pickup_point t_pickup)
{
    student_ticket_pickup_point = t_pickup;
}
void student_ticket::set_student_ticket_line(Line t_line)
{
    student_ticket_line = t_line;
}
void student_ticket::set_student_ticket_company(company t_company)
{
    student_ticket_company = t_company;
}
// ---- get ---- //
int student_ticket::get_student_ticket_id()
{
    return student_ticket_id;
}
string student_ticket::get_student_ticket_date()
{
    return student_ticket_date;
}
pickup_point student_ticket::get_student_ticket_pickup_point()
{
    return student_ticket_pickup_point;
}
Line student_ticket::get_student_ticket_line()
{
    return student_ticket_line;
}
company student_ticket::get_student_ticket_company()
{
    return student_ticket_company;
}
// ---- Other---- //





// ############# university menue IMPLEMENTATION ############# //
void view()
{
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        add_company();
    }
    case 2:
    {

    }
    default:
        break;
    }
}
void add_company()
{
    string name;
    string pass;
    string address;
    string phonenumber;
    string user_name;


    company c1;

    cout << "name: ";
    cin >> name;
    cout << "pass: ";
    cin >> pass;
    cout << "address: ";
    cin >> address;
    cout << "phone number: ";
    cin >> phonenumber;
    cout << "user name";
    cin >> user_name;


    c1.set_name(name);
    c1.set_address(address);
    c1.set_user_name(user_name);
    c1.set_pass(pass);
    c1.set_phone_number(phonenumber);


    int key = c_t.convert_to_key(c1.get_email());
    c_t.Insert_Item(key, c1);

}
void view_companys()
{
    //c_t.Display_Hash();
}
void view_all_students()
{

    s_t.Student_print();
}
void edit_student()
{
    string phone_number;
    string name;
    string pass;
    string cpass;
    string e_mail;
    string national_id;

    Student s1;

    int user_choice;
    int key;




    cout << "enter your password to edit";
    cin >> key;
    s1 = s_t.Search_Item(key);

    cout << "Address : " << s1.get_address() << "\n ";
    cout << "Mail : " << s1.get_mail() << "\n";
    cout << "Name : " << s1.get_name() << "\n ";
    cout << "National ID : " << s1.get_national_id() << "\n";
    cout << "Phone number : " << s1.get_phone_number() << "\n";
    cout << "\n" << "\n" << "\n" << "\n";

    cout << "choose the part you want to edited :\n";
    cout << "1- Username \n";
    cout << "2- Password \n";
    cout << "3- Mail \n"; // critical
    cout << "4- National ID \n"; // critical
    cout << "5- Phone number \n";
    cout << "6- ID \n"; // critical

    cin >> user_choice;

    if (user_choice == 1)
    {
        cout << "user name : ";
        cin >> name;
        s1.set_name(name);
    }


    else if (user_choice == 2)
    {
        while (1)
        {
            cout << "passward : ";
            cin >> pass;
            cout << "confirm passward : ";
            cin >> cpass;

            if (pass == cpass)
            {
                s1.set_password(pass);
                break;
            }

        }
    }



    else if (user_choice == 3)
    {



        while (true)
        {
            cout << "mail : ";
            cin >> e_mail;
            if (s1.set_mail(e_mail))
            {
                break;
            }
        }

    }

    else if (user_choice == 4)
    {

        while (true)
        {
            cout << "national id : ";
            cin >> national_id;

            if (s1.set_national_id(national_id))
            {
                break;
            }
        }

    }

    else if (user_choice == 5)
    {
        while (true)
        {
            cout << "phone number : ";
            cin >> phone_number;
            if (s1.set_phone_number(phone_number))
            {
                break;
            }
        }
    }

    else if (user_choice == 6)
    {

        while (true)
        {

            cout << "phone number : ";
            cin >> phone_number;
            if (s1.set_phone_number(phone_number))
            {
                break;
            }
        }

    }


}
void add_line()
{
    string line_name;
    string pickupPoint_name;
    pickup_point p;
    Line l;
    int x = 0;


    cout << "enter the line name: ";
    cin >> line_name;

    l.set_Line_Name(line_name);



    cout << "add pickup points to this line \n press 0 to add \n";

    while (x == 0)
    {
        cout << "enter the picup point name: ";
        cin >> pickupPoint_name;

        p.set_pickup_point_Name(pickupPoint_name);

        l.add_pickup_point(p);
        cout << "press 0 to add";
        cin >> x;
    }
    ALL_LINES.Push_Back(l);

}
void add_pickup_point_interface()
{
    pickup_point p;
    Line l;
    string n;
    cout << "choose the line you want to add in :\n";

    //l.

    l= select_line();
    cout << "\nname of pickuppoint : ";
    cin >> n;
    p.set_pickup_point_Name(n);

    l.add_pickup_point(p);


}
void view_all_lines()
{
    Line l;
    int x = 0;
    int counter = 1;
    ALL_LINES.go_head(&l);

    while (1)
    {
        cout << counter << "-";
        l.print_line();

        if (!ALL_LINES.Next(&l))
        {
            return;
        }
        ALL_LINES.Return_Data(&l);

        counter++;
        x++;
    }
}
Line select_line()
{
    Line l;
    int n;
    view_all_lines();
    cin >> n;
    ALL_LINES.go_head(&l);
    for (int i = 1; i <= n; i++)
    {
        ALL_LINES.Next(&l);
    }
    /*l.print_line();
    l.Display_pickup_point();*/

    return l;
}



// ############# campany menue IMPLEMENTATION ############# //
void add_driver(string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail) {
    driver d;
    d.set_driver(Name, Age, National_id, Gender, Password, phone_number, mail);
    int key = d_t.convert_to_key(d.get_mail());
    d_t.Insert_Item(key, d);

}
void delete_driver(string mail) {
    driver d;
    int key = d_t.convert_to_key(mail);
    //d_t.Delete_Item(key,);
}
void edit_driver(string mail) {

    static int counter1 = 0;
    static int counter2 = 0;
    int choice;
    driver d;
    d = d_t.Search_Item(mail);
    view_driver(mail);
    cout << "for editing 1. name" << endl << "2.age" << endl << "3.National_id" << endl << "4.Password"
        << "5.phone_number";

    cin >> choice;
    switch (choice) {
    case 1:
    {
        string new_name;
        cout << d.get_mail() << " name is" << d.get_name() << endl;
        cin >> new_name;
        d.set_name(new_name);
        cout << "done successfully the new name is :" << d.get_name();
        break;
    }

    case 2: {
        string new_age;
        cout << d.get_mail() << " age is " << d.get_age() << endl;
        cin >> new_age;
        d.set_age(new_age);
        cout << "done successfully the new age is :" << d.get_age();
        break;
    }

    case 3:
    {
        if (counter1 == 0)
        {
            string new_National_id;
            cout << d.get_mail() << "National_id is " << d.get_national_id();
            cin >> new_National_id;
            d.set_national_id(new_National_id);
            cout << "done successfully the new national is :" << d.get_national_id();
            break;
        }
        else cout << "Go to the uni" << endl;
    }

    case 4:
    {
        if (counter2 == 0)
        {
            string cpass;
            string new_password;
            cout << d.get_mail() << "Enter the new password : " << endl;
            cin >> new_password;

            cout << "confirm passward : ";
            cin >> cpass;

            if (new_password == cpass)
            {
                d.set_password(new_password);
                break;
            }
            cout << "done successfully the new password is :" << d.get_password();

            break;

        }
        else cout << "Go to the uni";
    }
    case 5: {
        string new_phone_number;
        cout << d.get_mail() << " phone number is " << d.get_phone_number() << endl;
        cin >> new_phone_number;
        d.set_phone_number(new_phone_number);
        cout << "done successfully the new phone number is :" << d.get_phone_number();
        break;
    }
    default: {
        cout << "you choose a wrong number";
        edit_driver(mail);

    }
    }



}
void view_driver(string mail) {
    driver d;
    d = d_t.Search_Item(mail);
    cout << "the name is" << d.get_name() << endl;
    cout << "the age is" << d.get_age() << endl;
    cout << "the National_id is" << d.get_national_id() << endl;
    cout << "the gender is" << d.get_gender() << endl;
    cout << "the password is" << d.get_password() << endl;
}

// ############# bus menue IMPLEMENTATION ############# //
string max_bus(int passengers_count, double* cost) {
    string car;
    if (passengers_count <= high_s) {
        car = "high s";
        *cost = high_s_cost;
    }
    else if (passengers_count == costar || (passengers_count > high_s && passengers_count < costar)) {
        car = "coaster";
        *cost = costar_cost;
    }
    else if (passengers_count == 2 * high_s || (passengers_count > costar && passengers_count < 2 * high_s)) {
        car = " 2 high s";
        *cost = 2 * high_s_cost;
    }

    else if (passengers_count == 2 * costar || (passengers_count > 2 * high_s && passengers_count < 2 * costar)) {
        car = " 2 costar";
        *cost = 2 * costar_cost;
    }
    else if (passengers_count == bus) {
        car = "bus";
        *cost = bus_cost;
    }
    return car;
}
string bus_plus(int passengers_count, double* cost) {
    int count = 0;
    double car2_cost = 0;
    string  car;
    while (passengers_count >= bus) {
        passengers_count - bus;
        count++;
    }
    if (passengers_count != 0) {
        string car2 = max_bus(passengers_count, &car2_cost);
        car = to_string(count) + "bus and " + car2;
        *cost = (count * bus_cost) + (car2_cost);
    }
    else {
        car = to_string(count) + "bus";
        *cost = count * bus_cost;
    }
    return car;
} 
void add_bus() {
    Line l;
    ALL_LINES.go_head(&l);
    double cost;
    int  passengers_count_go, passengers_count_come, passengers_count_both, passengers_count;
    while (true)
    {
        passengers_count_go = l.get_count_go();
        passengers_count_come = l.get_count_come();
        passengers_count_both = l.get_count_both();
        if ((passengers_count_both + passengers_count_go) >= (passengers_count_both + passengers_count_come))
        {
            passengers_count = passengers_count_both + passengers_count_go;
        }
        else if ((passengers_count_both + passengers_count_go) < (passengers_count_both + passengers_count_come))
        {
            passengers_count = passengers_count_both + passengers_count_come;
        }
        if (passengers_count == 0) {
            l.set_car_type("null");
        }
        else if (passengers_count > bus) {
            l.set_car_type(bus_plus(passengers_count, &cost));
            l.set_bus_cost(cost);
        }
        else if (passengers_count <= bus)
        {
            l.set_car_type(max_bus(passengers_count, &cost));
            l.set_bus_cost(cost);
        }
        if (ALL_LINES.go_head(&l) == 0) {
            break;
        }

    }
}
void create_line_go()
{
    Queue q;
    pickup_point pickPoint;
    Line l;
    linked_list<pickup_point> p;
    ALL_LINES.go_head(&l);
    while (true)
    {
        p = l.get_linkedlist_pickup_point();
        p.go_head(&pickPoint);
        while (true)
        {
            if (pickPoint.get_count_go() != 0)
            {
                q.enQueue(pickPoint);
            }
            if (p.Next(&pickPoint) == 0)
            {
                break;
            }
        }
        l.set_reserved_go(q);
        if (ALL_LINES.Next(&l) == 0) {
            break;
        }
    }
}
void create_line_come()
{
    Stack s;
    pickup_point pickPoint;
    Line l;
    linked_list<pickup_point> p;
    ALL_LINES.go_head(&l);
    while (true)
    {
        p = l.get_linkedlist_pickup_point();
        p.go_head(&pickPoint);
        while (true)
        {
            if (pickPoint.get_count_come() != 0)
            {
                s.push(pickPoint);
            }
            if (p.Next(&pickPoint) == 0)
            {
                break;
            }
        }
        l.set_reserved_come(s);
        if (ALL_LINES.Next(&l) == 0) {
            break;
        }
    }
}
void view_line_go(Line l)
{
    linked_list<pickup_point> p;
    p = l.get_linkedlist_pickup_point();
    Queue q = l.get_reserved_go();
    while (true) {
        q.deQueue();
    }
}
void view_line_come(Line l)
{
    linked_list<pickup_point> p;
    p = l.get_linkedlist_pickup_point();
    Stack s = l.get_reserved_come();
    while (true)
    {
        s.pop();
    }
}
void profit()
{
    int total_go = 0;
    int total_come = 0;
    int total_both = 0;
    double total = 0, profit = 0, total_profit = 0;
    Line l;
    ALL_LINES.go_head(&l);
    while (true)
    {
        total_go = l.get_count_go();
        total_come = l.get_count_come();
        total_both = l.get_count_both();
        total = ((total_go + total_come) * 75) + (total_both * 120); // change the price
        profit = total - l.get_bus_cost();
        if (ALL_LINES.Next(&l) == 0) {
            break;
        }
    }
    total_profit += profit;
}

// ############# SIGNUP STUDENT IMPLEMENTATION ############# // 
 void signup_student()
{
    int id;
    string phone_number;
    string name;
    string pass;
    string cpass;
    string e_mail;
    string national_id;
    Line l;
    pickup_point p;


    Student s1;


    cout << "user name : ";
    cin >> name;
    s1.set_name(name);

    while (1)
    {
        cout << "passward : ";
        cin >> pass;
        cout << "confirm passward : ";
        cin >> cpass;

        if (pass == cpass)
        {
            s1.set_password(pass);
            break;
        }

    }
    //while (true)
    //{
    //    cout << "mail : ";
    //    cin >> e_mail;
    //    if (s1.set_mail(e_mail))
    //    {
    //        break;
    //    }
    //}



   /* while (true)
    {
        cout << "national id : ";
        cin >> national_id;

        if (s1.set_national_id(national_id))
        {
            break;
        }
    }*/





    /*while (true)
    {
        cout << "phone number : ";
        cin >> phone_number;
        if (s1.set_phone_number(phone_number))
        {
            break;
        }
    }*/

    cout << "select your line";
    l=select_line();
    s1.set_student_line(l);

    s1.set_student_pickup_point(l.select_pickup_point());



    cout << "select pickup point ";





    cout << "ID : ";
    cin >> id;
    s1.set_id(id);


    s_t.Insert_Item(s1.get_id(), s1);

}
// ############# SIGNUP COMPANY IMPLEMENTATION ############# //
 void signup_company()
 {
     int id;
     string phone_number;
     string name;
     string pass;
     string cpass;
     string e_mail;
     string national_id;

     company s1;


     cout << "user name : ";
     cin >> name;
     s1.set_name(name);

     while (1)
     {
         cout << "passward : ";
         cin >> pass;
         cout << "confirm passward : ";
         cin >> cpass;

         if (pass == cpass)
         {
             s1.set_pass(pass);
             break;
         }

     }


     cout << "mail : ";
     cin >> e_mail;
     s1.set_email(e_mail);





     /*while (true)
     {
         cout << "national id : ";
         cin >> national_id;

         if (s1.set_national_id(national_id))
         {
             break;
         }
     }*/





     // while (true)
      //{
     cout << "phone number : ";
     cin >> phone_number;
     s1.set_phone_number(phone_number);
     /*if (s1.set_phone_number(phone_number))
     {
         break;
     }
 }*/





 /* cout << "ID : ";
  cin >> id;
  s1.set_id(id);*/

     int key = c_t.convert_to_key(s1.get_email());
     c_t.Insert_Item(key, s1);

 }

// ############# LOGIN STUDENT IMPLEMENTATION ############# //
 int login_page()
 {

     Student st;

     int id;
     string pass;

     cout << "enter your id : ";
     cin >> id;
     cout << "enter your passward : ";
     cin >> pass;



     st = s_t.Search_Item(id);

     if (st.get_password() == pass)
     {
         return 1;
     }
     else
     {
         return 0;
     }




 }

// ############# LOGIN COMPANY IMPLEMENTATION ############# //
 int login_company()
 {

     company st;

     string id;
     string pass;

     cout << "enter your id : ";
     cin >> id;
     cout << "enter your passward : ";
     cin >> pass;



     st = c_t.Search_Item(id);

     if (st.get_pass() == pass)
     {
         return 1;
     }
     else
     {
         return 0;
     }




 }


 // ############# booking IMPLEMENTATION ############# //

 void booking_ticket()
 {
     int user_choice;
     Student s1;
     student_ticket t1;
     pickup_point p1;
     Line l1;
     company c;
     linked_list<Line> l;

     c = select_company();
     l=c.get_lines();

     l1=select_line();
     t1.set_student_ticket_line(l1);
     p1 = l1.select_pickup_point();
     t1.set_student_ticket_pickup_point(p1);


     cout << "\nEnter your trip statues : (1-zahab     2- 3awda    3-zahab w 3awda) \n";
     cin >> user_choice;
     if (user_choice == 1)
     {
         p1.set_count_go();
     }
     else if (user_choice == 2)
     {
         p1.set_count_come();
     }
     else if (user_choice == 3)
     {
         p1.set_count_both();
     }

     cout << "Enter your line : \n";
    
    
     
     

     //view date
     //select date

   //  s1.se(t1);
 }

 // ############# select company ############# //

 company select_company()
 {
     string x;
     company c;
     int choise;

     ALL_COMPANYS.go_head(&x);

     while (true)
     {
         ALL_COMPANYS.Return_Data(&x);

         c = c_t.Search_Item(x);
         cout << c.get_name();
         if (!ALL_COMPANYS.Next(&x))
         {
             break;
         }
     }
     cout << "\nchoose the company you want to go with: ";
     cin >> choise;
     ALL_COMPANYS.go_head(&x);
     for (int i = 0; i < choise; i++)
     {
         ALL_COMPANYS.Next(&x);
     }
     c = c_t.Search_Item(x);
     return c;

 }


 // ############# student menue ############# //

 void student_menue()
 {
     int x;
     cout << "1-book ticket\n2-view ticket\n3-edit info\n4-delete account\n5-log out";
     cin >> x;
     

     switch (x)
     {
     case 1:
     {
         
         break;
     }
     case 2:
     {

         break;
     }
     case 3:
     {

         break;
     }
     case 4:
     {

         break;
     }
     case 5:
     {

         break;
     }


     default:
         break;
     }
 }



 // #############  company menue ############# //

 void company_menue()
 {
     int x;
     cout << "1-add driver\n2-(a5ly eldriver ya5od line\n3-see profit\n4-all tickets\n5-log out";//feh hagat msh mgm3ha
     cin >> x;


     switch (x)
     { 
     case 1:
     {

         break;
     }
     case 2:
     {

         break;
     }
     case 3:
     {

         break;
     }
     case 4:
     {

         break;
     }
     case 5:
     {

         break;
     }


     default:
         break;
     }
 }



 // ############# university menue ############# //


 void university_menue()
 {
     int x;
     cout << "1-add company\n2-edit student\n3-all students\n4-all companes\n5-add line\n6-add pickup point\n7-log out";//feh hagat msh mgm3ha
     cin >> x;


     switch (x)
     {
     case 1:
     {

         break;
     }
     case 2:
     {

         break;
     }
     case 3:
     {

         break;
     }
     case 4:
     {

         break;
     }
     case 5:
     {

         break;
     }
     case 6:
     {

         break;
     }
     case 7:
     {

         break;
     }

     default:
         break;
     }
 }


 // ############# driver menue ############# //


 void driver_menue()
 {
     int x;
     cout << "1-see line\n2-menue of students\n3-log out\n";//feh hagat msh mgm3ha
     cin >> x;


     switch (x)
     {
     case 1:
     {

         break;
     }
     case 2:
     {

         break;
     }
     case 3:
     {

         break;
     }


     default:
         break;
     }
 }