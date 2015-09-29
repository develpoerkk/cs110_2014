/**
 * File: mr.cc
 * -----------
 * Provides the entry point for MapReduce server, which
 * itself is responsible for launching new workers on a subset
 * of the myth machines to distribute the work needed to 
 * press the original input files through mapper executables and
 * to press intermediate files (sorted and grouped by key) through
 * the reducer executables.
 *
 * It's clear from the implementation below that virtually all of the
 * detail is managed by the MapReduceServer class, which is defined
 * and implemented in mapreduce-server.h/.cc.
 */

#include "mapreduce-server.h"
#include "mapreduce-server-exception.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  try {
    MapReduceServer server(argc, argv);
    server.run();
  } catch (const MapReduceServerException& mrse) {
    cerr << "Fatal error: " << mrse.what() << endl;
    return 1;
  }

  cout << "All done!" << endl;
  return 0;
}
