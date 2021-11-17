#ifndef DATA_H
#define DATA_H
#include <string>
#include <iostream>
class Data
{
public:
    int key;
    Data();
    Data(int new_key){
        this->key = new_key;
    }
    int hash() const{
        return this->key;
    }
    friend ostream & operator<< (ostream& output, const Data &D ){ 
         output << D.key;
         return output;            
      }
  
};

bool operator<(const Data& Data1, const Data& Data2){
	if (Data1.key < Data2.key) return true;
	else return false;
}
bool operator>(const Data& Data1, const Data& Data2){
	if (Data1.key > Data2.key) return true;
	else return false;
}
bool operator==(const Data& Data1, const Data& Data2){
	if (Data1.key == Data2.key) return true;
	else return false;
}

#endif