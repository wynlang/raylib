# raylib - Official Wyn Package

2D/3D graphics, games, and creative coding for Wyn. Wraps [raylib](https://www.raylib.com).

## Install

```bash
# Install raylib first
brew install raylib          # macOS
apt install libraylib-dev    # Ubuntu/Debian

# Then install the package
wyn pkg install github.com/wynlang/raylib
```

## Usage

```wyn
import raylib

raylib.Raylib_init(800, 600, "My Game")
var player_x = 100

while raylib.Raylib_should_close() == 0 {
    raylib.Raylib_begin_drawing()
    raylib.Raylib_clear(40, 40, 40)

    // Draw shapes
    raylib.Raylib_draw_rect(10, 10, 200, 100, 255, 0, 0)
    raylib.Raylib_draw_circle(400, 300, 50, 0, 255, 0)
    raylib.Raylib_draw_line(0, 0, 800, 600, 255, 255, 0)

    // Draw text
    raylib.Raylib_draw_text("Score: 42", 10, 10, 30, 255, 255, 255)

    // Input (262 = KEY_RIGHT, 0 = MOUSE_LEFT — see Key Constants below)
    if raylib.Raylib_is_key_down(262) == 1 {
        player_x = player_x + 5
    }
    if raylib.Raylib_is_mouse_pressed(0) == 1 {
        print("click at " + raylib.Raylib_mouse_x().to_string() + "," + raylib.Raylib_mouse_y().to_string())
    }

    raylib.Raylib_end_drawing()
}

raylib.Raylib_close()
```

## API

### Window
| Function | Description |
|----------|-------------|
| `Raylib_init(w, h, title)` | Create window |
| `Raylib_should_close()` | Check if window should close |
| `Raylib_close()` | Close window |

### Drawing
| Function | Description |
|----------|-------------|
| `Raylib_begin_drawing()` | Start frame |
| `Raylib_end_drawing()` | End frame |
| `Raylib_clear(r, g, b)` | Clear screen |
| `Raylib_draw_rect(x, y, w, h, r, g, b)` | Draw filled rectangle |
| `Raylib_draw_rect_lines(x, y, w, h, r, g, b)` | Draw rectangle outline |
| `Raylib_draw_circle(cx, cy, radius, r, g, b)` | Draw filled circle |
| `Raylib_draw_line(x1, y1, x2, y2, r, g, b)` | Draw line |
| `Raylib_draw_text(text, x, y, size, r, g, b)` | Draw text |
| `Raylib_text_width(text, size)` | Measure text width |

### Input
| Function | Description |
|----------|-------------|
| `Raylib_is_key_pressed(key)` | Key just pressed this frame |
| `Raylib_is_key_down(key)` | Key currently held |
| `Raylib_mouse_x()` | Mouse X position |
| `Raylib_mouse_y()` | Mouse Y position |
| `Raylib_is_mouse_pressed(btn)` | Mouse button just clicked |

### Timing
| Function | Description |
|----------|-------------|
| `Raylib_frame_time()` | Delta time (seconds) |
| `Raylib_time()` | Total elapsed time |
| `Raylib_fps()` | Current FPS |

### Key Constants
`KEY_UP`, `KEY_DOWN`, `KEY_LEFT`, `KEY_RIGHT`, `KEY_SPACE`, `KEY_ENTER`, `KEY_ESCAPE`, `KEY_W`, `KEY_A`, `KEY_S`, `KEY_D`

## Test

```bash
wyn run tests/test_raylib.wyn
```

10 tests: key constants, collision detection, movement, bounds checking, FPS timing.
