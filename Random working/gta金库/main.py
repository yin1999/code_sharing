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

screen_size = [(1080, 1920), (1440, 2560)]
template = []
template_finger = ()
l = []
screen_sel = 1
finger_sel = ()

img = screen.grabWindow(hwnd).toImage()
if (img.height(),img.width()) == screen_size[1]:
    template_finger = ('gta/finger2_1.jpg', 'gta/finger2_2.jpg', 'gta/finger2_3.jpg', 'gta/finger2_4.jpg')
    l = [(634, 363), (634, 554), (634, 747), (634, 939), (827, 939), (827, 747), (827, 554), (827, 363)]
    screen_sel = 1
    finger_sel = (205,880, 1300,1760)
    size = 154
elif (img.height(),img.width()) == screen_size[0]:
    template_finger = ('gta/finger1_1.jpg', 'gta/finger1_2.jpg', 'gta/finger1_3.jpg', 'gta/finger1_4.jpg')
    l = [(476, 272), (476, 415), (476, 560), (476, 704), (620, 704), (620, 560), (620, 415), (620, 272)]
    screen_sel = 0
    finger_sel = (155,684, 960,1343)
    size = 116


for f in template_finger:
    im = cv2.imread(f, cv2.IMREAD_GRAYSCALE)
    template.append(im)

sel = []
for i in range(1,5):
    part = []
    for j in range(1,5):
        part.append(cv2.imread('gta/%d_%d_%d.jpg'%(screen_sel+1,i,j), cv2.IMREAD_GRAYSCALE))
    sel.append(part)

print("screen size: %dX%d\nready."%screen_size[screen_sel])
while True:
    img = screen.grabWindow(hwnd).toImage()
    s = img.bits().asstring(img.width()*img.height()*img.depth() // 8)
    img = np.frombuffer(s, dtype=np.uint8).reshape((img.height(), img.width(), img.depth()//8))
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    if img.shape != screen_size[screen_sel]:
        print("请将gta的窗口调整为%dX%d"%screen_size[screen_sel])
        print("调整分辨率后回车继续")
        input()

    finger = img[finger_sel[0]:finger_sel[1], finger_sel[2]:finger_sel[3]]
    confi = []
    for im in template:
        res = cv2.matchTemplate(finger,im, cv2.TM_CCOEFF_NORMED)
        res = res.flatten()
        confi.append(res[0])

    i = 4
    maxValue = np.max(confi)
    if maxValue >= 0.8:
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
