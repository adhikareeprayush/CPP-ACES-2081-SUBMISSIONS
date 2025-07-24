# 📚 Auto Word Suggestion Program

An intelligent **Auto Word Suggestion** system built using C++, developed by **Shivam Karn** and **Siddhartha Karn**. This command-line program predicts/suggests words based on user input, much like a basic autocomplete engine.

---

## 🧠 Project Description

This project simulates a basic word prediction engine using preloaded data. It is designed to help users quickly complete words by suggesting likely completions as they type.

The program uses functions defined in custom header files and processes a dictionary of words provided in the `words.txt` file.

---

## 🗂️ File Structure

```
CPP_PROJECT/
├── HEADER/
│   ├── functions.hpp         # Contains core logic and utility functions
│   └── predictor.hpp         # Contains logic specific to word prediction
├── .gitignore                # Specifies files to be ignored by Git
├── main_program.cpp          # Main file to compile and run the project
├── main_program.exe          # Windows executable (after compilation)
├── README.md                 # This file (project documentation)
└── words.txt                 # Word list used for suggestions
```

---

## 🧪 How to Run the Program

### ✅ Prerequisites:

- A C++ compiler (like `g++`)
- A terminal (Command Prompt, PowerShell, or a terminal emulator on Linux/macOS)

### ▶️ Compile the program:

```bash
g++ main_program.cpp -o main_program
```

### ▶️ Run the compiled program:

```bash
./main_program
```

> On Windows:

```bash
main_program.exe
```

---

## 📄 How It Works

1. The program loads words from `words.txt`.
2. Based on user input, it suggests likely word completions.
3. Uses efficient functions and prediction logic implemented in:
   - `functions.hpp`
   - `predictor.hpp`

---

## 👨‍💻 Authors

- **Shivam Karn**
- **Siddhartha Karn**

---
