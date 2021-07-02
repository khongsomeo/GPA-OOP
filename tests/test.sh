echo -e "Formatted GPA:\n"
./main data/19120338.csv

echo -e "\n"

echo -e "Formatted GPA, with flag:\n"

./main data/19120338.csv --gpa

echo -e "\n"

echo -e "Formatted specific GPA:\n"

./main data/19120338.csv --specific CSC

echo -e "\n"

echo -e "Formatted ignored GPA:\n"

./main data/19120338.csv --ignore data/ignore.txt

echo -e "\n"

echo -e "CSV GPA:\n"

./main data/19120338.csv --csv

echo -e "\n"

echo -e "CSV GPA, with flag:\n"

./main data/19120338.csv --gpa --csv

echo -e "\n"

echo -e "CSV specific GPA:\n"

./main data/19120338.csv --specific CSC --csv

echo -e "\n"

echo -e "CSV ignored GPA:\n"

./main data/19120338.csv --ignore data/ignore.txt --csv

echo -e "\n"

echo -e "Finished!"
