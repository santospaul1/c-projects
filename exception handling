//  C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Tester{
//Access specifier
    public: int numerator;
    public: int denominator;
    public: int result;
    
//input values
    public: void values(){
        cout<<"Enter numerator: ";
        cin>> numerator;
        cout<<"Enter denominator: ";
        cin>> denominator;
    }

    //function to throw an excemption if you devide  number by zero 
    void  results1(int n, int d){
        
        if (d == 0){
            throw std::invalid_argument("Number cannot be divisible by zero");
        }
        else{
            result = n/d;
        cout<< result;
        }
        
    }
    
    
    
    
};
//main method
int main() {
    int numerator,denominator;
    Tester h; // creating an object
    h.values();
    
    h.results1(h.numerator,h.denominator);
    
    return 0;
}
