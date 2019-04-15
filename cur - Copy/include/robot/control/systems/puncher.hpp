#ifndef PUNCHER_HPP
#define PUNCHER_HPP

namespace puncher{
  //vars
  enum class Controllers{ONOFF,NONE};

  extern const int VMove;
  extern const int VStop;
  //vars FUNCTIONS
  // bool get_doubleShot();
  bool get_charged();
  //methods
  void execute();
  namespace OnOffCon{
    bool get_run();
  }
  namespace control{
    void charge();
    // void doubleBack();
    // void doubleFront();
  }
  namespace auton{
    void wait(int w=0);
    void charge(bool w=false);
    void fire(int wait=250);
  }
}
#endif /* end of include guard: PUNCHER_HPP */
