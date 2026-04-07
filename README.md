# L-Editor (Lobster Text Engine)

[![C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

**L-Editor** is a high-performance, lightweight console-based text editing engine written in C++. It focuses on efficient memory management and a "Virtual Rendering" approach for displaying text and cursor states.

## Key Features

- **Virtual Rendering Buffer:** The core text data remains clean. Line breaks (`\n`) and the cursor visual (`|`) are injected dynamically during the output phase, preserving data integrity.
- **Vim-like Command Interface:** Navigate and control the editor using specialized commands (e.g., `:q` to quit).
- **Manual Cursor Navigation:** Full control over cursor positioning via manual movement commands.
- **Low-Level Logic:** Built using raw arrays and C-style string manipulation, making it highly portable and suitable for learning system programming.

## Technical Stack

- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP)
- **Target OS:** Windows (utilizes `system("cls")` for frame refreshing)

## Controls & Commands

Type the following commands after the `>` prompt:

| Command | Action |
| :--- | :--- |
| `:q` | Quit the editor |
| `:h` | Show Help menu |
| `:l` | Move cursor Left |
| `:r` | Move cursor Right |
| `:u` | Move cursor Up |
| `:d` | Move cursor Down |
| `:D` | Delete last character (Backspace) |
| `any text` | Type text directly into the buffer |

## Architecture Overview

The engine is divided into three core modules:
1. **ScreenRenderer:** Handles X/Y coordinate logic and screen boundaries.
2. **TextEditor:** Manages the character array and the "Virtual Render" logic.
3. **TextEngine:** The main execution loop that bridges user input and interface updates.

## Installation & Build

1. Clone the repository:
   ```bash
   git clone [https://github.com/t1mar-sk/L-Editor.git](https://github.com/t1mar-sk/L-Editor.git)
