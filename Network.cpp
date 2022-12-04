#include <iostream>
#include <string>
#include <ctype.h>
#include "Network.h"

Network::Network() 
{
   this->numUsers = 0;
   for(int i = 0; i < this->MAX_USERS; i++) 
   {
      for(int j = 0; j < this->MAX_USERS; j++) 
      {
         this->following[i][j] = false;  
      }
   }
}

bool Network::follow(std::string usrn1, std::string usrn2) 
{
   int u1, u2;
   for(int i = 0; i < this->MAX_USERS; i++) 
   {
      if(this->profiles[i].getUsername() == usrn1) 
      {
         u1 = i;
      }
      if(this->profiles[i].getUsername() == usrn2) 
      {
         u2 = i;
      }
   }
   if(this->following[u1][u2]) 
   {
      return false;
   }
   else 
   {
      this->following[u1][u2] = true;
      return true;
   }
}

void Network::printDot() 
{
   std::cout << "digraph {\n";
   for(int o = 0; o < this->numUsers; o++) 
   {
      std::cout << "  @" + this->profiles[o].getUsername() << "\n";
   }

   std::cout << "\n";
   for(int i = 0; i < this->MAX_USERS; i++) 
   {
      for(int j = 0; j < this->MAX_USERS; j++) 
      {
         if(this->following[i][j]) 
         {
            std::cout << "  @"+ this->profiles[i].getUsername() + " ->"+" @"+ this->profiles[j].getUsername() << "\n";
         }   
      }
   }
   std::cout << "}\n";
}

int Network::findID (std::string usrn) 
{
   for(int i = 0; i < this->MAX_USERS; i++) 
   {
      if(this->profiles[i].getUsername() == usrn) 
      {
         return i;
      }
   }
   return -1;
}

bool Network::addUser(std::string usrn, std::string dspn) 
{
   if(usrn.length() > 0) 
   {
      int numc = 0;
      for(int i = 0; i < usrn.length(); i++) 
      {
         char c = usrn[i];
         if(isalnum(c)) 
         {
            numc++;
         }
         else if(!isalnum(c)) 
         {
            return false;
         }
      }
      if(numc > 0) 
      {
         if(this->numUsers < this->MAX_USERS) 
         {
            for(int i = 0; i < numUsers; i++) 
            {  
               if(this->profiles[i].getUsername() == usrn) 
               {
                  return false;
               }
            }
         }
      }
   }
   if(this->numUsers < 20-1) 
   {
   
      this->numUsers++;
      this->profiles[numUsers-1] = Profile(usrn, dspn);
      return true;
   }
   else 
   {
      return false;
   }
}
