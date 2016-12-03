#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Room.h"
#include "Player.h"
using namespace std;
string input(){
    cout<<"Your command: go ";
    string tmp;
    cin>>tmp;
    return tmp;
}
void showvector(vector<string> data){
    vector<string>::iterator i;
    cout<<"You can go:";
    i=data.begin();
    cout<<"\""<<*i<<"\"";
    i++;
    for(;i!=data.end();i++){
        cout<<", \""<<*i<< "\"";
    }
    cout<<"."<<endl;
}

Room* goroom(Room* now,string direction,Player& me){
    if (now->getexit(direction)==NULL){
        cout<<"Wrong direction!"<<endl;
    }else{
        now=now->getexit(direction);
        me.move();
        //cout<<"Type:"<<now->gettype()<<endl;
        if(now->gettype()==1) me.meetprincess();
        else if(now->gettype()==2) me.meetmonster();
    }
    return now;
}

void test_exits(){
    Room a,b;
    a.addexits("up");
    b.addexits("right",&a);
    a.addexits("left",&b);
    showvector(a.getexit("left")->getexit("right")->listexits());
}

int main(){
    int DEBUG=1;
    Player me;
    /*Create Map:*/
    Room lobby,rooms[5];
    int i;char tmp[999];
    string tmp1="Welcome to the adventure.You are in the lobby.";
    lobby.setdescription(tmp1);
    for(i=0;i<5;i++){
        sprintf(tmp,"You are at Room %d",i);
        tmp1=tmp;
        rooms[i].setdescription(tmp1);
    }
    lobby.addexits("north",&rooms[0]);
    rooms[0].addexits("south",&lobby);
    lobby.addexits("east",&rooms[1]);
    rooms[1].addexits("west",&lobby);
    lobby.addexits("south",&rooms[2]);
    rooms[2].addexits("north",&lobby);
    lobby.addexits("west",&rooms[3]);
    rooms[3].addexits("east",&lobby);
    rooms[0].addexits("up",&rooms[4]);
    rooms[4].addexits("down",&rooms[0]);
    int monster;
    srand (time(NULL));
    monster=rand()%5;
    rooms[monster].changetype(2);
    srand (time(NULL));
    int princess=rand()%5;
    while(princess==monster) princess=rand()%5;
    rooms[princess].changetype(1);
    
    if(DEBUG) cout<<"Debug Output: Monster:"<<monster<<"; Princess:"<<princess<<endl;
    
    /*loop, ask user to command*/
    Room* now=&lobby;
    while(true){
        cout<<now->getdescription()<<endl;
        if(now==&lobby){
            if(me.getstatus()==2) {
                cout<<"Happy Ending!"<<endl;
                exit(0);
            }else{
                cout<<"Continue to find the princess~"<<endl;
            }
        }
        showvector(now->listexits());
        now=goroom(now,input(),me);
    }
}
