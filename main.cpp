#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
void Multiply(int Multiplicand, std::vector<int> & Factor) {
    long long int Carry = 0;

    std::vector<int>::iterator I;

    for(I = Factor.begin(); I != Factor.end(); I++){
        long long int Output = (*I) * Multiplicand + Carry;
        *I = Output % 10;
        Carry = Output / 10;
    }

    while(Carry){
        Factor.push_back(Carry % 10);
        Carry /= 10;
    }
}

void Factorial(int Number){

    std::vector<int> Result;

    Result.push_back(1);

    for(long int i = 2; i <= Number; i++){
        Multiply(i, Result);
    }

    std::cout << "Factorial of given numbers is: " << std::endl;

    reverse(Result.begin(), Result.end());

    std::vector<int>::iterator J;
    for(J = Result.begin(); J != Result.end(); J++){
        std::cout << *J;
    }
}

int main(int argc, char** argv) {

    Factorial(30);

    system("pause");
    return 0;
}
