#include <iostream>
#include <string>

using namespace std;

class printer{

    string _name; 
    int _available_papers;
    
    
    public:

    printer(string name, int paper){
        _name = name;
        _available_papers = paper;
    }

    void print(string document){
        int required_papers = document.length()/10; // Assume each document requires 1 paper for simplicity

        if(required_papers > _available_papers){
            throw 40.0;;  
        }
     
        
        cout << "Printing document: " << document << " on printer: " << _name << endl;
        _available_papers -= required_papers;
        


    }


    
};

int main (){

    printer HP("HP LaserJet", 2);
    try{
        HP.print("Hello from Rauf!");
        HP.print("Hello from Rauf!");
        HP.print("Hello from Rauf!");
        HP.print("Hello from Rauf!");
    }

    catch(const char* txtexp){

        cout << "Exception caught: " << txtexp << endl;

    }

    catch (int expcode){

        cout << "Exception: " << expcode << endl;


    }

// DEFAULT EXCEPTION HANDLER
    catch (...){ // must be last, catches all types of exceptions
        cout << "Unknown exception caught!" << endl;
    }



    return 0;


    

}




