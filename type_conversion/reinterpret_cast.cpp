/*
https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast
*/
#include <iostream>
#include <bitset>

bool is_little_endian(void) {
  /*
  Representation of x in memory will be
    0000 0000 0000 0001 - if big endian
    0000 0001 0000 0000 - if little endian
  Since int is reinterpreted as unsigned char, the underlying
  memory layout won't get changed. Hence we can see the content
  in the way it is represented in the memory
  */
  std::uint16_t x = 0x1;

  auto p = reinterpret_cast<std::uint8_t*>(&x);

  return p != 0;
}

void print_mem(void) {
  std::uint32_t x = 0x1;

  auto p = reinterpret_cast<std::uint8_t*>(&x);
  std::cout << "Memory content using reinterpret_cast: ";
  for(int i = 0; i < 4; i++)
    std::cout << std::bitset<8>(*p++) << " ";

  std::cout << std::endl;
}

int main() {

  std::cout << "Is little endian: " << is_little_endian() << std::endl;
  print_mem();
  return 0;
}

/*
Output:
Is little endian: 1
Memory content using reinterpret_cast: 00000001 00000000 00000000 00000000
*/