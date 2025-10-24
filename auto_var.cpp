#include <iostream>
#include <vector>
using namespace std;

int main(){

vector<int> nums = {1, 2, 3, 4, 5};


for (auto n : nums) {   // type automatically deduced as int
    cout << n << "\n";
}

auto x = 12; 
auto y = 8; 

cout << x/y << "\n";


}


