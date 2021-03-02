#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void findOrigin(int nums[]);
void initializeArray(int nums[]);
bool isNegPresent(int nums[]);
void showArray(int nums[]);

int main() {
  int nums[10];
  initializeArray(nums);
  showArray(nums);

  srand(time(0));
  bool present = false;
  int temp;
  for (int i = 0; i < 10; i++) {
    temp = rand() % 10;
    cout << "--";
    showArray(nums);
    for (int j = 0; j <= i; j++) { //Check if num already exists
      if (temp == nums[j]) {
        present = true;
        break;
      }
    }

    if (!present) {
      nums[i] = temp;
      present = false;
      continue;
    }

    i--;


  }
  showArray(nums);
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

void showArray(int nums[]) {
  for (int i = 0; i < 10; i++) cout << nums[i] << endl;
}
