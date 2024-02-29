/*
Copyright[2021]
Justin Cheok
*/

#ifndef UNTITLED_FIBLFSR_H
#define UNTITLED_FIBLFSR_H
/*
Copyright [2021] <Justin Cheok>
*/
#include <iostream>
#include <vector>
#include <string>
class FibLFSR {
public:
FibLFSR(std::string seed, int tap); // constructor to create LFSR with
//the given initial seed and tap
int step();
int generate(int k);
std::vector<int> stringVector(std::string str);
friend std::ostream& operator<<(std::ostream& out, FibLFSR const& fibLfsr);
private:
  int _tap;
std::vector<int> _seed;
};
#endif //UNTITLED_FIBLFSR_H
