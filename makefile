all: admin player goalKeeper defender midfielder forward match team user futballFantasy main result clean run

admin: Admin.hpp ConstVariables.hpp
	g++ -c --std=c++11 Admin.cpp -o Admin.o
player: Player.hpp ConstVariables.hpp
	g++ -c --std=c++11 Player.cpp -o Player.o
goalKeeper: GoalKeeper.hpp Player.hpp Player.o ConstVariables.hpp
	g++ -c --std=c++11 GoalKeeper.cpp -o GoalKeeper.o
defender: Defender.hpp Player.hpp Player.o ConstVariables.hpp
	g++ -c --std=c++11 Defender.cpp -o Defender.o
midfielder: Midfielder.hpp Player.hpp Player.o ConstVariables.hpp
	g++ -c --std=c++11 Midfielder.cpp -o Midfielder.o
forward: Forward.hpp Player.hpp Player.o ConstVariables.hpp
	g++ -c --std=c++11 Forward.cpp -o Forward.o
match: Match.hpp ConstVariables.hpp
	g++ -c --std=c++11 Match.cpp -o Match.o
team: Team.hpp Player.hpp Player.o GoalKeeper.hpp GoalKeeper.o Midfielder.hpp Midfielder.o Defender.hpp Defender.o Forward.hpp Forward.o ConstVariables.hpp
	g++ -c --std=c++11 Team.cpp -o Team.o
user: User.hpp Team.hpp Team.o Player.hpp Player.o GoalKeeper.hpp GoalKeeper.o Midfielder.hpp Midfielder.o Defender.hpp Defender.o Forward.hpp Forward.o ConstVariables.hpp
	g++ -c --std=c++11 User.cpp -o User.o
futballFantasy: FutballFantasy.hpp Match.hpp Match.o User.hpp User.o Player.hpp Player.o GoalKeeper.hpp GoalKeeper.o Midfielder.hpp Midfielder.o Defender.hpp Defender.o Forward.hpp Forward.o Admin.hpp Admin.o ConstVariables.hpp
	g++ -c --std=c++11 FutballFantasy.cpp -o FutballFantasy.o
main: FutballFantasy.hpp FutballFantasy.o Match.hpp Match.o User.hpp User.o Player.hpp Player.o GoalKeeper.hpp GoalKeeper.o Midfielder.hpp Midfielder.o Defender.hpp Defender.o Forward.hpp Forward.o Admin.hpp Admin.o ConstVariables.hpp
	g++ -c --std=c++11 main.cpp -o main.o
result: main.o FutballFantasy.hpp FutballFantasy.o Match.hpp Match.o User.hpp User.o Player.hpp Player.o GoalKeeper.hpp GoalKeeper.o Midfielder.hpp Midfielder.o Defender.hpp Defender.o Forward.hpp Forward.o Admin.hpp Admin.o ConstVariables.hpp
	g++ --std=c++11 main.o FutballFantasy.o Admin.o Match.o User.o Team.o Player.o  -o futballFantasy
clean:
	del *.o
run:
	futballFantasy.exe