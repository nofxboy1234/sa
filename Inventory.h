#pragma once
#include "stdafx.h"

class Inventory {
public:
  Inventory();
  void add_orb();
  int total_orbs();

private:
  int _num_orbs;
};