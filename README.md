🎨 2D Graphics Editor in C

Created By: Shreyas S Bhat

⸻

📖 Project Overview

The 2D Graphics Editor in C is a menu-driven console application that simulates basic computer graphics operations using a 2D character array as a drawing canvas. The canvas is initialized with the underscore character (_) and graphical objects are drawn using the asterisk character (*).

This project demonstrates the concepts of Computer Graphics, Data Structures, Modular Programming, and Object Management in the C programming language.

⸻

✨ Features

* 🖌️ Draw graphical objects on a character-based canvas
* 📏 Draw Lines
* ▭ Draw Rectangles
* 🔺 Draw Triangles
* ⚪ Draw Circles
* ➕ Add new objects
* ❌ Delete existing objects
* ✏️ Modify object properties
* 🖥️ Display the canvas
* 🧹 Clear the canvas
* 🆔 Object ID management
* 📂 Modular code structure using multiple source and header files

⸻

🛠️ Technologies Used

* C Programming Language
* GCC Compiler
* Arrays
* Structures
* Functions
* Header Files
* Modular Programming

⸻

📁 Project Structure

graphics_editor/
│
├── main.c
├── canvas.h
├── canvas.c
├── shapes.h
├── shapes.c
├── object_manager.h
├── object_manager.c
├── README.md
│
└── output_example.txt

⸻

⚙️ How It Works

Canvas Initialization

The canvas is represented using a 2D character array.

char canvas[HEIGHT][WIDTH];

Initially, every position is filled with:

_

Example:

____________________
____________________
____________________
____________________

⸻

Drawing Objects

The program allows users to create graphical shapes:

* Line
* Rectangle
* Triangle
* Circle

Each shape is drawn using:

*

Example:

____________________
____********________
____*______*________
____*______*________
____********________
____________________

⸻

Object Management

Every shape is assigned:

* Unique Object ID
* Shape Type
* Position
* Dimensions

This enables:

* Easy deletion
* Easy modification
* Efficient redrawing

⸻

📋 Menu Options

===== 2D GRAPHICS EDITOR =====
1. Add Object
2. Delete Object
3. Modify Object
4. Display Canvas
5. Clear Canvas
6. Exit
Enter Choice:

⸻

🚀 Compilation

Compile all source files:

gcc *.c -o graphics_editor

Run the program:

./graphics_editor

For Windows:

graphics_editor.exe

⸻



📚 Concepts Demonstrated

Computer Graphics

* Shape Representation
* Rasterized Drawing
* Character-Based Rendering

Data Structures

* Structures
* Arrays
* Object Records

Programming Concepts

* Modular Programming
* Function Decomposition
* Dynamic Menu Systems
* Object-Oriented Design Principles (Implemented in C)

⸻

🔄 Program Workflow

START
   │
   ▼
Initialize Canvas
   │
   ▼
Display Menu
   │
   ▼
User Choice
   │
 ┌─┼─────────────────────┐
 │ │ │ │ │
 ▼ ▼ ▼ ▼ ▼
Add Delete Modify Display Exit
 │
 ▼
Redraw Canvas
 │
 ▼
Display Updated Canvas
 │
 ▼
Back to Menu

⸻

🎯 Learning Outcomes

By completing this project, you will learn:

* Working with 2D Arrays
* Shape Drawing Algorithms
* Function Design
* Header File Usage
* Structure-Based Programming
* Object Management Techniques
* Modular Project Development in C

⸻

🔮 Future Enhancements

* Color Support
* Mouse-Based Drawing
* GUI Version using Graphics Library
* Shape Filling Algorithms
* Undo/Redo Functionality
* File Save and Load Support
* Shape Rotation
* Shape Scaling
* Layer Management

⸻

🤝 Contributing

Contributions, suggestions, and improvements are welcome.

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Submit a pull request

⸻

📄 License

This project is developed for educational and academic purposes.

⸻

👨‍💻 Author

Shreyas S Bhat

Computer Science & Engineering Student

* Passionate about C Programming
* Embedded Systems Enthusiast
* IoT and Software Development Learner

⭐ If you found this project useful, consider giving it a star on GitHub!
