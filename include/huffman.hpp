#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "node.hpp"

#include <queue>
#include <regex>

using priority_queue_t = std::priority_queue<pointer, std::vector<pointer>, Greater>;

class Huffman_window;

class Huffman{
  const std::string TYPE = ".hff";
  static const int BYTE_SIZE {8};

  Huffman_window * hw;
  
  int ratio         {0};
  int file_size     {0};
  int new_file_size {0};
  
  std::string file_name;
  std::string out_file_name;

  std::vector<int> frequency;
  std::vector<std::string> codes;

  priority_queue_t queue;
  pointer root {nullptr};
  
  std::string encode_message;
  std::string decode_message;
  std::string message;

public:
  Huffman(const std::string name, Huffman_window* w);
   
  virtual ~Huffman() = default;
  
  void compress();
  void decompress();
  
private:
  void encode_file();
  void fill_queue();
  void build_tree();

  void message2code(std::ifstream& input_file);
  void chs2codes();
  
  void write_frequency(std::ofstream& output_file);
  void write_raw_message(std::ofstream& output_file);
  void write_encoding_file();
  
  void gui_compress_result();
  
  void read_frequency(std::ifstream& input_file, int& count);
  void read_raw_message(std::ifstream& input_file);
  void read_decoding_file();

  void check_file_name();
  void codes2chs();
  void write_decoding_file();
  
  void gui_decompress_result();
  void gui_set_progress(int value);

};


#endif //HUFFMAN_H
