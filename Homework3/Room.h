#ifndef __ROOM_H
#define __ROOM_H
#include <string>
#include <vector>
#include <map> 
using namespace std;
class Room;
class Room{
private:
	map<string,Room*> exits;
	string description;
	int type;//0 normal; 1 princess; 2 monster
public:
	Room():description("No desciption"),type(0){};
	virtual ~Room(){
	};
	inline void changetype(int type){
		this->type=type;
	}
	inline int gettype(){
		return type;
	}
	inline vector<string> listexits(){
		vector<string> data;
		map<string,Room*>::iterator i;
		for(i=exits.begin();i!=exits.end();i++){
			data.push_back(i->first);
		}
		return data;
	}
	inline void addexits(string direction){
		exits.insert(pair<string,Room*>(direction,NULL));
	}
	inline void addexits(string direction, Room* next){
		exits.insert(pair<string,Room*>(direction,next));
	}
	inline Room* getexit(string direction){
		map<string,Room*>::iterator i=exits.find(direction);
		if (i==exits.end()) return NULL;
		else return i->second;
	}
	inline void setdescription(string& description){
		this->description=description;
	}
	inline string& getdescription(){
		return description;
	}
};
#endif
