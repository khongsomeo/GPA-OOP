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

test_seeds[0]="./main data/19120338.csv"
test_seeds[1]="./main data/19120338.csv --gpa"
test_seeds[2]="./main data/19120338.csv --specific CSC"
test_seeds[3]="./main data/19120338.csv --ignore data/ignore.txt"
test_seeds[4]="./main data/19120338.csv --csv"
test_seeds[5]="./main data/19120338.csv --gpa --csv"
test_seeds[6]="./main data/19120338.csv --specific CSC --csv"
test_seeds[7]="./main data/19120338.csv --ignore data/ignore.txt --csv"
test_seeds[8]="./main --gpa"
test_seeds[9]="./main data/19120338.csv --specific --csv"
test_seeds[10]="./main data/19120338.csv --specific"
test_seeds[11]="./main data/19120338.csv --ignore"
test_seeds[12]="./main data/19120338.csv --ignore --csv"
test_seeds[13]="./main"
test_seeds[14]="./main --csv"

for i in "${!test_seeds[@]}" 
do
  printf "${BLUE}Testcase #%d: %s\n" "$i" "${test_seeds[$i]}"

  check=$(${test_seeds[$i]})

  printf "${BLUE}%s${NC}\n" "Expected:"

  printf "%s\n" "$(< output/$i.out)"

  printf "${BLUE}%s${NC}\n" "Runtime:"

  printf "%s\n" "$check"

  if [[ $(< output/$i.out) != "$check"  ]]; then
    printf "${BLUE}Result: ${RED}%s${NC}\n" "failed"
    exit 1
  else
    printf "${BLUE}Result: ${GREEN}%s${NC}\n" "passed"
  fi

  printf "\n"
done
