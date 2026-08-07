#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LoginSystem
{
private:
    string userName, email, password;
    string searchName, searchPassword, searchMail;
    fstream file;

    bool userExists(const string &name, const string &mail)
    {
        file.open("loginData.txt", ios::in);
        while (getline(file, userName, '*') &&
               getline(file, email, '*') &&
               getline(file, password, '\n'))
        {
            if (userName == name || email == mail)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

public:
    void login();
    void signUp();
    void forgetPassword();
};

void LoginSystem::signUp()
{
    cout << "\n===== SIGN UP =====\n";
    cout << "Username : ";
    getline(cin, userName);
    cout << "Email    : ";
    getline(cin, email);
    cout << "Password : ";
    getline(cin, password);

    if (userName.empty() || email.empty() || password.empty())
    {
        cout << "Fields cannot be empty!\n";
        return;
    }

    if (userExists(userName, email))
    {
        cout << "User already exists!\n";
        return;
    }

    file.open("loginData.txt", ios::app);
    file << userName << "*" << email << "*" << password << "\n";
    file.close();

    cout << "Account created successfully.\n";
}

void LoginSystem::login()
{
    cout << "\n===== LOGIN =====\n";
    cout << "Username : ";
    getline(cin, searchName);
    cout << "Password : ";
    getline(cin, searchPassword);

    file.open("loginData.txt", ios::in);
    bool found = false;

    while (getline(file, userName, '*') &&
           getline(file, email, '*') &&
           getline(file, password, '\n'))
    {

        if (userName == searchName)
        {
            found = true;
            if (password == searchPassword)
            {
                cout << "\nLogin Successful!\n";
                cout << "Welcome, " << userName << "\n";
                cout << "Email : " << email << "\n";
            }
            else
            {
                cout << "Incorrect password!\n";
            }
            break;
        }
    }

    if (!found)
        cout << "User not found!\n";

    file.close();
}

void LoginSystem::forgetPassword()
{
    cout << "\n===== FORGOT PASSWORD =====\n";
    cout << "Username : ";
    getline(cin, searchName);
    cout << "Email    : ";
    getline(cin, searchMail);

    file.open("loginData.txt", ios::in);

    while (getline(file, userName, '*') &&
           getline(file, email, '*') &&
           getline(file, password, '\n'))
    {

        if (userName == searchName && email == searchMail)
        {
            cout << "Password : " << password << "\n";
            file.close();
            return;
        }
    }

    file.close();
    cout << "Account not found!\n";
}

int main()
{
    LoginSystem obj;
    char choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Login\n";
        cout << "2. Sign Up\n";
        cout << "3. Forgot Password\n";
        cout << "4. Exit\n";
        cout << "Choice : ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1':
            obj.login();
            break;
        case '2':
            obj.signUp();
            break;
        case '3':
            obj.forgetPassword();
            break;
        case '4':
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != '4');

    print("Thanks for Playing!")
    return 0;
}
