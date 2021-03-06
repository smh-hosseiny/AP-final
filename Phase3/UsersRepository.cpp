#include "UsersRepository.h"
#include "Member.h"
#include "Publisher.h"
#include "Exception.h"
#include "BadRequest.h"
#include "PermissionDenied.h"
#include "NotFound.h"
#include <regex>
#include <iostream>


using namespace std;

shared_ptr<UsersRepository> UsersRepository :: the_instance=0;

shared_ptr<UsersRepository> UsersRepository :: get_instance()
{
	if(the_instance == 0)
		the_instance = make_shared<UsersRepository>(UsersRepository());
	return the_instance;
}

bool UsersRepository::is_username_valid(string user_name)
{
	if(all_members.empty())
		return true;
	for(auto &elem : all_members)
	{
		if(elem->get_username() == user_name)
			return false;
	}
	return true;
}

bool UsersRepository::is_email_valid(const std::string& email)
{
   const regex pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return regex_match(email, pattern);
}


string UsersRepository::Hash(string password)
{
	unsigned int Hash;
	for(int i=0; i<password.length(); i++)
		Hash = Hash ^ int(password[i]);
	return to_string(Hash);
}



void UsersRepository :: add_member(string user_name, string pass, string e_mail, int age, bool publisher)
{
	if(is_username_valid(user_name))
	{
		int user_id = all_members.size()+1;
		if(publisher)
			all_members.push_back(make_shared<Publisher>(Publisher(user_name, Hash(pass), e_mail, age, user_id)));
		else
			all_members.push_back(make_shared<Member>(Member(user_name, Hash(pass), e_mail, age, user_id)));
	}
	else
		throw BadRequest();
}


bool UsersRepository :: login_member(string username, string password)
{
	for(auto &elem : all_members)
	{
		if(elem-> get_username() == username && elem-> get_password() == Hash(password))
			return true;
		if(elem-> get_username() == username && elem-> get_password() != Hash(password))
			throw BadRequest();
	}
	throw NotFound();
}


shared_ptr<Member> UsersRepository :: get_member(string username, string password)
{
	for(auto &elem : all_members)
	{
		if(elem-> get_username() == username && elem-> get_password() == Hash(password))
			return elem;
	}
	throw NotFound();
}


shared_ptr<Member> UsersRepository :: get_member(int id)
{
	for(auto &elem : all_members)
	{
		if(elem->get_id() == id)
			return elem;
	}
	throw NotFound();
}