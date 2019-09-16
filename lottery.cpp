#include <iostream>    
#include <thread>        
#include <atomic>        

std::atomic<bool> ready1(false);
std::atomic<bool> ready2(false);
std::atomic<bool> ready3(false);

void lotto_1(int id) {
  while (!ready1) {            
    std::this_thread::yield();
  }
  for (volatile int i=0; i<55; ++i) {}
  std::cout <<" "<< id;
}

void lotto_2(int id) {
  while (!ready1) {            
    std::this_thread::yield();
  }
  for (volatile int i=0; i<55; ++i) {}
  std::cout << id;
}

void lotto_3(int id) {
  while (!ready1) {            
    std::this_thread::yield();
  }
  for (volatile int i=0; i<55; ++i) {}
  std::cout << id << " ";
}

int main ()
{
  std::thread myThreads1[6];
  std::thread myThreads2[6];
  std::thread myThreads3[6];
  
  std::cout << "Lotto Winners!\n";
  
   std::cout << "First Winner: ";
  for (int i=0; i<6; i++) myThreads1[i]=std::thread(lotto_1,i);
  ready1 = true; 
  for (auto& th1 : myThreads1) th1.join();


  for (int i=0; i<6; i++) myThreads2[i]=std::thread(lotto_2,i);
  std::cout << "\nSecond Winner: ";
  ready2 = true; 
  for (auto& th2 : myThreads2) th2.join();

  
  for (int i=0; i<6; i++) myThreads3[i]=std::thread(lotto_3,i); 
  std::cout << "\nThird Winner: ";
  ready3 = true; 
  for (auto& th3 : myThreads3) th3.join();
  
  

  return(0);
}
