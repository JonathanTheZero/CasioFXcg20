#include <fxcg/display.h>
#include <fxcg/keyboard.h>

int main() {
  PrintXY(3,8,"--Hello World!", TEXT_MODE_NORMAL, TEXT_COLOR_RED);

  int key;
  while(1)
    GetKey(&key);
  
  return 0;
}