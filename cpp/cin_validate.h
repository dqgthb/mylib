#ifndef CIN_VALIDATE_H
#define CIN_VALIDATE_H
#include <iostream>
#include <sstream>
#include <typeinfo>

/*
void cin_int(int& x){
    std::string input;
    while(getline(std::cin, input)){
        std::stringstream(input) >> x;
    }
}
*/

/*
void cin_int(int& input){
    bool bad=false;
    do{
        std::cin >> input;
        bad = std::cin.fail();
        if(bad){
            std::cout << "Invalid input. Please enter valid int." << "\n";
            std::cin.clear();
            std::cin.ignore(255,'\n');
        }
    } while (bad);
}
*/

//Many thanks to MetalMilitia from
//http://www.cplusplus.com/forum/beginner/76374/
void cin_int(int& ref){
    std::string in;
    while(true){
        getline(std::cin, in);
        if(std::cin.eof()){
            std::cerr << "cin_int: eof!\n";
            exit(1);
        }
        std::stringstream ss(in);
        if(ss >> ref && !(ss >> in)) return;
        // (ss >> out) checks for valid conversion to integer
        // !(ss >> in) checks for unconverted input and rejects it
        std::cin.clear(); // in case of a cin error, like eof() -- prevent infinite loop
        std::cerr << "cin_int: Invalid input. Please try again.\n";
    }
}

/*
template <typename T>
void cin_validate(T& input){
    bool bad=false;
    do{
        std::cin >> input;
        std::cin.ignore(255, '\n');

        bad = std::cin.fail();
        std::cout << "<<bad>> is " << bad << "\n";
        if(bad){
            std::cout << "Invalid input. Please enter valid " << typeid(input).name() << "." << "\n";
            std::cin.clear();
            std::cin.ignore(255,'\n');
        }
    } while (bad);
}
*/

// by codesafer
template <typename T>
void cin_valid(T& ref){
    std::string in;
    while(true){
        //std::cout << "type "<< typeid(ref).name() << ": "; // for debugging
        getline(std::cin, in);
        std::stringstream ss(in);
        if(ss >> ref && !(ss >> in)) return;
        // (ss >> out) checks for valid conversion to integer
        // !(ss >> in) checks for unconverted input and rejects it
        std::cin.clear(); // in case of a cin error, like eof() -- prevent infinite loop
        std::cerr << "Invalid input. Please try again.\n";
    }
}

#endif /* CIN_VALIDATE_H */
