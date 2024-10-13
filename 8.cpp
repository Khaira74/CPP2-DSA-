//// construtorssss
// deconstructors


#include<iostream>;
using namespace std;
class hero{
    private:
    int health;
    public:
    char level;
    hero(){                   /// in BTS  ramesh.hero() is created//  ((hero is fxn))
        cout<<"constructor called"<<endl;//// called  when a object is created
                                          ///b by defaut there is some constructor but we can creat,like now this time 
                                          /// we created
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
        health=h
    }
    void setLevel(char ch){
        level=ch;

    }


}
int main(){
    hero suresh;     
}