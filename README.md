# 🎮 Hatsan Engine SDK

**Hatsan Engine SDK** is a lightweight game engine written in Python using [Pygame](https://www.pygame.org/). It supports Python and Assembly integration, and is built by a passionate young coder who loves retro tech, game development, and anime-inspired creativity.

---

## ✨ Features

- 🐍 Written in Python (Pygame-based)
- ⚙️ Assembly and MATLAB component support
- 🖼️ Basic 2D rendering (images, text)
- 🎮 Game loop and input event handling
- 💻 Cross-platform (Windows & Linux)

---

## 📦 Installation

1. Clone the repository:

```bash
git clone https://github.com/Saturn-Girl/Hatsan-Engine-SDK-new.git
cd Hatsan-Engine-SDK-new
(Optional) Create and activate a virtual environment:

python3 -m venv venv
source venv/bin/activate  # For Linux/macOS
venv\Scripts\activate.bat  # For Windows
🧪 Example Usage
import HatsanEngine

screen = HatsanEngine.init("My Game Window")
image = HatsanEngine.LoadImage("my_image.png")

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((30, 30, 30))
    screen.blit(image, (100, 100))
    pygame.display.flip()

pygame.quit()
