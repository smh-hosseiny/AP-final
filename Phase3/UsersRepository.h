#ifndef USERS_REPOSITORY_H
#define USERS_REPOSITORY_H

#include <vector>
#include <memory>
#include "Member.h"


class UsersRepository
{

public:
   static std::shared_ptr<UsersRepository> get_instance();

   bool is_username_valid(std::string user_name);

   std::string Hash(std::string password);

   bool is_email_valid(const std::string& email);

   void add_member(std::string user_name, std::string pass, 
   			std::string e_mail, int age, bool publisher);
	
	bool login_member(std::string username, std::string password);

	std::shared_ptr<Member> get_member(std::string username, std::string password);
	std::shared_ptr<Member> get_member(int id);


private:
	static std::shared_ptr<UsersRepository> the_instance;
	std::vector<std::shared_ptr<Member> > all_members;
} ;


#endif
