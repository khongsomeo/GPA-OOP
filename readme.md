# GPA-OOP
My example OOP project for CSC10003 - Introduction to Object Oriented Programming.

VNUHCM - University of Science, Spring 2021.

## Installation
- Make sure your C++ version >= C++17.
- `git clone`

## Running
### Calculate overall GPA
1. Create `YOUR_GRADE_FILE.csv` with `YOUR_GRADE_FILE` replaced by an awesome name. The file's content should look like this:

    | Course name | Credits | Grade |
    |-------------|---------|-------|
    |First course |   1     |  10.0 |
    |Second course|   1     |   9.0 |
    |(continue)   |   ..    |   ..  |

    Example input file: `data/19120338.csv`.

2. In `run.sh`, 

    change `YOUR_GRADE_FILE` to your `.csv` filename from step 2.

    change `GPA_FILE` to a nice, awesome filename; or just leave it alone.
3. Grant permissons for `compile.sh` and `run.sh`:

    `chmod 0700 compile.sh run.sh`. 
4. Compile the script: `./compile.sh`
5. Run the script: `./run.sh`

### Don't want to use shell scripts?
This program use commandline arguments, so you need to compile it to executable file before taken any further actions.

To start the program, `./<PROGRAM_NAME> <path to your .csv data file>` with `<PROGRAM NAME>` replaced with your program name after compile.

### Calculate average grade of custom classes only.
Let's assuming you're a Computer Science student and you want to know what is your Computer Science courses's average. Assuming your CS classes's code start with "CSC". `./<PROGRAM_NAME> <path to your .csv data file> CSC` will calculate average of CSC classes.

### Custom textart
- `data/textart.txt` stores the textart file. Modify it with your own textart.

## Attention!
1. Default grade scale is 10.
2. 4-scale and A-scale are based on [VNUHCM - University of Science Student Guide 2020-21](https://www.hcmus.edu.vn/component/content/article/124-cong-tac-sinh-vien/thong-tin-danh-cho-tan-sinh-vien/3323-so-tay-sinh-vien-nam-hoc-2020-2021?Itemid=437)
3. You can place default data file inside `data/` folder.
