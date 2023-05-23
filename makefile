all: player match team user game main result run

player: Player.hpp
	g++ -c --std=c++11 Player.cpp -o Player.o
match: Match.hpp 
	g++ -c --std=c++11 Match.cpp -o Match.o
team: Team.hpp Player.hpp Player.o
	g++ -c --std=c++11 Team.cpp -o Team.o
user: User.hpp Team.hpp Team.o Player.hpp Player.o
	g++ -c --std=c++11 User.cpp -o User.o
game: Game.hpp Match.hpp Match.o User.hpp User.o
	g++ -c --std=c++11 Game.cpp -o Game.o
main: Game.hpp Game.o Match.hpp Match.o User.hpp User.o
	g++ -c --std=c++11 main.cpp -o main.o
result: main.o  Game.hpp Game.o Match.hpp Match.o User.hpp User.o
	g++ --std=c++11 main.o Game.o  Match.oUser.hpp User.o -o main 

run: 
	./main weeks_stats premier_legue.csv