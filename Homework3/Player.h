#ifndef __PLAYER_H
#define __PLAYER_H
#include <string>
#include <vector>
#include <map> 
using namespace std;
class Player{
private:
	int status;//0 died,1 alive,2 with princess
	int count;
public:
	Player():status(1),count(0){};
	virtual ~Player(){};
	inline void move(){
		count+=1;
	}
	inline int getstatus(){return status;};
	inline void meetprincess(){//once meet the princess, change status to 2
		status=2;
		cout<<"Wonderful! You meet the princess! Bring her back to the lobby!"<<endl;
		return;
	}
	inline void meetmonster(){
		status=0;
		cout<<"Oops....You meet the monster!\nYou died after "<<count<<" moves"<<endl;
		exit(0);
	}
};

#endif
