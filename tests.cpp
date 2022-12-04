#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Network.cpp"
#include "Profile.cpp"

TEST_CASE("Profile Test Cases") 
{
   Profile p = Profile("arandomperson", "ARP");
   CHECK(p.getUsername() == "arandomperson");
   CHECK(p.getUsername() != "ARP");
   CHECK(p.getFullName() == "ARP(@arandomperson)");
   p.setDisplayName("aperson");
   CHECK(p.getUsername() == "arandomperson");
   CHECK(p.getFullName() == "aperson(@arandomperson)");
}

TEST_CASE("Network Test Cases") 
{
   Network n;
   n.addUser("mario", "Mario");
   n.addUser("luigi", "Luigi");
   n.addUser("yoshi", "Yoshi");
   n.addUser("person", "aperson");
   n.addUser("person2", "aperson2");
   n.follow("mario", "luigi");
   n.follow("mario", "yoshi");
   n.follow("luigi", "mario");
   n.follow("luigi", "yoshi");
   n.follow("yoshi", "mario");
   n.follow("yoshi", "luigi");
   CHECK(n.addUser("mario", "Mario") == 0);
   CHECK(n.addUser("luigi", "Luigi") == 0);
   CHECK(n.addUser("yoshi", "Yoshi") == 0);
   CHECK(n.addUser("person", "aperson") == 0);
   CHECK(n.addUser("person2", "aperson2") == 0);
}