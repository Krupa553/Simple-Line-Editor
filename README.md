# Simple Line Editor Using C

## Project Description
The Simple Line Editor is a command-line text editor developed using the C programming language.

It allows users to create, modify, display, save and load a text document.

## Team Members
- Krupa S.

(Add your other team members' names if applicable.)

## Data Structure Used
Array of Strings.

```c
char lines[100][200];
int count = 0;
```

## Features Implemented
1. Insert a Line
2. Delete a Line
3. Display Document
4. Save File
5. Load File

## Technologies Used
- Programming Language: C
- Compiler: GCC
- Editor: Visual Studio Code

## Project Structure

```text
Simple-Line-Editor/
├── line_editor.c
├── HELP.md
├── README.md
└── document.txt
```

## How to Compile

```bash
gcc line_editor.c -o line_editor
```

## How to Run

```powershell
.\line_editor.exe
```

## File Handling
The program saves and loads document contents using a text file named `document.txt`.

## Conclusion
This project demonstrates the use of arrays, strings, functions, loops, conditional statements and file handling in C programming.
