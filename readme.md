# GPA-OOP
[![C/C++ CI](https://github.com/khongsomeo/GPA-OOP/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/khongsomeo/GPA-OOP/actions/workflows/c-cpp.yml)

Calculating my GPA, in an OOP way.

![screenshot.png](screenshot.png)

## Installation
### Prerequisites
Make sure your C++ version >= C++17.

### How-to:
`git clone` the project, then you'll have some options to compile:

Using Makefile:
```
make
```

Using `g++` - compile all files inside `src/` directory:
```
g++ src/*.cpp main -std=c++17
```

So simple, right?

## Development
### Testing
Adding a new 19120338th test:
- Payload: write test payloads to the 19120338th line of `tests/payloads.txt`
- Output: create a new file `tests/output/19120338.out`

Running tests:
1. `make`
2. `make init_test`
3. `make test`

### Code coverage
We support code coverage reports! Just make sure you have `lcov` installed.
1. `make gcov`
2. `make init_test`
3. `make test`
4. `make lcov`
5. `make generate-coverage-report`

Coverage Report will be automatically generated inside `coverage/`


### Format
We require your code to be formatted with `clang-format` before going further.
Follow these steps:

Install `clang-format`:
```
sudo apt-get install clang-format
```

Run checks:
```
make lint
```

If there are any linting errors, run `make format` to format it.
```
make format
```

## Running
### 1. Input format
- The input `.csv` file should looks like this:

  |course code|course credit|course grade|
  |:---------:|:-----------:|:----------:|
  |CSC10001|4|10
  |CSC10002|4|8.5
  |...|...|...

### 2. Command-line arguments
Given that the program has been compiled successfully to `<PROGRAM>.exe`, then:
- To calculate overall GPA:
  ```shell
  ./<PROGRAM> --input <GRADE_FILE.csv> --gpa
  ```
- To calculate GPA of courses start with a prefix:
  ```shell
  ./<PROGRAM> --input <GRADE_FILE.csv> --specific <SPECIFIC_COURSES.txt>
  ```

  `<SPECIFIC_COURSES.txt>` content should looks like this:
  ```
  course1prefix
  course2prefix
  course3prefix

  (notice that if you use full course code, then only one course added,
  using a prefix would choose every course have `courseprefix` as a prefix).
  ```
- To calculate GPA but ignore some courses defined inside
  `<IGNORED_COURSES.txt>`:
  ```shell
  ./<PROGRAM> --input <GRADE_FILE.csv> --ignore <IGNORED_COURSES.txt>
  ```

  `IGNORED_COURSES.txt` content should looks like this:
  ```
  course1code
  course2code
  course3code

  (notice that this command using course code, not prefix. To ignore courses
  with a same prefix, using --specific without a prefix).
  ```
- Export to `.csv` format:
  ```shell
  ./<PROGRAM> --input <GRADE_FILE.csv>
    [--specific <SPECIFIC_COURSES.txt> /
     --ignore <IGNORED_COURSES.txt>] --csv
  ```
- Ignore parsing errors

  With .csv files created by Microsoft Excel, sometimes there will be blank lines marked by two commas between data blocks:
  ```
  CSC10001,4,10
  ,,
  CSC10002,4,8.5
  ```
  And eventually this will cause an error message logging to the screen.

  To ignore this: simply adding `--ignore-parsing-error` option:
  ```shell
  ./<PROGRAM> --input <GRADE_FILE.csv>
  [--specific <SPECIFIC_COURSES.txt> /
  --ignore <IGNORED_COURSES.txt>] [ --csv ]
  --ignore-parsing-error
  ```
- Ignore textart?

  Sometimes you need to ignore the textart. Adding `--no-textart` will solve the problem.
  ```shell
  ./<PROGRAM> --input <GRADE_FILE.csv>
  [--specific <SPECIFIC_COURSES.txt> /
  --ignore <IGNORED_COURSES.txt>] [ --csv ] [ --ignore-parsing-error ]
  --no-textart
  ```

### 4. Custom textart
- `data/textart.txt` stores the textart file. Modify it with your own textart.

## Attention!
1. Default grade scale is 10.
2. 4-scale and A-scale are based on [VNUHCM -
  University of Science Student Guide 2020-21](https://www.hcmus.edu.vn/component/content/article/124-cong-tac-sinh-vien/thong-tin-danh-cho-tan-sinh-vien/3323-so-tay-sinh-vien-nam-hoc-2020-2021?Itemid=437)

## LICENSE
These works are under [The MIT License](LICENSE)
