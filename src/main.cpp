#include <iostream>
#include <exception>
#include <emscripten/emscripten.h>

extern "C" {
  int EMSCRIPTEN_KEEPALIVE hello(int n){
    try {
      throw std::runtime_error("test");
    } catch (std::exception &e) {
      std::cout << "Catch: " << e.what() << "\n";
    } catch (...) {
      std::cout << "Catch...: " << "\n";
    }
    std::cout << "Hello World\n";
    return 3 + n;
  }
}
