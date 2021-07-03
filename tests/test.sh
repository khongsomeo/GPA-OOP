declare -a test_seeds

test_seeds[0]="./main data/19120338.csv"
test_seeds[1]="./main data/19120338.csv --gpa"
test_seeds[2]="./main data/19120338.csv --specific CSC"
test_seeds[3]="./main data/19120338.csv --ignore data/ignore.txt"
test_seeds[4]="./main data/19120338.csv --csv"
test_seeds[5]="./main data/19120338.csv --gpa --csv"
test_seeds[6]="./main data/19120338.csv --specific CSC --csv"
test_seeds[7]="./main data/19120338.csv --ignore data/ignore.txt --csv"

for i in "${!test_seeds[@]}" 
do
  printf "Testcase #%d: %s\n" "$i" "${test_seeds[$i]}"

  check=$(${test_seeds[$i]})

  if [[ $(< output/$i.out) != "$check"  ]]; then
    echo "failed."
    exit 1
  else
    echo "passed."
  fi
done
