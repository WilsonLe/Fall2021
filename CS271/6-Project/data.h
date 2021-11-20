#ifndef DATA_H
#define DATA_H
#include <string>
#include <iostream>
#include <climits>

// class str is a string that has a hash function
class str {
	public:
		str(){
			this->data = "";
		}
		str(string s){
			this->data = s;
		}
		int hash(int numSlots) const{
			// The maximum value of numSlots should be INT_MAX
			numSlots = min(numSlots, INT_MAX);

			// Since the char type has 8-bits, which can represents 256 characters,
			// we will choose 257 as our base because 257 is a prime which is close to 256.
			int base = 257; 
			int powOfBase = 1;
			int mod = numSlots;

			int hashRes = 0; // The hash result
			for(int i = 0; i < this->data.length(); i++) {
				unsigned char c = this->data[i];
				// Using the property (a+b) mod n=(a mod n + b mod n) mod n 
				// and the property (ab) mod p = ( (a mod p) (b mod p) ) mod p,
				// we can use the following formulas to calculate the same result as 
				// (hashing a string by expressing it as radix-257 and then mod by a number)
				hashRes = (hashRes + (c * powOfBase)) % mod;
				powOfBase = (powOfBase * base) % mod;
			}

			return hashRes;
		}
		friend ostream& operator<<(ostream& os, const str& s){
			os << s.data;
			return os;
		}
		friend bool operator<(const str& s1, const str& s2){
			return s1.data < s2.data;
		}
		friend bool operator>(const str& s1, const str& s2){
			return s1.data > s2.data;
		}
		friend bool operator==(const str& s1, const str& s2){
			return s1.data == s2.data;
		}
	private:
		string data;
};

template <class K, class V>
class Data {
	public:
		Data(K k, V v){
			this->key = k;
			this->value = v;
		};
		int hash(int numSlots) const{
			return this->key.hash(numSlots);
		}
        string toString() const {
            stringstream ss;
            ss << this->key << ": " << this->value;
            return ss.str();
        }
		friend ostream & operator<< (ostream& output, const Data &D ){ 
			output << D.toString();
			return output;            
		}
		friend bool operator<(const Data& Data1, const Data& Data2){
			return Data1.key < Data2.key;
		}
		friend bool operator>(const Data& Data1, const Data& Data2){
			return Data1.key > Data2.key;
		}
		friend bool operator==(const Data& Data1, const Data& Data2){
			return Data1.key == Data2.key;
		}
	private:
		K key;
		V value;
};
#endif