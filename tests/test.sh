#!/bin/bash

##
## Simple bash script to check if the program give correct outputs
##
## @trhgquan - https://github.com/trhgquan
##

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

declare -a test_seeds

test_seeds[0]="./main data/has_fail.csv"
test_seeds[1]="./main data/has_fail.csv --gpa"
test_seeds[2]="./main data/has_fail.csv --specific data/specific.txt"
test_seeds[3]="./main data/has_fail.csv --ignore data/ignore.txt"
test_seeds[4]="./main data/has_fail.csv --csv"
test_seeds[5]="./main data/has_fail.csv --gpa --csv"
test_seeds[6]="./main data/has_fail.csv --specific data/specific.txt --csv"
test_seeds[7]="./main data/has_fail.csv --ignore data/ignore.txt --csv"
test_seeds[8]="./main --gpa"
test_seeds[9]="./main data/has_fail.csv --specific --csv"
test_seeds[10]="./main data/has_fail.csv --specific"
test_seeds[11]="./main data/has_fail.csv --ignore"
test_seeds[12]="./main data/has_fail.csv --ignore --csv"
test_seeds[13]="./main"
test_seeds[14]="./main --csv"
test_seeds[15]="./main data/no_fail.csv"
test_seeds[16]="./main data/no_fail.csv --csv"

for i in "${!test_seeds[@]}"
do
  echo -e "${BLUE}Testcase #$i: ${test_seeds[$i]}"

  check=$(${test_seeds[$i]})

  if [[ $(< output/$i.out) != "$check" ]]; then
    echo -e "${RED}✘ Testcase failed.${NC}"

    echo -e "${BLUE}Expected:${NC}"

    echo "$(< output/$i.out)"

    echo -e "${BLUE}Runtime:${NC}"

    echo "$check"

    exit 1
  else
    echo -e "${GREEN}✔ Testcase passed.${NC}"
  fi

  printf "\n"
done
