# CC105 Week 10 – Scenario 02 Documentation

## Project

**Scenario 02: Computer Laboratory Assets**

This project demonstrates how to find a workstation using its equipment tag. It implements iterative Linear Search and Binary Search using `std::vector<int>` instead of an array.

## Scenario details

- Scenario number: 02
- Scenario title: Computer Laboratory Assets
- Lookup task: Find a workstation by its equipment tag.
- Base key (`B`): `120000`
- Additional scenario test: Try retiring equipment tag `120005` and check whether it exists.
- Verification dataset: 12 unique, ascending equipment tags.
- Dataset formula: `key[i] = B + 2 * i`

## Files in this ZIP

- `CC105_W10_Scenario02_Vector.cpp` – complete C++ source code.
- `Project_Documentation.md` – project overview, design, implementation, and explanation.
- `Test_Cases.md` – required verification tests and expected results.
- `Hand_Trace.md` – manual trace of Linear Search and Binary Search.
- `Benchmark_Report_Template.md` – benchmark table and machine/compiler details to complete after running.
- `Complexity_Analysis.md` – Big-O analysis and recommendation.
- `Submission_Checklist.md` – items to complete before submission.

## How to compile and run

Use a C++11-or-newer compiler (for example, g++).

```sh
g++ -std=c++11 -O2 CC105_W10_Scenario02_Vector.cpp -o scenario02
./scenario02
```

On Windows with MinGW:

```sh
g++ -std=c++11 -O2 CC105_W10_Scenario02_Vector.cpp -o scenario02.exe
scenario02.exe
```

The program uses `std::vector`, `<algorithm>`, `<random>`, and `<chrono>`. It is not written for the old Turbo C++ compiler.

## Important

Run the program on the group's own computer and copy the actual console output into the report. Benchmark times depend on the computer, compiler, and optimization settings. Do not invent or reuse timing values from another computer.
