# GPA-OOP
My example OOP project for CSC10003 - Introduction to Object Oriented Programming.

VNUHCM - University of Science, Spring 2021.

## Installation
- Make sure your C++ version >= C++17.
- `git clone`

## Running
### Some usefull command-line arguments
Let's think you have compiled the program successfully to <PROGRAM>.exe, then:
- `./<PROGRAM> <GRADE_FILE.csv> --gpa` _calculate GPA overall_
- `./<PROGRAM> <GRADE_FILE.csv> --specific <COURSE CODE>` _calculate GPA of courses start with <COURSE CODE>_
- `./<PROGRAM> <GRADE_FILE.csv> --except <EXCEPTION_FILE.txt>` _calculate GPA, ignore courses inside EXCEPTION_FILE.txt_

### Setting up shell scripts
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

### Custom textart
- `data/textart.txt` stores the textart file. Modify it with your own textart.

## Attention!
1. Default grade scale is 10.
2. 4-scale and A-scale are based on [VNUHCM - University of Science Student Guide 2020-21](https://www.hcmus.edu.vn/component/content/article/124-cong-tac-sinh-vien/thong-tin-danh-cho-tan-sinh-vien/3323-so-tay-sinh-vien-nam-hoc-2020-2021?Itemid=437)
3. You can place default data file inside `data/` folder.
