/*
Copyright [2021] <Justin Cheok>
*/
#include "FibLFSR.hpp"
using namespace std;
FibLFSR::FibLFSR(string seed, int tap) {
_seed = stringVector(seed);
if(tap <= (int)_seed.size()) {
  _tap = tap;
}
}
int FibLFSR::step() {
int temp, tapPosition;
tapPosition = _seed.size() - _tap - 1;
temp = _seed[0] ^ _seed[tapPosition];
_seed.erase(_seed.begin());
_seed.insert(_seed.end(), temp);
return temp;
}
int FibLFSR::generate(int k) {
int number = 0;
for(int i = 0; i < k; i++) {
  number = number*2 + step();
}
  return number;
}
std::ostream& operator<<(std::ostream& out, FibLFSR const&
fibLfsr ) {
for(int i = 0; i < (int)fibLfsr._seed.size(); i++){
  out << fibLfsr._seed[i];
}
return out;
}
vector<int>FibLFSR::stringVector(string str) {
int temp;
Std::vector <int> stVect;
for(int i = 0; i < (int)str.length(); i++) {
  temp = str[i] - 48;
  stVect.push_back(temp);
}
  return stVect;
}
