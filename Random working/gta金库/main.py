import win32gui
import time
from PyQt5.QtWidgets import QApplication
import sys
import numpy as np
import cv2
import ctypes

size = 116

posi = [(0,0),(0,1),(0,2),(0,3), (1,3), (1,2), (1,1), (1,0)]

key_right = 0xCD
key_up = 0xC8
key_down = 0xD0
key_return = 0x1C
key_tab = 0x0F

pause_time = 0.07

SendInput = ctypes.windll.user32.SendInput

# C struct redefinitions 
PUL = ctypes.POINTER(ctypes.c_ulong)
class KeyBdInput(ctypes.Structure):
    _fields_ = [("wVk", ctypes.c_ushort),
                ("wScan", ctypes.c_ushort),
                ("dwFlags", ctypes.c_ulong),
                ("time", ctypes.c_ulong),
                ("dwExtraInfo", PUL)]

class HardwareInput(ctypes.Structure):
    _fields_ = [("uMsg", ctypes.c_ulong),
                ("wParamL", ctypes.c_short),
                ("wParamH", ctypes.c_ushort)]

class MouseInput(ctypes.Structure):
    _fields_ = [("dx", ctypes.c_long),
                ("dy", ctypes.c_long),
                ("mouseData", ctypes.c_ulong),
                ("dwFlags", ctypes.c_ulong),
                ("time",ctypes.c_ulong),
                ("dwExtraInfo", PUL)]

class Input_I(ctypes.Union):
    _fields_ = [("ki", KeyBdInput),
                 ("mi", MouseInput),
                 ("hi", HardwareInput)]

class Input(ctypes.Structure):
    _fields_ = [("type", ctypes.c_ulong),
                ("ii", Input_I)]

# Actuals Functions

def PressKey(hexKeyCode):
    extra = ctypes.c_ulong(0)
    ii_ = Input_I()
    ii_.ki = KeyBdInput( 0, hexKeyCode, 0x0008, 0, ctypes.pointer(extra) )
    x = Input( ctypes.c_ulong(1), ii_ )
    ctypes.windll.user32.SendInput(1, ctypes.pointer(x), ctypes.sizeof(x))

def ReleaseKey(hexKeyCode):
    extra = ctypes.c_ulong(0)
    ii_ = Input_I()
    ii_.ki = KeyBdInput( 0, hexKeyCode, 0x0008 | 0x0002, 0, ctypes.pointer(extra) )
    x = Input( ctypes.c_ulong(1), ii_ )
    ctypes.windll.user32.SendInput(1, ctypes.pointer(x), ctypes.sizeof(x))

def keyinput(out):
    now = [0,0]
    for i in out:
        next_ = posi[i]
        if next_[0] != now[0]:
            PressKey(key_right)
            time.sleep(pause_time)
            ReleaseKey(key_right)
            time.sleep(pause_time)
            now[0] = next_[0]
        delta = next_[1] - now[1]
        if delta > 0:
            for _ in range(delta):
                PressKey(key_down)
                time.sleep(pause_time)
                ReleaseKey(key_down)
                time.sleep(pause_time)
            now[1] = next_[1]
        elif delta < 0:
            for _ in range(-delta):
                PressKey(key_up)
                time.sleep(pause_time)
                ReleaseKey(key_up)
                time.sleep(pause_time)
            now[1] = next_[1]
        PressKey(key_return)
        time.sleep(pause_time)
        ReleaseKey(key_return)
        time.sleep(pause_time)
    PressKey(key_tab)
    time.sleep(pause_time)
    ReleaseKey(key_tab)
    time.sleep(pause_time)


hwnd = win32gui.FindWindow(None, 'Grand Theft Auto V')
app = QApplication(sys.argv)
screen = QApplication.primaryScreen()

template_finger = ('gta/finger_1.jpg', 'gta/finger_2.jpg', 'gta/finger_3.jpg', 'gta/finger_4.jpg')
template = []
for f in template_finger:
    im = cv2.imread(f, cv2.IMREAD_GRAYSCALE)
    template.append(im)

l = [(476, 272), (476, 415), (476, 560), (476, 704), (620, 704), (620, 560), (620, 415), (620, 272)]

sel = []
for i in range(1,5):
    part = []
    for j in range(1,5):
        part.append(cv2.imread('gta/%d_%d.jpg'%(i,j), cv2.IMREAD_GRAYSCALE))
    sel.append(part)

print("ready.")
while True:
    img = screen.grabWindow(hwnd).toImage()
    s = img.bits().asstring(img.width()*img.height()*img.depth() // 8)
    img = np.frombuffer(s, dtype=np.uint8).reshape((img.height(), img.width(), img.depth()//8))
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    if img.shape != (1080, 1920):
        print("请将gta的窗口调整为1920x1080")
        input()

    finger = img[155:684,960:1343]

    confi = []
    for im in template:
        res = cv2.matchTemplate(finger,im, cv2.TM_CCOEFF_NORMED)
        res = res.flatten()
        confi.append(res[0])

    i = 4
    maxValue = np.max(confi)
    if maxValue >= 0.9:
        i = np.where(confi==maxValue)[0][0]

    if i != 4:
        confi_ = confi[i]
        print(confi_)
        out = []
        for v1 in sel[i]:
            confi = []
            for x,y in l:
                res = cv2.matchTemplate(img[y:y+size,x:x+size], v1, cv2.TM_CCOEFF_NORMED)
                res = res.flatten()
                confi.append(res[0])
            maxValue = np.max(confi)
            out.append(np.where(confi==maxValue)[0][0])

        if len(out) == 4:
            out.sort()
            print(out)
            time.sleep(0.3)
            keyinput(out)
            
        time.sleep(2)

sys.exit(app.exec_())

