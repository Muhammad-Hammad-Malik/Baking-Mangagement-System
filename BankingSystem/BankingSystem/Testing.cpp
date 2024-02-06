#include <iostream>
#include "sqlite3.h"
#include <sstream>
#include <ctime>
using namespace std;
// ________________________________________________________________________________________
// ________________________________________________________________________________________
// ________________________________________________________________________________________

int currentUser;

string IntToStringConvert(int x)
{
    stringstream ss;
    ss << x;
    string st = ss.str();
    return st;
}

string getCurrentDateAsString() 
{
    time_t now = time(nullptr);
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeinfo);
    return string(buffer);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
struct QueueNode {
    int sender;
    int receiver;
    int amount;
    string date;
    QueueNode* next;

    QueueNode(int s, int r, int a, const string& d) : sender(s), receiver(r), amount(a), date(d), next(nullptr) {}
};

// Queue implementation
class CustomQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    CustomQueue() : front(nullptr), rear(nullptr) {}
    void enqueue(int sender, int receiver, int amount, const string& date) 
    {
        QueueNode* newNode = new QueueNode(sender, receiver, amount, date);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() 
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue.\n";
        }
        else
        {
            QueueNode* temp = front;
            front = front->next;

            if (front == nullptr)
            {
                rear = nullptr;
            }
            delete temp;
        }
    }

    QueueNode* getFront()
    {
        return front;
    }
    bool isEmpty() 
    {
        return front == nullptr;
    }
    void deleteAllNodes() 
    {
        while (front != nullptr) 
        {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr; 
    }
    void printAll()
    {
        QueueNode* current = front;
        if (isEmpty())
        {
            return;
        }
        cout << "The Transections are following:" << endl;
        while (current != nullptr) 
        {
            cout << "Sender: " << current->sender << ", Receiver: " << current->receiver
                << ", Amount: " << current->amount << ", Date: " << current->date << endl;
            current = current->next;
        }
    }
    void printUser()
    {
        QueueNode* current = front;
        if (isEmpty())
        {
            return;
        }
        cout << "The Transections are following:" << endl;
        while (current != nullptr)
        {
            if ((currentUser == current->sender) || (currentUser == current->receiver))
            {
                cout << "Sender: " << current->sender << ", Receiver: " << current->receiver
                    << ", Amount: " << current->amount << ", Date: " << current->date << endl;
                
            }
            current = current->next;
        }
    }
};

CustomQueue myQueue;


// _________________________________________________________________________________________
// _________________________________________________________________________________________
// _________________________________________________________________________________________

struct LoanNode 
{
    int sender;
    int amount;
    string date;
    LoanNode* next;
    LoanNode(int sender, int amount, const string& date) : sender(sender), amount(amount), date(date), next(nullptr) {}
};

class CustomQueue2 {
private:
    LoanNode* front;
    LoanNode* rear;
    int size;
public:
    CustomQueue2() : front(nullptr), rear(nullptr) 
    {
        size = 0;
    }

    void enqueue(int sender, int amount, const string& date) 
    {
        LoanNode* newNode = new LoanNode(sender, amount, date);
        size++;
        if (isEmpty()) 
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeueAll()
    {
        for (int a = 0; a < size; a++)
        {
            dequeue();
        }
    }
    int getSize()
    {
        return size;
    }
    void printAll() 
    {
        LoanNode* current = front;
        cout << "Queue Contents:" << endl;
        while (current != nullptr) 
        {
            cout << "Sender: " << current->sender << ", Amount: " << current->amount
                << ", Date: " << current->date << endl;
            current = current->next;
        }
    }
    void dequeue() 
    {
        size--;
        if (!isEmpty())
        {
            LoanNode* temp = front;
            front = front->next;
            delete temp;

            if (front == nullptr)
            {
                rear = nullptr;
            }
        }
        else
        {
            cout << "Queue is empty, cannot dequeue." << endl;
        }
    }

    LoanNode* peek()  
    {
        return front;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    ~CustomQueue2() 
    {
        while (!isEmpty()) 
        {
            dequeue();
        }
    }
};

CustomQueue2 LoanQueue;
//__________________________________________________________________________________________
//__________________________________________________________________________________________
//__________________________________________________________________________________________
struct Node 
{
    int accountNo;
    string firstName;
    string lastName;
    int deposit;
    string password;
    Node* next;
};

class LinkedList 
{
private:
    Node* head;
    int size;

public:
    LinkedList() 
    {
        size = 0;
        head = nullptr;
    }
    void insertNode(int accNo, string fName, string lName, int dep, string pass) 
    {
        Node* newNode = new Node;
        newNode->accountNo = accNo;
        newNode->firstName = fName;
        newNode->lastName = lName;
        newNode->deposit = dep;
        newNode->password = pass;
        newNode->next = head;
        head = newNode;
        size++;
    }
    void deleteAllNodes() 
    {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        size = 0;
    }
    int getsize()
    {
        return size;
    }
    void displayList() 
    {
        Node* temp = head;
        if (temp == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Account Details:" << endl;
        while (temp != nullptr) 
        {
            cout << "Account No: " << temp->accountNo << endl;
            cout << "First Name: " << temp->firstName << endl;
            cout << "Last Name: " << temp->lastName << endl;
            cout << "Deposit: " << temp->deposit << endl;
            cout << "--------------------" << endl;
            temp = temp->next;
        }
    }
    Node* searchNode(int accNo) 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            if (temp->accountNo == accNo)
            {
                return temp;
            }
            temp = temp->next;
        }
        cout << "Node not found." << endl;
        return nullptr;
    }
    bool searchAccount(int accNo)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->accountNo == accNo)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    bool LogInStatus(int accountno1 , int pass)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->accountNo == accountno1 && temp->password == IntToStringConvert(pass))
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
        
    }
};

LinkedList accounts;

// _________________________________________________________________________________________
// -----------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------

class hashTable
{
public:

    hashTable()
    {

    }
    int hashString(int input) 
    {
        int hashValue = input * 7; 
        hashValue = hashValue / 3; 
        hashValue = hashValue + 11; 

        return hashValue;
    }
};

// _________________________________________________________________________________________
// -----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------
struct StackNode
{
    int sender;
    string message;
    StackNode* next;
    StackNode(int sender, const string& message) : sender(sender), message(message), next(nullptr)
    {

    }
};

class CustomStack 
{
private:
    StackNode* topNode;
    int stackSize;

public:
    CustomStack() : topNode(nullptr), stackSize(0) 
    {

    }

    void push(int sender, const string& message) 
    {
        StackNode* newNode = new StackNode(sender, message);
        newNode->next = topNode;
        topNode = newNode;
        stackSize++;
    }

    void pop() 
    {
        if (!isEmpty())
        {
            StackNode* temp = topNode;
            topNode = topNode->next;
            delete temp;
            stackSize--;
        }
        else
        {
            cout << "Stack is empty, cannot pop." << endl;
        }
    }

    StackNode* top() 
    {
        return topNode;
    }

    bool isEmpty()
    {
        return topNode == nullptr;
    }

    int size()
    {
        return stackSize;
    }

    ~CustomStack() 
    {
        while (topNode != nullptr) 
        {
            StackNode* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

CustomStack stack;
//_________________________________________________________________________________________
//_________________________________________________________________________________________
//_________________________________________________________________________________________
void fillStackFromDatabase(sqlite3* db) 
{
    string sql = "SELECT sender, message FROM suggestions";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) 
    {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) 
    {
        int sender = sqlite3_column_int(stmt, 0);
        const unsigned char* message = sqlite3_column_text(stmt, 1);
        stack.push(sender, message ? reinterpret_cast<const char*>(message) : "");
    }
    if (rc != SQLITE_DONE) 
    {
        cout << "Error retrieving data: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}

void insertIntoComplaintTable(sqlite3* db, int sender, const string& message) 
{
    string sql = "INSERT INTO suggestions (sender, message) VALUES (?, ?)";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }
    sqlite3_bind_int(stmt, 1, sender);
    sqlite3_bind_text(stmt, 2, message.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        cout << "Error inserting data into Complaint table: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt);
}

void populateQueueFromDatabase(sqlite3* db)
{
    myQueue.deleteAllNodes(); 
    string sql = "SELECT sender, receiver, amount, date FROM TransectionHistory";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int sender = sqlite3_column_int(stmt, 0);
        int receiver = sqlite3_column_int(stmt, 1);
        int amount = sqlite3_column_int(stmt, 2);
        string date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        myQueue.enqueue(sender, receiver, amount, date);
    }
    if (rc != SQLITE_DONE) {
        cout << "Error retrieving data: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}



void insertAccount(sqlite3* db, string FirstName, string LastName,int Deposit , int Password)
{
    hashTable hash;
    string deposit = IntToStringConvert(Deposit);
    int password1 = hash.hashString(Password);
    string password = IntToStringConvert(password1);
    cout << password1;
    char* errorMessage = nullptr;
    string sql = "INSERT INTO Account (FirstName, LastName, Deposit, Password) VALUES ('" + FirstName + "', '" + LastName + "', " + deposit + ", " + (password) + ")";
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errorMessage);
    if (rc != SQLITE_OK)
    {
        cout << "Error executing SQL: " << errorMessage << endl;
        sqlite3_free(errorMessage); 
        return;
    }
}

void insertIntoLoanTable(sqlite3* db, int sender, int amount, const string& date) 
{
    string sql = "INSERT INTO Loan (sender, amount, date) VALUES (?, ?, ?)";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }
    sqlite3_bind_int(stmt, 1, sender);
    sqlite3_bind_int(stmt, 2, amount);
    sqlite3_bind_text(stmt, 3, date.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) 
    {
        cout << "Error inserting data into Loan table: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}

void insertFromDatabase(sqlite3* db) 
{
    accounts.deleteAllNodes();
    string sql = "SELECT * FROM Account";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) 
    {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) 
    {
        int accountNo = sqlite3_column_int(stmt, 0);
        string firstName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        string lastName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int deposit = sqlite3_column_double(stmt, 3);
        string password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        accounts.insertNode(accountNo, firstName, lastName, deposit, password);
    }
    if (rc != SQLITE_DONE) 
    {
        cout << "Error retrieving data: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}
void SendMoney(sqlite3* db)
{
    insertFromDatabase(db);
    int acc;
    Node *obj=accounts.searchNode(currentUser);
    cout << "enter the accountno to send to " << endl;
    cin >> acc;
    if (!accounts.searchAccount(acc))
    {
        cout << "NO ACCOUNT FOUND TRANSECTION FAILED" << endl;
        return;
    }
    int amount;
    cout << "how much do you want to send current balance is "<<obj->deposit << endl;
    cin >> amount;
    if (amount > obj->deposit)
    {
        cout << "INSUFFICENT BALANCE TRANSECTION FAILED" << endl;
        return;
    }
    string senderAccountNo = IntToStringConvert(currentUser);
    string receiverAccountNo = IntToStringConvert(acc);
    string amountx = IntToStringConvert(amount);
    string sqlSender = "UPDATE Account SET Deposit = Deposit - " + amountx + " WHERE AccountNo = " + senderAccountNo;
    int rcSender = sqlite3_exec(db, sqlSender.c_str(), nullptr, 0, nullptr);
    string sqlReceiver = "UPDATE Account SET Deposit = Deposit + " + amountx + " WHERE AccountNo = " + receiverAccountNo;
    int rcReceiver = sqlite3_exec(db, sqlReceiver.c_str(), nullptr, 0, nullptr);
    string currentDate = getCurrentDateAsString();
    string sqlTransaction = "INSERT INTO TransectionHistory (sender, receiver, amount, date) VALUES ('" + senderAccountNo + "', '" + receiverAccountNo + "', " + amountx + ", '" + currentDate + "')";
    int rcTransaction = sqlite3_exec(db, sqlTransaction.c_str(), nullptr, 0, nullptr);
    
}
void CreateAccount(sqlite3* db)
{
    string fname;
    string lname;
    int deposit;
    int password;
    cout << "enter your first name " << endl;
    cin >> fname;
    cout << "enter your last name " << endl;
    cin >> lname;
    cout << "enter the amount to initially deposit" << endl;
    cin >> deposit;
    cout << "enter your password" << endl;
    cin >> password;
    insertAccount(db, fname, lname, deposit, password);
    insertFromDatabase(db);
    cout << endl << endl << " YOUR ACCOUNT NUMBER IS " << accounts.getsize()<<endl<<endl;
    system("pause");
}
void printLoanDataForUser(sqlite3* db)
{
    string sql = "SELECT sender, amount, date FROM Loan WHERE sender = ?";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) 
    {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }
    sqlite3_bind_int(stmt, 1, currentUser);
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) 
    {
        int sender = sqlite3_column_int(stmt, 0);
        int amount = sqlite3_column_int(stmt, 1);
        const unsigned char* date = sqlite3_column_text(stmt, 2);
        cout << "Sender: " << sender << ", Amount: " << amount
            << ", Date: " << (date ? reinterpret_cast<const char*>(date) : "NULL") << endl;
    }
    if (rc != SQLITE_DONE) 
    {
        cout << "Error retrieving data: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}


void DisplayClientMenu()
{
    cout << "Menu:\n";
    cout << "1. Create Account\n";
    cout << "2. Log In\n";
    cout << "3. exit\n";
}
void DisplayLoggedClientMenu()
{
    cout << "Menu:\n";
    cout << "1. Send Money\n";
    cout << "2. View Transection History\n";
    cout << "3. Apply for loan\n";
    cout << "4. Lodge Complaint\n";
    cout << "5. View Loan Status\n";
    cout << "6. Check Lottery Winners\n";
    cout << "7. Check Balance\n";
    cout << "8. Exit\n";
}
void ShowLotteryWinners(sqlite3* db) 
{
    cout << "THE LOTTERY WINNERS ARE " << endl;
    string sql = "SELECT AccountNo, FirstName, LastName, Date FROM lottery";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) 
    {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) 
    {
        int accountNo = sqlite3_column_int(stmt, 0);
        const unsigned char* firstName = sqlite3_column_text(stmt, 1);
        const unsigned char* lastName = sqlite3_column_text(stmt, 2);
        const unsigned char* date = sqlite3_column_text(stmt, 3);
        cout << "AccountNo: " << accountNo << ", First Name: " << (firstName ? reinterpret_cast<const char*>(firstName) : "NULL")
            << ", Last Name: " << (lastName ? reinterpret_cast<const char*>(lastName) : "NULL")
            << ", Date: " << (date ? reinterpret_cast<const char*>(date) : "NULL") << endl;
    }

    if (rc != SQLITE_DONE) 
    {
        cout << "Error retrieving data: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}

void ShowUserTransections(sqlite3* db)
{
    populateQueueFromDatabase(db);
    myQueue.printUser();

}
void CheckBalance(sqlite3* db)
{
    insertFromDatabase(db);
    Node *record = accounts.searchNode(currentUser);
    cout << endl <<"remaining balance : "<< record->deposit << endl;
}
void ApplyForLoan(sqlite3* db)
{
    insertFromDatabase(db);
    Node* user = accounts.searchNode(currentUser);
    int amount = user->deposit;
    insertIntoLoanTable(db, currentUser, amount, "pending");
    cout << "successfully applied for loan" << endl;
}
void SubmitComplaint(sqlite3* db)
{
    string message;
    cout << "enter the complaint message ";
    cin.ignore();
    getline(cin, message);
    insertIntoComplaintTable(db, currentUser, message);
}
void LoggedInMenu(sqlite3* db)
{
    int choice;
    bool exitMenu = false;

    while (!exitMenu)
    {
        DisplayLoggedClientMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Initiating Money Transfer\n";
            SendMoney(db);
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Here are all your transections\n";
            ShowUserTransections(db);
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Applying for loan\n";
            ApplyForLoan(db);
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Preparing to submit complaint\n";
            SubmitComplaint(db);
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Here are the lottery winners\n";
            printLoanDataForUser(db);
            system("pause");
            system("cls");
            break;
        case 6:
            cout << "Displaying account balance\n";
            ShowLotteryWinners(db);
            system("pause");
            system("cls");
            break;
        case 7:
            cout << "Exitting\n";
            CheckBalance(db);
            system("pause");
            system("cls");
            break;
        case 8:
            cout << "You selected Option 3\n";
            exitMenu = true;
            system("pause");
            system("cls");
            break;
        default:
            cout << "Invalid choice.\n";
            system("pause");
            system("cls");
            break;
        }
    }
}
void LogIn(sqlite3* db)
{
    insertFromDatabase(db);
    cout << "enter your account no" << endl;
    int account;
    cin >> account;
    cout << "enter your password" << endl;
    int password;
    cin >> password;
    hashTable hash1;
    int pass = hash1.hashString(password);
    if (accounts.LogInStatus(account, pass))
    {
        currentUser = account;
        cout << "Log IN Success" << endl;
        LoggedInMenu(db);
        system("pause");
    }
    else
    {
        cout << "failure incorrect credentials or account does not exist" << endl;
    }

}
void ClientSide(sqlite3* db)
{
    int choice;
    bool exitMenu = false;

    while (!exitMenu) 
    {
        DisplayClientMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Initiating SIGN UP\n";
                CreateAccount(db);
                system("pause");
                system("cls");
                break;
            case 2:
                cout << "Initiating LOG IN\n";
                LogIn(db);
                system("pause");
                system("cls");
                break;
            case 3:
                cout << "EXITTING\n";
                exitMenu = true;
                system("pause");
                system("cls");
                break;
            default:
                cout << "Invalid choice.\n";
                system("pause");
                system("cls");
                break;
        }
    }
}


//========================================================================================
//========================================================================================
//========================================================================================

void ShowAllAccounts(sqlite3* db)
{
    insertFromDatabase(db);
    accounts.displayList();
}

void ShowAllComplaints(sqlite3* db)
{
    StackNode* node;
    fillStackFromDatabase(db);
    int x = stack.size();
    for (int a = 0; a < x; a++)
    {
        node = stack.top();
        cout <<"account no: "<< node->sender << endl;
        cout << "Message: " << node->message << endl;
        cout << "______________________________________" << endl;
        stack.pop();
    }
}
void refillLoanTableFromQueue(sqlite3* db) 
{
    string clearSql = "DELETE FROM Loan";
    char* errMsg;
    int rc = sqlite3_exec(db, clearSql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) 
    {
        cout << "Error clearing table: " << errMsg << endl;
        sqlite3_free(errMsg);
        return;
    }
    LoanNode* current = LoanQueue.peek();
    while (current != nullptr) 
    {
        string sender =IntToStringConvert(current->sender);
        string amount = IntToStringConvert(current->amount);
        string data = current->date;
        string refillSql = "INSERT INTO Loan (sender, amount, date) VALUES ('" +
            sender + "', '" +
            amount + "', '" +
            data + "')";
        rc = sqlite3_exec(db, refillSql.c_str(), nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) 
        {
            cout << "Error refilling table: " << errMsg << endl;
            sqlite3_free(errMsg);
            return;
        }
        current = current->next;
    }
}


void populateLoanQueueFromDatabase(sqlite3* db) {
    string sql = "SELECT sender, amount, date FROM Loan WHERE date = 'pending'";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int sender = sqlite3_column_int(stmt, 0);
        int amount = sqlite3_column_int(stmt, 1);
        const unsigned char* date = sqlite3_column_text(stmt, 2);
        string strDate = date ? reinterpret_cast<const char*>(date) : "";
        LoanQueue.enqueue(sender, amount, strDate);
    }

    if (rc != SQLITE_DONE) {
        cout << "Error retrieving data: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt);
}


void SetLoanStatus(sqlite3* db)
{
    LoanQueue.dequeueAll();
    populateLoanQueueFromDatabase(db);
    LoanNode* node;
    string response;
    int x = LoanQueue.getSize();
    for (int a = 0; a < x; a++)
    {
        node = LoanQueue.peek();
        cout << "Requester : " << node->sender << "amount " << node->amount << endl;
        cout << "enter Y to accept , enter anything else to reject " << endl;
        cin >> response;
        if (response == "Y")
        {
            LoanQueue.enqueue(node->sender, node->amount, "Accepted");
            string amountx = IntToStringConvert(node->amount);
            string receiverAccountNo = IntToStringConvert(node->sender);
            string sqlReceiver = "UPDATE Account SET Deposit = Deposit + " + amountx + " WHERE AccountNo = " + receiverAccountNo;
            int rcReceiver = sqlite3_exec(db, sqlReceiver.c_str(), nullptr, 0, nullptr);
        }
        else
        {
            LoanQueue.enqueue(node->sender, node->amount, "Rejected");
        }
        LoanQueue.dequeue();
    }
    refillLoanTableFromQueue(db);
}

void insertIntoLotteryTable(sqlite3* db, int accountNo, const string& firstName, const string& lastName, const string& date) 
{
    string sql = "INSERT INTO lottery (AccountNo, FirstName, LastName, Date) VALUES (?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) 
    {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }
    sqlite3_bind_int(stmt, 1, accountNo);
    sqlite3_bind_text(stmt, 2, firstName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, lastName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, date.c_str(), -1, SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) 
    {
        cout << "Error inserting data into lottery table: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
}


void conductLottery(sqlite3* db)
{
    insertFromDatabase(db);
    int size = accounts.getsize();
    srand(time(0));
    int winner = rand() % size;
    winner++;
    Node* node = accounts.searchNode(winner);
    string receiverAccountNo = IntToStringConvert(winner);
    string amountx = IntToStringConvert(10000);
    string sqlReceiver = "UPDATE Account SET Deposit = Deposit + " + amountx + " WHERE AccountNo = " + receiverAccountNo;
    int rcReceiver = sqlite3_exec(db, sqlReceiver.c_str(), nullptr, 0, nullptr);
    int accountNo = winner;
    string FirstName = node->firstName;
    string LastName = node->lastName;
    string date = getCurrentDateAsString();
    insertIntoLotteryTable(db, accountNo, FirstName, LastName, date);
    insertFromDatabase(db);
    cout << "THE LOTTERY WINNER IS " << accountNo << " 10000 has been deposited in account" << endl;
}


void DisplayBankerInterfaceMenu()
{
    cout << "Menu:\n";
    cout << "1. See All Accounts\n";
    cout << "2. See All Complaints\n";
    cout << "3. See All Transections\n";
    cout << "4. Review All Pending Loan Applications\n";
    cout << "5. Conduct a Lottery Session\n";
    cout << "6. Exit\n";
}
void BankerInterface(sqlite3* db)
{
    int choice;
    bool exitMenu = false;
    while (!exitMenu)
    {
        DisplayBankerInterfaceMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "here are all the accounts\n";
            ShowAllAccounts(db);
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "here are all the complaints\n";
            ShowAllComplaints(db);
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "here are all the transections\n";
            populateQueueFromDatabase(db);
            myQueue.printAll();
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "here are all the loan requests\n";
            SetLoanStatus(db);
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "conducting lottery\n";
            conductLottery(db);
            system("pause");
            system("cls");
            break;
        case 6:
            cout << "EXITTING\n";
            exitMenu = true;
            system("pause");
            system("cls");
            break;
        default:
            cout << "Invalid choice.\n";
            system("pause");
            system("cls");
            break;
        }
    }
}


void DisplayInterfaceMenu()
{
    cout << "Menu:\n";
    cout << "1. ClientSide\n";
    cout << "2. BankSide\n";
    cout << "3. Exit\n";
}


void MainInterface(sqlite3* db)
{
    int password = 1234;
    int inputPassword;
    int choice;
    bool exitMenu = false;

    while (!exitMenu)
    {
        DisplayInterfaceMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "CUSTOMER INTERFACE\n";
            ClientSide(db);
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "SIGN IN AS BANK \n";
            cout << "enter the password " << endl;
            cin >> inputPassword;
            if (inputPassword == password)
            {
                cout << "LOGGED IN AS BANKER \n";
                BankerInterface(db);
            }
            else
            {
                cout << "You have entered the Wrong password" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "EXITTING\n";
            exitMenu = true;
            system("pause");
            system("cls");
            break;
        default:
            cout << "Invalid choice.\n";
            system("pause");
            system("cls");
            break;
        }
    }
}
int main() 
{
    sqlite3* db;
    const char* dbPath = "D:/VS/source/repos/BankingSystem/BankingSystem/Bank.db"; 
    int rc = sqlite3_open(dbPath, &db);
    MainInterface(db);
    sqlite3_close(db);
    return 0;
}
