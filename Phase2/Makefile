CC = g++ -std=c++11
CFLAG= -c
all: server.out
server.out: main.o Netflix.o Interface.o Command_Handler.o POST_Handler.o GET_Handler.o Admin.o MovieGraph.o \
UsersRepository.o MoviesRepository.o Member.o  Movie.o Publisher.o Comment.o Exception.o BadRequest.o PermissionDenied.o NotFound.o  
	${CC}  main.o Netflix.o Interface.o Command_Handler.o POST_Handler.o GET_Handler.o Admin.o MovieGraph.o \
	UsersRepository.o MoviesRepository.o Member.o Movie.o Publisher.o Comment.o Exception.o BadRequest.o PermissionDenied.o NotFound.o -o server.out 


main.o: main.cpp Interface.h
	${CC} ${CFLAG} main.cpp -o main.o


Interface.o: Interface.h Interface.cpp Netflix.h Exception.h BadRequest.h \
	PermissionDenied.h NotFound.h POST_Handler.h GET_Handler.h
	${CC} ${CFLAG} Interface.cpp -o Interface.o

Command_Handler.o: Command_Handler.h Command_Handler.cpp
	${CC} ${CFLAG} Command_Handler.cpp -o Command_Handler.o

POST_Handler.o: POST_Handler.h POST_Handler.cpp Command_Handler.h Netflix.h
	${CC} ${CFLAG} POST_Handler.cpp -o POST_Handler.o

GET_Handler.o: GET_Handler.h GET_Handler.cpp Command_Handler.h Netflix.h
	${CC} ${CFLAG} GET_Handler.cpp -o GET_Handler.o


Netflix.o: Netflix.h Netflix.cpp UsersRepository.h MoviesRepository.h Member.h Exception.h \
 BadRequest.h PermissionDenied.h NotFound.h Admin.h
	${CC} ${CFLAG} Netflix.cpp -o Netflix.o


UsersRepository.o: UsersRepository.h UsersRepository.cpp MoviesRepository.h Member.h \
Publisher.h Exception.h BadRequest.h PermissionDenied.h NotFound.h
	${CC} ${CFLAG} UsersRepository.cpp -o UsersRepository.o

MoviesRepository.o: MoviesRepository.h MoviesRepository.cpp MovieGraph.h Movie.h Exception.h \
 BadRequest.h PermissionDenied.h NotFound.h
	${CC} ${CFLAG} MoviesRepository.cpp -o MoviesRepository.o


Movie.o: Movie.h Movie.cpp Comment.h Exception.h BadRequest.h PermissionDenied.h NotFound.h
	${CC} ${CFLAG} Movie.cpp -o Movie.o

Member.o: Member.h Member.cpp Exception.h BadRequest.h PermissionDenied.h NotFound.h
	${CC} ${CFLAG} Member.cpp -o Member.o

Publisher.o: Publisher.h Publisher.cpp 
	${CC} ${CFLAG} Publisher.cpp -o Publisher.o


Comment.o: Comment.h Comment.cpp
	${CC} ${CFLAG} Comment.cpp -o Comment.o

Exception.o: Exception.h Exception.cpp
	${CC} ${CFLAG} Exception.cpp -o Exception.o


BadRequest.o: BadRequest.h BadRequest.cpp
	${CC} ${CFLAG} BadRequest.cpp -o BadRequest.o


PermissionDenied.o: PermissionDenied.h PermissionDenied.cpp
	${CC} ${CFLAG} PermissionDenied.cpp -o PermissionDenied.o

NotFound.o: NotFound.h NotFound.cpp
	${CC} ${CFLAG} NotFound.cpp -o NotFound.o

Admin.o: Admin.h Admin.cpp
	${CC} ${CFLAG} Admin.cpp -o Admin.o

MovieGraph.o: MovieGraph.h MovieGraph.cpp
	${CC} ${CFLAG} MovieGraph.cpp -o MovieGraph.o



.PHONY: clean
clean:
	rm -r *.o
