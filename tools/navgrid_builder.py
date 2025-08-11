#!/usr/bin/env python3
"""
Generates a binary navgrid from a PNG heightmap threshold.
"""
from PIL import Image
import sys, struct
img=Image.open(sys.argv[1]).convert("L")
thr=int(sys.argv[2]) if len(sys.argv)>2 else 16
w,h=img.size
data=bytearray([1 if p>thr else 0 for p in img.getdata()])
open(sys.argv[3],"wb").write(struct.pack("<II",w,h)+data)
