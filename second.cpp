#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

void showVector(vector<int> &nums);
void initializeLoader(vector<int> &loader);
void setVector(vector<int> &nums, vector<int> &loader);

int main() {
  vector<int> nums, loader;
  initializeLoader(loader);

  setVector(nums, loader);

  showVector(nums);

  return 0;
}


void initializeLoader(vector<int> &loader) {
  for (int i = 0; i < 10; i++) loader.push_back(i+1);
}

void showVector(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) cout << nums[i] << endl;
}

void setVector(vector<int> &nums, vector<int> &loader) {
  srand(time(0));
  int randIndex;
  for (int i = 0; i < 10; i++) {
    randIndex = rand() % loader.size();
    nums.push_back(loader[randIndex]);
    loader.erase(loader.begin() + randIndex);
  }
}
