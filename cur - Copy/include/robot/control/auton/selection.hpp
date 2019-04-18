#ifndef SELECTION_HPP
#define SELECTION_HPP
#include <string>

enum class OnScreen {POSITION};
extern int POSITION;
extern std::string POSITIONS [6];

namespace auton{
      void onScreen();
      namespace selection{
        void on_right_button();
        void on_left_button();
  }
}

#endif /* end of include guard: SELECTION_HPP */
