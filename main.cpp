/*
Author: Christopher Pawlus
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Classes and Programming a Social Network, Lab 11.

This program uses classes that are used to 
create a social network system.
*/

#include <iostream>
#include <string>
#include <cctype>
#include "Network.h"
#include "Profile.h"

int main()
{
   // A
   Profile p1("marco", "Marco");    
   std::cout << p1.getUsername() << std::endl; 
   std::cout << p1.getFullName() << std::endl; 

   p1.setDisplayName("Marco Rossi"); 
   std::cout << p1.getUsername() << std::endl; 
   std::cout << p1.getFullName() << std::endl; 

   Profile p2("tarma1", "Tarma Roving");    
   std::cout << p2.getUsername() << std::endl; 
   std::cout << p2.getFullName() << "\n-----\n"; 
   // B 
   Network nw;
   std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
   std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

   std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
   std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
   std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

   for(int i = 2; i < 20; i++)
   {
      std::cout << nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) << std::endl;   // true (1)
   }
   std::cout << nw.addUser("yoshi", "Yoshi") << "\n-----\n";     // false (0)
   // C
   Network nw2;
   nw2.addUser("mario", "Mario");
   nw2.addUser("luigi", "Luigi");
   nw2.addUser("yoshi", "Yoshi");

   nw2.follow("mario", "luigi");
   nw2.follow("mario", "yoshi");
   nw2.follow("luigi", "mario");
   nw2.follow("luigi", "yoshi");
   nw2.follow("yoshi", "mario");
   nw2.follow("yoshi", "luigi");

   nw2.addUser("wario", "Wario");

   for(int i = 2; i < 6; i++) {
      std::string usrn = "mario" + std::to_string(i);
      std::string dspn = "Mario " + std::to_string(i);
      nw2.addUser(usrn, dspn);
      nw2.follow(usrn, "mario");
   }
   nw2.follow("mario2", "luigi");
   nw2.printDot();
   return 0;
}