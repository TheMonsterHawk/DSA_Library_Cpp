#include <iostream>

#ifndef Set
#include "set.h"
#endif

Set::Set(){
    for(int i = 0; i < Set::domain; i++){
        this->elements[i] = 0;
    }
}

Set::Set(const bool elements[]){
    for(int i = 0; i < Set::domain; i++){
        this->elements[i] = elements[i];
    }
}

Set Set::operator+(const Set &other) const {
    Set result;
    for(int i = 0; i < Set::domain; i++){
        result.elements[i] = other.elements[i] || this->elements[i];
    }
    return result;
}

Set Set::operator+(const int &other) const {
    Set result(this->elements);
    result.elements[other] = 1;
    return result;
}

Set Set::operator-(const Set &other) const {
    Set result;
    for(int i = 0; i < Set::domain; i++){
        if(other.elements[i] == 1){
            result.elements[i] = 0;
        } else {
            result.elements[i] = this->elements[i];
        }
    }
    return result;
}

Set Set::operator^(const Set &other) const {
    Set result;
    for(int i = 0; i < Set::domain; i++)
    if(other.elements[i] == 1 and this->elements[i] == 1){
        result.elements[i] = 1;
    }
    return result;
}

Set Set::operator- (const int &other) const {
    Set result;
    for(int i = 0; i < Set::domain; i++){
        result.elements[i] = this->elements[i];
    }
    result.elements[other] = 0;
    return result;
}

Set Set::operator^(const int &other) const {
    Set result;
    result.elements[other] = this->elements[other];
    return result;
}

Set Set::operator~ () const {
    Set result;
    for(int i = 0; i < Set::domain; i++) {
        result.elements[i] = 1 - this->elements[i];
    }
    return result;
}

Set Set::operator+() const {
    Set result;
    for(int i = 0; i < Set::domain; i++){
        result.elements[i] = 1;
    }
    return result;
}

Set Set::operator-() const {
    Set result;
    return result;
}

bool Set::operator<=(const Set &other) const {
    for(int i = 0; i < Set::domain; i++){
        if(this->elements[i] == 1 and other.elements[i] == 0) return false;
    }
    return true;
}

bool Set::operator< (const Set &other) const {
    Set result(this->elements);
    for(int i = 0; i < Set::domain; i++){
        if(this->elements[i] ==1 and other.elements[i]==0) return false;
    }
    return result() < other();
}

bool Set::operator== (const Set &other) const {
    for(int i = 0; i < Set::domain; i++){
        if(this->elements[i] != other.elements[i]) return false;
    }
    return true;
}

bool Set::operator!= (const Set &other) const {
    Set result(this->elements);
    return !(result == other);
}

bool Set::operator! () const {

}

int Set::operator()() const {
    int total_elements = 0;
    for(int i = 0; i < Set::domain; i++) total_elements += this->elements[i]==1;
    return total_elements;
}

bool Set::operator[] (const int &pos) const {
    return this->elements[pos]==1;
}

std::istream& operator>>(std::istream &in, Set &set) {
    bool arr[256];
    char open;
    in>>open;
    if (in.fail() || open!='{') {
    in.setstate(std::ios::failbit);
    return in;
    }
    for (int i=0;i<256;i++)
    arr[i]=false;
    std::string buff;
    std::getline(in,buff,'}');
    std::stringstream ss(buff);
    std::string field;
    while (true) {
    std::getline(ss,field,',');
    if (ss.fail()) break;
    int el;
    std::stringstream se(field);
    se>>el;
    if (el>=0&&el<256)
    arr[el]=true;
    }
    set=Set(arr);
    return in;
}

std::ostream& operator<<(std::ostream &out, const Set &set){
    std::cout <<"{";
    bool present = false;
    for(int i = 0; i < 256; i++){
        if(set.elements[i]==1){
            if(present) std::cout << ", ";
            std::cout << i;
            present = true;
        }
    }
    std::cout << "}";
    return out;
}

/*
Set operator+() const; //Set of universe
	Set operator-() const; //Empty set

	bool operator<=(const Set &other) const; //Subset
	bool operator<(const Set &other) const; //Strict subset
	bool operator>=(const Set &other) const; //Superset
	bool operator>(const Set &other) const; //Strict superset
	bool operator==(const Set &other) const; //Test for set equality
	bool operator!=(const Set &other) const; //Test for set inequality
	bool operator!() const; //Test for empty set
	int operator()() const; //Cardinality of set. i.e. |Set|
	bool operator[](const int &pos) const; //Test for 'is element of'

	friend std::ostream& operator<<(std::ostream &out, const Set &set);
	friend std::istream& operator>>(std::istream &in, Set &set);

*/
