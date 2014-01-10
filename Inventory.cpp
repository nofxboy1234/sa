#include "stdafx.h"
#include "Inventory.h"

Inventory::Inventory() {
  _num_orbs = 0;

}

void Inventory::add_orb() {
  _num_orbs += 1;
}

int Inventory::total_orbs() {
  return _num_orbs;
}