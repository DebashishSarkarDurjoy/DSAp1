#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

class p1 {
  private:
    int size = 10;
    int randCalls = 0;
    int totalAtOrigin = 0;
    int totalUnchanged = 0;
    vector<int> nums, loader;

  public:
    p1() {
      for (int i = 0; i < this->size; i++) this->loader.push_back(i);
    }

  void setVector() {
    srand(time(0));
    int randIndex;
    for (int i = 0; i < this->size; i++) {
      randIndex = rand() % this->loader.size();
      this->randCalls++;
      this->nums.push_back(this->loader[randIndex]);
      this->loader.erase(this->loader.begin() + randIndex);
    }
  }

  void atOrigin() {
    for (int i = 0; i < this->size; i++) {
      if (this->nums[i] == i) this->totalAtOrigin++;
    }
    this->totalUnchanged += this->totalAtOrigin;
  }

  string returnInfo() {
    string vectorData = " ";
    for (int i = 0; i < this->size; i++) {
      vectorData += to_string(this->nums[i]);
      vectorData += " ";
    }
    vectorData += "unchanged: " + to_string(this->totalAtOrigin) + " ";
    vectorData += "random calls to rand(): " + to_string(this->randCalls);
    return vectorData;
  }

  int getTotalUnchanged() {
    return this->totalUnchanged;
  }

  void showVector() {
    for (int i = 0; i < 10; i++) cout << this->nums[i];
  }

};

int main() {

  p1 *myO = new p1();
  myO->setVector();
  myO->atOrigin();
  cout << myO->returnInfo() << endl;


  return 0;
}
