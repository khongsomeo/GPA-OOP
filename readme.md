# GPA-OOP
My example OOP project for CSC10003 - Introduction to Object Oriented Programming.

VNUHCM - University of Science, Spring 2021.

## How-to
1. `git clone`
2. Create `YOUR_GRADE_FILE.csv` with `YOUR_GRADE_FILE` is some awesome name, using this format:

    | Course name | Credits | Grade |
    |-------------|---------|-------|
    |First course |   1     |  10.0 |
    |Second course|   1     |   9.0 |
    |(continue)   |   ..    |   ..  |

    Example input file: `19120338.csv`.

3. In `run.sh`, 
    edit `YOUR_GRADE_FILE` with your `.csv` name from step 2.
    edit `GPA_FILE` with a nice, awesome file name, or just leave it alone.
4. Grant permissons for `compile.sh` and `run.sh`: `chmod 0700 compile.sh`. 

    Same to `run.sh` 
5. Compile the script: `./compile.sh`
6. Run the script: `./run.sh`

