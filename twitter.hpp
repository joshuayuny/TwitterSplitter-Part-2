#ifndef TWITTER_HPP // This code prevents multiple includes of twitter.hpp
#define TWITTER_HPP

#include <iostream>
#include <string>
using namespace std;
//class tweet
class Tweet
{
//variables used for the class tweet in private
private:
string username;
string message;
int charLength;
//public inside tweet
public:
    //setters for username
    void setUsername(string u)
    {
      username = u;
    }
    //setters for message
    void setMessage(string m)
    {
      message = m;
      charLength = m.length();
    }
    //getters for username
    string getUsername()
    {
      return username;
    }
    //getter for message
    string getMessage()
    {
      return message;
    }
    //setters for charLength
    void setcharLength(int x)
    {
      charLength = x;
    }
    //getter for charLength
    int getCharLength()
    {
      return charLength;
    }
    //default constructror for tweet
    Tweet()
    {
      username = "";
      message = "";
      charLength = 0;
    }
    //constructor for tweet that acccept username and message
    Tweet(string u, string m)
    {
      username = u;
      message = m;
      charLength = m.length();
    }
    //deconstructor for tweet
    ~Tweet()
    {

    }
    //display function
    void display()
    {
      cout << "@" << username << ": " << message << endl;
    }
};

class TwitterManager
{
  //private variables used for twittermanager
  private:
    string username;
    string message;
    Tweet *tweet;
    int length = 0;
  public:
    //setter for username
    void setUsername(string u)
    {
      username = u;
    }
    //setter for message
    void setMessage(string m)
    {
      message = m;
      splitTweets();
    }
    //getter for username
    string getUsername()
    {
      return username;
    }
    //getter for message
    string getMessage()
    {
      return message;
    }
    //getter for length
    int getLength()
    {
      return length;
    }
    //Default constructor for twittermanager
    TwitterManager()
    {
      username = "";
      message = "";
      tweet = new Tweet[100];
      length = 0;
      //~TwitterManager(){};
    }
    //constructor for twittermanager that acccept username and message
    TwitterManager(string u, string m)
    {
      username = u;
      message = m;
      tweet = new Tweet[100];
      length = 0;
      splitTweets();

    }
    //Creating display function
    void display();
    //Creating splitTweets function
    void splitTweets();
    //deconstructor for TwitterManager
    ~TwitterManager()
    {
      delete[] tweet;
      tweet = nullptr;
    }
};


#endif
