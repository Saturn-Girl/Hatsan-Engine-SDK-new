# HatsanEngine - a game engine written in Python using Pygame

import pygame
import sys

# Constants
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
BG_COLOR = (30, 30, 30)
TEXT_COLOR = (255, 255, 255)
DEFAULT_FONT_SIZE = 48

# Initialize Pygame and create window
def init(window_name: str) -> pygame.Surface:
    pygame.init()
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption(window_name)
    return screen

# Load image safely
def LoadImage(image_name: str) -> pygame.Surface:
    try:
        return pygame.image.load(image_name).convert_alpha()
    except pygame.error as e:
        print(f"[ERROR] Failed to load image '{image_name}': {e}")
        sys.exit(1)

# Render text as a surface
def TextLine(text: str, size: int = DEFAULT_FONT_SIZE, color=TEXT_COLOR) -> pygame.Surface:
    font = pygame.font.SysFont(None, size)
    return font.render(text, True, color)
