#include "twitter.hpp"
//const max variable to store the max value which is 274
const int MAX = 274;
//splitTweets function
void TwitterManager::splitTweets()
{
  {
      //Variables used in the splitTweets function
      //String variable equal to the message
      string tweets = message;
      //Char 's' represents the space character
      char s = ' ';
      //Char '!' represents the exclamation mark character
      char e = '!';
      //Char '?' represents the Question mark character
      char q = '?';
      //Char '.' represents the Period character
      char p = '.';
      //int counter is set to zero for the counter
      int counter = 0;
      //Total tweets length < 274 then store entire thing in array 0
      if((message.length()) <= 280)
      {
          //created object and stored username and message in array
          Tweet t;
          t.setUsername(username);
          t.setMessage(message.substr(0,message.length()));
          tweet[0] = t;
          length = 1;
      }
      //Goes here when total tweet length is bigger than 274
      else
      {
        //While loop when the tweet is bigger than zero
        while (message.length() > 0)
        {
          //Tweet is less than 273 then stores in the first array
          if(message.length() < (MAX - 1))
          {
            //created object and stored username and message in array
            Tweet t;
            t.setUsername(username);
            t.setMessage(message);
            tweet[length] = t;
            message.erase(0,message.length());
          }
          //if the 273 character in the tweet is a space
          else if(message[MAX - 1] == s)
          {
            //created object and stored username and message in array
            Tweet t;
            t.setUsername(username);
            t.setMessage(message.substr(0,MAX));
            tweet[length] = t;
            message.erase(0,MAX);
          }
          //If the 273 character is an exlamation mark
          else if(message[(MAX - 1)] == e)
          {
            //created object and stored username and message in array
            Tweet t;
            t.setUsername(username);
            t.setMessage(message.substr(0,MAX));
            tweet[length] = t;
            message.erase(0,MAX);
          }
          //If the 273 character is a question mark
          else if(message[(MAX - 1)] == q)
          {
            //created object and stored username and message in array
            Tweet t;
            t.setUsername(username);
            t.setMessage(message.substr(0,MAX));
            tweet[length] = t;
            message.erase(0,MAX);
          }
          //If the 273 character is a period
          else if(message[(MAX - 1)] == p)
          {
            //created object and stored username and message in array
            Tweet t;
            t.setUsername(username);
            t.setMessage(message.substr(0,MAX));
            tweet[length] = t;
            message.erase(0,MAX);
          }
          //If the no puncuation or space is found at 273
          //search for the largest position that has one
          else
          {
            //counter grabs the number from the index of the space in rfind of 273
              counter = message.rfind(' ',(MAX - 1));
              //if the counter is equal to a string null position then
              //stores the username and message from 0-274 inside of the object called t
              //thus erases afterwards
              if (counter == string::npos)
              {
                //created object and stored username and message in array
                Tweet t;
                t.setUsername(username);
                t.setMessage(message.substr(0,MAX));
                tweet[length] = t;
                message.erase(0,MAX);
              }
              //else stores the username and message inside of object with the
              //counter incrememting by one
              else
              {
                //created object and stored username and message in array
                Tweet t;
                t.setUsername(username);
                t.setMessage(message.substr(0,counter+1));
                tweet[length] = t;
                message.erase(0, counter+1);
              }
            }
          //If period is the largest position then set the end to that position
          if (tweets.rfind(p) > tweets.rfind(e) && tweets.rfind(p) > tweets.rfind(q) && tweets.rfind(p) > tweets.rfind(s) && tweets.rfind(p) < MAX)
          {
            //Set counter to the position of that period
            counter = tweets.rfind(p);
            //created object and stored username and message in array
            Tweet t;
            t.setUsername(username);
            t.setMessage(message.substr(0,counter+1));
            tweet[length] = t;
            message.erase(0,counter+1);
          }
          //If question mark is the largest position then set the end to that position
          else if (tweets.rfind(q) > tweets.rfind(e) && tweets.rfind(q) > tweets.rfind(p) && tweets.rfind(q) > tweets.rfind(s) && tweets.rfind(q) < MAX)
          {
            //Set counter to the position of that question mark
            counter = tweets.rfind(q);
            //created object and stored username and message in array
            Tweet t;
            t.setUsername(username);
            t.setMessage(message.substr(0,counter+1));
            tweet[length] = t;
            message.erase(0,counter+1);
          }
          //If exclamtion mark is the largest position then set the end to that position
          else if (tweets.rfind(e) > tweets.rfind(p) && tweets.rfind(e) > tweets.rfind(q) && tweets.rfind(e) > tweets.rfind(s) && tweets.rfind(e) < MAX)
          {
            //Set counter to the position of that exclamtion mark
            counter = tweets.rfind(e);
            //created object and stored username and message in array
            Tweet t;
            t.setUsername(username);
            t.setMessage(message.substr(0,counter+1));
            tweet[length] = t;
            message.erase(0,counter+1);
          }
          //If a space is the largest position then set the end to that posittion
          else if (tweets.rfind(s) > tweets.rfind(e) && tweets.rfind(s) > tweets.rfind(q) && tweets.rfind(s) > tweets.rfind(p) && tweets.rfind(s) < MAX)
          {
            //Set counter to the position of that space
            counter = tweets.rfind(s);
            //created object and stored username and message in array
            Tweet t;
            t.setUsername(username);
            t.setMessage(message.substr(0,counter+1));
            tweet[length] = t;
            message.erase(0,counter+1);
          }
          //increments counter to one
          length++;
        }
        //counter = 1
        int x = 1;
        //for loop go through the array
        for (int i = 0; i < length; i++)
        {
          //created temp variable to store and get the message
          string temp = tweet[i].getMessage();
          //modified the message by adding the counter
          temp += " (" + to_string(x) + "/" + to_string(length) + ")";
          //stored the modified counter into the message
          tweet[i].setMessage(temp);
          //incrementing the counter
          x++;
        }
      }
   }
}
//display function
void TwitterManager::display()
{
  //if the length is greater than one runs through the loop prints out
  if (length > 1)
  {
   for (int i = 0; i < length; i++)
   {
     (tweet[i]).display();
   }
  }
  //else if it isnt then it displays in the tweet array of zero
  else
  {
    (tweet[0]).display();
  }
}
