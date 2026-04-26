# 🐍 Snake Game (Linked List Implementation in C)

## 🎮 Overview

This is a **console-based Snake Game** built in **C**, where the snake is implemented using a **linked list data structure**.
The game supports both **single-player** and **two-player modes**, making it interactive and competitive.

---

## 🚀 Features

* 🐍 Snake implemented using **linked list**
* 🎮 **Two game modes**:

  * Single Player
  * Two Player (turn-based)
* 🍎 Random food generation
* ⚡ Dynamic speed changes during gameplay
* 💥 Collision detection (walls & self)
* 📊 Score tracking system
* 🎯 Real-time keyboard controls

---

## 🧠 Data Structure Used

### Linked List

Each segment of the snake is represented as a node:

```c id="fczx0j"
typedef struct Node {
    int x, y;
    struct Node *next;
} Node;
```

👉 Benefits:

* Efficient growth of snake
* Easy addition/removal of body parts
* Dynamic memory usage

---

## 🎮 Controls

| Key | Action     |
| --- | ---------- |
| W   | Move Up    |
| S   | Move Down  |
| A   | Move Left  |
| D   | Move Right |

---

## 🖥️ Game Interface

```text id="b31qti"
H = Wall
O = Snake Head
o = Snake Body
F = Food
```

---

## 📸 Screenshots

> Add your screenshots in a folder named `screenshots/`

### 🏠 Gameplay

```markdown id="gq7jfz"
![Gameplay](screenshots/gameplay.png)
```

---

## ⚙️ How It Works

```text id="i4ifvj"
User Input → Move Snake → Check Collision → Eat Food → Grow Snake → Update Score
```

---

## 🛠️ Compilation & Run

### 🔧 Compile

```bash id="9i0lra"
gcc snake.c -o snake
```

### ▶️ Run

```bash id="fz3nfy"
./snake
```

---

## 📂 Project Structure

```text id="vbbd9q"
.
├── snake.c
├── README.md
└── screenshots/
```

---

## 🎯 Game Modes

### 1️⃣ Single Player

* Play solo
* Try to achieve maximum score

### 2️⃣ Two Player (Turn-Based)

* Player 1 plays first
* Player 2 plays next
* Highest score wins 🏆

---

## ⚡ Game Logic Highlights

* **Snake Movement**: Head moves, tail updates dynamically
* **Food Generation**: Random position not overlapping snake
* **Collision Detection**:

  * Wall collision
  * Self collision
* **Speed Variation**:

  * Changes every 10 seconds randomly

---

## ⚠️ Platform Note

This game uses:

```text id="uqo3po"
<conio.h>
<windows.h>
```

👉 Works on **Windows only**

---

## 🔥 Future Improvements

* 🎨 Better UI using graphics library (SDL/OpenGL)
* 🌐 Cross-platform support (Linux/Mac)
* 🧠 AI-controlled snake mode
* 💾 High score saving
* 🎮 Multiplayer (real-time)

---

## 👨‍💻 Author

**Bharani RM**

---

## ⭐ Support

If you like this project, give it a ⭐ on GitHub!

---

## 📜 License

This project is for learning and educational purposes.
