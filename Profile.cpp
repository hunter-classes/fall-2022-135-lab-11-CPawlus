#include <iostream>
#include <string>
#include "Profile.h"

Profile::Profile(std::string usrn, std::string dspn) 
{
   this->displayname = dspn;
   this->username = usrn;
}

Profile::Profile() 
{
   this->displayname = "";
   this->username = "";
}

std::string Profile::getUsername() 
{
   return this->username;
}

std::string Profile::getFullName() 
{
   return this->displayname +"(@"+ this->username +")";
}

void Profile::setDisplayName(std::string dspn) 
{
   this->displayname = dspn;
}