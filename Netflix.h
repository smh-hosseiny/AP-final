#ifndef NETFLIX_H
#define NETFLIX_H

#include <vector>
#include <memory>
#include "Member.h"


class UsersRepository;
class MoviesRepository;
class Exception;

class Netflix
{

public:
  Netflix();
  static std::shared_ptr<Netflix> get_instance();

  bool is_loggedin_user(const std::vector<std::string> &input);

  void add_member(std::string username, std::string pass, 
          std::string email, int age, bool publisher);

  void login_member(std::string username, std::string pass);

  void charge_account(double amount);

  bool is_publisher_of_this_film(int film_id);

  bool is_publisher();

  void recieve_money();

  void set_current_user(std::shared_ptr<Member> user);

  void follow(int user_id);

  void get_followers();

  void get_unread_notifications();

  void get_read_notifications(int limit);

  void post_film(std::string name, int year, int length_of_movie,
  double price, std::string summary,  std::string director);

  void edit_film(int film_id, std::string name, int year, int length_of_movie,
        double price, std::string summary,  std::string director);

  void show_publishers_films(const std::string &name, int min_year, int max_year, double min_rate,
      double price, const std::string &director);

  void show_all_films(const std::string &name, int min_year, int max_year, double min_rate,
      double price, const std::string &director);

  void show_one_single_film(int film_id);

  void show_purchased_films(const std::string &name, double price, int min_year,
  int max_year, const std::string &director);

  void remove_film(int film_id);

  void buy_film(int film_id);

  void rate_film(int film_id, int score);

  void comment_film(int film_id, const std::string &content);

  void delete_comment(int film_id, int content_id);

  void reply_to_film_comments(int film_id, int comment_id, const std::string &content);


private:
	static std::shared_ptr<Netflix> the_instance;
   std::shared_ptr<UsersRepository> Users_repository;
   std::shared_ptr<MoviesRepository> Movies_repository;
   std::shared_ptr<Member> current_user;
   int income;

};


#endif