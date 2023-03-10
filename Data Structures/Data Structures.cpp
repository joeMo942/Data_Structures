/// transportation services app
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include "LIBRARY/color-console-master/include/color.hpp"


using namespace std;
using namespace dye;
using namespace this_thread;     // sleep_for, sleep_until
using namespace chrono_literals; // ns, us, ms, s, h, etc.
using chrono::system_clock;

void errors()
{
    #pragma warning(disable : 4552)
    #pragma warning(disable : 4101)
    #pragma warning(disable : 4715)
    #pragma warning(disable : 6011)
    #pragma warning(disable : 28182)
    #pragma warning(disable : 26812)
    #pragma warning(disable : 6001)
    #pragma warning(disable : 26495)

}

static int company_ticket_counter = 0;
static int student_ticket_counter = 0;
static int line_counter = 0;
int num_error = 0;
int limit_of_error = 3;
string cin_str;

template <class T> class linked_list;
class Stack;
class Queue;
template <class T> class Hash;
class pickup_point;
class Line;
class student_ticket;
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

enum type { high_s, super_jet, mini_bus };


// ---------- TOOLS HEADER ---------- //
void delay(int n)
{
    sleep_for(1s);
    while (n)
    {
        system("cls");
        cout << "Returning at " << n << " ...";
        --n;
        sleep_for(1s);
    }

}

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
    link prev;
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
    void Push_between_B(int x, T y);
    //ex
    bool Return_Data(T* data);
    bool go_head(T* data);
    bool Next(T* data);
    void delete_Data(T* data);
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
        int counter = 1;
        link temp;
        if (top == NULL) {
            cout << "\nno rservation in this point ";
            return;
        }
        else {
            temp = top;
            while (temp != NULL) {
                cout << "\t" << counter << "-" << temp->data.get_pickup_point_Name();
                temp = temp->next;
                if (temp != NULL)
                    cout << "\n";
                counter++;
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

    int deQueue(pickup_point* p)
    {
        if (front == NULL)
        {
            cout << "no resrvation in this line" << endl;
        }
        link temp = front;

        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        rear = temp;
        free(rear);
        *p = temp->data;
        num_of_ele--;
        return 1;

    }
    void display()
    {
        link temp;
        if ((front == NULL) && (rear == NULL)) {
            printf("\nQueue is Empty\n");
        }
        else {
            printf("The queue is \n");
            temp = front;
            while (temp) {
                cout << temp->data.get_pickup_point_Name() << endl;
                temp = temp->next;
            }
            cout << "\n";
        }
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
    void set_linked_list_points(linked_list<pickup_point> p);
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
    pickup_point select_pickup_point(int* x);
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
    int set_email(string mail);
    void set_address(string address);
    void set_lines(linked_list<Line> l);
    int set_phone_number(string num);
    void set_profit(int profit);
    // ---- get ---- //
    string get_name();
    string get_user_name();
    string get_email();
    string get_pass();
    string get_address();
    string get_phone_number();
    int get_profit();
    linked_list<Line> get_lines();
    // ---- Other---- //
    void delet_line(Line l);
    void view_lines();
    void print_company();
    //new//
    void view_company_lines();
    Line select_company_line();
    void create_line_go();
    void create_line_come();
    void view_line_go(Line& l);
    void view_line_come(Line& l);
    Line select_line_company();

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
    void print_ticket();
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
    int price;

public:
    student_ticket();
    student_ticket(int id, string date, pickup_point t_pickup, Line t_line, company t_company);
    void set_student_ticket_id(int id);
    void set_student_ticket_date(string date);
    void set_student_ticket_pickup_point(pickup_point point);
    void set_student_ticket_line(Line t_line);
    void set_student_ticket_company(company t_company);
    void set_stident_ticket_price(int x);
    int get_student_ticket_id();
    string get_student_ticket_date();
    pickup_point get_student_ticket_pickup_point();
    Line get_student_ticket_line();
    company get_student_ticket_company();
    int get_student_ticket_price();
    void print_ticket();
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
    void person_print() const;
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
    linked_list<student_ticket> all_student_tickets;
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
    void add_student_ticket(student_ticket ticket);

    // ---- get ---- //
    int get_id();
    string get_address();
    string get_mail();
    Line get_student_line();
    pickup_point get_student_pickup_point();
    // ---- Other---- //
    void class_print_Student();
    void print_ticket();
    //new//
    void print_line_pickupPoint();
    pickup_point get_student_pickupPoint();
    void print_student_ticket();
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
    void Student_print();
    void student_ticket_print();
    Student* Search_Item(int key);
    void Student_Delete_Item(int key);
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
    void company_Insert_Item(string mail, company c1);
    void all_companys_print();
    company* Search_Item(string mail);
    void company_Delete_Item(string mail);
    //void Table_company_save();
   // void Table_company_load();


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
    driver* Search_Item(string mail);
    void driver_Delete_Item(string mail);
    //void Table_Student_save();
   // void Table_Student_load();
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
void edit_student(Student* s);
void edit_company();
void add_line();
void add_pickup_point_interface();
void view_all_lines();
void delete_line(string name);
Line select_line();
void booking_ticket(Student* s);

company select_company();


// ---------- campany menue ---------- //
//buses define
#define high_s 3
#define costar 5
#define bus 11
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
void view_lines_buses();
void create_line_go();
void create_line_come();
void view_line_go(Line l);
void view_line_come(Line l);
void profit();
void signup_student();
int login_student(Student* s);
void signup_company();
int login_company(company* c);
int login_uni();




/////// all menus///////
void university_menue();
void Admin_company();
void Admin_Line();
void student_menue(Student* s);
void company_menue(company* c);
void log_menue();
void main_menue();
void driver_menue();
int Select_from_to(int start, int end);
int num_of_error(int error, int& counter, int limit_of_error);


int main()
{
    errors();

    while (true)
    {
        main_menue();
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
template<class T> void linked_list<T>::Push_between_B(int x, T y)
{
    link new_node = new node;
    link prev = NULL;
    new_node->data = y;
    current = head;
    x = x - 1;
    if (head == 0)
    {
        Push_Back(y);
        return;
    }
    else if (x == 0)
    {
        head = head->next;
        delete current;
        Push_Front(y);
        return;
    }

    for (int i = 0; i < x; i++)
    {
        if (head == 0)
        {
            Push_Back(y);
            return;
        }
        else
        {
            prev = current;
            current = current->next;
        }


    }

    new_node->next = current->next;
    prev->next = new_node;
    delete current;



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
template<class T> void linked_list<T>::delete_Data(T* data)
{
    if (current == 0)
    {

        return;
    }
    else if (current->next == 0)
    {
        prev = 0;
        delete current;
    }
    else if (head == current)
    {
      
        head = current->next;
        delete current;
    }
    else
    {
        prev->next = current->next;
        delete current;

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
    prev = NULL;
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

    if (head == 0 || head->next == 0)
    {
        return 0;
    }
    else if (current->next == 0)
    {
        return 0;


    }
    else
    {
        prev = current;
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
    cout << "\t Name: " << pickup_point_Name << endl;
    cout << "\t One way (From the city): " << count_go<<endl;
    cout << "\t One way (From The university): " << count_come << endl << endl;
    
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
void Line::set_linked_list_points(linked_list<pickup_point> p)
{
    pickup_point_Names = p;
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
    cout << "\t" << line_counter << Line_Name << endl;
    cout << "Round trip: " << count_both << endl;
    cout << "One way (From town): " << count_go << endl;
    cout << "One way (From university): " << count_come << endl;
}
void Line::Display_pickup_point()
{
    cout << "\n\t Line name: " << Line_Name << endl;
    cout << "\t\t(Pickup points)\n";
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
pickup_point Line::select_pickup_point(int* y)
{
    int counter = 0;
    int x=0;

    pickup_point p;
    Display_pickup_point();
    cout << "\n\tChosse your Pickup point: ";
    cin >> x;
   
    pickup_point_Names.go_head(&p);



    pickup_point_Names.go_head(&p);

    for (int i = 1; i < x; i++)
    {
        pickup_point_Names.Next(&p);
    }
    *y = x;
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
    if (stoi(age) > 17 && stoi(age) <= 100)
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
        cout << red("Invalid National Number..!");
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
    if ((str == "010" || str == "011" || str == "012" || str == "015")&& phone_number.length() == 11)
    {
        this->phone_number = phone_number;
        return 1;
    }
    else {
        cout << red("Invalid phone number..!");
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
void Person::person_print() const
{
    cout << get_name() << endl;
    cout << get_age() << endl;
    cout << get_national_id() << endl;
    cout << get_gender() << endl;
    cout << get_password() << endl;
    cout << get_phone_number() << endl;
}


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
        cout << red("Invalid Email address..!") << endl;
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
void Student::add_student_ticket(student_ticket ticket)
{
    all_student_tickets.Push_Back(ticket);
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
void Student::print_student_ticket()
{

    student_ticket st;
    int x = 0;
    int counter = 1;
    all_student_tickets.go_head(&st);
    if (all_student_tickets.go_head(&st))
    {
        
        while (1)
        {
            cout <<"\t" << counter << " - ";
            st.print_ticket();

            if (!all_student_tickets.Next(&st))
            {
                return;
            }
            all_student_tickets.Return_Data(&st);
            counter++;
            x++;
        }
    }
   
}
// ---- Other---- //
void Student::class_print_Student()
{
    cout << "Name: " << Person::get_name()<<endl;
    cout << "Email: " << get_mail() <<endl;
    cout << "ID: " << get_id() << endl;
    cout << "National Number: " << get_national_id() << endl << endl << endl;
    //print_line_pickupPoint();
}
void Student::print_ticket()
{
   //st.print_ticket();
}


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
void driver::set_driver(string Name, string Age, string National_id, string Gender, string Password, string phone_number, string mail)
{
    Person::set_name(Name);
    Person::set_age(Age);
    Person::set_national_id(National_id);
    Person::set_gender(Gender);
    Person::set_password(Password);
    Person::set_phone_number(phone_number);
    driver::set_mail(mail);

}
void driver::set_camany_name(string name)
{
    Campany_name = name;
}
void driver::set_mail(string mail)
{
    Mail = mail;
}
// ---- get ---- //
string driver::get_camany_name()
{
    return Campany_name;

}
string driver::get_mail()
{
    return Campany_name;

}
// ---- Other---- //


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
int company::set_email(string mail)
{

    if (mail.length() <= 10)
    {

        return 0;
    }
    if (mail.substr(mail.length() - 10) == "@gu.edu.eg")
    {
        this->email = mail;
        return 1;
    }
    else {
        cout << red("Invalid Email address..!") << endl;
        //system("pause");
        return 0;
    }
}
void company::set_address(string add)
{
    address = add;
}
void company::set_lines(linked_list<Line> l)
{
    lines = l;
}
int company::set_phone_number(string num)
{

    string str;

    //str = phone_number.resize(2);

    str = num.substr(0, 3);
    if ((str == "010" || str == "011" || str == "012" || str == "015") && num.length() == 11)
    {

        this->phone_number = num;
        return 1;
    }
    else {
        cout << red("Invalid phone number\n");
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
string company::get_phone_number()
{
    return phone_number;
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
   // lines.print();

}
void company::print_company()
{
    cout << "\tCompany name: " << name << endl;
}
void company::view_company_lines()
{
    Line l;
    if (lines.go_head(&l))
    {
        while (true)
        {
            l.print_line();
            if (!lines.Next(&l))
            {
                break;
            }
        }
    }

}
Line company::select_company_line()
{
    return Line();
}
Line company::select_line_company()
{
    Line l1;
    int n;
    view_all_lines();
    cin >> n;
    lines.go_head(&l1);
    for (int i = 1; i <= n; i++)
    {
        lines.Next(&l1);
    }
    /*l.print_line();
    l.Display_pickup_point();*/
    return l1;

}


// --------------- TABLE IMPLEMENTATION --------------- // 
// ############# Student Table IMPLEMENTATION ############# // 
Student_Table::Student_Table()
{

}
Student_Table::Student_Table(int Bucket) :Hash(Bucket)
{}
Student* Student_Table::Search_Item(int key)
{

    int index = Hash_Function(key);
    Table[index].go_head(&s1);
    Table[index].Return_Data(&s1);
    while (key != s1.get_id() && Table[index].Next(&s1) != 0)
    {
        //Table[index].Next(&s1);

        Table[index].Return_Data(&s1);
    }
    return &s1;

}
void Student_Table::Student_Delete_Item(int key)
{
    // Student* s;
    int index = Hash_Function(key);
    Table[index].go_head(&s1);
    Table[index].Return_Data(&s1);
    while (key != s1.get_id() && Table[index].Next(&s1) != 0)
    {
        //Table[index].Next(&s1);

        Table[index].Return_Data(&s1);
    }
    if (key == s1.get_id())
    {
        Table[index].delete_Data(&s1);
    }
    else
    {
        cout << yellow("NOT FOUND") << endl;
    }


}
void Student_Table::Student_print()
{

    for (int i = 0; i < Bucket; i++)
    {
            while (Table[i].Return_Data(&s1))
            {
                s1.class_print_Student();
                if (Table[i].Next(&s1) == 0)
                {
                    break;
                }
                cout << endl;
            }

    }
}
void Student_Table::student_ticket_print()
{
    for (int i = 0; i < Bucket; i++)
    {

            while (Table[i].Return_Data(&s1))
            {
                s1.print_ticket();
                cout << endl;
                if (Table[i].Next(&s1) == 0)
                {
                    break;
                }
            }
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
        csv_file << "ID, Name, age, national_id, gender, password, phone_number, address, mail \n";
        csv_file.close();
    }
    else
    {
        ofstream csv_file;
        csv_file.open("shiref.csv", ios::out | ios::trunc);
        csv_file << "ID,Name,age,national_id,gender,password,phone_number,address,mail \n";
        for (int i = 0; i < Bucket; i++)
        {
            cout << "Bucket Number : " << i << endl;
            if (Table[i].go_head(&s1) == 0)
            {
                cout << yellow("Nothing") << endl;
            }
            else
            {

                while (Table[i].Return_Data(&s1))
                {
                    csv_file << s1.get_id() << ","
                        << s1.get_name() << ","
                        << s1.get_age() << ","
                        << s1.get_national_id() << ","
                        << s1.get_gender() << ","
                        << s1.get_password() << ","
                        << s1.get_phone_number() << ","
                        << s1.get_address() << ","
                        << s1.get_mail() << endl;


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
        cout << red("NO FILE") << endl;
    }
    else
    {
        string line;

        // Skip the header row
        getline(csv_file, line);

        while (getline(csv_file, line)) {
            stringstream lineStream(line);
            string cell;
            string name, id_string, age, national_id, gender, password, phone_number, address, mail;
            int id;


            // ID, Name, age, national_id, gender, password, phone_number, address, mail

            getline(lineStream, id_string, ',');
            id = stoi(id_string);
            getline(lineStream, name, ',');
            getline(lineStream, age, ',');
            getline(lineStream, national_id, ',');
            getline(lineStream, gender, ',');
            getline(lineStream, password, ',');
            getline(lineStream, phone_number, ',');
            getline(lineStream, address, ',');
            getline(lineStream, mail, ',');


            s1.set_id(id);
            s1.set_name(name);
            s1.set_age(age);
            s1.set_national_id(national_id);
            s1.set_gender(gender);
            s1.set_password(password);
            s1.set_phone_number(phone_number);
            s1.set_address(address);
            s1.set_mail(mail);


            Insert_Item(s1.get_id(), s1);




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
driver* driver_table::Search_Item(string mail)
{
    int key = convert_to_key(mail);
    int index = Hash_Function(key);
    Table[index].Return_Data(&d1);
    while (mail != d1.get_mail() && Table[index].Next(&d1) != 0)
    {
        //Table[index].Next(&c1);
        Table[index].Return_Data(&d1);
    }
    return &d1;
}
void driver_table::driver_Delete_Item(string mail)
{
    int key = convert_to_key(mail);
    int index = Hash_Function(key);
    Table[index].go_head(&d1);
    Table[index].Return_Data(&d1);
    while (mail != d1.get_mail() && Table[index].Next(&d1) != 0)
    {
        //Table[index].Next(&s1);

        Table[index].Return_Data(&d1);
    }
    if (mail == d1.get_mail())
    {
        Table[index].delete_Data(&d1);
    }
    else
    {
        cout << yellow("NOT FOUND") << endl;
    }

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
void company_table::company_Insert_Item(string mail, company c1)
{
    int key;
    key = convert_to_key(mail);
    Insert_Item(key, c1);
}
void company_table::all_companys_print()
{
    int counter = 0;
    for (int i = 0; i < Bucket; i++)
    {
            while (Table[i].Return_Data(&c1))
            {
                cout << counter << " - ";
                c1.print_company();
                if (Table[i].Next(&c1) == 0)
                {
                    break;
                }
                cout << endl;
                counter++;
            }

    }

}
company* company_table::Search_Item(string mail)
{
    int key = convert_to_key(mail);
    int index = Hash_Function(key);
    Table[index].go_head(&c1);
    Table[index].Return_Data(&c1);
    while (mail != c1.get_email() && Table[index].Next(&c1) != 0)
    {
        //Table[index].Next(&c1);
        Table[index].Return_Data(&c1);
    }
    return &c1;
}
void company_table::company_Delete_Item(string mail)
{
    int key = convert_to_key(mail);
    int index = Hash_Function(key);
    Table[index].go_head(&c1);
    Table[index].Return_Data(&c1);
    while (mail != c1.get_email() && Table[index].Next(&c1) != 0)
    {
        //Table[index].Next(&s1);

        Table[index].Return_Data(&c1);
    }
    if (mail == c1.get_email())
    {
        Table[index].delete_Data(&c1);
    }
    else
    {
        cout << yellow("NOT FOUND") << endl;
    }

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
// ---- set ---- //
void ticket::set_car(car car)
{

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
void ticket::set_company(company c)
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
void ticket::print_ticket()
{
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
void student_ticket::set_stident_ticket_price(int x)
{
    price = x;
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
int student_ticket::get_student_ticket_price()
{
    return price;
}
void student_ticket::print_ticket()
{
    cout << "\n\t(ticket info)\n";
    cout << "The Line is: " << student_ticket_line.get_Line_point_Name() << endl;
    cout <<  "The Pickup point is: " << student_ticket_pickup_point.get_pickup_point_Name() << endl;
    cout << "The Price: " << price << endl;

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
    company c1;

    
    cout << "\nName: ";
    cin >> cin_str;
    c1.set_name(cin_str);

    cout << "\nPassword: ";
    cin >> cin_str;
    c1.set_pass(cin_str);

    cout << "\nAddress: ";
    cin >> cin_str;
    c1.set_address(cin_str);


    while (num_error < limit_of_error)
    {
        cout << "\nPhone number: ";
        cin >> cin_str;
        if (c1.set_phone_number(cin_str) == 1)
        {
            num_error = 0;
            break;
        }
        else if (num_of_error(0, num_error, limit_of_error) == -1)
        {
            num_error = 0;
            return;
        }

    }


    cout << "\nUsername: ";
    cin >> cin_str;
    c1.set_user_name(cin_str);


    while (num_error < limit_of_error)
    {
        cout << "\nEmail: ";
        cin >> cin_str;
        if (c1.set_email(cin_str) == 1)
        {
            num_error = 0;
            break;
        }
        else if (num_of_error(0, num_error, limit_of_error) == -1)
        {
            num_error = 0;
            return;
        }
    }



    int key = c_t.convert_to_key(c1.get_email());
    ALL_COMPANYS.Push_Back(c1.get_email());
    c_t.Insert_Item(key, c1);

}
void view_companys()
{
    c_t.all_companys_print();
}
void view_all_students()
{

    s_t.Student_print();
}
void edit_student(Student* s)
{
    string phone_number;
    string name;
    string pass;
    string cpass;
    string e_mail;
    string national_id;

    Student* s1 = s_t.Search_Item(s->get_id());

    int user_choice;

    cout << "Enter your password to edit: ";
    cin >> pass;
    s1 = s_t.Search_Item(s->get_id());

    if (s1->get_password() != pass)
    {
        cout << red("Wrong password..!") << endl;
        system("cls");
        return;
    }

    cout << "Address: " << s1->get_address() << "\n ";
    cout << "Email: " << s1->get_mail() << "\n";
    cout << "Name: " << s1->get_name() << "\n ";
    cout << "National Number: " << s1->get_national_id() << "\n";
    cout << "Phone number: " << s1->get_phone_number() << "\n";
    cout << "\n" << "\n";

    cout << "\t(Choose the part you want to edit)\n";
    cout << "1- Username \n";
    cout << "2- Password \n";
    cout << "3- Email \n";
    cout << "4- National Number \n";
    cout << "5- Phone number \n";
    user_choice = Select_from_to(1, 5);

    if (user_choice == 1)
    {
        cout << "User name: ";
        cin >> name;

        s1->set_name(name);
        cout << "Name: " << s1->get_name() << "\n";
    }


    else if (user_choice == 2)
    {
        while (1)
        {
            cout << "Password: ";
            cin >> pass;
            cout << "Confirm password: ";
            cin >> cpass;

            if (pass == cpass)
            {
                s1->set_password(pass);
                break;
            }

        }
    }



    else if (user_choice == 3)
    {



        while (true)
        {
            cout << "Email: ";
            cin >> e_mail;
            if (s1->set_mail(e_mail))
            {
                break;
            }
        }

    }

    else if (user_choice == 4)
    {

        while (true)
        {
            cout << "National number: ";
            cin >> national_id;

            if (s1->set_national_id(national_id))
            {
                break;
            }
        }

    }

    else if (user_choice == 5)
    {
        while (true)
        {
            cout << "Phone number: ";
            cin >> phone_number;
            if (s1->set_phone_number(phone_number))
            {
                break;
            }
        }
    }


    s_t.Insert_Item(s1->get_id(), *s1);
    s_t.Student_Delete_Item(s1->get_id());
    system("cls");
    main_menue();

}
void edit_company()
{
    string phone_number;
    string name;
    string pass;
    string cpass;
    string Address;
    string national_id;

    company* c1;

    int user_choice;
    string key;


    cout << "Enter your E-mail to edit: ";
    cin >> key;
    c1 = c_t.Search_Item(key);
    cout << "Enter your password to edit: ";
    cin >> key;
    if (c1->get_pass() == key)
    {

        cout <<  "\n Email: " << c1->get_email() << "\n";
        cout << "Name: " << c1->get_name() << "\n ";
        cout << "Address: " << c1->get_address() << "\n ";
        cout << "Phone number: " << c1->get_phone_number() << "\n";
        cout << "\n" << "\n";


        cout << "\t(Choose the part you want to edit)\n";
        cout << "1- Name \n";
        cout << "2- Address \n";
        cout << "3- Phone number \n"; 
        cout << "4- Password \n"; 
        cout << "5- Back\n";

        user_choice = Select_from_to(1, 5);



        if (user_choice == 1)
        {
            cout << "\n\nName: ";
            cin >> name;

            c1->set_name(name);
            cout << "\tNew Name: " << c1->get_name() << "\n";
        }
        else if (user_choice == 2)
        {
            while (true)
            {
                cout << "\n\nAddress: ";
                cin >> Address;
                c1->set_address(Address);
                break;
            }

        }
        else if (user_choice == 3)
        {
            while (true)
            {
                cout << "\n\nPhone number: ";
                cin >> phone_number;
                if (c1->set_phone_number(phone_number))
                {
                    break;
                }
            }
        }
        else if (user_choice == 4)
        {
            while (1)
            {
                cout << "Password: ";
                cin >> pass;
                cout << "Confirm Password: ";
                cin >> cpass;

                if (pass == cpass)
                {
                    c1->set_pass(pass);
                    break;
                }
                else cout << red("The passwords doesn't match..!");

            }
        }


        c_t.company_Insert_Item(c1->get_email(), *c1);
        c_t.company_Delete_Item(c1->get_email());
    }
    else
    {
        cout << red("Wrong password or wrong E-mail\n");
    }




}
void add_line()
{
    string line_name;
    string pickupPoint_name;
    pickup_point p;
    Line l;
    int x = 1;


    cout << "\nEnter line name: ";
    getline(cin, line_name);
    getline(cin, line_name);
    

    l.set_Line_Name(line_name);



    cout << "\n\t\tAdd pickup points to this line\n\n";

    while (x)
    {
        cout << "Enter picup point name: ";
        getline(cin,pickupPoint_name);
        getline(cin, pickupPoint_name);
        p.set_pickup_point_Name(pickupPoint_name);
        l.add_pickup_point(p);
        cout << yellow("\n\t Press 1 to add another     0 to Exit");
        cin >> x;
    }
    ALL_LINES.Push_Back(l);
    line_counter++;

}
void add_pickup_point_interface()
{
    pickup_point p;
    Line l;
    string n;
    cout << "\n\tChoose the line you want to add in \n";

    l = select_line();
    cout << "\nName of pickup point: ";
    getline(cin, n);
    getline(cin, n);
    p.set_pickup_point_Name(n);

    l.add_pickup_point(p);


}
void edit_line()
{
    pickup_point p;
    Line l;
    string n, prev;

    int select;
    l = select_line();
    cout << "1- Edit the Line name\n";
    cout << "2- Back \n";
    select = Select_from_to(1, 2);
        if (select == 1)
        {
            prev = l.get_Line_point_Name();
            cout << "Enter the new name: ";
            cin >> n;
            l.set_Line_Name(n);

            ALL_LINES.Push_Back(l);
            delete_line(prev);

            return;
        }

        else if (select == 2)
        {
            return;
        }

}
void view_all_lines()
{
    Line l;
    int x = 0;
    int counter = 1;
    ALL_LINES.go_head(&l);

    while (1)
    {
        cout << counter << " - ";
        l.Display_pickup_point();
        
        if (!ALL_LINES.Next(&l))
        {
            return;
        }
        ALL_LINES.Return_Data(&l);

        counter++;
        x++;
    }

}
void delete_line(string name)
{
    Line l;
    ALL_LINES.go_head(&l);

    while (name != l.get_Line_point_Name() && ALL_LINES.Next(&l) != 0)
    {

        ALL_LINES.Return_Data(&l);
    }
    if (name == l.get_Line_point_Name())
    {
        ALL_LINES.delete_Data(&l);

    }
    else
    {
        cout << yellow("\n\tNOT FOUND") << endl;
    }
}
Line select_line()
{
    Line l;
    int n;
    view_all_lines();
    cout << "\nSelect Line: ";
    cin >> n;
    ALL_LINES.go_head(&l);
    for (int i = 1; i < n; i++)
    {
        ALL_LINES.Next(&l);
    }

    return l;
}


// ############# DRIVER IMPLEMENTATION ############# //
void add_driver(int user_choice)
{
    system("cls");
    int num_error = 0, limit_of_error = 3;
    string object_name, user_data;
    cin.ignore();// new page

    cout << "\nEnter driver name: ";
    cin >> object_name;
    user_data = object_name;
    driver d;
    d.set_name(user_data);


    while (num_error < limit_of_error)
    {
        cout << "\nEnter phone number: ";
        cin >> user_data;
        if (d.set_phone_number(user_data) == 1)
        {
            num_error = 0;
            break;
        }
        else if (num_of_error(0, num_error, limit_of_error) == -1)
        {
            num_error = 0;
            return;
        }

    }


    while (num_error < limit_of_error)
    {
        cout << "\nEnter Gender       (1- Male    2- Female)";
        user_choice = Select_from_to(1, 2);
        if (user_choice == 1)
        {
            d.set_gender("male");
            num_error = 0;
            break;
        }
        else if (user_choice == 2)
        {
            d.set_gender("female");
            num_error = 0;
            break;
        }
        else if (num_of_error(0, num_error, limit_of_error) == -1)
        {
            num_error = 0;
            return;
        }

    }


    while (num_error < limit_of_error)
    {
        cout << "\nEnter Age: ";
        cin >> user_data;
        if (d.set_age(user_data) == 1)
        {
            num_error = 0;
            break;
        }
        else if (num_of_error(0, num_error, limit_of_error) == -1)
        {
            num_error = 0;
            return;
        }

    }


    while (num_error < limit_of_error)
    {
        cout << "\nEnter National number: ";
        cin >> user_data;
        if (d.set_national_id(user_data) == 1)
        {
            num_error = 0;
            break;
        }
        else if (num_of_error(0, num_error, limit_of_error) == -1)
        {
            num_error = 0;
            return;
        }

    }

    // add the compnay to the obj from the sign in return
    d.set_password(d.get_phone_number());
    d.set_mail(d.get_name() + "@" /* + company obj username */ + "gu.edu.eg");

    cout << "\n\n ( Give this info to the driver! )";
    cout << "\n\tEmail is: " << d.get_mail() << "\tPassword is: " << d.get_password() << "\n\n";

    int key = d_t.convert_to_key(d.get_mail());
    d_t.Insert_Item(key, d);

}
void delete_driver(string mail) {
    driver d;
    int key = d_t.convert_to_key(mail);
}
void edit_driver(string mail) {

    static int counter1 = 0;
    static int counter2 = 0;
    int choice;
    driver d;
    view_driver(mail);
    cout << "\n\tChoose one to edit\n" << "1. Name\n" << endl << "2. Age\n" << endl << "3. National number\n" << "4. Password\n"
        << "5. Phone number";

    choice = Select_from_to(1, 5);
    switch (choice) {
    case 1:
    {
        string new_name;
        cout << d.get_mail() << "The Name is: " << d.get_name() << endl;
        cin >> new_name;
        d.set_name(new_name);
        cout << green("\n\nDone successfully\t") << "The new name is: " << d.get_name();
        break;
    }

    case 2: {
        string new_age;
        cout << d.get_mail() << "The Age is: " << d.get_age() << endl;
        cin >> new_age;
        d.set_age(new_age);
        cout << green("\n\nDone successfully\t") << "The new age is: " << d.get_age();
        break;
    }

    case 3:
    {
        if (counter1 == 0)
        {
            string new_National_id;
            cout << d.get_mail() << "The National number is: " << d.get_national_id();
            cin >> new_National_id;
            d.set_national_id(new_National_id);
            cout << green("\n\nDone successfully\t") << "The new National number is: " << d.get_national_id();
            break;
        }
        else cout << "Go to the university" << endl;
    }

    case 4:
    {
        if (counter2 == 0)
        {
            string cpass;
            string new_password;
            cout << d.get_mail() << "Enter the new Password: " << endl;
            cin >> new_password;

            cout << "Confirm Password : ";
            cin >> cpass;

            if (new_password == cpass)
            {
                d.set_password(new_password);
                break;
            }
            cout << green("Done successfully") << "The new Password is: " << d.get_password();

            break;

        }
        else cout << "Go to the university";
    }
    case 5: {
        string new_phone_number;
        cout << d.get_mail() << "The Phone number is " << d.get_phone_number() << endl;
        cin >> new_phone_number;
        d.set_phone_number(new_phone_number);
        cout << green("\n\nDone successfully\t") << "The new Phone number is: " << d.get_phone_number();
        break;
    }
    default: {
        cout << red("You choosed a wrong number..!");
        edit_driver(mail);

    }
    }



}
void view_driver(string mail) {
    driver d;
   // d = d_t.Search_Item(mail);
    cout << "Name: " << d.get_name() << endl;
    cout << "Age: " << d.get_age() << endl;
    cout << "National number: " << d.get_national_id() << endl;
    cout << "Gender: " << d.get_gender() << endl;
    cout << "Password: " << d.get_password() << endl;

}


// ############# BUS MENU IMPLEMENTATION ############# //
string max_bus(int passengers_count, double* cost) {
    string car;
    if (passengers_count <= high_s) {
        car = "\nHigh S";
        *cost = high_s_cost;
        return car;
    }
    else if (passengers_count == costar || (passengers_count > high_s && passengers_count < costar)) {
        car = "\nCoaster";
        *cost = costar_cost;
        return car;
    }
    else if (passengers_count == 2 * high_s || (passengers_count > costar && passengers_count < 2 * high_s)) {
        car = "\n2 High S";
        *cost = 2 * high_s_cost;
        return car;
    }

    else if (passengers_count == 2 * costar || (passengers_count > 2 * high_s && passengers_count < 2 * costar)) {
        car = "\n2 Coasters";
        *cost = 2 * costar_cost;
        return car;
    }
    else if (passengers_count == bus) {
        car = "\nBus";
        *cost = bus_cost;
        return car;
    }
    return car;
    
}
string bus_plus(int passengers_count, double* cost) {
    int count = 0;
    double car2_cost = 0;
    string  car;
    while (passengers_count >= bus) {
        passengers_count -= bus;
        count++;
    }
    if (passengers_count != 0) {
        string car2 = max_bus(passengers_count, &car2_cost);
        car = to_string(count) + "Bus and " + car2;
        *cost = (count * bus_cost) + (car2_cost);
    }
    else {
        car = to_string(count) + "Bus";
        *cost = count * bus_cost;
    }
    return car;
}
void add_bus() {
    Line l;
    Line temp_l;
    ALL_LINES.go_head(&l);
    double cost;
    int  passengers_count_go, passengers_count_come, passengers_count_both, passengers_count;
    while (true)
    {
        temp_l = l;
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
        ALL_LINES.delete_Data(&temp_l);
        ALL_LINES.Push_Back(l);
        if (ALL_LINES.Next( &l) == 0) {
            break;
        }

    }
}
void view_lines_buses()
{
    Line l;
    int x = 0;
    int counter = 1;
    ALL_LINES.go_head(&l);

    while (1)
    {
        cout << counter << " - ";
        l.Display_pickup_point();
        cout << l.get_carType();

        if (!ALL_LINES.Next(&l))
        {
            return;
        }
        ALL_LINES.Return_Data(&l);

        counter++;
        x++;
    }
}
void create_line_go()
{
    Queue q;
    pickup_point pickPoint;
    Line l;
    Line temp_l;
    linked_list<pickup_point> p;
    if (ALL_LINES.go_head(&l))
    {
        while (true)
        {
            p = l.get_linkedlist_pickup_point();
            if (p.go_head(&pickPoint))
            {
                while (true)
                {
                    if (pickPoint.get_count_go() != 0)
                    {
                        q.enQueue(pickPoint);
                        cout << pickPoint.get_pickup_point_Name() << endl;
                    }
                    if (p.Next(&pickPoint) == 0)
                    {
                        break;
                    }

                }
                l.set_reserved_go(q);
                ALL_LINES.delete_Data(&temp_l);
                ALL_LINES.Push_Back(l);
                if (ALL_LINES.Next(&l) == 0) {
                    break;
                }
            }
        }
    }


}
void create_line_come()
{
    Stack s;
    pickup_point pickPoint;
    Line l;
    Line temp_l;
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
        ALL_LINES.delete_Data(&temp_l);
        ALL_LINES.Push_Back(l);
        if (ALL_LINES.Next(&l) == 0) {
            break;
        }
    }
}
void view_line_go(Line l)
{

    Queue q = l.get_reserved_go();
    q.display();

}
void view_line_come(Line l)
{
    linked_list<pickup_point> p;
    Stack s = l.get_reserved_come();
    cout << "The trip road: " << endl;
    s.display();
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
        total = ((total_go + total_come) * 75) + (total_both * 120);
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
    system("cls");
    int id = 0;
    string phone_number;
    string name;
    string pass;
    string cpass;
    string e_mail;
    string national_id;
    Student s1;
    Student* check;
    int check_id;
    cout << "\nUser name: ";
    cin >> name;
    s1.set_name(name);
    s1.set_mail(name + "@gu.edu.eg");

    while (true)
    {
        cout << "\nID: ";
        cin >> id;
        check_id = id;
        check = s_t.Search_Item(id);
        if (check->get_id() == id)
        {
            cout << yellow("\n\tThis ID has been entered before..!");
        }
        else
        {
            s1.set_id(id);
            break;
        }
    }
    check = s_t.Search_Item(check_id);
        while (num_error < limit_of_error)
        {
            cout << "\nPassword : ";
            cin >> pass;
            cout << "\nConfirm Password : ";
            cin >> cpass;

            if (pass == cpass)
            {
                s1.set_password(pass);
                break;
            }
            else if (num_of_error(0, num_error, limit_of_error) == -1)
            {
                num_error = 0;
                return;
            }

            else if (pass != cpass) cout << red("\n\tPassword not matched..!");

        }


    while (true)
    {
        cout << "\nNational Number: ";
        cin >> national_id;
        if (check->get_national_id() == national_id)
        {
            cout << yellow("\n\tThis National Number has been entered before..!");
        }
        else 
        {
            if (s1.set_national_id(national_id) == 1) break;

        }
    }


    while (true)
    {
        cout << "\nPhone Number: ";
        cin >> phone_number;
        if (check->get_phone_number() == phone_number)
        {
            cout << yellow("\n\tThis Phone Number has been entered before..!");
        }
        else
        {
            if (s1.set_phone_number(phone_number) == 1) break;
        }
    }


    s_t.Insert_Item(s1.get_id(), s1);
    system("cls");
}


// ############# SIGNUP COMPANY IMPLEMENTATION ############# //
void signup_company()
{
    system("cls");

    int id;
    string phone_number;
    string name;
    string pass;
    string cpass;
    string e_mail;
    string national_id;
    company s1, *check;
    check = c_t.Search_Item(s1.get_email());

    while (true)
    {
        cout << "Username: ";
        cin >> name;
        if (check->get_name() == name)
        {
            cout << yellow("\n\tThis Username has been entered before..!");
        }
        else
        {
            s1.set_name(name);
            break;
        }
    }


    while (1)
    {
        cout << "Password: ";
        cin >> pass;
        cout << "Confirm Password: ";
        cin >> cpass;

        if (pass == cpass)
        {
            s1.set_pass(pass);
            break;
        }

    }

    while (true)
    {
        cout << "Email: ";
        cin >> e_mail;
        if (check->get_email() == e_mail)
        {
            cout << yellow("\n\tThis Email has been entered before..!");
        }
        else
        {
            s1.set_email(e_mail);
            break;
        }
    }

    while (true)
    {
        cout << "Phone number: ";
        cin >> phone_number;
        if (check->get_phone_number() == phone_number)
        {
            cout << yellow("\n\tThis Phone Number has been entered before..!");
        }
        else
        {
            s1.set_phone_number(phone_number);
            break;
        }
    }

    int key = c_t.convert_to_key(s1.get_email());
    c_t.Insert_Item(key, s1);

}


// ############# LOGIN STUDENT IMPLEMENTATION ############# //
int login_student(Student* s)
{
    system("cls");
    int id;
    string pass;

    cout << "\n\tEnter your id: ";
    cin >> id;
    cout << "\n\tEnter your password: ";
    cin >> pass;
    s = s_t.Search_Item(id);

    if (s->get_password() == pass)
    {
        return 1;
    }
    else
    {
        return 0;
        main_menue();
    }

}


// ############# LOGIN COMPANY IMPLEMENTATION ############# //
int login_company(company* c)
{
    system("cls");
    string id = "company", id_ent;
    string pass = "123", pass_ent;

    cout << "\nEnter the Username: ";
    cin >> id_ent;
    cout << "\nEnter the Password: ";
    cin >> pass_ent;
    
    if (id_ent == id && pass_ent == pass)
    {
        return 1;
    }

}


// ############# BOOKING IMPLEMENTATION ############# //
void booking_ticket(Student* s)
{
    int user_choice;
    Student* s1 = s_t.Search_Item(s->get_id());
    student_ticket t1;
    pickup_point p1;
    Line l1;
    pickup_point temp_p;
    Line temp_l;
    int x;

    company c;

    linked_list<pickup_point> allp;
    if (line_counter == 0)
    {
        cout << yellow("There is no Lines yet..!");
        return;
    }
    l1 = select_line();
    temp_l = l1;
    allp = l1.get_linkedlist_pickup_point();
    p1= l1.select_pickup_point(&x);
    cout << x;
    temp_p = p1;
    

    cout << "\nEnter your trip statues : (1- One way (From town)     2- One way (From university)    3- Round trip) \n";
    user_choice = Select_from_to(1, 3);
    if (user_choice == 1)
    {
        p1.set_count_go();
        l1.set_count_go();
        t1.set_stident_ticket_price(75);
    }
    else if (user_choice == 2)
    {
        p1.set_count_come();
        l1.set_count_come();
        t1.set_stident_ticket_price(75);

    }
    else if (user_choice == 3)
    {
        p1.set_count_both();
        l1.set_count_both();
        t1.set_stident_ticket_price(120);
    }

    cout << p1.get_count_go() << endl << l1.get_count_go() << endl;



   allp.Push_between_B(x, p1);

    l1.set_linked_list_points(allp);

    ALL_LINES.delete_Data(&temp_l);

    ALL_LINES.Push_Back(l1);

    t1.set_student_ticket_line(l1);
    t1.set_student_ticket_company(c);
    t1.set_student_ticket_pickup_point(p1);
    
    s1->add_student_ticket(t1);



    t1.print_ticket();



    s_t.Insert_Item(s1->get_id(), *s1);
    s_t.Student_Delete_Item(s1->get_id());


}


// ############# SELECT COMPANY ############# //
company select_company()
{
    string x;
     company* c1;
    int choise;

    ALL_COMPANYS.go_head(&x);
    cout << "\nChoose the company you want to go with: ";
    while (true)
    {
        ALL_COMPANYS.Return_Data(&x);
        c1 = c_t.Search_Item(x);
        cout << c1->get_name();
        if (!ALL_COMPANYS.Next(&x))
        {
            break;
        }
    }

    cin >> choise;
    ALL_COMPANYS.go_head(&x);
    for (int i = 0; i < choise; i++)
    {
        ALL_COMPANYS.Next(&x);
    }
    c1 = c_t.Search_Item(x);

    return *c1;
}


// ############# STUDENT MENU ############# //
void student_menue(Student* s)
{
    student_ticket t;

    while (true)
    {
       
        int user_choice;
        cout << "\n.................. MAIN MENU ..................";
        cout << "\n\n\t1) Book a ticket\n"
             << "\t2) View your ticket\n"
             << "\t3) Edit your Info\n"
             << "\t4) View profile\n" 
             << "\t5) Log out\n\n" 
             << "YOUR CHOICE ->   ";

        user_choice = Select_from_to(1, 5);
        Student* s1 = s_t.Search_Item(s->get_id());
        switch (user_choice)
        {
        case 1:
        {
            system("cls");
            booking_ticket(s1);
            break;
        }
        case 2:
        {
            system("cls");
            s1->print_student_ticket();
           
            break;
        }
        case 3:
        {
            system("cls");
            edit_student(s1);
            break;
        }
        case 4:
        {
            system("cls");
            s1->class_print_Student();
            break;
        }
        case 5:
        {
            system("cls");
            main_menue();
            break;
        }


        default:
            break;
        }
    }
}


// #############  COMPANY MENU ############# //
void company_menue(company* c)
{
    while (true)
    {
        Line l;

        int user_choice;
        cout << "\n.................. COMPANY MENU ..................";
        cout << "\n\n\t1) View line buses\n"
             << "\t2) Students counter  \n"
             << "\t3) View lines trips\n" 
             << "\t4) Trip(from uni to cairo)\n" 
             << "\t5) Trip(from cairo to uni)\n"
             << "\t6) Log out\n\n" 
             << "YOUR CHOICE ->   ";

        user_choice = Select_from_to(1, 6);


        switch (user_choice)
        {
        case 1:
        {
            system("cls");
            add_bus();
            view_lines_buses();
            break;
        }
        case 2:
        {
            system("cls");
            view_all_lines();
            break;
        }
        case 3:
        {
            system("cls");
            create_line_go();
            l = select_line();
            view_line_come(l);
            break;
        }
        case 4:
        {            
        l = select_line();
        view_line_come(l);

        cout << endl << endl;
        create_line_come();
        break;
        }
        case 5:
        {
            system("cls");
            l = select_line();
            view_line_come(l);
            cout << endl << endl;
            create_line_go();
                break;
        }
        case 6:
        {
            system("cls");
            main_menue();
            break;
        }


        default:
            break;
        }
    }
}


// ############# UNIVERSITY MENU ############# //
void university_menue()
{
    while (true)
    {

        int user_choice;
        cout << "\n.................. ADMIN MENU ..................";
        cout << "\n\n\t1) Company menu\n"
             << "\t2) Line menu\n" 
             << "\t3) View student\n"
             << "\t4) Back\n\n" 
             << "YOUR CHOICE ->   ";

        user_choice = Select_from_to(1, 4);

        switch (user_choice)
        {
        case 1:
        {
            system("cls");
            Admin_company();
            break;
        }
        case 2:
        {
            system("cls");
            Admin_Line();
            break;
        }
        case 3:
        {
            system("cls");
            view_all_students();
            break;
        }
        case 4:
        {
            system("cls");
            main_menue();
            break;
        }

        default:
            break;
        }
    }
}
void Admin_company()
{
    while (true)
    {


        int user_choice;
        cout << "\n.................. COMPANY MENU ..................";
        cout << "\n\n\t1) Add company\n"
             << "\t2) Edit company\n"
             << "\t3) View all companys\n"
             << "\t4) Back\n\n"
             << "YOUR CHOICE ->   ";

        user_choice = Select_from_to(1, 4);

        switch (user_choice)
        {
        case 1:
        {
            system("cls");
            add_company();
            break;
        }
        case 2:
        {
            system("cls");
            edit_company();
            break;
        }
        case 3:
        {
            system("cls");
            view_companys();
            break;
        }
        case 4:
        {
            system("cls");
            return;
            break;
        }
        default:
            break;
        }
    }
}
void Admin_Line()
{
    while (true)
    {


        int user_choice;
        cout << "\n.................. Line MENU ..................";
        cout << "\n\n\t1) Add Line\n"
            << "\t2) Edit Line\n"
            << "\t3) View all Line\n"
            << "\t4) Back\n\n"
            << "YOUR CHOICE ->   ";
        user_choice = Select_from_to(1, 4);

        switch (user_choice)
        {
        case 1:
        {
            system("cls");
            add_line();
            break;
        }
        case 2:
        {
            system("cls");
            edit_line();
            break;
        }
        case 3:
        {
            system("cls");
            view_all_lines();
            break;
        }
        case 4:
        {
            system("cls");
            return;
            break;
        }
        default:
            break;
        }
    }
}


// ############# TOOLS ############# //
int Select_from_to(int start, int end)
{
    int select, counter = 0;
    //cout << "Select one of them" << endl;
    while (counter != 3)
    {
        cin >> select;
        for (int i = start; i <= end; i++)
        {
            if (select == i)
            {
                return select;
            }
        }
        if (counter != 2)
        {
            cout << red("\n\nWrong Selection..!") << endl;
            cout << "\nPlease Select Number from ( " << start << " ) To " << "( " << end << " )" << endl;
        }
        else
        {
            cout << red("\n\nWrong Selection..!") << endl;
        }
        counter++;
    }
    select = -1;
    return select;
}
int num_of_error(int error, int& counter, int limit_of_error)
{
    if (error == 0)
    {
        counter++;
    }
    else
    {
        counter = limit_of_error + 1;
        return counter;
    }
    if (counter == limit_of_error)
    {
        cout << red("\n\tToo much wrong entries...!") << endl;
        return -1;
    }

}
void main_menue()
{
    int user_choice;
    cout << "\n.................. MAIN MENU ..................";
    cout << "\n\n\t1) Login\n"
        << "\t2) Signup\n\n"
        << "YOUR CHOICE ->   ";
    user_choice = Select_from_to(1, 2);

    switch (user_choice)
    {
    case 1:
    {
        system("cls");
        log_menue();
        break;
    }
    case 2:
    {
        system("cls");
        signup_student();
        break;
    }
    default:
        break;
    }



}
int login_uni()
{
    system("cls");

    string admin_user = "admin";
    string pass_admin = "admin";
    string u, p;
    cout << "\tEnter the username: ";
    cin >> u;
    cout << "\tEnter the Password: ";
    cin >> p;


    if (u == admin_user && p == pass_admin)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}
void log_menue()
{
    Student s;
    company c;
    driver d;


    int user_choice;
    cout << "\n.................. Login MENU ..................";
    cout << "\n\n\t1) Login as student\n"
        << "\t2) Login as company\n"
        << "\t3) Login as admin\n"
        << "\t4) Back\n\n"
        << "YOUR CHOICE ->   ";
    user_choice = Select_from_to(1, 4);

    switch (user_choice)
    {
    case 1:
    {
        if (login_student(&s))
        {
            system("cls");
            student_menue(&s);
        }
        else
        {
            cout << red("\t\nWrong password or username..!\n");
            delay(3);
            system("cls");
            break;
        }

    }
    case 2:
    {
        if (login_company(&c) == 1)
        {
            system("cls");
            company_menue(&c);
            break;
        }
        else
        {
            cout << red("\t\nWrong password or username..!\n");
            delay(3);
            system("cls");
            break;
        }
    }
   
    case 3:
    {
        if (login_uni())
        {
            system("cls");
            university_menue();
            break;
        }
        else
        {
            cout << red("\t\nWrong password or username..!\n");
            delay(3);
            system("cls");
            break;
        }
    }
    case 4:
    {
        system("cls");
        main_menue();
        break;
    }
    default:
        break;
    }

}
