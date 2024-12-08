#!/bin/bash
# find . -name '*.c' | xargs clang-tidy -- -I./include

find . -name '*.c' | xargs clang-tidy