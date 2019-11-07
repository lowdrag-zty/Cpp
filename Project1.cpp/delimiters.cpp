#include <iostream>
#include <cassert>
#include "project_1.hpp"

//func_declarations
int main();
void print_program();
bool does_delimiter_match(char del);
bool do_delimiters_nest();


int main() {
    print_program();
    std::cout << does_delimiter_match('(') << std::endl;
    std::cout << does_delimiter_match('[') << std::endl;
    std::cout << does_delimiter_match('{') << std::endl;
    std::cout << do_delimiters_nest() << std::endl;
    
    return 0;
}

void print_program(){
    ece150::start_reading_file();
    while (ece150::at_eof()!= true) {
        std::cout << ece150::get_next_character();
    }
}

bool does_delimiter_match(char del){
   
    ece150::start_reading_file();
    char in;
    int open = 0;
    std::string miss = "";
    
    if(del=='('){
        
        while (ece150::at_eof()!= true) {
            
            in = ece150::get_next_character();
            
            if (in=='(') {
                open ++;
                }
            if (in==')') {
                if (open - 1 < 0) {
                    std::cout << "Unmatched )" << std::endl;
                }
                else{
                    open -= 1;
                }
            }
        }
        if (open==0) {
            return true;
        }
        else{
            for (int i = 0; i < open; i++) {
                miss += ')';
            }
            std::cout << "Missing " << miss << std::endl;
            return false;
        }
}
    
    else if(del=='['){
        
        while (ece150::at_eof()!= true) {
            
            in = ece150::get_next_character();
            
            if (in=='[') {
                open ++;
            }
            if (in==']') {
                if (open - 1 < 0) {
                    std::cout << "Unmatched ]" << std::endl;
                }
                else{
                    open -= 1;
                }
            }
        }
        if (open==0) {
            return true;
        }
        else{
            for (int i = 0; i < open; i++) {
                miss += ']';
            }
            std::cout << "Missing " << miss << std::endl;
            return false;
        }
}
    
    else if(del=='{'){

        while (ece150::at_eof()!= true) {
            
            in = ece150::get_next_character();
            
            if (in=='{') {
                open ++;
            }
            if (in=='}') {
                if (open - 1 < 0) {
                    std::cout << "Unmatched }" << std::endl;
                }
                else{
                    open -= 1;
                }
            }
        }
        if (open==0) {
            return true;
        }
        else{
            
            for (int i = 0; i < open; i++) {
                miss += "}";}
            
            std::cout << "Missing " << miss << std::endl;
            return false;
        }
}
    
    else{
        return false;
    }
}


bool do_delimiters_nest() {
    
    ece150::start_reading_file();
    ece150::initialize_table();
    
    char read;
    int count=0;

    while (ece150::at_eof()==0) {
        read = ece150::get_next_character();
       
        if (read=='('||read=='['||read=='{') {
            ece150::place_character(read);
        }
        if (read==')') {
            if (ece150::get_right_most_character()=='(') {
                ece150::erase_right_most_character();
            }
            else{
                std::cout << "Unmatched )" << std::endl;
                count++;
            }
        }
        if (read==']') {
            if (ece150::get_right_most_character()=='[') {
                ece150::erase_right_most_character();
            }
            else{
                std::cout << "Unmatched ]" << std::endl;
                count++;
            }
        }
        if (read=='}') {
            if (ece150::get_right_most_character()=='{') {
                ece150::erase_right_most_character();
            }
            else{
                std::cout << "Unmatched }" << std::endl;
                count++;
            }
        }
    }
    
    if (ece150::is_table_empty()==0) {
        std::cout << "Missing ";
        while (ece150::is_table_empty()==0) {
            if (ece150::get_right_most_character()=='(') {
                std::cout << ')';
                ece150::erase_right_most_character();
            }
            else if (ece150::get_right_most_character()=='['){
                std::cout << ']';
                ece150::erase_right_most_character();
            }
            else {
                std::cout << '}';
                ece150::erase_right_most_character();
            }
        }
        std::cout << std::endl;
        return false;
    }
    
    if (count>0) {
        return false;
    }
    
    return true;
}


    

   

    

        
        
        
        
        
        
        
        
    
    
    




