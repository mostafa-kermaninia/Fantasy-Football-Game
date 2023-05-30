all: admin player match team user futballFantasy main result run

admin: Admin.hpp ConstVariables.hpp
	g++ -c --std=c++11 Admin.cpp -o Admin.o
player: Player.hpp ConstVariables.hpp
	g++ -c --std=c++11 Player.cpp -o Player.o 
match: Match.hpp ConstVariables.hpp
	g++ -c --std=c++11 Match.cpp -o Match.o
team: Team.hpp Player.hpp Player.o ConstVariables.hpp
	g++ -c --std=c++11 Team.cpp -o Team.o
user: User.hpp Team.hpp Team.o Player.hpp Player.o ConstVariables.hpp
	g++ -c --std=c++11 User.cpp -o User.o
futballFantasy: FutballFantasy.hpp Match.hpp Match.o User.hpp User.o Admin.hpp Admin.o ConstVariables.hpp
	g++ -c --std=c++11 FutballFantasy.cpp -o FutballFantasy.o
main: FutballFantasy.hpp FutballFantasy.o Match.hpp Match.o User.hpp User.o Admin.hpp Admin.o ConstVariables.hpp
	g++ -c --std=c++11 main.cpp -o main.o
result: main.o  FutballFantasy.hpp FutballFantasy.o Match.hpp Match.o User.hpp User.o Admin.hpp Admin.o ConstVariables.hpp
	g++ --std=c++11 main.o FutballFantasy.o Admin.o Match.o User.o Team.o Player.o  -o futballFantasy.out 
