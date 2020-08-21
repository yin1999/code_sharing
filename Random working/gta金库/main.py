import win32gui
import time
from PyQt5.QtWidgets import QApplication
import sys
import numpy as np
import cv2

size = 116

hwnd = win32gui.FindWindow(None, 'Grand Theft Auto V')
app = QApplication(sys.argv)
screen = QApplication.primaryScreen()

template_finger = ('gta/finger_1.jpg', 'gta/finger_2.jpg', 'gta/finger_3.jpg', 'gta/finger_4.jpg')
template = []
for f in template_finger:
    im = cv2.imread(f, cv2.IMREAD_GRAYSCALE)
    template.append(im)

l = [(476, 272), (476, 415), (476, 560), (476, 704), (620, 272), (620, 415), (620, 560), (620, 704)]

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
        break

    finger = img[155:684,960:1343]

    confi = []
    for im in template:
        res = cv2.matchTemplate(finger,im, cv2.TM_CCOEFF_NORMED)
        res = res.flatten()
        confi.append(res[0])

    maxValue = np.max(confi)
    i = 4
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
            out.append(np.where(confi==maxValue)[0][0]+1)

        if len(out) != 0:
            out.sort()
            print(out)
            
        
        time.sleep(2)

sys.exit(app.exec_())