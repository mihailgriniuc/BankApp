#include <iostream>
#include <fstream>
#include <String>
#include <filesystem>
#include <Windows.h>

using namespace std;

void mainMenu();
void menu();
void registerMenu();
void findAccount();

// GLOBAL VARIABLES (in order)
string username; // Account username
string password; // Account password
double balance; // Account balance
string firstName; // Ben
string lastName; // Dover
string phoneNumber; // 8880007777
string houseAddress; // 
string houseAddress2; // 
string houseAddress3; // 
string cityAddress; // Staten
string cityAddress2; // Island
string stateAddress; // NY
int zipAddress; // 12345

// ADDITIONAL GLOBAL VARS
double newBal;

// Registration menu code
void registerMenu() {
    bool registerSuccess = false;
    bool usernameSuccess = false;
    string saveInfo;

    system("CLS"); // Clear Console

    cout << "Please create your account.\n";
    
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Phone Number: ";
    cin >> phoneNumber;
    cout << "Address: ";
    cin >> houseAddress;
    cin >> houseAddress2;
    cin >> houseAddress3;
    cout << "City: ";
    cin >> cityAddress;
    cin >> cityAddress2;
    cout << "State: ";
    cin >> stateAddress;
    cout << "Zip Code: ";
    cin >> zipAddress;
    cout << endl;
    cout << "Save information?" << endl << "Y/N" << endl;
    cin >> saveInfo;

    if (saveInfo == "Y" || saveInfo == "y") {
        cout << "-----------INFORMATION SAVED!-----------\n";
    }
    else if (saveInfo == "N" || saveInfo == "n") {
        registerMenu();
    }
    else {
        registerMenu();
    }

    cout << "\n\n";
    do {
        cout << "Username: ";
        cin >> username;

        ifstream usernameCheck("Accounts\\""user_" + username + ".txt");
        if (usernameCheck.is_open()) {
            cout << "This username already exists. Create a different username.\n\n";
            Sleep(1000);
        }
        else {
            cout << "\n\t! USERNAME AVAILABLE !\n";
            usernameSuccess = true;
        }
    } while (!usernameSuccess);

    do {
        cout << "Password: ";
        cin >> password;

        if (password.length() >= 8) {
            balance = 0;
            system("CLS"); // Clear Console

            cout << "Registration complete!\n";

            // [START] Create Account file
            ofstream registration;
            registration.open("Accounts\\""user_" + username + ".txt");
            registration << username << endl << password << endl << balance << endl << firstName << endl << lastName << endl << phoneNumber << endl << houseAddress + " " + houseAddress2 + " " + houseAddress3 << endl << cityAddress + " " + cityAddress2 << endl << stateAddress << endl << zipAddress;
            registration.close();
            // [FINISH] Create Username file

            registerSuccess = true;
            password = password;

            Sleep(1000);
            system("CLS"); // Clear Console
            cout << "--------------------------------" << endl;
            cout << "    Account Information\n";
            cout << "Username: " << username << endl;
            cout << "Password: " << password << endl;
            cout << "Balance: $" << balance << endl;
            cout << "--------------------------------" << endl;
            cout << "Forwarding you in 5 seconds..." << endl;
            Sleep(5000);
            mainMenu();

        }
        else {
            cout << "\n\nPassword must contain at least 8 characters. (You entered " << password.length() << " characters)\nPlease try again.\n";
        }
    } while (!registerSuccess);

}

// Login menu code
void login() {
    bool loginCorrect = false;
    bool passwordCorrect = false;

    cout << "Please login with your credentials below." << endl;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

        ifstream registration;
        registration.open("Accounts\\""user_" + username + ".txt");

        if(registration.is_open()){
            string login;
            getline(registration, login); // gets USERNAME data
            if(username == login){
                loginCorrect = true;
            }
            getline(registration, login); // gets PASSWORD data
            if(password == login){
                passwordCorrect = true;
            }
        }

        if(loginCorrect == true && passwordCorrect == true){
            registration.close();
            menu();
        } else if (loginCorrect == false || passwordCorrect == false){
            system("CLS");
            cout << "LOGIN OR PASSWORD INCORECT! PLEASE TRY AGAIN" << endl;
            login();
        }
}

// Find my account code
void findAccount() {
    system("CLS"); // Clear Console
    cout << "--------------------------------\n";
    cout << "       FIND ACCOUNT" << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "\n--------------------------------\n\n";

    ifstream registration;
    registration.open("Accounts\\""user_" + username + ".txt");
    if (registration.is_open()) {
        string account;
        getline(registration, account);
        cout << "Your username: " << account << endl;
        getline(registration, account);
        cout << "Your password: " << account << endl;
        getline(registration, account);
        cout << "Balance: $" << account << endl;
        cout << endl;
        registration.close();
        system("PAUSE");
    }
    else {
        system("CLS"); // Clear Console
        int choice;
        cout << "Account not found in system." << "\n";
        cout << "Would you like to create an account?\n";
        cout << "1. Yes\n";
        cout << "2. No\n";
        cout << "3. Try again\n";
        cin >> choice;

        if (choice == 1) {
            registerMenu();
        }
        else if (choice == 2) {
            mainMenu();
        }
        else if (choice == 3) {
            findAccount();
        }
    }
}

// Main menu code
void mainMenu() {
    system("CLS"); // Clear Console

    int choiceMainMenu;

    cout << "Welcome to the Bank App!\n";
    cout << "1) Login\n";
    cout << "2) Register\n";
    cout << "3) Account Information\n\n";
    cout << "Type the number of your choice: ";
    cin >> choiceMainMenu;

    if (choiceMainMenu == 1) {
        login();
    }
    else if (choiceMainMenu == 2) {
        registerMenu();
    }
    else if (choiceMainMenu == 3) {
        findAccount();
    }
    else {
        mainMenu();
    }
}

// Menu after successfull login code
void menu() {
    system("CLS"); // Clear Console
    int choice;
    int answer;
    double depositAmount;
    ifstream accountInfo;
    accountInfo.open("Accounts\\""user_" + username + ".txt");
    string first_name;
    getline (accountInfo, first_name);
    getline (accountInfo, first_name);
    getline (accountInfo, first_name);
    getline (accountInfo, first_name);
    cout << "Welcome, " << first_name << endl << endl;
    accountInfo.close();
    cout << "What action would you like to do?" << endl;
    cout << "1) View Balance" << endl;
    cout << "2) Deposit" << endl;
    cout << "3) Withdraw" << endl;
    cout << "4) Logout" << endl << endl;
    cout << "Type the number of your choice: ";
    cin >> choice;

    system("CLS"); // CLEAR CONSOLE

    fstream accountInfoMore;
    accountInfoMore.open("Accounts\\""user_" + username + ".txt");
    string account;

    if(choice == 1){
        getline (accountInfoMore, account);
        getline (accountInfoMore, account);
        getline (accountInfoMore, account);
        cout << "Your balance: $" << account;
        cout << endl << endl;
        cout << "1. Back" << endl;
        cout << "2. Logout" << endl;
        cin >> answer;
        system("CLS"); // CLEAR CONSOLE
        if(answer == 1){
            menu();
        } else if (answer == 2){
            cout << "Logging you out in 5 seconds...\n";
            Sleep(5000);
            mainMenu();
        } else {
            cout << "ERROR \t You must enter 1 or 2 to continue. Closing application...\n";
            Sleep(3000);
            exit;
        }
    } else if(choice == 2){
        getline (accountInfoMore, account);
        getline (accountInfoMore, account);
        getline (accountInfoMore, account);
        cout << "--------------DEPOSIT--------------\n";
        cout << "Your balance: $" << account << endl << endl;
        cout << "How much would you like to deposit?\nDeposit Amount: $";
        cin >> depositAmount;
        double updateBal = stod(account.substr());
        newBal = updateBal + depositAmount;
        cout << "New balance amount: $" << newBal;
        accountInfoMore.close();

        // FIX THIS SHIT BELOW

        fstream accountInfoMore;
        accountInfoMore.open("Accounts\\""user_" + username + ".txt");
        getline (accountInfoMore, account);
        getline (accountInfoMore, account);
        double updateBal2 = updateBal;
        double finalBal = newBal;
        accountInfoMore << finalBal << endl;

        // UP TO HERE
    }

    accountInfoMore.close();
}

// Main function
int main() {

    mainMenu();

    return 0;
}
