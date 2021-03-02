#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

void showVector(vector<int> &nums);
void initializeLoader(vector<int> &loader);
void setVector(vector<int> &nums, vector<int> &loader, int &randCalls);
void atOrigin(vector<int> &nums, int &randCalls);

int main() {
  vector<int> nums, loader;
  initializeLoader(loader);

  int randCalls = 0;
  setVector(nums, loader, randCalls);

  showVector(nums);
  atOrigin(nums, randCalls);

  return 0;
}


void initializeLoader(vector<int> &loader) {
  for (int i = 0; i < 10; i++) loader.push_back(i+1);
}

void showVector(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) cout << nums[i] << endl;
}

void setVector(vector<int> &nums, vector<int> &loader, int &randCalls) {
  srand(time(0));
  int randIndex;
  for (int i = 0; i < 10; i++) {
    randIndex = rand() % loader.size();
    randCalls++;
    nums.push_back(loader[randIndex]);
    loader.erase(loader.begin() + randIndex);
  }
}

void atOrigin(vector<int> &nums, int &randCalls) {
  int total = 0;
  for (int i = 0; i < 10; i++) {
    if (nums[i] == i) total++;
  }
  cout << "Total at original position: " << total << endl;
  cout << "Total calls to random function: " << randCalls << endl;
}
