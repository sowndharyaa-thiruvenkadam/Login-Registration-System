#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser();
bool loginUser();

void registerUser()
{
  string username, password;

  cout << "Enter username: ";
  cin >> username;
  cout << "Enter password: ";
  cin >> password;

  ofstream file;
  file.open(username + ".txt");
  file << username << endl
       << password;
  file.close();

  cout << "Registration successful!" << endl;
}

bool loginUser()
{
  string username, password, un, pw;

  cout << "Enter username: ";
  cin >> username;
  cout << "Enter password: ";
  cin >> password;

  ifstream file(username + ".txt");
  getline(file, un);
  getline(file, pw);

  if (un == username && pw == password)
  {
    cout << "Login successful!" << endl;
    return true;
  }
  else
  {
    cout << "Login failed. Invalid username or password." << endl;
    return false;
  }
}

int main()
{
  int choice;

  cout << "1. Register" << endl;
  cout << "2. Login" << endl;
  cout << "Enter your choice: ";
  cin >> choice;

  if (choice == 1)
  {
    registerUser();
  }
  else if (choice == 2)
  {
    if (loginUser())
    {
      cout << "Welcome!" << endl;
    }
  }
  else
  {
    cout << "Invalid choice!" << endl;
  }

  return 0;
}
