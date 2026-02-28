#include <gtest/gtest.h>
#include <iostream>
#include "findCycle.hpp"

int findCycleLength(Node* start) {

  if (start == nullptr) {
    return -1;
  }

  int length {0};
  Node* tortoise = start;
  Node* hare = start->next;

  while (hare != nullptr) {
    if (tortoise == hare) {
      Node* start = tortoise;
      length++;
      for (Node* current = start->next; current != start; current = current->next) {
        length++;
      }
      return length;
    }
    tortoise = tortoise->next;
    if (hare->next == nullptr) {
      return -1;
    }
    hare = hare->next->next;
  }
  return -1;
}
