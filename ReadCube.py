import cv2
import numpy as np
import glob

def sample_patch(hsv_img, cx, cy, size=5):
    # Extract a square patch around (cx, cy)
    patch = hsv_img[cy - size:cy + size, cx - size:cx + size]
    avg = np.mean(patch.reshape(-1, 3), axis=0)
    h, s, v = avg.astype(int)

    # print(f"HSV at ({cx},{cy}): H={h} S={s} V={v}")

    # Color classification with fixed ranges for red and orange
    if ((0 <= h <= 6 or 170 <= h <= 180) and s >= 100 and v >= 100):
        return 'red'
    elif 7 <= h <= 20 and s >= 100 and v >= 100:
        return 'orange'
    elif 21 <= h <= 34 and s >= 100 and v >= 100:
        return 'yellow'
    elif 35 <= h <= 85 and s >= 80 and v >= 80:
        return 'green'
    elif 86 <= h <= 130 and s >= 80 and v >= 80:
        return 'blue'
    elif s <= 60 and v >= 170:
        return 'white'
    else:
        # print(f"Unknown HSV: H={h}, S={s}, V={v}")
        return 'unknown'

def read_face_colors(image_path):
    img = cv2.imread(image_path)
    if img is None:
        print("Error: Image not found or can't be read.")
        return []
    
    h, w = img.shape[:2]
    crop_size = min(w, h)  # Just in case height < width
    img = img[0:crop_size, 0:crop_size]

    hsv_img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    h, w = img.shape[:2]

    # Assuming a 3x3 grid, get centers of each square (facelet)
    # Adjust offsets as needed based on image size and perspective
    offsets_x = [w // 6, w // 2, 5 * w // 6]
    offsets_y = [h // 6, h // 2, 5 * h // 6]

    colors = []
    for cy in offsets_y:
        for cx in offsets_x:
            color = sample_patch(hsv_img, cx, cy, size=5)
            colors.append(color)

    return colors

def map_color_to_letter(color_name):
    color_map = {
        'white': 'w',
        'red': 'r',
        'green': 'g',
        'yellow': 'y',
        'orange': 'o',
        'blue': 'b'
    }
    return color_map.get(color_name.lower(), '?')  # fallback to '?' for unknown

if __name__ == "__main__":
    face_colors = [None]*6
    color_to_face_index = {
    'w': 0,
    'r': 1,
    'g': 2,
    'y': 3,
    'o': 4,
    'b': 5
    }
    extensions = ["*.jpg", "*.jpeg", "*.png", "*.bmp", "*.webp"]
    image_paths = []

    for ext in extensions:
        image_paths.extend(glob.glob(f"Cube_Images/{ext}"))
        
    for image_path in image_paths:
        colors = read_face_colors(image_path)
        letters_grid = [map_color_to_letter(color) for color in colors]
        for j in range(9):
            face_colors[color_to_face_index[letters_grid[4]]]=letters_grid

    with open("input.txt", "w") as f:
        for face in face_colors:
            f.write("".join(face) + "\n")
    

