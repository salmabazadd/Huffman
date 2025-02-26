#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

inline std::ifstream::pos_type get_filesize(std::string& filename){
  std::ifstream in(filename, std::ifstream::ate);
  if(!in){
    std::cerr << "File opening error: " << filename << ". Can't get file size" << std::endl; 
    return -1;
  }
  return in.tellg();
}

template<class T>
/*void Print (const std::vector<int>& v){  //vector<int> v;  
for (int i=0; i<v.size();i++){  
    cout << v[i] << endl; 
     }
  }*/
void print(const std::vector <const T>& v) {
  for(size_t i = 0; i < v.size(); ++i){
    std::cout << "[" << i << "] = " << v[i] << ",\t ";
  }
  std::cout << std::endl;
}

template<typename T> void print_queue(T& queue) {
  while(!queue.empty()) {
    std::cout << *(queue.top()) << " ";
    queue.pop();
  }
  std::cout << std::endl;
}

#endif //AUXILIARY_H
