#include <iostream>
#include <string>
#include "twitter.hpp"

using namespace std;

int main()
{
  string username;
  string message;
  cout << "Please enter your username: ";
  cin >> username;
  cin.ignore();
  cout << "Please input your message: ";
  getline(cin, message);
  // Creating a TwitterManager object
  TwitterManager twe;
  //calling the second constructor: provide a username and message from user input
  twe.setUsername(username);
  twe.setMessage(message);
  //calls the TwitterManager object's display function.
  twe.display();
  return 0;
}
