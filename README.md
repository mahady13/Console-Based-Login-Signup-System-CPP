# Console-Based Login & Signup System (C++)

A secure, file-based User Authentication and Password Recovery Management System written in C++. The project implements Object-Oriented Programming (OOP) concepts via classes and structures data storage using character delimiters within local text databases.

## Features
- **Persistent Data Storage:** Saves user credentials securely in a local text file (`login.txt`), preventing data loss when the application closes.
- **Data Structuring via Delimiters:** Efficiently packs and parses multiple fields (Username, Email, Password) on a single line using custom delimiter tokens (`*`).
- **Dynamic Password Validation:** Enforces input matching by verifying passwords and confirmation passwords before finalizing accounts.
- **Secure Retrieval Loop:** Utilizes a custom search matrix to safely crawl file text streams, avoiding standard file parsing traps like duplicate end-of-file (EOF) execution.
- **Account Password Recovery:** Allows locked-out users to securely recover passwords by validating matched combinations of user records and linked emails.

## System Architecture & Data Design
The system registers data onto the disk line-by-line using the following flat-file layout:
```text
[username]*[email]*[password]
```
During queries (Login/Forgot), the application streams through text paths sequentially, dynamically slicing strings at `*` intersections to isolate targets cleanly.

## Project Structure
- `main.cpp` - Contains the primary runtime layout, class logic, and console execution nodes.
- `login.txt` - The locally generated flat-file lookup database.
- `README.md` - Technical documentation of the application.

## Prerequisites
To compile and test this project, ensure you have:
- A modern C++ compiler supporting standard execution (GCC/MinGW, Clang, or MSVC)
- A code workspace setup (Visual Studio Code recommended)

## Installation & How to Build

### 1. Compiling via Terminal
Navigate to your project file pathway and build using standard execution protocols:
```bash
g++ loginsignupforgotform.cpp -o AuthSystem
```

### 2. Execution Run
- **Windows Environment:**
  ```bash
  .\AuthSystem.exe
  ```
- **macOS / Linux Modules:**
  ```bash
  ./AuthSystem
  ```

## Usage Instructions
1. Run the application to see the primary utility hub console.
2. Select Option `1` to build a unique identity profile.
3. Use Option `2` to authenticate status against the existing data files.
4. If credentials slip from memory, map Option `3` to run a recovery sequence against target records.
