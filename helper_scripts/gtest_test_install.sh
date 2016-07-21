#!/bin/bash

result=(ldconfig -v | grep gtest | diff <(echo "libgtest.so.0 -> libgtest.so.0.0.0 \ libgtest_main.so.0 -> libgtest_main.so.0.0.0") -)
if [[ $(result) ]]; then
  echo "GTEST TEST FAILED"
else
  echo "GTEST RAN SUCCESSFULLY"
fi
