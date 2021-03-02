#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void findOrigin(int nums[]);
void initializeArray(int nums[]);
bool isNegPresent(int nums[]);

int main() {
  srand(time(0));

  int nums[10], temp;
  bool present = false;

  initializeArray(nums);

  while (isNegPresent(nums)) {
    for (int i = 0; i < 10; i++){
      temp = rand() % 10;
      for (int j = 0; j < 10; j++) {
        if (temp == nums[j]) {
          present = true;
          break;
        }
      }
      if (!present) {
        nums[i] = temp;
        present = false;
      }
      cout << ".";
    }
  }

  findOrigin(nums);

  return 0;
}

void findOrigin(int nums[]) {
  int totalOrigin = 0;

  for (int i = 0; i < 10; i++){
    if (nums[i] == i) totalOrigin++;
  }

  cout << endl << "Total at original position: " << totalOrigin << endl;
}

void initializeArray(int nums[]) {
  for (int i = 0; i < 10; i++) nums[i] = -1;
}

bool isNegPresent(int nums[]) {
  for (int i = 0; i < 10; i++) {
    if (nums[i] == -1) return true;
  }
  return false;
}
