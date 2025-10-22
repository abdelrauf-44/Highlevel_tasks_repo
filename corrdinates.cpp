#include <iostream> 
using namespace std;
using std::string; 



class point{

    protected: 
        double X , Y;
    public: 
        string Robot_type;
    void print_position(){
        cout << Robot_type << ": "<< "X: " << X << " Y: " << Y << endl; 
    } 

    void set_position(double x, double y){
        X = x; 
        Y = y; 
    }
    double get_X_position(){

        return X;

    }
    double get_Y_position(){

        return Y;

    }
    point(string robot_type, double x , double y) {
        Robot_type = robot_type;
        X = x; 
        Y = y; 

    }




};

class point3D:public point{

    public:
        double Z; 

        point3D(string robot_type,double x, double y, double z):point(robot_type,x, y){
            Z = z;
        }
    
    void print_position3D(){
        cout<< Robot_type <<": " <<" X: " << get_X_position() << " Y: " << get_Y_position() << " Z: " << Z << endl;
    }
};

int main (){


    point robot1 = point("self_balacing_robot",0.0, 0.0);
    point robot2 = point("Auto_car",1.1, 1.1);
    point3D robot3 = point3D("Robotic_arm", 1.1, 0.5, 3.3);
    robot1.print_position();
    robot2.set_position(2.2,2.2);
    robot2.print_position();
    robot3.print_position3D();

}
