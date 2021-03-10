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
    p1() { //initialize the loader vector with 0-9
      for (int i = 0; i < 10; i++) this->loader.push_back(i);
    }

  void setVector() {
    vector<int> nums, loader;

    int randIndex;
    for (int i = 0; i < this->size; i++) {
      randIndex = rand() % this->loader.size(); // get random number within the loader vector
      this->randCalls++;
      this->nums.push_back(this->loader[randIndex]);
      this->loader.erase(this->loader.begin() + randIndex); // remove the number from loader vector
    }
  }

  void atOrigin() {
    for (int i = 0; i < this->size; i++) {
      if (this->nums[i] == i) this->totalAtOrigin++; // calculate total at origin for each list
    }
    this->totalUnchanged += this->totalAtOrigin; // calculate total at origin overall
  }

  string returnInfo() { // form the string for each list
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
  srand(time(0));
  vector<string> allInfo;
  for (int i = 0; i < 20; i++) {
    p1 *myO = new p1();
    myO->setVector();
    myO->atOrigin();
    allInfo.push_back(myO->returnInfo());
  }

  for (int i = 0; i < 20; i++) {
    cout << allInfo[i] << endl;
  }
  // p1 *myO = new p1();
  // myO->setVector();
  // myO->atOrigin();
  // cout << myO->returnInfo() << endl;


  return 0;
}
