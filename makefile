all: ride mission countmission distancemission timemission driver drivermissionsystem main result

ride: Ride.hpp
	g++ -c --std=c++11 Ride.cpp -o Ride.o
mission: Mission.hpp Ride.hpp Ride.o
	g++ -c --std=c++11 Mission.cpp -o Mission.o
countmission: CountMission.hpp Mission.hpp Mission.o Ride.hpp Ride.o
	g++ -c --std=c++11 CountMission.cpp -o CountMission.o
distancemission: DistanceMission.hpp Mission.hpp Mission.o Ride.hpp Ride.o
	g++ -c --std=c++11 DistanceMission.cpp -o DistanceMission.o
timemission: TimeMission.hpp Mission.hpp Mission.o Ride.hpp Ride.o
	g++ -c --std=c++11 TimeMission.cpp -o TimeMission.o
driver: Driver.hpp Mission.hpp Mission.o Ride.hpp Ride.o
	g++ -c --std=c++11 Driver.cpp -o Driver.o
drivermissionsystem: DriverMissionSystem.hpp Driver.hpp Driver.o Mission.hpp Mission.o Ride.hpp Ride.o CountMission.hpp CountMission.o DistanceMission.hpp DistanceMission.o TimeMission.hpp TimeMission.o
	g++ -c --std=c++11 DistanceMission.cpp -o DistanceMission.o
main: DriverMissionSystem.hpp DriverMissionSystem.o Driver.hpp Driver.o Mission.hpp Mission.o Ride.hpp Ride.o CountMission.hpp CountMission.o DistanceMission.hpp DistanceMission.o TimeMission.hpp TimeMission.o
	g++ -c --std=c++11 main.cpp -o main.o
result: main.o DriverMissionSystem.hpp DriverMissionSystem.o Driver.hpp Driver.o Mission.hpp Mission.o Ride.hpp Ride.o CountMission.hpp CountMission.o DistanceMission.hpp DistanceMission.o TimeMission.hpp TimeMission.o
	g++ --std=c++11 main.o DriverMissionSystem.o Mission.o Driver.o Ride.o TimeMission.o DistanceMission.o CountMission.o  -o main 
	