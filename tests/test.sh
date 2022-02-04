#!/bin/bash

##
## Simple bash script to check if the program give correct outputs
##
## @trhgquan - https://github.com/trhgquan
##

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
NC="\033[0m"

# Loading payloads
PAYLOAD_FILE="payloads.txt"

declare -a test_seeds

readarray -t test_seeds < $PAYLOAD_FILE

# total testcases
total_testcases=${#test_seeds[@]}

# progress bar
current_progress=""

# Test driver
for i in "${!test_seeds[@]}"
do
  check=$(${test_seeds[$i]})
  
  total_remain=$(($total_testcases - $i - 1))

  remain_progress="$(printf %$((total_remain))s |tr ' ' '.')"

  if [[ $(< output/$i.out) != "$check" ]]; then
    # If failed, print the failed testcase (expected & runtime)

    current_progress="${current_progress}${RED}✘${NC}"

    echo -ne "Testing: ${current_progress}${remain_progress} ($((${i} + 1))/${total_testcases})\r"

    echo -ne "\n"

    echo -e "${RED}✘ Testcase #$(($i + 1)) failed.${NC}"

    echo -e "${BLUE}Payload: ${test_seeds[$i]}${NC}"

    echo -e "${BLUE}Expected:${NC}"

    echo "$(< output/$i.out)"

    echo -e "${BLUE}Runtime:${NC}"

    echo "$check"

    exit 1
  
  else
    # Else, print progress (with green ticks!)

    current_progress="${current_progress}${GREEN}✔${NC}"
  
    echo -ne "Testing: ${current_progress}${remain_progress} ($((${i} + 1))/${total_testcases})\r"
  fi
done

# All tests passed. Printing congratulations!
echo -ne "\n"
echo -e "${GREEN}✔ All testcases passed${NC} ($((${i} + 1))/${total_testcases})"
