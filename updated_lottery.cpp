
#include <iostream>      
#include <thread>     
#include <atomic>  

using namespace std;

atomic<bool> ready1(false);
atomic<bool> ready2(false);
atomic<bool> ready3(false);

atomic<int> counter1 (0);
atomic<int> counter2 (0);
atomic<int> counter3 (0);

void lotto_1(int id) {
  while (!ready1) {           
    this_thread::yield();
  }
  for (volatile int i=1; i<55; ++i) {
++counter1;
if(counter1 <= 6) {
    cout << id;
}
}
}
void lotto_2(int id) {
  while (!ready2) {           
    this_thread::yield();
  }
  for (volatile int i=1; i<55; ++i) {
++counter2;
if(counter2 <= 6) {
    cout << id;
}
}
}
void lotto_3(int id) {
  while (!ready3) {           
    this_thread::yield();
  }
  for (volatile int i=1; i<55; ++i) {
++counter3;
if(counter3 <= 6) {
    cout << id;
}
}
}
int main ()
{
int i = 1;
  thread threads1[55];
  thread threads2[55];
  thread threads3[55];
  cout << "Lotto Winners!\n";
  
  for (int i=1; i<7; ++i) threads1[i]=std::thread(lotto_1,i);
  cout << "\nFirst Winner: ";
  ready1 = true; 
  threads1[i].join();
  
  for (int i=1; i<7; ++i) threads2[i]=std::thread(lotto_2,i);
  cout << "\nSecond Winner: ";
  ready2 = true; 
  threads2[i].join();
  
  for (int i=1; i<7; ++i) threads3[i]=std::thread(lotto_3,i);
  cout << "\nThird Winner: ";
  ready3 = true; 
  threads3[i].join();
  cout << "\nCongratulations!!";
  return 0;
 
}
