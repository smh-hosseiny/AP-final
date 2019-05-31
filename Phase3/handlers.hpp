#ifndef _MY_HANDLERS_
#define _MY_HANDLERS_

#include "server/server.hpp"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>

class RandomNumberHandler : public RequestHandler {
public:
  Response *callback(Request *);
};

class LoginHandler : public RequestHandler {
public:
  Response *callback(Request *);
};

class SignupHandler : public RequestHandler {
public:
  Response *callback(Request *);
};

class UploadHandler : public RequestHandler {
public:
  Response *callback(Request *);
};

class ColorHandler : public TemplateHandler {
public:
  ColorHandler(std::string filePath);
  std::map<std::string, std::string> handle(Request *req);
};

std::vector<std::string> generate_signup_request(std::string username, std::string password, std::string email, std::string age, std::string publisher);
std::string is_publisher(std::string publisher);


#endif
