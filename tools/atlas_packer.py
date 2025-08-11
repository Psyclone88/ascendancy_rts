#!/usr/bin/env python3
"""
Packs PNGs into a single atlas (trivial grid layout).
"""
from PIL import Image
import sys, math, os

inputs=sys.argv[1:-2]
out=sys.argv[-2]
meta=sys.argv[-1]
n=len(inputs)
cols=int(math.ceil(math.sqrt(n))); rows=int(math.ceil(n/cols))
imgs=[Image.open(p).convert("RGBA") for p in inputs]
w=max(i.width for i in imgs); h=max(i.height for i in imgs)
atlas=Image.new("RGBA",(cols*w,rows*h),(0,0,0,0))
frames={}
for idx,img in enumerate(imgs):
    x=(idx%cols)*w; y=(idx//cols)*h
    atlas.paste(img,(x,y)); frames[os.path.basename(inputs[idx])]=[x,y,w,h]
atlas.save(out)
open(meta,"w").write(str(frames))
