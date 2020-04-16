#pragma once

#include <shared_mutex>

/**
 * Difference between a class and a struct in C++:
 * structs have default public members and bases and classes have default private members and 
 * bases. Both classes and structs can have a mixture of public and private members, can use 
 * inheritance, and can have member functions. I would recommend using structs as plain-old-data 
 * structures without any class-like features, and using classes as aggregate data structures with 
 * private data and member functions.
 */

namespace littleBadger {
  // semantics for locks, RESERVED and PENDDING are for DLE 
  enum Semantic {UNLOCKED, SHARED, RESERVED, PENDING, EXCLUSIVE};

  class LockWrapper {
  public:
    Semantic semantic;
    std::shared_timed_mutex m;
    int sharedRefCount;

    LockWrapper();

  private:
    
  };

  // init lockManager
  const void initLockManager(int numRecord);

  // acquire a lock for a record
  const bool acquire(int key, Semantic s);

  // release a lock of a record
  const bool release(int key);

  // check lock status of a record
  const void check(int key);
}