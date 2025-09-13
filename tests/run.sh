#!/usr/bin/env sh

set -x

test -d build || mkdir build

TESTS="double_free bad_realloc track_memory"

for test in $TESTS; do
  SRC="tests/$test.c"
  OBJ="build/$test"
  cc -g -Wno-variadic-macros -ansi -std=c89 -Wpedantic -Wall -Wextra -Wfatal-errors -Werror $SRC -o $OBJ
  if [ $? != 0 ]; then
    exit 1
  fi
  ./$OBJ > /dev/null
  if [ $? != 0 ]; then
    echo "OK: $test"
  else
    echo "FAILED: $test"
    exit 1
  fi
done
