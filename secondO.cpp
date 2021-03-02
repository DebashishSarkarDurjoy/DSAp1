#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

class p1 {
  private:
    int size = 10;
    int randCalls = 0;
    int totalAtOrigin = 0;
    vector<int> nums, loader;

  public:
    p1() {
      for (int i = 0; i < 10; i++) this->loader.push_back(i+1);
    }

  void showVectorInfo() {
    for (int i = 0; i < this->size; i++) cout << this->nums[i] << endl;
    cout << "Total at original position: " << this->totalAtOrigin << endl;
    cout << "Total calls to random function: " << this->randCalls << endl;
  }

  void setVector() {
    srand(time(0));
    int randIndex;
    for (int i = 0; i < size; i++) {
      randIndex = rand() % this->loader.size();
      this->randCalls++;
      this->nums.push_back(loader[randIndex]);
      this->loader.erase(loader.begin() + randIndex);
    }
  }

  void atOrigin() {
    for (int i = 0; i < 10; i++) {
      if (this->nums[i] == i) this->totalAtOrigin++;
    }
  }

};

int main() {
  p1 myObject;
  myObject.setVector();
  myObject.atOrigin();
  myObject.showVectorInfo();
  return 0;
}
