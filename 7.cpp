


#include<iostream>
using namespace std;
class hero{
    private:
    int health;
    public:
    char level; 
    /// parameterized constructor 
    hero(int health){
        cout<<this<<endl;
        this -> health = health; //// (this ->) points to the health datavlue of object ramesh
                                 /// we want to put health value in health datavalue of class hero
    }
    hero(int health,char level){
        this -> health=health;
        this-> level=level;
    }
    void print(){
        cout<<level<<endl;
    }
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }
    void setHealth(int h){
        health=h;
    }
    void setLevel(char ch){
        level=ch;

    }
};
int main(){
    hero ramesh(10);
    hero kumesh(66,'A');
    kumesh.print();/// it prints only ADC as in print fxn only level is printed
}